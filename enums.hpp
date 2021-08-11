

enum mFlags
{
	FL_ONGROUND = (1 << 0),
	IN_ATTACK = (1 << 0),
	IN_ZOOM = (1 << 11),
	IN_JUMP = (1 << 1),
	IN_FORWARD = (1 << 3),
	IN_BACK = (1 << 4),
	IN_MOVELEFT = (1 << 9),
	IN_MOVERIGHT = (1 << 10),
	IN_BULLRUSH = (1 << 22),
	IN_SCORE = (1 << 16)
};

enum MoveType
{
	MOVETYPE_NOCLIP = 8,
	MOVETYPE_LADDER = 9
};

enum mhitgrp
{
	Head = 1,
	Chest,
	Stomach,
	LeftArm,
	RightArm,
	LeftLeg,
	RightLeg
};

enum ClassIds
{
	GetWearables = 54
};
