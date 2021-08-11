#include "include.hpp"

void CfgSystem::LoadCfg(bool left, bool right)
{
	static char path[MAX_PATH];
	std::string folder, file;

	if (left)
	{
		if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path)))
		{
			char szCmd[256];
			sprintf(szCmd, "\\insolegit\\config.ini");

			folder = std::string(path) + "\\insolegit\\";
			file = std::string(path) + szCmd;
		}
		CreateDirectoryA(folder.c_str(), NULL);
	}

	if (right)
	{
		if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path)))
		{
			char szCmd[256];
			sprintf(szCmd, "\\insorage\\config.ini");

			folder = std::string(path) + "\\insorage\\";
			file = std::string(path) + szCmd;
		}
		CreateDirectoryA(folder.c_str(), NULL);
	}

	CIniWriter writer(file.c_str());

	gCvars.Smoothnessyaw = writer.ReadFloat("Smoothnessyaw");
	gCvars.Smoothnesspitch = writer.ReadFloat("Smoothnesspitch");
	gCvars.legitenable = writer.ReadFloat("legitenable");
	gCvars.RCSASSIST = writer.ReadFloat("RCSASSIST");
	gCvars.AimTeam = writer.ReadFloat("AimTeam");
	gCvars.AimFOV = writer.ReadFloat("AimFOV");
	gCvars.AimSpot = writer.ReadFloat("AimSpot");
	gCvars.Bunnyhop = writer.ReadFloat("Bunnyhop");
	gCvars.inattack = writer.ReadFloat("inattack");
	gCvars.radar = writer.ReadFloat("radar");
	gCvars.velocity = writer.ReadFloat("velocity");
	gCvars.watermark = writer.ReadFloat("watermark");
	gCvars.gloves = writer.ReadFloat("gloves");
	gCvars.knife = writer.ReadFloat("knife");
	gCvars.knifeskin = writer.ReadFloat("knifeskin");
	gCvars.ak47skin = writer.ReadFloat("ak47skin");
	gCvars.awpskin = writer.ReadFloat("awpskin");
	gCvars.deagleskin = writer.ReadFloat("deagleskin");
	gCvars.glockskin = writer.ReadFloat("glockskin");
	gCvars.uspskin = writer.ReadFloat("uspskin");
	gCvars.triggerkey = writer.ReadFloat("triggerkey");
	gCvars.m4a1skin = writer.ReadFloat("m4a1skin");
	gCvars.skinchanger = writer.ReadFloat("skinchanger");
	gCvars.skinselection = writer.ReadFloat("skinselection");
	gCvars.trigenable = writer.ReadFloat("trigenable");
	gCvars.trighead = writer.ReadFloat("trighead");
	gCvars.triggerbody = writer.ReadFloat("triggerbody");
	gCvars.trigerdelay = writer.ReadFloat("trigerdelay");
	gCvars.speclist = writer.ReadFloat("speclist");
	gCvars.trigteam = writer.ReadFloat("trigteam");
	gCvars.autopistol = writer.ReadFloat("autopistol");
	gCvars.espbox = writer.ReadFloat("espbox");
	gCvars.healthbar = writer.ReadFloat("healthbar");
	gCvars.chams = writer.ReadFloat("chams");
	gCvars.XQZ = writer.ReadFloat("XQZ");
	gCvars.espteam = writer.ReadFloat("espteam");
	gCvars.radarsize = writer.ReadFloat("radarsize");
	gCvars.radarrange = writer.ReadFloat("radarrange");
	gCvars.radarteam = writer.ReadFloat("radarteam");
	gCvars.radarnames = writer.ReadFloat("radarnames");
	gCvars.radaringame = writer.ReadFloat("radaringame");
	gCvars.glovekit1 = writer.ReadFloat("glovekit1");
	gCvars.glovekit2 = writer.ReadFloat("glovekit2");
	gCvars.glovekit3 = writer.ReadFloat("glovekit3");
	gCvars.glovekit4 = writer.ReadFloat("glovekit4");
	gCvars.glovekit5 = writer.ReadFloat("glovekit5");
	gCvars.glovekit6 = writer.ReadFloat("glovekit6");
	gCvars.RCSFOV = writer.ReadFloat("RCSFOV");
	gCvars.RCSSMOOTH = writer.ReadFloat("RCSSMOOTH");
	gCvars.lagcomp = writer.ReadFloat("lagcomp");
	gCvars.flRadarPos_x = writer.ReadFloat("flRadarPos_x");
	gCvars.flRadarPos_y = writer.ReadFloat("flRadarPos_y");
	gCvars.colorsredone = writer.ReadFloat("colorsredone");
	gCvars.colorsgreenone = writer.ReadFloat("colorsgreenone");
	gCvars.colorsblueone = writer.ReadFloat("colorsblueone");
	gCvars.colorsredtwo = writer.ReadFloat("colorsredtwo");
	gCvars.colorsgreentwo = writer.ReadFloat("colorsgreentwo");
	gCvars.colorsbluetwo = writer.ReadFloat("colorsbluetwo");
	gCvars.colorsredTHREE = writer.ReadFloat("colorsredTHREE");
	gCvars.colorsgreenTHREE = writer.ReadFloat("colorsgreenTHREE");
	gCvars.colorsblueTHREE = writer.ReadFloat("colorsblueTHREE");
	gCvars.colorsredFOUR = writer.ReadFloat("colorsredFOUR");
	gCvars.colorsgreenFOUR = writer.ReadFloat("colorsgreenFOUR");
	gCvars.colorsblueFOUR = writer.ReadFloat("colorsblueFOUR");
	gCvars.colorsredFIVE = writer.ReadFloat("colorsredFIVE");
	gCvars.colorsgreenFIVE = writer.ReadFloat("colorsgreenFIVE");
	gCvars.colorsblueFIVE = writer.ReadFloat("colorsblueFIVE");
	gCvars.sg553skin = writer.ReadFloat("sg553skin");
	gCvars.scoutskin = writer.ReadFloat("scoutskin");
	gCvars.m4a4skin = writer.ReadFloat("m4a4skin");
	gCvars.p2000skin = writer.ReadFloat("p2000skin");
	gCvars.dualskin = writer.ReadFloat("dualskin");
	gCvars.augskin = writer.ReadFloat("augskin");
	gCvars.galilskin = writer.ReadFloat("galilskin");
	gCvars.ak47stats = writer.ReadFloat("ak47stats");
	gCvars.awpstats = writer.ReadFloat("awpstats");
	gCvars.deaglestats = writer.ReadFloat("deaglestats");
	gCvars.glockstats = writer.ReadFloat("glockstats");
	gCvars.uspstats = writer.ReadFloat("uspstats");
	gCvars.m4a1stats = writer.ReadFloat("m4a1stats");
	gCvars.sg553stats = writer.ReadFloat("sg553stats");
	gCvars.scoutstats = writer.ReadFloat("scoutstats");
	gCvars.m4a4stats = writer.ReadFloat("m4a4stats");
	gCvars.p2000stats = writer.ReadFloat("p2000stats");
	gCvars.dualstats = writer.ReadFloat("dualstats");
	gCvars.augstats = writer.ReadFloat("augstats");
	gCvars.galilstats = writer.ReadFloat("galilstats");
	gCvars.ak47seed = writer.ReadFloat("ak47seed");
	gCvars.awpseed = writer.ReadFloat("awpseed");
	gCvars.deagleseed = writer.ReadFloat("deagleseed");
	gCvars.glockseed = writer.ReadFloat("glockseed");
	gCvars.uspseed = writer.ReadFloat("uspseed");
	gCvars.m4a1seed = writer.ReadFloat("m4a1seed");
	gCvars.sg553seed = writer.ReadFloat("sg553seed");
	gCvars.scoutseed = writer.ReadFloat("scoutseed");
	gCvars.m4a4seed = writer.ReadFloat("m4a4seed");
	gCvars.p2000seed = writer.ReadFloat("p2000seed");
	gCvars.dualseed = writer.ReadFloat("dualseed");
	gCvars.augseed = writer.ReadFloat("augseed");
	gCvars.galilseed = writer.ReadFloat("galilseed");
	gCvars.esprenderdist = writer.ReadFloat("esprenderdist");
	gCvars.recoilxhair = writer.ReadFloat("recoilxhair");
	gCvars.drawmonitor = writer.ReadFloat("drawmonitor");
	gCvars.f1monitorpos_x = writer.ReadFloat("f1monitorpos_x");
	gCvars.f1monitorpos_y = writer.ReadFloat("f1monitorpos_y");
	gCvars.espweapon = writer.ReadFloat("espweapon");
	gCvars.espname = writer.ReadFloat("espname");
	gCvars.espteam = writer.ReadFloat("espteam");
	gCvars.CHAMTEAM = writer.ReadFloat("CHAMTEAM");
	gCvars.noflash = writer.ReadFloat("noflash");
	gCvars.nosmoke = writer.ReadFloat("nosmoke");
	gCvars.slidewalk = writer.ReadFloat("slidewalk");
	gCvars.mp5seed = writer.ReadFloat("mp5seed");
	gCvars.mp5stat = writer.ReadFloat("mp5stat");
	gCvars.mp5skin = writer.ReadFloat("mp5skin");
	gCvars.r8seed = writer.ReadFloat("r8seed");
	gCvars.r8stat = writer.ReadFloat("r8stat");
	gCvars.r8skin = writer.ReadFloat("r8skin");
	gCvars.scarseed = writer.ReadFloat("scarseed");
	gCvars.scarstat = writer.ReadFloat("scarstat");
	gCvars.scarskin = writer.ReadFloat("scarskin");
	gCvars.p250skin = writer.ReadFloat("p250skin");
	gCvars.p250stat = writer.ReadFloat("p250stat");
	gCvars.p250seed = writer.ReadFloat("p250seed");
	gCvars.novaskin = writer.ReadFloat("novaskin");
	gCvars.novastat = writer.ReadFloat("novastat");
	gCvars.novaseed = writer.ReadFloat("novaseed");
	gCvars.mp9skin = writer.ReadFloat("mp9skin");
	gCvars.mp9stat = writer.ReadFloat("mp9stat");
	gCvars.mp9seed = writer.ReadFloat("mp9seed");
	gCvars.umpseed = writer.ReadFloat("umpseed");
	gCvars.umpstat = writer.ReadFloat("umpstat");
	gCvars.umpskin = writer.ReadFloat("umpskin");
	gCvars.fivesevenseed = writer.ReadFloat("fivesevenseed");
	gCvars.fivesevenstat = writer.ReadFloat("fivesevenstat");
	gCvars.fivesevenskin = writer.ReadFloat("fivesevenskin");
	gCvars.famasseed = writer.ReadFloat("famasseed");
	gCvars.famasstat = writer.ReadFloat("famasstat");
	gCvars.famasskin = writer.ReadFloat("famasskin");
	gCvars.g3sg1seed = writer.ReadFloat("g3sg1seed");
	gCvars.g3sg1stat = writer.ReadFloat("g3sg1stat");
	gCvars.g3sg1skin = writer.ReadFloat("g3sg1skin");
	gCvars.m249seed = writer.ReadFloat("m249seed");
	gCvars.m249stat = writer.ReadFloat("m249stat");
	gCvars.m249skin = writer.ReadFloat("m249skin");
	gCvars.p90seed = writer.ReadFloat("p90seed");
	gCvars.p90stat = writer.ReadFloat("p90stat");
	gCvars.p90skin = writer.ReadFloat("p90skin");
	gCvars.mac10seed = writer.ReadFloat("mac10seed");
	gCvars.mac10stat = writer.ReadFloat("mac10stat");
	gCvars.mac10skin = writer.ReadFloat("mac10skin");
	gCvars.xm1000skin = writer.ReadFloat("xm1000skin");
	gCvars.xm1000stat = writer.ReadFloat("xm1000stat");
	gCvars.xm1000seed = writer.ReadFloat("xm1000seed");
	gCvars.bizonskin = writer.ReadFloat("bizonskin");
	gCvars.bizonstat = writer.ReadFloat("bizonstat");
	gCvars.bizonseed = writer.ReadFloat("bizonseed");
	gCvars.mag7skin = writer.ReadFloat("mag7skin");
	gCvars.mag7seed = writer.ReadFloat("mag7seed");
	gCvars.mag7seed = writer.ReadFloat("mag7seed");
	gCvars.negevskin = writer.ReadFloat("negevskin");
	gCvars.negevstat = writer.ReadFloat("negevstat");
	gCvars.negevseed = writer.ReadFloat("negevseed");
	gCvars.sawedskin = writer.ReadFloat("sawedskin");
	gCvars.sawedstat = writer.ReadFloat("sawedstat");
	gCvars.sawedseed = writer.ReadFloat("sawedseed");
	gCvars.tecskin = writer.ReadFloat("tecskin");
	gCvars.tecstat = writer.ReadFloat("tecstat");
	gCvars.tecseed = writer.ReadFloat("tecseed");
	gCvars.mp7skin = writer.ReadFloat("mp7skin");
	gCvars.mp7stat = writer.ReadFloat("mp7stat");
	gCvars.mp7seed = writer.ReadFloat("mp7seed");
	gCvars.showrank = writer.ReadFloat("showrank");
	gCvars.nosleeve = writer.ReadFloat("nosleeve");
}



