#include "include.hpp"

bool shoot;
static int custom_delay = 0;

bool caimbot::IsVisible(Vector& vecStart, Vector& vecEnd, Entities* pLocal, Entities* target)
{
	if (!pLocal || !target)
		return false;

	raytrace r(vecStart, vecEnd);
	traceclass tr;
	tracefitlers Skip = pLocal;

	pEngineTrace->TraceRay(r,&Skip,&tr);

	if (tr.fraction == 1.0f)
	{
		return true;
	}

	if (tr.entity && target)
	{
		if (tr.entity == target)
		{
			return true;
		}
	}

	return false;
}

void caimbot::triggerbot(UserCmd *cmd, Entities* local, int weaponid)
{
	if (weaponid == WEAPON_AWP || weaponid == WEAPON_SCOUT)
	{
		if (!local->IsScoped())
			return;
	}

	Vector ViewAngles = cmd->viewangles + local->GetAimPunchAngle();

	Vector CrosshairForward;
	Math::angleVectors(ViewAngles,CrosshairForward);

	CrosshairForward *= 8192.0f;

	Vector TraceSource = local->GetEyePosition();
	Vector TraceDestination = TraceSource + CrosshairForward;

	raytrace r(TraceSource, TraceDestination);
	traceclass Trace;
	tracefitlers Skip = local;

	pEngineTrace->TraceRay(r,&Skip,&Trace);

	if (!Trace.entity)
		return;

	if (!Trace.entity->IsAlive())
		return;

	if (!Trace.entity->IsPlayer())
		return;

	if (!gCvars.trigteam && local->GetTeamNum() == Trace.entity->GetTeamNum())
		return;

	bool didHit = false;

	if (gCvars.trighead && Trace.hitgroup == mhitgrp::Head) didHit = true;
	if (gCvars.triggerbody && Trace.hitgroup == mhitgrp::Chest) didHit = true;
	if (gCvars.triggerbody && Trace.hitgroup == mhitgrp::Stomach) didHit = true;

	if (gCvars.trigerdelay >= 1)
	{
		if (custom_delay >= gCvars.trigerdelay / 30)
		{
			if (didHit)
			{
				custom_delay = 0;
				shoot = true;
				cmd->buttons |= IN_ATTACK;
			}
		}
		else
		{
			custom_delay++;
		}
	}
}

bool caimbot::GetHitboxpos(Entities* pLocal, Entities* Entitiy, Vector &vPos)
{
	if (!pLocal || !Entitiy)
		return false;

	vPos = Entitiy->GetBonePos(gCvars.AimSpot);

	if (vPos.IsZero())
		return false;

	if (IsVisible(vEyePos, vPos, pLocal, Entitiy))
		return true;

	return false;
}

void caimbot::Main(UserCmd* pUserCmd, Entities* pLocal)
{
	if (gCvars.bMenu)
		return;

	if (gCvars.inattack)
	{
		if (!GetAsyncKeyState(0x01))
			return;
	}

	int iMyTeam = pLocal->GetTeamNum();

	vEyePos = pLocal->GetEyePosition();

	static Vector vClientViewAngles;
	pEngine->GetViewAngles(vClientViewAngles);

	static Vector vAngle;
	Math::angleVectors(vClientViewAngles,vAngle);

	Reset();

	for (int ax = 1; ax <= 64; ax++)
	{
		Entities* entity = pEntList->GetClientEntity(ax);

		if (!entity)
			continue;

		if (entity == pLocal)
			continue;

		if (!entity->IsAlive())
			continue;

		if (entity->IsDormant())
			continue;

		if (!gCvars.AimTeam && entity->GetTeamNum() == iMyTeam)
			continue;

		if (!pEngine->GetPlayerInfo(ax, &info))
			continue;

		if (!GetHitboxpos(pLocal,entity, vTarget))
			continue;

		float fCurrFOV = Math::GetFov(vEyePos,vTarget,vAngle);

		if(fCurrFOV > gCvars.AimFOV)
			continue;

		fCurrFOV = (Vector(vTarget - vEyePos).Length());

		if(fBestTarget < fCurrFOV)
			continue;

		fBestTarget = fCurrFOV;

		vFinal = vTarget;

		iTarget = ax;
	}

	if(HasTarget())
	{
		Math::CalcAngle(vEyePos,vFinal,pUserCmd->viewangles);

		if (gCvars.Smoothnesspitch > 0 && gCvars.Smoothnessyaw > 0)
		{
			vClientViewAngles.x = Math::AngleNormalize(vClientViewAngles.x);
			vClientViewAngles.y = Math::AngleNormalize(vClientViewAngles.y);

			Vector qDelta = pUserCmd->viewangles - vClientViewAngles;

			qDelta.x = Math::AngleNormalize(qDelta.x);
			qDelta.y = Math::AngleNormalize(qDelta.y);

			pUserCmd->viewangles.x = vClientViewAngles.x + qDelta.x / (float)gCvars.Smoothnesspitch;
			pUserCmd->viewangles.y = vClientViewAngles.y + qDelta.y / (float)gCvars.Smoothnessyaw;

			pUserCmd->viewangles.x = Math::AngleNormalize(pUserCmd->viewangles.x);
			pUserCmd->viewangles.y = Math::AngleNormalize(pUserCmd->viewangles.y);
		}
	}
}


