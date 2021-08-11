
#include "include.hpp"

HFont Fonts::m_WatermarkFont;
HFont Fonts::m_VelocityFont;
HFont Fonts::m_ListItemFont;

void Draw::InitFonts()
{
	if (pSurface == nullptr)
		return;

	pSurface->SetFontGlyphSet(Fonts::m_WatermarkFont = pSurface->FontCreate(), "Tahoma", 13, 700, 0, 0, 0x200);
	pSurface->SetFontGlyphSet(Fonts::m_VelocityFont = pSurface->FontCreate(), "Tahoma", 24, 700, 0, 0, 0x200);
	pSurface->SetFontGlyphSet(Fonts::m_ListItemFont = pSurface->FontCreate(), "Visitor TT2 BRK", 13, 500, 0, 0, 0x200);
}

void Draw::RenderWchar(int x, int y, int r, int g, int b, int a, HFont font, const wchar_t * text)
{
	pSurface->DrawSetTextPos(x, y);
	pSurface->DrawSetTextFont(font);
	pSurface->DrawSetTextColor(r, g, b, a);
	pSurface->DrawPrintText(text, wcslen(text));
}

void Draw::RenderText(int x, int y, int r, int g, int b, int a, bool center, HFont font, const char *input, ...)
{
	if (font == NULL || input == NULL)
		return;

	wchar_t wstr[128];
	char	cstr[256];

	va_list	va_alist;
	va_start(va_alist, input);
	vsprintf(cstr, input, va_alist);
	va_end(va_alist);

	MultiByteToWideChar(CP_UTF8, 0, cstr, -1, wstr, 128);

	if (center)
	{
		int w, h;
		pSurface->GetTextSize(font, wstr, w, h);

		if (w > 0)
			w /= 2;

		x -= w;
	}

	pSurface->DrawSetTextColor(r, g, b, a);
	pSurface->DrawSetTextFont(font);
	pSurface->DrawSetTextPos(x, y);
	pSurface->DrawPrintText(wstr, strlen(cstr));
}

#define clamp(val, min, max) (((val) > (max)) ? (max) : (((val) < (min)) ? (min) : (val)))
void Draw::DrawMonitorBar(int x, int y, int cur, const char* title)
{
	cur = clamp(cur, 0, 100);
	Draw::FillRGBA(x, y, 30, 160, (int)(cur*2.55), (255 - (int)(cur*2.55)), 0, 255);
	Draw::FillRGBA(x, y, 30, 160 - (cur * 1.6), 0, 0, 0, 255);
	Draw::RenderText( x, y + 169, 255, 255, 255, 255, false, Fonts::m_WatermarkFont, title);
}

void Draw::SoftOutlinedRectangle(int x, int y, int w, int h, int r, int g, int b, int a)
{
	Draw::FillRGBA(x + 2, y, w - 3, 1, r, g, b, a);
	Draw::FillRGBA(x + 1, y + 1, 1, 1, r, g, b, a);
	Draw::FillRGBA(x, y + 2, 1, h - 3, r, g, b, a);
	Draw::FillRGBA(x + 1, y + h - 1, 1, 1, r, g, b, a);
	Draw::FillRGBA(x + w, y + 2, 1, h - 3, r, g, b, a);
	Draw::FillRGBA(x + w - 1, y + 1, 1, 1, r, g, b, a);
	Draw::FillRGBA(x + 2, y + h, w - 3, 1, r, g, b, a);
	Draw::FillRGBA(x + w - 1, y + h - 1, 1, 1, r, g, b, a);
}

void Draw::Box(int x, int y, int w, int h, int lw, int R, int G, int B, int A)
{
	Draw::FillRGBA(x, y, w, lw, R, G, B, A);
	Draw::FillRGBA(x + w - lw, y + lw, lw, h - lw, R, G, B, A);
	Draw::FillRGBA(x, y + lw, lw, h - lw, R, G, B, A);
	Draw::FillRGBA(x + lw, y + h - lw, w - lw * 2, lw, R, G, B, A);
}

void Draw::BoxOutline(int x, int y, int w, int h, int lw, int R, int G, int B, int A)
{
	Box(x - 1, y - 1, w + 2, h + 2, lw + 2, 0, 0, 0, A);
	Box(x, y, w, h, lw, R, G, B, A);
}

void Draw::OutlinedRectangle(int x, int y, int w, int h, int r, int g, int b, int a)
{
	FillRGBA(x, y, w, 1, r, g, b, a);
	FillRGBA(x, y, 1, h, r, g, b, a);
	FillRGBA(x + w, y, 1, h + 1, r, g, b, a);
	FillRGBA(x, y + h, w, 1, r, g, b, a);
}

void Draw::RenderLine(int x, int y, int w, int h, int r, int g, int b, int a)
{
	pSurface->DrawSetColor(r, g, b, a);
	pSurface->DrawLine(x, y, w, h);
}

void Draw::FillRGBA(int x, int y, int w, int h, int r, int g, int b, int a)
{
	pSurface->DrawSetColor(r, g, b, a);
	pSurface->DrawFilledRect(x, y, x + w, y + h);
}

int iRed, iGreen, iBlue;
void Draw::GradientVertical(int x, int y, int w, int h, int r, int g, int b, int a, int r2, int g2, int b2)
{
	y += 1;

	for (int i = 1; i < h; i++)
	{
		iRed = (int)((float)i / h * (r - r2));
		iGreen = (int)((float)i / h * (g - g2));
		iBlue = (int)((float)i / h * (b - b2));
		FillRGBA(x, y + i - 1, w, 1, r - iRed, g - iGreen, b - iBlue, a);
	}
}

bool Draw::WorldToScreen(const Vector &vOrigin, Vector &vScreen)
{
	return (pOverlay->ScreenPosition(vOrigin, vScreen) != 1);
}