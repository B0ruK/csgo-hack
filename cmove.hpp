
#include "misc.hpp"
#include "lagcomp.hpp"

void DoStuff(UserCmd* pUserCmd)
{
	Entities* pLocal = pEntList->GetClientEntity(pEngine->GetLocalPlayer());

	if (!pLocal)
		return;

	if (gCvars.showrank && pUserCmd->buttons & IN_SCORE)
	{
		pClient->DispatchUserMessage(50, 0, 0, nullptr);
	}

	if (!pLocal->IsAlive())
		return;

	if (gCvars.Bunnyhop)
	{
		RunBhop(pUserCmd, pLocal);
	}

	if (gCvars.slidewalk)
	{
		Slidewalk(pUserCmd, pLocal);
	}

	if (gCvars.noflash)
	{
		pLocal->GetFlashDuration(0.f);
	}

	Entities* pWeapon = (Entities*)pEntList->GetClientEntityFromHandle(pLocal->GetActiveWeapon());

	if (!pWeapon || !pWeapon->HasAmmo())
		return;

	int weaponid = *pWeapon->GetItemDefinitionIndex();

	if (!IsAimWep(weaponid) && !IsRecoilWep(weaponid))
		return;

	if (gCvars.trigenable)
	{
		if (GetAsyncKeyState(gCvars.triggerkey) & 1)
			gCvars.triglol = !gCvars.triglol;

		if (gCvars.triglol)
		{
			g_aimbot.triggerbot(pUserCmd, pLocal,weaponid);
		}
	}

	if (!gCvars.legitenable)
		return;

	if (gCvars.lagcomp)
	{
		lagcomp(pUserCmd, pLocal);
	}

	if (gCvars.autopistol && weaponid != WEAPON_REVOLVER)
	{
		AutoPistols(pUserCmd, pLocal, pWeapon);
	}

	if (!gCvars.RCSASSIST)
	{
		g_aimbot.Main(pUserCmd, pLocal);
	}

	if (gCvars.RCSASSIST)
	{
		if (IsRecoilWep(weaponid))
		{
			g_aimbot.Main_RCS(pUserCmd, pLocal);
		}

		if (IsAimWep(weaponid))
		{
			g_aimbot.Main(pUserCmd, pLocal);
		}
	}

	Math::ClampAngles(pUserCmd->viewangles);

}