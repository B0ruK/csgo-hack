
#pragma pack(push, 1)
struct c_jmp_back
{
	uint8_t original_bytes[10];

	uint8_t jmp;
	uintptr_t addr;

	__forceinline void copy_original_bytes(void* function, int size)
	{
		memset(this->original_bytes, 0x90, sizeof(this->original_bytes));
		memcpy(this->original_bytes, function, size);
	}

	__forceinline void create_jmp(void* replacement, void* function)
	{
		uintptr_t jmp_addr = (reinterpret_cast<uintptr_t>(replacement) - reinterpret_cast<uintptr_t>(function)) - 5;

		this->jmp = 0xE9;
		this->addr = jmp_addr;
	}
};

struct c_jmp_creation
{
	uint8_t jmp;
	uint32_t addr;

	__forceinline void create_jmp(void* replacement, void* function)
	{
		uintptr_t jmp_addr = (reinterpret_cast<uintptr_t>(replacement) - reinterpret_cast<uintptr_t>(function)) - 5;

		this->jmp = 0xE9;
		this->addr = jmp_addr;
	}
};
#pragma pack(pop)

extern "C" 
{
	NTSTATUS NTAPI NtProtectVirtualMemory(HANDLE handle, void** addr, ULONG* size, ULONG new_prot, PULONG old_prot);
	NTSTATUS NTAPI NtAllocateVirtualMemory(HANDLE handle, void** addr, ULONG_PTR zero_bits, SIZE_T* size, ULONG type, ULONG protect);
}

class c_holy_hook
{
	void* function;
	size_t size;
public:
	void* original_bytes;

	__forceinline void create(void* vtable, int index, void* replacement, size_t size)
	{
		void** arr = *reinterpret_cast<void***>(vtable);
		this->create_inline(arr[index], replacement, size);
	}

	__declspec(noinline) void create_inline(void* function, void* replacement, size_t size)
	{
		this->size = size;
		this->function = function;

		DWORD old;
		ULONG tmp_size = this->size;
		void* tmp_addr = this->function;

		NtProtectVirtualMemory((void*)-1, &tmp_addr, &tmp_size, PAGE_EXECUTE_READWRITE, &old);

		this->rebuild_overwritten_bytes(this->function, this->size);
		c_jmp_creation* p_jmp_creation = reinterpret_cast<c_jmp_creation*>(this->function);
		p_jmp_creation->create_jmp(replacement, this->function);

		NtProtectVirtualMemory((void*)-1, &tmp_addr, &tmp_size, old, &old);
	}


	__forceinline void rebuild_overwritten_bytes(void* function, size_t size)
	{
		SIZE_T tmp_size = sizeof(c_jmp_back);
		this->original_bytes = nullptr;

		NtAllocateVirtualMemory((void*)-1, &this->original_bytes, 0, &tmp_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		c_jmp_back* p_jmp_bck = reinterpret_cast<c_jmp_back*>(this->original_bytes);
		p_jmp_bck->copy_original_bytes(function, size);

		void* replacement = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(function) + size);
		p_jmp_bck->create_jmp(replacement, &p_jmp_bck->jmp);
	}

	template <typename return_type, typename... arg_types>
	__forceinline return_type call_original(arg_types... args)
	{
		using function_typedef = return_type(__fastcall*)(arg_types...);
		function_typedef function = reinterpret_cast<function_typedef>(this->original_bytes);
		return function(args...);
	}
};