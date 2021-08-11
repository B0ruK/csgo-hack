
struct ModelRenderInfo
{
	BYTE         pad[32];
	const void*  pModel;
	BYTE         Pad[16];
	int          entity_index;
};

enum MaterialVarFlag
{
	ZNEARER = (1 << 10),
	NOCULL = (1 << 13),
	NOFOG = (1 << 14),
	IGNOREZ = (1 << 15),
	HALFLAMBERT = (1 << 27),
	WIREFRAME = (1 << 28)
};

struct Material
{
	void ColorModulate(float r, float g, float b)
	{
		typedef void(__thiscall* ColorModulateFn)(void*, float, float, float);
		getvfunc<ColorModulateFn>(this, 28)(this, r, g, b);
	}

	void SetFlag(int fl, bool set)
	{
		return getvfunc< void(__thiscall*)(void*, int, bool) >(this, 29)(this, fl, set);
	}
};

struct ModelRender
{
	void ForcedMaterialOverride(Material* material)
	{
		typedef void(__thiscall* Fn)(void*, Material*, int, int);
		return getvfunc<Fn>(this, 1)(this, material, 0, 0);
	}
};

struct MaterialSystem
{
	Material* FindMaterial(const char* name)
	{
		return  getvfunc< Material*(__thiscall*)(void *, const char*, char*, bool, void*) >(this, 84)(this, name, nullptr, true, NULL);
	}
};
