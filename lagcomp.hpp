
#define NUM_OF_TICKS 12

struct lagcompData
{
	float simtime;
	Vector hitboxPos;
};

lagcompData headPositions[64][NUM_OF_TICKS];

void lagcomp(UserCmd* cmd, Entities* pLocal)
{
	int bestTargetIndex = -1;

	float bestFov = FLT_MAX;

	playerinfo info;

	for (int ax = 1; ax <= 64; ax++)
	{
		auto entity = (Entities*)pEntList->GetClientEntity(ax);

		if (!entity)
			continue;

		if (entity == pLocal)
			continue;

		if (!entity->IsAlive())
			continue;

		if (!pEngine->GetPlayerInfo(ax, &info))
			continue;

		if (entity->IsDormant())
			continue;

		if (entity->GetTeamNum() == pLocal->GetTeamNum())
			continue;

		float simtime = entity->m_flSimulationTime();

		Vector hitboxPos = entity->GetBonePos(gCvars.AimSpot);

		if (hitboxPos.IsZero())
			continue;

		headPositions[ax][cmd->command_number % NUM_OF_TICKS] = lagcompData{ simtime, hitboxPos };

		Vector ViewDir = Math::MakeVector(cmd->viewangles + (pLocal->GetAimPunchAngle() * 2.f));

		float FOVDistance = Math::GetFov(pLocal->GetEyePosition(), hitboxPos, ViewDir);

		if (bestFov > FOVDistance)
		{
			bestFov = FOVDistance;
			bestTargetIndex = ax;
		}
	}

	float bestTargetSimTime;

	if (bestTargetIndex != -1)
	{
		float tempFloat = FLT_MAX;
		Vector ViewDir = Math::MakeVector(cmd->viewangles + (pLocal->GetAimPunchAngle() * 2.f));

		for (int t = 0; t <= NUM_OF_TICKS; ++t)
		{
			float tempFOVDistance = Math::GetFov(pLocal->GetEyePosition(), headPositions[bestTargetIndex][t].hitboxPos, ViewDir);

			if (tempFloat > tempFOVDistance && headPositions[bestTargetIndex][t].simtime > pLocal->m_flSimulationTime() - 1)
			{
				tempFloat = tempFOVDistance;
				bestTargetSimTime = headPositions[bestTargetIndex][t].simtime;
			}
		}

		if (bestTargetSimTime >= 0 && cmd->buttons & IN_ATTACK)
		{
			cmd->tick_count = Math::TimeToTicks(bestTargetSimTime);
		}
	}
}
