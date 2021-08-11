#include "include.hpp"

#define COLORESP (gCvars.colorsredtwo), (gCvars.colorsgreentwo), (gCvars.colorsbluetwo), 255
#define RADARESP (gCvars.colorsredTHREE), (gCvars.colorsgreenTHREE), (gCvars.colorsblueTHREE), 255

void CESP::drawvelocity(Entities* local_player)
{
	Vector speed = local_player->GetVelocity();

	int intspeed = round(speed.Length2D());

	Draw::RenderText(iScreenWidth / 2, iScreenHeight - 100, COLORESP, true, Fonts::m_VelocityFont, "%0i", intspeed);
}

void CESP::DrawMonitor(Entities * plocal)
{
	int sizex = 50;
	int sizey = 100;

	if (g_Mouse.LeftClick(gCvars.f1monitorpos_x - (sizex * 0.5) - 6, gCvars.f1monitorpos_y - (sizey * 0.5) - 6, sizex * 2 + 12, sizey * 2 + 12))
	{
		gCvars.f1monitorpos_x = g_Mouse.mouse_x;
		gCvars.f1monitorpos_y = g_Mouse.mouse_y;
		gCvars.f1monitorpos_x = gCvars.f1monitorpos_x;
		gCvars.f1monitorpos_y = gCvars.f1monitorpos_y;
	}

	int centerx = gCvars.f1monitorpos_x + (sizex * 0.5);
	int centery = gCvars.f1monitorpos_y + (sizey * 0.5);

	Draw::FillRGBA(centerx - sizex - 6, centery - sizey - 20, 2 * sizex + 12, 2 * sizey + 26, 35, 35, 35, 255);
	Draw::OutlinedRectangle(centerx - sizex - 6, centery - sizey - 20, 2 * sizex + 12, 2 * sizey + 26, 0, 0, 0, 254);
	Draw::RenderText(centerx - sizex, centery - sizey - 17, 255, 255, 255, 255, false, Fonts::m_WatermarkFont, "Monitor");
	Draw::FillRGBA(centerx - sizex, centery - sizey, 2 * sizex, 2 * sizey, 50, 50, 50, 255);
	Draw::OutlinedRectangle(centerx - sizex, centery - sizey, 2 * sizex, 2 * sizey, 0, 0, 0, 254);

	int iSpeed = 0;
	float flPunch = 0.0f;

	if (plocal->IsAlive())
	{
		Vector vSpeed = plocal->GetVelocity();
		iSpeed = (int)vSpeed.Length2D();

		Vector pAngle = plocal->GetAimPunchAngle();
		float flModifier = pAngle.Normalize();

		flModifier -= (10.0f + flModifier * 0.5f) * pGlobalVars->pertick;
		pAngle *= flModifier;
		flPunch = ((pAngle.x * 17.77777777777778) * 1.25);
	}

	Draw::DrawMonitorBar(centerx - sizex + 9, centery - sizey + 12, (-flPunch), "Recoil");
	Draw::DrawMonitorBar(centerx - sizex + 59, centery - sizey + 12, (iSpeed * 0.2), "Speed");
}

void CESP::Crosshair(Entities* local)
{
	if (local->GetShotsFired() < 1)
		return;

	int x = iScreenWidth * 0.5;
	int y = iScreenHeight * 0.5;

	int dx = iScreenWidth / 90;
	int dy = iScreenHeight / 90;

	x -= (dx * local->GetAimPunchAngle().y);
	y += (dy * local->GetAimPunchAngle().x);

	Draw::FillRGBA(x - 2, y - 2, 6, 6, 0, 0, 0, 255);
	Draw::FillRGBA(x - 1, y - 1, 4, 4, COLORESP);
}

