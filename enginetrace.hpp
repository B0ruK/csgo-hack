
enum Masksray
{
	MASK_SHOT = 0x46004009
};

struct raytrace
{
	raytrace(const Vector& src, const Vector& dest) : start(src), delta(dest - src) { isSwept = delta.x || delta.y || delta.z; }
	Vector start{ };
	float pad{ };
	Vector delta{ };
	byte pad2[40]{ };
	bool isRay{ true };
	bool isSwept{ };
};

struct tracefitlers
{
	tracefitlers(const Entities* entity) : skip{ entity } { }
	virtual bool shouldHitEntity(Entities* entity, int) { return entity != skip; }
	virtual int getTraceType() const { return 0; }
	const void* skip;
};

struct traceclass
{
	BYTE  PPad[44];
	float fraction;
	BYTE  XPad[17];
	int hitgroup;
	BYTE  CPad[4];
	Entities* entity;
	BYTE  BPad[4];
};


struct Enginetrace
{
	void TraceRay(const raytrace &ray, tracefitlers *pTraceFilter, traceclass *ptrace)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, const raytrace &, unsigned int, tracefitlers *, traceclass *);
		getvfunc<OriginalFn>(this, 5)(this, ray, MASK_SHOT, pTraceFilter, ptrace);
	}
};

