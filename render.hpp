

namespace Fonts
{
	extern HFont m_WatermarkFont;
	extern HFont m_VelocityFont;
	extern HFont m_ListItemFont;
}

namespace Draw
{
	void InitFonts();
	void RenderWchar(int,int,int,int,int,int,HFont,const wchar_t * text);
	void DrawMonitorBar(int,int,int,const char*);
	void SoftOutlinedRectangle(int,int,int,int,int,int,int,int);
	void Box(int,int,int,int,int,int,int,int,int);
	void BoxOutline(int,int,int,int,int,int,int,int,int);
	void RenderText(int,int,int,int,int,int,bool,HFont,const char * input, ...);
	void FillRGBA(int,int,int,int,int,int,int,int);
	void OutlinedRectangle(int,int,int,int,int,int,int,int);
	void RenderLine(int,int,int,int,int,int,int,int);
	void GradientVertical(int,int,int,int,int,int,int,int,int,int,int);
	bool WorldToScreen(const Vector&, Vector&);
}