void caimbot::Main_RCS(UserCmd* pUserCmd, Entities* pLocal)
{
	if (gCvars.bMenu)
		return;

	if (gCvars.inattack)
	{
		if (!GetAsyncKeyState(0x01))
			return;
	}

	int iMyTeam = pLocal->GetTeamNum();

	vEyePos = pLocal->GetEyePosition();

	static Vector vClientViewAngles;
	pEngine->GetViewAngles(vClientViewAngles);

	static Vector vAngle;
	Math::angleVectors(vClientViewAngles, vAngle);

	ResetRCS();

	for (int ax = 1; ax <= 64; ax++)
	{
		Entities* entity = pEntList->GetClientEntity(ax);

		if (!entity)
			continue;

		if (entity == pLocal)
			continue;

		if (!entity->IsAlive())
			continue;

		if (entity->IsDormant())
			continue;

		if (!gCvars.AimTeam && entity->GetTeamNum() == iMyTeam)
			continue;

		if (!pEngine->GetPlayerInfo(ax, &info))
			continue;

		if (!GetHitboxpos(pLocal,entity, vRCSTarget))
			continue;

		float fCurrFOV = Math::GetFov(vEyePos, vRCSTarget, vAngle);

		if (fBestRCSTarget < fCurrFOV)
			continue;

		fBestRCSTarget = fCurrFOV;

		vRCSFinal = vRCSTarget;

		iRCSTarget = ax;
	}

	if (HasTargetRCS())
	{
		float fLen = Vector(vRCSFinal - vEyePos).Length();

		Vector qAngle;
		Math::CalcAngle(vEyePos, vRCSFinal, qAngle);

		Vector qPunchangle = pLocal->GetAimPunchAngle();

		qAngle.x -= qPunchangle.x * 2;
		qAngle.y -= qPunchangle.y * 2;

		qAngle.x = Math::AngleNormalize(qAngle.x);
		qAngle.y = Math::AngleNormalize(qAngle.y);

		static Vector vForward;
		Math::angleVectors(qAngle, vForward);

		vForward = (vForward * fLen) + vEyePos;

		if (Math::GetFov(vEyePos, vForward, vAngle) <= gCvars.RCSFOV)
		{
			pUserCmd->viewangles = qAngle;

			if (gCvars.RCSSMOOTH > 0)
			{
				vClientViewAngles.x = Math::AngleNormalize(vClientViewAngles.x);
				vClientViewAngles.y = Math::AngleNormalize(vClientViewAngles.y);

				Vector qDelta = pUserCmd->viewangles - vClientViewAngles;

				qDelta.x = Math::AngleNormalize(qDelta.x);
				qDelta.y = Math::AngleNormalize(qDelta.y);

				pUserCmd->viewangles.x = vClientViewAngles.x + qDelta.x / (float)gCvars.RCSSMOOTH;
				pUserCmd->viewangles.y = vClientViewAngles.y + qDelta.y / (float)gCvars.RCSSMOOTH;

				pUserCmd->viewangles.x = Math::AngleNormalize(pUserCmd->viewangles.x);
				pUserCmd->viewangles.y = Math::AngleNormalize(pUserCmd->viewangles.y);
			}

			pUserCmd->viewangles.z = 0.0f;
		}
	}
}
