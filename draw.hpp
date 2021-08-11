

inline int iScreenWidth, iScreenHeight;

inline void AddToDrawList(unsigned int vguiPanel)
{
	pEngine->GetScreenSize(iScreenWidth, iScreenHeight);

	if (GetAsyncKeyState(VK_END) & 1)
		gCvars.bMenu = !gCvars.bMenu;

	if (iScreenWidth != 0 && iScreenHeight != 0)
	{
		if (gCvars.watermark)
		{
			Draw::RenderText( 20, 20, 255, 255, 255, 255, false, Fonts::m_WatermarkFont, "INSOMNIA");
		}

		Entities* pLocal = pEntList->GetClientEntity(pEngine->GetLocalPlayer());

		if (pLocal)
		{
			if (gCvars.espname || gCvars.espweapon || gCvars.espbox || gCvars.healthbar)
			{
				g_ESP.draw(pLocal);
			}

			if (gCvars.radar)
			{
				g_ESP.DrawRadarBack();
			}

			if (gCvars.radar || gCvars.radaringame)
			{
				g_ESP.drawradar(pLocal);
			}

			if (gCvars.drawmonitor)
			{
				g_ESP.DrawMonitor(pLocal);
			}

			if (pLocal->IsAlive())
			{
				if (gCvars.trigenable && gCvars.triglol)
				{
					Draw::RenderText(iScreenWidth * 0.5, iScreenHeight * 0.7, 255, 0, 0, 255, true, Fonts::m_WatermarkFont, "TRIGGER:ON");
				}

				if (gCvars.velocity)
				{
					g_ESP.drawvelocity(pLocal);
				}

				if (gCvars.recoilxhair)
				{
					g_ESP.Crosshair(pLocal);
				}

				if (gCvars.speclist)
				{
					g_ESP.SpecList(pLocal);
				}
			}
		}

		pPanel->SetMouseInputEnabled(vguiPanel, gCvars.bMenu);

		if (gCvars.bMenu)
		{
			g_Mouse.Update(iScreenWidth, iScreenHeight);

			int copy_x, copy_y;
			int copy_w, copy_h;

			g_Menu.GetMenuPos(copy_x, copy_y);
			g_Menu.GetMenuSize(copy_w, copy_h);

			g_Menu.DrawMenu();

			g_Mouse.Drag(g_Mouse.bDragged[0], !g_Menu.IsHandlingItem(), g_Mouse.LeftClick(copy_x, copy_y, copy_w, copy_h), copy_x, copy_y, g_Mouse.iDiffX[0], g_Mouse.iDiffY[0]);

			g_Menu.SetMenuPos(copy_x, copy_y);

			if (g_Menu.IsHandlingItem())
				g_Menu.RemoveMenuFlag(FL_DISABLEDRAG);
		}
	}
}
