
typedef unsigned long HFont;

class Overlay
{
public:
	int ScreenPosition(const Vector& vIn, Vector& vOut)
	{
		typedef int(__thiscall* OriginalFn)(PVOID, const Vector&, Vector&);
		return getvfunc<OriginalFn>(this, 13)(this, vIn, vOut);
	}
};

struct Panel
{
	void SetMouseInputEnabled(unsigned int iPanel, bool bState)
	{
		return (getvfunc<void(__thiscall*)(PVOID, int, bool)>(this, 32))(this, iPanel, bState);
	}

	const char *GetName(unsigned int vguiPanel)
	{
		typedef const char* (__thiscall* OriginalFn)(PVOID, unsigned int);
		return getvfunc<OriginalFn>(this, 36)(this, vguiPanel);
	}
};

struct Surface
{
	void DrawSetColor(int r, int g, int b, int a)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, int, int, int, int);
		getvfunc<OriginalFn>(this, 15)(this, r, g, b, a);
	}

	void DrawFilledRect(int x0, int y0, int x1, int y1)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, int, int, int, int);
		getvfunc<OriginalFn>(this, 16)(this, x0, y0, x1, y1);
	}

	void DrawLine(int x0, int y0, int x1, int y1)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, int, int, int, int);
		getvfunc<OriginalFn>(this, 19)(this, x0, y0, x1, y1);
	}

	void DrawSetTextFont(HFont font)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, HFont);
		getvfunc<OriginalFn>(this, 23)(this, font);
	}

	void DrawSetTextColor(int r, int g, int b, int a)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, int, int, int, int);
		getvfunc<OriginalFn>(this, 25)(this, r, g, b, a);
	}

	void DrawSetTextPos(int x, int y)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, int, int);
		getvfunc<OriginalFn>(this, 26)(this, x, y);
	}

	void DrawPrintText(const wchar_t* text, int textLen)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, const wchar_t*, int, int);
		getvfunc<OriginalFn>(this, 28)(this, text, textLen, 0);
	}

	HFont FontCreate()
	{
		typedef unsigned int(__thiscall* OriginalFn)(PVOID);
		return getvfunc<OriginalFn>(this, 71)(this);
	}

	void SetFontGlyphSet(HFont font, const char* windowsFontName, int tall, int weight, int blur, int scanlines, int flags)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, HFont, const char*, int, int, int, int, int, int, int);
		getvfunc<OriginalFn>(this, 72)(this, font, windowsFontName, tall, weight, blur, scanlines, flags, 0, 0);
	}

	void GetTextSize(HFont font, const wchar_t* text, int& wide, int& tall)
	{
		typedef void(__thiscall* OriginalFn)(PVOID, HFont, const wchar_t*, int&, int&);
		getvfunc< OriginalFn >(this, 79)(this, font, text, wide, tall);
	}

	void SurfaceGetCursorPos(int& x, int& y)
	{
		typedef void(__thiscall* oSurfaceGetCursorPos)(PVOID, int&, int&);
		return getvfunc<oSurfaceGetCursorPos>(this, 100)(this, x, y);
	}
};