void CESP::DrawPlayer(Entities * entity, int iMyTeam)
{
	Vector Origin3D = entity->GetAbsOrigin();
	Vector Origin;

	if (Origin3D.IsZero())
		return;

	if (!Draw::WorldToScreen(Origin3D, Origin))
		return;

	Vector Head3D = entity->GetBonePos(8);

	if (Head3D.IsZero())
		return;

	Head3D.z += 15.0f;

	Vector Head;

	if (!Draw::WorldToScreen(Head3D, Head))
		return;

	float h = fabs(Head.y - Origin.y);
	float w = h / 1.65f;

	RECT rect =
	{
		static_cast<long>(Origin.x - w * 0.5f),
		static_cast<long>(Head.y),
		static_cast<long>(w),
		static_cast<long>(Origin.y)
	};

	rect.right += static_cast<long>(rect.left);

	int middle = ((rect.right - rect.left) * 0.5) + rect.left;

	if (gCvars.espbox)
	{
		DrawBox(rect);
	}

	if (gCvars.healthbar)
	{
		DrawHealth(rect, entity);
	}

	if (gCvars.espname)
	{
		wchar_t buf[128];

		if (MultiByteToWideChar(CP_UTF8, 0, info.m_name, -1, buf, 128) > 0)
		{
			int w, h;

			pSurface->GetTextSize(Fonts::m_WatermarkFont, buf, w, h);

			Draw::RenderWchar(rect.left + (rect.right - rect.left) / 2.f - (w / 2.f),rect.top - 16, 255, 255, 255, 255, Fonts::m_WatermarkFont, buf);
		}
	}

	if (gCvars.espweapon)
	{
		Entities* pWeapon = (Entities*)pEntList->GetClientEntityFromHandle(entity->GetActiveWeapon());

		if (!pWeapon) return;

		if (!pWeapon->GetWpnData()) return;

		auto text = pWeapon->GetWpnData()->WeaponName + 7;

		if (!text)
			text = "";

		Draw::RenderText(middle,rect.bottom + 1, 255, 255, 255, 255, true, Fonts::m_WatermarkFont,text);
	}
}

void CESP::DrawHealth(const RECT& rect, Entities* player)
{
	int hp = player->GetHealth();

	if (hp > 100)
		hp = 100;

	float box_h = (float)fabs(rect.bottom - rect.top);

	float off = 6;

	auto height = (((box_h * hp) / 100));

	int x = rect.left - off;
	int y = rect.top;
	int w = 4;
	int h = box_h;

	Draw::FillRGBA(x, y, w, h, 0, 0, 0, 255);
	Draw::FillRGBA(x + 1, y + 1, w - 1, height - 2, 0, 255, 0, 255);
}

void CESP::DrawBox(const RECT& rect)
{
	Draw::BoxOutline(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,1,COLORESP);
}

void CESP::drawradar(Entities* local)
{
	int iMyTeam = local->GetTeamNum();

	static Vector vClientViewAngles;

	pEngine->GetViewAngles(vClientViewAngles);

	for (int ax = 1; ax <= 64; ax++)
	{
		Entities* entity = pEntList->GetClientEntity(ax);

		if (!entity)
			continue;

		if (entity == local)
			continue;

		if (entity->IsDormant())
			continue;

		if (!entity->IsAlive())
			continue;

		int iTeamNum = entity->GetTeamNum();

		if (iTeamNum == iMyTeam && !gCvars.radarteam)
			continue;

		if (gCvars.radaringame)
		{
			*(char*)((DWORD)(entity)+offsets.DT_BaseEntity.m_bSpotted) = 1;
		}

		if (gCvars.radar)
		{
			if (!pEngine->GetPlayerInfo(ax, &info))
				continue;

			DrawRadarPoint(entity->GetAbsOrigin(), local->GetAbsOrigin(), vClientViewAngles, info);
		}
	}
}

void CESP::SpecList(Entities *local)
{
	int kapi = 0;

	for (int ax = 1; ax <= 64; ax++)
	{
		Entities* pEntity = pEntList->GetClientEntity(ax);

		if (pEntity && pEntity != local)
		{
			if (pEngine->GetPlayerInfo(ax, &info) && !pEntity->IsAlive() && !pEntity->IsDormant())
			{
				HANDLE obs = pEntity->GetObserverTargetHandle();

				if (obs)
				{
					Entities *pTarget = pEntList->GetClientEntityFromHandle(obs);
					playerinfo pinfo2;

					if (pTarget && pTarget->GetIndex() == local->GetIndex())
					{
						if (pEngine->GetPlayerInfo(pTarget->GetIndex(), &pinfo2))
						{
							wchar_t buf[128];

							if (MultiByteToWideChar(CP_UTF8, 0, info.m_name, -1, buf, 128) > 0)
							{
								Draw::RenderWchar(25, iScreenHeight * 0.5 - 20 + (16 * kapi) + 20, COLORESP, Fonts::m_WatermarkFont, buf);
							}

							kapi++;
						}
					}
				}
			}
		}
	}

	Draw::RenderText(25, iScreenHeight * 0.5 - 20, 255,255,255,255, false, Fonts::m_WatermarkFont, "Spectating you:");
}

