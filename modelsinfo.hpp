

struct ModelInfo
{
	int GetModelIndex(const char* Filename)
	{
		return getvfunc<int(__thiscall *)(void*, const char*)>(this, 2)(this, Filename);
	}

	const char* GetModelName(const void* Model) 
	{
		return getvfunc<const char*(__thiscall *)(void*, const void*)>(this, 3)(this, Model);
	}
};