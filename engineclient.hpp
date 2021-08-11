
struct ClientState
{
	BYTE  Pad[372];
	uint32_t m_nDeltaTick;
};

struct playerinfo
{
	BYTE    Pad[8];
	int     xuid_low;
	int     xuid_high;
	char    m_name[128];
	BYTE    BPad[201];
};

struct EngineClient
{
	void GetScreenSize(int& width, int& height)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, int&, int&);
		return getvfunc<OriginalFn>(this, 5)(this, width, height);
	}

	bool GetPlayerInfo(int iIndex, playerinfo *pInfo)
	{
		typedef bool(__thiscall* OriginalFn)(PVOID, int, playerinfo*);
		return getvfunc<OriginalFn>(this, 8)(this, iIndex, pInfo);
	}

	int GetLocalPlayer()
	{
		typedef int(__thiscall* OriginalFn)(PVOID);
		return getvfunc<OriginalFn>(this, 12)(this);
	}

	void GetViewAngles(Vector& vAngles)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, Vector&);
		return getvfunc< OriginalFn >(this, 18)(this, vAngles);
	}
};

struct EntityList
{
	Entities* GetClientEntity(int entnum)
	{
		typedef Entities* (__thiscall* OriginalFn)(PVOID, int);
		return getvfunc<OriginalFn>(this, 3)(this, entnum);
	}
	Entities *GetClientEntityFromHandle(HANDLE hEnt)
	{
		typedef Entities* (__thiscall* OriginalFn)(PVOID, HANDLE);
		return getvfunc<OriginalFn>(this, 4)(this, hEnt);
	}
	int GetHighestEntityIndex(void)
	{
		typedef int(__thiscall* OriginalFn)(PVOID);
		return getvfunc<OriginalFn>(this, 6)(this);
	}
};

struct CLient
{
	ClientClass* GetAllClasses()
	{
		typedef ClientClass* (__thiscall* OriginalFn)(PVOID);
		return getvfunc<OriginalFn>(this, 8)(this);
	}

	bool DispatchUserMessage(int messageType, int arg, int arg1, void* data)
	{
		using DispatchUserMessage_t = bool* (__thiscall*)(void*, int, int, int, void*);
		return getvfunc<DispatchUserMessage_t>(this, 38)(this, messageType, arg, arg1, data);
	}
};
