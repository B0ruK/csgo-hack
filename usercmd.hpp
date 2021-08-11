
struct GlobalVars
{
	BYTE   Pad[32];
	float  pertick;
};

struct PlayerInfo
{
	GlobalVars* GetGlobalVars()
	{
		typedef GlobalVars* (__thiscall* OriginalFn)(PVOID);
		return getvfunc<OriginalFn>(this, 1)(this);
	}
};

struct UserCmd
{
	BYTE      Pad[4];
	int       command_number;
	int       tick_count;
	Vector    viewangles;
	Vector    aimdirection;
	float     forwardmove;
	float     sidemove;
	float     upmove;
	int       buttons;
};