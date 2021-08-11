

void Slidewalk(UserCmd* cmd, Entities* pLocal)
{
	if (pLocal->GetMoveType() == MOVETYPE_LADDER || pLocal->GetMoveType() == MOVETYPE_NOCLIP)
		return;

	if (cmd->forwardmove > 0)
	{
		cmd->buttons |= IN_BACK;
		cmd->buttons &= ~IN_FORWARD;
	}

	if (cmd->forwardmove < 0)
	{
		cmd->buttons |= IN_FORWARD;
		cmd->buttons &= ~IN_BACK;
	}

	if (cmd->sidemove < 0)
	{
		cmd->buttons |= IN_MOVERIGHT;
		cmd->buttons &= ~IN_MOVELEFT;
	}

	if (cmd->sidemove > 0)
	{
		cmd->buttons |= IN_MOVELEFT;
		cmd->buttons &= ~IN_MOVERIGHT;

	}
}

void RunBhop(UserCmd* cmd, Entities* pLocal)
{
	if (pLocal->GetMoveType() == MOVETYPE_LADDER || pLocal->GetMoveType() == MOVETYPE_NOCLIP)
		return;

	static bool jumped_last_tick = false;
	static bool should_fake_jump = false;

	if (!jumped_last_tick && should_fake_jump)
	{
		should_fake_jump = false;
		cmd->buttons |= IN_JUMP;
	}
	else if (cmd->buttons & IN_JUMP)
	{
		if (pLocal->GetFlags() & FL_ONGROUND)
		{
			jumped_last_tick = true;
			should_fake_jump = true;
		}
		else
		{
			cmd->buttons &= ~IN_JUMP;
			jumped_last_tick = false;
		}
	}
	else
	{
		jumped_last_tick = false;
		should_fake_jump = false;
	}
}


void AutoPistols(UserCmd* pUserCmd,Entities* pLocal,Entities* weapon)
{
	float fCurTime = pGlobalVars->pertick * (pLocal->GetTickBase() + 1);
	float fNextPrimary = weapon->GetNextPrimaryAttack();

	bool bCanFire = true;

	static bool bOldBullet;

	if ((fNextPrimary > fCurTime) || bOldBullet)
		bCanFire = false;

	if (!(fNextPrimary > fCurTime))
		bOldBullet = false;

	if ((pUserCmd->buttons & IN_ATTACK))
	{
		if (bCanFire)
			bOldBullet = true;
		else
		{
			pUserCmd->buttons &= ~IN_ATTACK;
		}
	}
}