void CfgSystem::SaveCFG(bool left, bool right)
{
	static char path[MAX_PATH];
	std::string folder, file;

	if (left)
	{
		if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path)))
		{
			char szCmd[256];
			sprintf(szCmd, "\\insolegit\\config.ini");

			folder = std::string(path) + "\\insolegit\\";
			file = std::string(path) + szCmd;
		}
		CreateDirectoryA(folder.c_str(), NULL);
	}

	if (right)
	{
		if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path)))
		{
			char szCmd[256];
			sprintf(szCmd, "\\insorage\\config.ini");

			folder = std::string(path) + "\\insorage\\";
			file = std::string(path) + szCmd;
		}
		CreateDirectoryA(folder.c_str(), NULL);
	}

	CIniWriter writer(file.c_str());

	writer.WriteFloat("Smoothnessyaw", gCvars.Smoothnessyaw);
	writer.WriteFloat("Smoothnesspitch", gCvars.Smoothnesspitch);
	writer.WriteFloat("legitenable", gCvars.legitenable);
	writer.WriteFloat("RCSASSIST", gCvars.RCSASSIST);
	writer.WriteFloat("AimTeam", gCvars.AimTeam);
	writer.WriteFloat("AimFOV", gCvars.AimFOV);
	writer.WriteFloat("AimSpot", gCvars.AimSpot);
	writer.WriteFloat("Bunnyhop", gCvars.Bunnyhop);
	writer.WriteFloat("inattack", gCvars.inattack);
	writer.WriteFloat("radar", gCvars.radar);
	writer.WriteFloat("velocity", gCvars.velocity);
	writer.WriteFloat("watermark", gCvars.watermark);
	writer.WriteFloat("gloves", gCvars.gloves);
	writer.WriteFloat("knife", gCvars.knife);
	writer.WriteFloat("knifeskin", gCvars.knifeskin);
	writer.WriteFloat("ak47skin", gCvars.ak47skin);
	writer.WriteFloat("awpskin", gCvars.awpskin);
	writer.WriteFloat("deagleskin", gCvars.deagleskin);
	writer.WriteFloat("glockskin", gCvars.glockskin);
	writer.WriteFloat("uspskin", gCvars.uspskin);
	writer.WriteFloat("triggerkey", gCvars.triggerkey);
	writer.WriteFloat("m4a1skin", gCvars.m4a1skin);
	writer.WriteFloat("skinchanger", gCvars.skinchanger);
	writer.WriteFloat("skinselection", gCvars.skinselection);
	writer.WriteFloat("trigenable", gCvars.trigenable);
	writer.WriteFloat("trighead", gCvars.trighead);
	writer.WriteFloat("triggerbody", gCvars.triggerbody);
	writer.WriteFloat("trigerdelay", gCvars.trigerdelay);
	writer.WriteFloat("speclist", gCvars.speclist);
	writer.WriteFloat("trigteam", gCvars.trigteam);
	writer.WriteFloat("autopistol", gCvars.autopistol);
	writer.WriteFloat("espbox", gCvars.espbox);
	writer.WriteFloat("healthbar", gCvars.healthbar);
	writer.WriteFloat("chams", gCvars.chams);\
	writer.WriteFloat("XQZ", gCvars.XQZ);
	writer.WriteFloat("espteam", gCvars.espteam);
	writer.WriteFloat("radarsize", gCvars.radarsize);
	writer.WriteFloat("radarrange", gCvars.radarrange);
	writer.WriteFloat("radarteam", gCvars.radarteam);
	writer.WriteFloat("radarnames", gCvars.radarnames);
	writer.WriteFloat("radaringame", gCvars.radaringame);
	writer.WriteFloat("glovekit1", gCvars.glovekit1);
	writer.WriteFloat("glovekit2", gCvars.glovekit2);
	writer.WriteFloat("glovekit3", gCvars.glovekit3);
	writer.WriteFloat("glovekit4", gCvars.glovekit4);
	writer.WriteFloat("glovekit5", gCvars.glovekit5);
	writer.WriteFloat("glovekit6", gCvars.glovekit6);
	writer.WriteFloat("RCSFOV", gCvars.RCSFOV);
	writer.WriteFloat("RCSSMOOTH", gCvars.RCSSMOOTH);
	writer.WriteFloat("lagcomp", gCvars.lagcomp);
	writer.WriteFloat("flRadarPos_x", gCvars.flRadarPos_x);
	writer.WriteFloat("flRadarPos_y", gCvars.flRadarPos_y);
	writer.WriteFloat("colorsredone", gCvars.colorsredone);
	writer.WriteFloat("colorsgreenone", gCvars.colorsgreenone);
	writer.WriteFloat("colorsblueone", gCvars.colorsblueone);
	writer.WriteFloat("colorsredtwo", gCvars.colorsredtwo);
	writer.WriteFloat("colorsgreentwo", gCvars.colorsgreentwo);
	writer.WriteFloat("colorsbluetwo", gCvars.colorsbluetwo);
	writer.WriteFloat("colorsredTHREE", gCvars.colorsredTHREE);
	writer.WriteFloat("colorsgreenTHREE", gCvars.colorsgreenTHREE);
	writer.WriteFloat("colorsblueTHREE", gCvars.colorsblueTHREE);
	writer.WriteFloat("colorsredFOUR", gCvars.colorsredFOUR);
	writer.WriteFloat("colorsgreenFOUR", gCvars.colorsgreenFOUR);
	writer.WriteFloat("colorsblueFOUR", gCvars.colorsblueFOUR);
	writer.WriteFloat("colorsredFIVE", gCvars.colorsredFIVE);
	writer.WriteFloat("colorsgreenFIVE", gCvars.colorsgreenFIVE);
	writer.WriteFloat("colorsblueFIVE", gCvars.colorsblueFIVE);
	writer.WriteFloat("sg553skin", gCvars.sg553skin);
	writer.WriteFloat("scoutskin", gCvars.scoutskin);
	writer.WriteFloat("m4a4skin", gCvars.m4a4skin);
	writer.WriteFloat("p2000skin", gCvars.p2000skin);
	writer.WriteFloat("dualskin", gCvars.dualskin);
	writer.WriteFloat("augskin", gCvars.augskin);
	writer.WriteFloat("galilskin", gCvars.galilskin);
	writer.WriteFloat("ak47stats", gCvars.ak47stats);
	writer.WriteFloat("awpstats", gCvars.awpstats);
	writer.WriteFloat("deaglestats", gCvars.deaglestats);
	writer.WriteFloat("glockstats", gCvars.glockstats);
	writer.WriteFloat("uspstats", gCvars.uspstats);
	writer.WriteFloat("m4a1stats", gCvars.m4a1stats);
	writer.WriteFloat("sg553stats", gCvars.sg553stats);
	writer.WriteFloat("scoutstats", gCvars.scoutstats);
	writer.WriteFloat("m4a4stats", gCvars.m4a4stats);
	writer.WriteFloat("p2000stats", gCvars.p2000stats);
	writer.WriteFloat("dualstats", gCvars.dualstats);
	writer.WriteFloat("augstats", gCvars.augstats);
	writer.WriteFloat("galilstats", gCvars.galilstats);
	writer.WriteFloat("ak47seed", gCvars.ak47seed);
	writer.WriteFloat("awpseed", gCvars.awpseed);
	writer.WriteFloat("deagleseed", gCvars.deagleseed);
	writer.WriteFloat("glockseed", gCvars.glockseed);
	writer.WriteFloat("m4a1seed", gCvars.m4a1seed);
	writer.WriteFloat("sg553seed", gCvars.sg553seed);
	writer.WriteFloat("scoutseed", gCvars.scoutseed);
	writer.WriteFloat("m4a4seed", gCvars.m4a4seed);
	writer.WriteFloat("p2000seed", gCvars.p2000seed);
	writer.WriteFloat("dualseed", gCvars.dualseed);
	writer.WriteFloat("augseed", gCvars.augseed);
	writer.WriteFloat("galilseed", gCvars.galilseed);
	writer.WriteFloat("esprenderdist", gCvars.esprenderdist);
	writer.WriteFloat("recoilxhair", gCvars.recoilxhair);
	writer.WriteFloat("drawmonitor", gCvars.drawmonitor);
	writer.WriteFloat("f1monitorpos_x", gCvars.f1monitorpos_x);
	writer.WriteFloat("f1monitorpos_y", gCvars.f1monitorpos_y);
	writer.WriteFloat("espweapon", gCvars.espweapon);
	writer.WriteFloat("espname", gCvars.espname);
	writer.WriteFloat("espteam", gCvars.espteam);
	writer.WriteFloat("CHAMTEAM", gCvars.CHAMTEAM);
	writer.WriteFloat("noflash", gCvars.noflash);
	writer.WriteFloat("nosmoke", gCvars.nosmoke);
	writer.WriteFloat("slidewalk", gCvars.slidewalk);
	writer.WriteFloat("umpseed", gCvars.umpseed);
	writer.WriteFloat("umpstat", gCvars.umpstat);
	writer.WriteFloat("umpskin", gCvars.umpskin);
	writer.WriteFloat("fivesevenseed", gCvars.fivesevenseed);
	writer.WriteFloat("fivesevenstat", gCvars.fivesevenstat);
	writer.WriteFloat("fivesevenskin", gCvars.fivesevenskin);
	writer.WriteFloat("famasseed", gCvars.famasseed);
	writer.WriteFloat("famasstat", gCvars.famasstat);
	writer.WriteFloat("famasskin", gCvars.famasskin);
	writer.WriteFloat("g3sg1seed", gCvars.g3sg1seed);
	writer.WriteFloat("g3sg1stat", gCvars.g3sg1stat);
	writer.WriteFloat("g3sg1skin", gCvars.g3sg1skin);
	writer.WriteFloat("m249seed", gCvars.m249seed);
	writer.WriteFloat("m249stat", gCvars.m249stat);
	writer.WriteFloat("m249skin", gCvars.m249skin);
	writer.WriteFloat("p90seed", gCvars.p90seed);
	writer.WriteFloat("p90stat", gCvars.p90stat);
	writer.WriteFloat("p90skin", gCvars.p90skin);
	writer.WriteFloat("mac10seed", gCvars.mac10seed);
	writer.WriteFloat("mac10stat", gCvars.mac10stat);
	writer.WriteFloat("mac10skin", gCvars.mac10skin);
	writer.WriteFloat("mp7seed", gCvars.mp7seed);
	writer.WriteFloat("mp7stat", gCvars.mp7stat);
	writer.WriteFloat("mp7skin", gCvars.mp7skin);
	writer.WriteFloat("tecseed", gCvars.tecseed);
	writer.WriteFloat("tecstat", gCvars.tecstat);
	writer.WriteFloat("tecskin", gCvars.tecskin);
	writer.WriteFloat("sawedseed", gCvars.sawedseed);
	writer.WriteFloat("sawedstat", gCvars.sawedstat);
	writer.WriteFloat("sawedskin", gCvars.sawedskin);
	writer.WriteFloat("negevseed", gCvars.negevseed);
	writer.WriteFloat("negevstat", gCvars.negevstat);
	writer.WriteFloat("negevskin", gCvars.negevskin);
	writer.WriteFloat("mag7seed", gCvars.mag7seed);
	writer.WriteFloat("mag7stat", gCvars.mag7stat);
	writer.WriteFloat("mag7skin", gCvars.mag7skin);
	writer.WriteFloat("bizonseed", gCvars.bizonseed);
	writer.WriteFloat("bizonstat", gCvars.bizonstat);
	writer.WriteFloat("bizonskin", gCvars.bizonskin);
	writer.WriteFloat("xm1000seed", gCvars.xm1000seed);
	writer.WriteFloat("xm1000stat", gCvars.xm1000stat);
	writer.WriteFloat("xm1000skin", gCvars.xm1000skin);
	writer.WriteFloat("mp9skin", gCvars.mp9skin);
	writer.WriteFloat("mp9stat", gCvars.mp9stat);
	writer.WriteFloat("mp9seed", gCvars.mp9seed);
	writer.WriteFloat("novaskin", gCvars.novaskin);
	writer.WriteFloat("novastat", gCvars.novastat);
	writer.WriteFloat("novaseed", gCvars.novaseed);
	writer.WriteFloat("p250skin", gCvars.p250skin);
	writer.WriteFloat("p250stat", gCvars.p250stat);
	writer.WriteFloat("p250seed", gCvars.p250seed);
	writer.WriteFloat("scarskin", gCvars.scarskin);
	writer.WriteFloat("scarstat", gCvars.scarstat);
	writer.WriteFloat("scarseed", gCvars.scarseed);
	writer.WriteFloat("r8skin", gCvars.r8skin);
	writer.WriteFloat("r8stat", gCvars.r8stat);
	writer.WriteFloat("r8seed", gCvars.r8seed);
	writer.WriteFloat("mp5skin", gCvars.mp5skin);
	writer.WriteFloat("mp5stat", gCvars.mp5stat);
	writer.WriteFloat("mp5seed", gCvars.mp5seed);
	writer.WriteFloat("showrank", gCvars.showrank);
	writer.WriteFloat("nosleeve", gCvars.nosleeve);
}
