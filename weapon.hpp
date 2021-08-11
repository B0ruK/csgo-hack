

enum WeaponIndx
{
	WEAPON_DEAGLE = 1,
	WEAPON_DUALS = 2,
	WEAPON_FIVE7 = 3,
	WEAPON_GLOCK = 4,
	WEAPON_AK47 = 7,
	WEAPON_AUG = 8,
	WEAPON_AWP = 9,
	WEAPON_FAMAS = 10,
	WEAPON_G3SG1 = 11,
	WEAPON_GALIL = 13,
	WEAPON_M249 = 14,
	WEAPON_M4A1 = 16,
	WEAPON_MAC10 = 17,
	WEAPON_P90 = 19,
	WEAPON_MP5SD = 23,
	WEAPON_UMP45 = 24,
	WEAPON_XM1014 = 25,
	WEAPON_BIZON = 26,
	WEAPON_MAG7 = 27,
	WEAPON_NEGEV = 28,
	WEAPON_SAWEDOFF = 29,
	WEAPON_TEC9 = 30,
	WEAPON_P2000 = 32,
	WEAPON_MP7 = 33,
	WEAPON_MP9 = 34,
	WEAPON_NOVA = 35,
	WEAPON_P250 = 36,
	WEAPON_SCAR20 = 38,
	WEAPON_SG553 = 39,
	WEAPON_SCOUT = 40,
	WEAPON_KNIFE_T = 42,
	WEAPON_KNIFE_CT = 59,
	WEAPON_M4A1S = 60,
	WEAPON_USPS = 61,
	WEAPON_CZ75 = 63,
	WEAPON_REVOLVER = 64,
	WEAPON_KNIFE_BAYONET = 500,
	WEAPON_KNIFE_FLIP = 505,
	WEAPON_KNIFE_GUT = 506,
	WEAPON_KNIFE_KARAMBIT = 507,
	WEAPON_KNIFE_M9BAYONET = 508,
	GLOVE_STUDDED_BLOODHOUND = 5027,
	GLOVE_SPORTY = 5030,
	GLOVE_SLICK = 5031,
	GLOVE_LEATHER_WRAP = 5032,
	GLOVE_MOTORCYCLE = 5033,
	GLOVE_SPECIALIST = 5034
};

struct WeaponInfo
{
	BYTE  pad[4];
	char* WeaponName;
};

inline bool IsRecoilWep(int iWpnID)
{
	return (iWpnID == WEAPON_AK47
		|| iWpnID == WEAPON_AUG
		|| iWpnID == WEAPON_FAMAS
		|| iWpnID == WEAPON_GALIL
		|| iWpnID == WEAPON_M249
		|| iWpnID == WEAPON_M4A1
		|| iWpnID == WEAPON_MAC10
		|| iWpnID == WEAPON_P90
		|| iWpnID == WEAPON_MP5SD
		|| iWpnID == WEAPON_UMP45
		|| iWpnID == WEAPON_BIZON
		|| iWpnID == WEAPON_NEGEV
		|| iWpnID == WEAPON_MP7
		|| iWpnID == WEAPON_MP9
		|| iWpnID == WEAPON_SG553
		|| iWpnID == WEAPON_DUALS
		|| iWpnID == WEAPON_M4A1S);
}

inline bool IsAimWep(int iWpnID)
{
	return (iWpnID == WEAPON_DEAGLE
		|| iWpnID == WEAPON_FIVE7
		|| iWpnID == WEAPON_GLOCK
		|| iWpnID == WEAPON_AWP
		|| iWpnID == WEAPON_G3SG1
		|| iWpnID == WEAPON_MAG7
		|| iWpnID == WEAPON_SAWEDOFF
		|| iWpnID == WEAPON_XM1014
		|| iWpnID == WEAPON_TEC9
		|| iWpnID == WEAPON_P2000
		|| iWpnID == WEAPON_NOVA
		|| iWpnID == WEAPON_P250
		|| iWpnID == WEAPON_SCAR20
		|| iWpnID == WEAPON_SCOUT
		|| iWpnID == WEAPON_USPS
		|| iWpnID == WEAPON_REVOLVER);
}