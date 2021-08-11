#include "include.hpp"


void cMouse::Drag(bool& bDrag, bool bCheck, bool bDragCheck,int& x, int& y, int& xdif, int& ydif)
{
	if(bCheck)								  
	{					
		if(bDragCheck || (mouse1pressed && bDrag))		  
		{
			if(!bDrag)					  
				bDrag = true;

			if(xdif == -1 || ydif == -1)	  
			{							
				xdif = mouse_x - x;	  
				ydif = mouse_y - y;	  
			}

			x += mouse_x - (xdif + x); 
			y += mouse_y - (ydif + y); 
		}									  
		else								  
		{			
			if(bDrag)
				bDrag = false;

			xdif = -1;						  
			ydif = -1;						  
		}									  
	}
}

bool cMouse::LeftClick(int x,int y,int w,int h)
{
	return (mouse1pressed && IsOver(x,y,w,h));
}

bool cMouse::OneLeftClick(int x,int y,int w,int h)
{
	return (mouse1released && IsOver(x,y,w,h));
}

bool cMouse::IsOver(int x,int y,int w,int h)
{
	return (mouse_x > x  && w+x > mouse_x && mouse_y > y  && h+y > mouse_y);
}

void cMouse::Update(int width, int height)
{
	pSurface->SurfaceGetCursorPos(mouse_x, mouse_y);

	if (mouse_x > width)
		mouse_x = width;

	if (mouse_x < 0)
		mouse_x = 0;

	if (mouse_y > height)
		mouse_y = height;

	if (mouse_y < 0)
		mouse_y = 0;

	if (GetAsyncKeyState(VK_LBUTTON))
		mouse1pressed = true;
	else if (!GetAsyncKeyState(VK_LBUTTON))
	{
		if (mouse1pressed)
			mouse1released = true;
		else
			mouse1released = false;

		mouse1pressed = false;
	}

	if (GetAsyncKeyState(VK_RBUTTON))
		mouse2pressed = true;
	else if (!GetAsyncKeyState(VK_RBUTTON))
	{
		if (mouse2pressed)
			mouse2released = true;
		else
			mouse2released = false;

		mouse2pressed = false;
	}
}