void CESP::draw(Entities* local)
{
	int iMyTeam = local->GetTeamNum();

	for (int ax = 1; ax <= 64; ax++)
	{
		Entities* entity = pEntList->GetClientEntity(ax);

		if (!entity)
			continue;

		if (entity == local)
			continue;

		if (entity->IsDormant())
			continue;

		if (!entity->IsAlive())
			continue;

		if (!pEngine->GetPlayerInfo(ax, &info))
			continue;

		int iTeamNum = entity->GetTeamNum();

		if (!gCvars.espteam && iTeamNum == iMyTeam)
			continue;

		if (gCvars.esprenderdist > 1)
		{
			if (local->GetOrigin().DistTo(entity->GetOrigin()) > gCvars.esprenderdist)
				continue;
		}

		DrawPlayer(entity, iMyTeam);
	}
}

void CESP::DrawRadarBack()
{
	int size = gCvars.radarsize;

	if (g_Mouse.LeftClick(gCvars.flRadarPos_x - (size * 0.5) - 6, gCvars.flRadarPos_y - (size * 0.5) - 6, size * 2 + 12, size * 2 + 12))
	{
		gCvars.flRadarPos_x = g_Mouse.mouse_x;
		gCvars.flRadarPos_y = g_Mouse.mouse_y;
		gCvars.flRadarPos_x = gCvars.flRadarPos_x;
		gCvars.flRadarPos_y = gCvars.flRadarPos_y;
	}

	int centerx = gCvars.flRadarPos_x + (size * 0.5);
	int centery = gCvars.flRadarPos_y + (size * 0.5);

	Draw::FillRGBA(centerx - size - 6, centery - size - 20, 2 * size + 12, 2 * size + 26, 35, 35, 35, 255);
	Draw::OutlinedRectangle(centerx - size - 6, centery - size - 20, 2 * size + 12, 2 * size + 26, 0, 0, 0, 254);
	Draw::RenderText(centerx - size, centery - size - 17,255, 255, 255, 255, false, Fonts::m_WatermarkFont, "Radar");
	Draw::FillRGBA(centerx - size, centery - size, 2 * size, 2 * size, 50, 50, 50, 255);
	Draw::OutlinedRectangle(centerx - size, centery - size, 2 * size, 2 * size, 0, 0, 0, 254);
	Draw::FillRGBA(centerx, centery - size, 1, 2 * size, 0, 0, 0, 120);
	Draw::FillRGBA(centerx - size, centery, 2 * size, 1, 0, 0, 0, 120);
}

void CESP::DrawRadarPoint(Vector vecOriginx, Vector vecOriginy, Vector vAngle, playerinfo info)
{
	int size = gCvars.radarsize;

	size -= 3;

	int centerx = gCvars.flRadarPos_x + (size * 0.5);
	int centery = gCvars.flRadarPos_y + (size * 0.5);

	float dx = vecOriginx.x - vecOriginy.x;
	float dy = vecOriginx.y - vecOriginy.y;
	float flAngle = vAngle.y;
	float yaw = (flAngle)* (PI / 180.0);
	float mainViewAngles_CosYaw = cos(yaw);
	float mainViewAngles_SinYaw = sin(yaw);
	float x = dy * (-mainViewAngles_CosYaw) + dx * mainViewAngles_SinYaw;
	float y = dx * (-mainViewAngles_CosYaw) - dy * mainViewAngles_SinYaw;
	float range = gCvars.radarrange * 30;
	if (fabs(x) > range || fabs(y) > range)
	{
		if (y > x)
		{
			if (y > -x) {
				x = range * x / y;
				y = range;
			}
			else {
				y = -range * y / x;
				x = -range;
			}
		}
		else {
			if (y > -x) {
				y = range * y / x;
				x = range;
			}
			else {
				x = -range * x / y;
				y = -range;
			}
		}
	}
	int ScreenX = centerx + int(x / range * float(size));
	int ScreenY = centery + int(y / range * float(size));
	size -= 3;
	int radar_menu_x = centerx;
	int radar_menu_y = centery;

	if (ScreenX < radar_menu_x - size)
		ScreenX = radar_menu_x - size + 1;
	else if (ScreenX > radar_menu_x + size)
		ScreenX = radar_menu_x + size - 3;

	if (ScreenY < radar_menu_y - size)
		ScreenY = radar_menu_y - size + 2;
	else if (ScreenY > radar_menu_y + size)
		ScreenY = radar_menu_y + size - 4;

	Draw::FillRGBA(ScreenX - 2, ScreenY - 2, 6, 6, 0, 0, 0, 255);
	Draw::FillRGBA(ScreenX - 1, ScreenY - 1, 4, 4, RADARESP);

	if (gCvars.radarnames)
	{
		wchar_t buf[128];

		if (MultiByteToWideChar(CP_UTF8, 0, info.m_name, -1, buf, 128) > 0)
		{
			Draw::RenderWchar(ScreenX + 2, ScreenY + 4, 255, 255, 255, 255, Fonts::m_WatermarkFont, buf);
		}
	}
}