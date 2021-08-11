#include "include.hpp"


bool bSliderFix[50];

int iSliderIndex = -1;
int iCurrSlider;

DWORD dwWait;

#define COLOR1 60, 60, 60, 255
#define COLOR2 85, 85, 85, 255
#define COLOR3 0, 0, 0, 255
#define COLOR4 35, 35, 35, 255
#define COLOR5 50, 50, 50, 255
#define COLOR6 100, 100, 100, 255
#define COLOR7 73, 73, 73, 255
#define COLOR8 65, 65, 65, 255
#define COLOR10 255, 255, 255, 255

#define COLOR9 (gCvars.colorsredone), (gCvars.colorsgreenone), (gCvars.colorsblueone), 255
#define COLOR69 (gCvars.colorsredone), (gCvars.colorsgreenone), (gCvars.colorsblueone), 110

#define ELEMENT_HEIGHT 15
#define ELEMENT_SEPERATION 20
#define CHECKBOX_SEPERATION_FROM_TEXT 95
#define CHECKBOX_SIZE 13

#define DEFAULT_X_TO_ADD (CHECKBOX_SEPERATION_FROM_TEXT + CHECKBOX_SIZE + 40)

#define DROPDOWN_WIDTH 56
#define DROPDOWN_HEIGHT 15

#define ADDER_SIZEX 12
#define ADDER_SIZEY 13

#define ADDER_SEPERATE_FROM_BOXES 44 

cMenu::cMenu(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
}

char *shitknifeskinnames[] = { "Vanilla","Crimson","Night","Boreal","Forest","Hardened","Fade","Slaughter" };
float shitknifeskinvalues[] = { 0,12,40,77,5,44,38,59 };

char *ak47skinnames[] = { "Vanilla","Vulcan","Rebel","Redline","Black","Fuel" };
float ak47skinvalues[] = { 0,302,380,282,172,524};

char *awpskinnames[] = { "Vanilla","Strike","Graphite","Pink","Money","Asimov" };
float awpskinvalues[] = { 0,51,212,84,295,279 };

char *deagleskinnames[] = { "Vanilla","Hypno","Cobalt","Blaze","Night","Naga" };
float deagleskinvalues[] = { 0,61,231,37,40,397};

char *glockskinnames[] = { "Vanilla","Rebel","Dragon","Fade","Element","Brass" };
float glockskinvalues[] = { 0,586,48,38,353,159 };

char *uspskinnames[] = { "Vanilla","Guard","Stainless","Blueprint","Serum","Orion" };
float uspskinvalues[] = { 0,290,277,657,221,313 };

char *m4a1skinnames[] = { "Vanilla","Cyrex","Atomic","Guardian","Knight","Basilik" };
float m4a1skinvalues[] = { 0,360,301,257,326,383 };

char *sg553skinnames[] = { "Vanilla","Cyrex","Integrale","Hypnotic","Traveler","Triarch" };
float sg553skinvalues[] = { 0,487,750,61,363,613 };

char *firstglovename[] = { "None","Charred","Bronze","Guerila","Snake" };
float firstglovevalue[] = { 0,10006,10008,10039,10007 };

char *secondglovename[] = { "None","Purple","Green","Omega","Sling" };
float secondglovevalue[] = { 0,10037,10038,10047,10073 };

char *thirdglovename[] = { "None","Snow","Tie","Lunar","Racing" };
float thirdglovevalue[] = { 0,10070,10072,10013,10044 };

char *fourthglovename[] = { "None","Tape","Leather","Desert","Cobalt" };
float fourthglovevalue[] = { 0,10055,10009,10081,10053 };

char *fifthglovename[] = { "None","Boom","Mint","Polygon","Turtle" };
float fifthglovevalue[] = { 0,10027,10026,10052,10050 };

char *sixthglovename[] = { "None","Orange","Crimson","Mogul","Emerald" };
float sixthglovevalue[] = { 0,10035,10033,10064,10034 };

char *scoutskinnames[] = { "Vanilla","Abyss","Brake","Hypnotic","Slashed","Parallax" };
float scoutskinvalues[] = { 0,361,319,751,304,989 };

char *m4a4skinnames[] = { "Vanilla","Asiimov","Poseidon","Daybreak","Magnes","Mainframe" };
float m4a4skinvalues[] = { 0,255,449,471,811,780 };

char *p2000skinnames[] = { "Vanilla","Scorpion","Chainmail","Handgun","Corticera","Turf" };
float p2000skinvalues[] = { 0,71,327,485,184,635 };

char *dualskinnames[] = { "Vanilla","Marina","Elite 1.6","Emerald","Hemo","Cartel" };
float dualskinvalues[] = { 0,261,903,453,220,528 };

char *augskinnames[] = { "Vanilla","Chameleon","Wings","Aristocrat","Torque","Ricochet" };
float augskinvalues[] = { 0,280,73,583,305,507 };

char *galilskinnames[] = { "Vanilla","Cerberus","Tuxedo","Akoben","Firefight","Signal" };
float galilskinvalues[] = { 0,379,297,842,546,807 };

char *mac10skinnames[] = { "Vanilla","Malachite","Graven","Ultraviolet","Fade","Calf Skin" };
float mac10skinvalues[] = { 0,402,188,98,38,748 };

char *p90skinnames[] = { "Vanilla","Asiimov","Trigon","Module","Leather","Traction" };
float p90skinvalues[] = { 0,359,283,335,342,717 };

char *m249skinnames[] = { "Vanilla","Spectre","Magma","Warbird","Aztec","Jungle" };
float m249skinvalues[] = { 0,547,266,900,902,151 };

char *g3sg1skinnames[] = { "Vanilla","Flux","Stinger","Chronos","Hunter","Murky" };
float g3sg1skinvalues[] = { 0,493,628,438,677,382 };

char *famasskinnames[] = { "Vanilla","Djinn","Afterimage","Valence","Sergeant","Pulse" };
float famasskinvalues[] = { 0,429,154,529,288,260 };

char *fivesevenskinnames[] = { "Vanilla","Kami","Nitro","Night","Urban","Copper" };
float fivesevenskinvalues[] = { 0,265,254,223,387,274 };

char *umpskinnames[] = { "Vanilla","Plastique","Moonrise","Exposure","Scaffold","Labyrinth" };
float umpskinvalues[] = { 0,916,851,688,652,362 };

char *xm1000skinnames[] = { "Vanilla","Season","Leather","Bones","Varicamo","Urban" };
float xm1000skinvalues[] = { 0,654,348,370,238,135 };

char *bizonskinnames[] = { "Vanilla","Embargo","Osiris","Antique","Runic","Brass" };
float bizonskinvalues[] = { 0,884,349,306,973,159 };

char *mag7skinnames[] = { "Vanilla","Justice","Swag","Heat","Bulldozer","Memento" };
float mag7skinvalues[] = { 0,948,703,431,39,177 };

char *negevskinnames[] = { "Vanilla","Dazzle","Terrain","Bulkhead","Palm","Nuclear" };
float negevskinvalues[] = { 0,610,285,783,201,369 };

char *sawedskinnames[] = { "Vanilla","Kraken","Serenity","Origami","Baggage","Amber" };
float sawedskinvalues[] = { 0,256,405,434,345,246 };

char *tecskinnames[] = { "Vanilla","Nuclear","Fubar","Isaac","Toxic","Terrace" };
float tecskinvalues[] = { 0,179,816,303,374,463 };

char *mp7skinnames[] = { "Vanilla","Nemesis","Impire","Ocean","Fade","Cirrus" };
float mp7skinvalues[] = { 0,481,536,213,752,627 };

char *mp9skinnames[] = { "Vanilla","Airlock","Hypnotic","Rose","Bulldozer","Bioleak" };
float mp9skinvalues[] = { 0,609,61,262,39,549 };

char *novaskinnames[] = { "Vanilla","Antique","Koi","Graphite","Exo","Tempest" };
float novaskinvalues[] = { 0,286,356,214,590,191 };

char *p250skinnames[] = { "Vanilla","Asiimov","Muertos","Cartel","Franklin","Mehndi" };
float p250skinvalues[] = { 0,551,404,388,295,258 };

char *scarskinnames[] = { "Vanilla","Cardiac","Cyrex","Splash","Emerald","Assault" };
float scarskinvalues[] = { 0,391,312,165,196,914 };

char *revolverskinnames[] = { "Vanilla","Fade","Memento","Grip","Crimson","Nitro" };
float revolverskinvalues[] = { 0,522,892,701,12,798 };

char *mp5skinnames[] = { "Vanilla","Agent","Gauss","Procesor","Nitro","Lab Rat" };
float mp5skinvalues[] = { 0,915,846,781,798,800 };

int iRowTwo = DEFAULT_X_TO_ADD;
int iRowThree = ((DEFAULT_X_TO_ADD) * 2) - 10;

void cMenu::InitMenuElements()
{
	static cMenuSection mslegitbot;
	static cMenuSection mslegitbotSliders;
	static cMenuSection msEsp;
	static cMenuSection msRemovals;
	static cMenuSection hoodrich;
	static cMenuSection colortabslide;
	static cMenuSection colortabshow;
	static cMenuSection nightmodesliders;
	static cMenuSection trashniggers;
	static cMenuSection trashniggerstwo;

	int iUsualX = m_x + 10;

	iCurrSlider = 0;

	switch (GetTabIndex())
	{
	case LEGITAB:

		mslegitbot.ClearSection();
		mslegitbotSliders.ClearSection();

		mslegitbot.Draw(iUsualX, m_y + 13, m_w - 22, 80);

		mslegitbot.AddElement(ONOFF, 0, 0, "AIMBOT", &gCvars.legitenable);
		mslegitbot.AddElement(ONOFF, 0, 0, "BACKTRACK", &gCvars.lagcomp);
		mslegitbot.AddElement(ADDER, 0, 0, "AIM BONE", &gCvars.AimSpot, 0, 8);

		mslegitbot.RestartSection();

		mslegitbot.AddElement(ONOFF, iRowTwo, 0, "AIM ONFIRE", &gCvars.inattack);
		mslegitbot.AddElement(ONOFF, iRowTwo, 0, "AIM TEAM", &gCvars.AimTeam);
		mslegitbot.AddElement(ONOFF, iRowTwo, 0, "AUTOPISTOL", &gCvars.autopistol);

		mslegitbot.RestartSection();

		mslegitbot.AddElement(ONOFF, iRowThree, 0, "RCS ASSIST", &gCvars.RCSASSIST);
		mslegitbot.AddElement(ADDER, iRowThree, 0, "RCS FOV", &gCvars.RCSFOV, 0, 20);
		mslegitbot.AddElement(ADDER, iRowThree, 0, "RCS SMOOTH", &gCvars.RCSSMOOTH, 0, 50);


		mslegitbotSliders.Draw(iUsualX, m_y + 99, m_w - 22, 124);

		mslegitbotSliders.SetSlider(iCurrSlider, true);
		mslegitbotSliders.AddElement(SLIDER, 0, 0, "TARGET SELECTION FOV", &gCvars.AimFOV, 0, 20);
		mslegitbotSliders.SetSlider(iCurrSlider, true);
		mslegitbotSliders.AddElement(SLIDER, 0, 0, "SMOOTHNESS PITCH", &gCvars.Smoothnesspitch, 0, 50);
		mslegitbotSliders.SetSlider(iCurrSlider, true);
		mslegitbotSliders.AddElement(SLIDER, 0, 0, "SMOOTHNESS YAW", &gCvars.Smoothnessyaw, 0, 50);

		break;

	case ESPTAB:
		msEsp.ClearSection();
		nightmodesliders.ClearSection();

		msEsp.Draw(iUsualX, m_y + 13, m_w - 22, 114);

		msEsp.AddElement(ONOFF, 0, -4, "BOX ESP", &gCvars.espbox);
		msEsp.AddElement(ONOFF, 0, -4, "HEALTH ESP", &gCvars.healthbar);
		msEsp.AddElement(ONOFF, 0, -4, "WEAPON ESP", &gCvars.espweapon);
		msEsp.AddElement(ONOFF, 0, -4, "NAME ESP", &gCvars.espname);
		msEsp.AddElement(ONOFF, 0, -4, "ESP TEAM", &gCvars.espteam);
		msEsp.RestartSection();
		msEsp.AddElement(ONOFF, iRowTwo, -4, "CHAMS", &gCvars.chams);
		msEsp.AddElement(ONOFF, iRowTwo, -4, "CHAMS XQZ", &gCvars.XQZ);
		msEsp.AddElement(ONOFF, iRowTwo, -4, "CHAM TEAM", &gCvars.CHAMTEAM);
		msEsp.AddElement(ONOFF, iRowTwo, -4, "NO FLASH", &gCvars.noflash);
		msEsp.AddElement(ONOFF, iRowTwo, -4, "NO SMOKE", &gCvars.nosmoke);

		msEsp.RestartSection();

		msEsp.AddElement(ONOFF, iRowThree, -4, "RADAR", &gCvars.radar);
		msEsp.AddElement(ONOFF, iRowThree, -4, "RADAR TEAM", &gCvars.radarteam);
		msEsp.AddElement(ADDER, iRowThree, -4, "RADAR SIZE", &gCvars.radarsize, 1, 150);
		msEsp.AddElement(ONOFF, iRowThree, -4, "RADAR NAME", &gCvars.radarnames);
		msEsp.AddElement(ONOFF, iRowThree, -4, "RADAR GAME", &gCvars.radaringame);

		nightmodesliders.Draw(iUsualX, m_y + 133, m_w - 22, 90);

		nightmodesliders.SetSlider(iCurrSlider, true);
		nightmodesliders.AddElement(SLIDER, 0, 0, "ESP RENDER RANGE", &gCvars.esprenderdist, 0, 8000);
		nightmodesliders.SetSlider(iCurrSlider, true);
		nightmodesliders.AddElement(SLIDER, 0, 0, "RADAR RENDER DIST", &gCvars.radarrange, 0, 200);

		break;

	case MISCTAB:
		msRemovals.ClearSection();
		hoodrich.ClearSection();

		hoodrich.Draw(iUsualX, m_y + 13, m_w - 22, 64);
		hoodrich.AddElement(ONOFF, 0, 0, "TRIGGERBOT", &gCvars.trigenable);
		hoodrich.AddElement(ONOFF, 0, 0, "TRIG TEAM", &gCvars.trigteam);
		hoodrich.RestartSection();
		hoodrich.AddElement(ONOFF, iRowTwo, 0, "TRIG HEAD", &gCvars.trighead);
		hoodrich.AddElement(KEYBIND, iRowTwo, 0, "KEY BIND", &gCvars.triggerkey);
		hoodrich.RestartSection();
		hoodrich.AddElement(ONOFF, iRowThree, 0, " TRIG BODY", &gCvars.triggerbody);
		hoodrich.AddElement(ADDER, iRowThree, 0, " DELAY", &gCvars.trigerdelay, 10, 200);

		msRemovals.Draw(iUsualX, m_y + 83, m_w - 22, 140);
		msRemovals.AddElement(ONOFF, 0, 0, "BUNNYHOP", &gCvars.Bunnyhop);
		msRemovals.AddElement(ONOFF, 0, 0, "SLIDEWALK", &gCvars.slidewalk);
		msRemovals.AddElement(ONOFF, 0, 0, "WATERMARK", &gCvars.watermark);
		msRemovals.AddElement(ONOFF, 0, 0, "NO SLEEVE", &gCvars.nosleeve);
		msRemovals.AddElement(ONOFF, 0, 0, "SPECLIST", &gCvars.speclist);
		msRemovals.AddElement(ONOFF, 0, 0, "MONITOR", &gCvars.drawmonitor);
		msRemovals.RestartSection();
		msRemovals.AddElement(ONOFF, iRowTwo, 0, "VELOCITY", &gCvars.velocity);
		msRemovals.AddElement(ONOFF, iRowTwo, 0, "SHOW RANK", &gCvars.showrank);
		msRemovals.AddElement(ONOFF, iRowTwo, 0, "RCS XHAIR", &gCvars.recoilxhair);

		hoodrich.PostSection();
		break;
	case SKINTAB:
		ListItemArray.ClearList();

		ListItemArray.AddItem("ak-47");
		ListItemArray.AddItem("m4a1-s");
		ListItemArray.AddItem("awp");
		ListItemArray.AddItem("deagle");
		ListItemArray.AddItem("glock");
		ListItemArray.AddItem("usp-s");
		ListItemArray.AddItem("sg553");
		ListItemArray.AddItem("scout");
		ListItemArray.AddItem("m4a4");
		ListItemArray.AddItem("p2000");
		ListItemArray.AddItem("dualies");
		ListItemArray.AddItem("aug");
		ListItemArray.AddItem("galil");
		ListItemArray.AddItem("mac-10");
		ListItemArray.AddItem("p90");
		ListItemArray.AddItem("m249");
		ListItemArray.AddItem("g3sg1");
		ListItemArray.AddItem("famas");
		ListItemArray.AddItem("five-seven");
		ListItemArray.AddItem("ump-45");
		ListItemArray.AddItem("xm-1014");
		ListItemArray.AddItem("pp-bizon");
		ListItemArray.AddItem("mag-7");
		ListItemArray.AddItem("negev");
		ListItemArray.AddItem("sawed-off");
		ListItemArray.AddItem("tec-9");
		ListItemArray.AddItem("mp-7");
		ListItemArray.AddItem("mp-9");
		ListItemArray.AddItem("nova");
		ListItemArray.AddItem("p250");
		ListItemArray.AddItem("scar-20");
		ListItemArray.AddItem("revolver");
		ListItemArray.AddItem("mp5");
		ListItemArray.Draw(iUsualX, m_y + 16, 280, 209, true);

		trashniggers.ClearSection();
		trashniggerstwo.ClearSection();

		trashniggers.Draw(iUsualX + 285, m_y + 13, 160, 123);
		trashniggers.AddElement(ONOFF, 0, 0, "SKINS", &gCvars.skinchanger);
		trashniggers.AddElement(ADDER, 0, 0, "KNIFE", &gCvars.knife, 0, 5);
		trashniggers.SetValueNames(shitknifeskinnames, shitknifeskinvalues, 8);
		trashniggers.AddElement(DROPDOWN, 0, 0, "KNIFE KIT", &gCvars.knifeskin);
		trashniggers.AddElement(ADDER, 0, 0, "GLOVE", &gCvars.gloves, 0, 5);

		if (gCvars.gloves == 0)
		{
			trashniggers.SetValueNames(firstglovename, firstglovevalue, 5);
			trashniggers.AddElement(DROPDOWN, 0, 0, "GLOVE KIT", &gCvars.glovekit1);
		}
		else if (gCvars.gloves == 1)
		{
			trashniggers.SetValueNames(secondglovename, secondglovevalue, 5);
			trashniggers.AddElement(DROPDOWN, 0, 0, "GLOVE KIT", &gCvars.glovekit2);
		}
		else if (gCvars.gloves == 2)
		{
			trashniggers.SetValueNames(thirdglovename, thirdglovevalue, 5);
			trashniggers.AddElement(DROPDOWN, 0, 0, "GLOVE KIT", &gCvars.glovekit3);
		}
		else if (gCvars.gloves == 3)
		{
			trashniggers.SetValueNames(fourthglovename, fourthglovevalue, 5);
			trashniggers.AddElement(DROPDOWN, 0, 0, "GLOVE KIT", &gCvars.glovekit4);
		}
		else if (gCvars.gloves == 4)
		{
			trashniggers.SetValueNames(fifthglovename, fifthglovevalue, 5);
			trashniggers.AddElement(DROPDOWN, 0, 0, "GLOVE KIT", &gCvars.glovekit5);
		}
		else if (gCvars.gloves == 5)
		{
			trashniggers.SetValueNames(sixthglovename, sixthglovevalue, 5);
			trashniggers.AddElement(DROPDOWN, 0, 0, "GLOVE KIT", &gCvars.glovekit6);
		}

		trashniggerstwo.ClearSection();
		trashniggerstwo.Draw(iUsualX + 285, m_y + 143, 160, 79);

		if (ListItemArray.IsSelected(0))
		{
			trashniggerstwo.SetValueNames(ak47skinnames, ak47skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.ak47skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.ak47stats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.ak47seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(1))
		{
			trashniggerstwo.SetValueNames(m4a1skinnames, m4a1skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.m4a1skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.m4a1stats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.m4a1seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(2))
		{
			trashniggerstwo.SetValueNames(awpskinnames, awpskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.awpskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.awpstats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.awpseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(3))
		{
			trashniggerstwo.SetValueNames(deagleskinnames, deagleskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.deagleskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.deaglestats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.deagleseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(4))
		{
			trashniggerstwo.SetValueNames(glockskinnames, glockskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.glockskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.glockstats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.glockseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(5))
		{
			trashniggerstwo.SetValueNames(uspskinnames, uspskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.uspskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.uspstats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.uspseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(6))
		{
			trashniggerstwo.SetValueNames(sg553skinnames, sg553skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.sg553skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.sg553stats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.sg553seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(7))
		{
			trashniggerstwo.SetValueNames(scoutskinnames, scoutskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.scoutskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.scoutstats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.scoutseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(8))
		{
			trashniggerstwo.SetValueNames(m4a4skinnames, m4a4skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.m4a4skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.m4a4stats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.m4a4seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(9))
		{
			trashniggerstwo.SetValueNames(p2000skinnames, p2000skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.p2000skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.p2000stats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.p2000seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(10))
		{
			trashniggerstwo.SetValueNames(dualskinnames, dualskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.dualskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.dualstats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.dualseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(11))
		{
			trashniggerstwo.SetValueNames(augskinnames, augskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.augskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.augstats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.augseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(12))
		{
			trashniggerstwo.SetValueNames(galilskinnames, galilskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.galilskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.galilstats, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.galilseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(13))
		{
			trashniggerstwo.SetValueNames(mac10skinnames, mac10skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.mac10skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.mac10stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.mac10seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(14))
		{
			trashniggerstwo.SetValueNames(p90skinnames, p90skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.p90skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.p90stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.p90seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(15))
		{
			trashniggerstwo.SetValueNames(m249skinnames, m249skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.m249skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.m249stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.m249seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(16))
		{
			trashniggerstwo.SetValueNames(g3sg1skinnames, g3sg1skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.g3sg1skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.g3sg1stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.g3sg1seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(17))
		{
			trashniggerstwo.SetValueNames(famasskinnames, famasskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.famasskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.famasstat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.famasseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(18))
		{
			trashniggerstwo.SetValueNames(fivesevenskinnames, fivesevenskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.fivesevenskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.fivesevenstat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.fivesevenseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(19))
		{
			trashniggerstwo.SetValueNames(umpskinnames, umpskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.umpskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.umpstat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.umpseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(20))
		{
			trashniggerstwo.SetValueNames(xm1000skinnames, xm1000skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.xm1000skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.xm1000stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.xm1000seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(21))
		{
			trashniggerstwo.SetValueNames(bizonskinnames, bizonskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.bizonskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.bizonstat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.bizonseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(22))
		{
			trashniggerstwo.SetValueNames(mag7skinnames, mag7skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.mag7skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.mag7stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.mag7seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(23))
		{
			trashniggerstwo.SetValueNames(negevskinnames, negevskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.negevskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.negevstat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.negevseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(24))
		{
			trashniggerstwo.SetValueNames(sawedskinnames, sawedskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.sawedskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.sawedstat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.sawedseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(25))
		{
			trashniggerstwo.SetValueNames(tecskinnames, tecskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.tecskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.tecstat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.tecseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(26))
		{
			trashniggerstwo.SetValueNames(mp7skinnames, mp7skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.mp7skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.mp7stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.mp7seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(27))
		{
			trashniggerstwo.SetValueNames(mp9skinnames, mp9skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.mp9skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.mp9stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.mp9seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(28))
		{
			trashniggerstwo.SetValueNames(novaskinnames, novaskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.novaskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.novastat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.novaseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(29))
		{
			trashniggerstwo.SetValueNames(p250skinnames, p250skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.p250skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.p250stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.p250seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(30))
		{
			trashniggerstwo.SetValueNames(scarskinnames, scarskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.scarskin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.scarstat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.scarseed, 0, 99);
		}
		else if (ListItemArray.IsSelected(31))
		{
			trashniggerstwo.SetValueNames(revolverskinnames, revolverskinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.r8skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.r8stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.r8seed, 0, 99);
		}
		else if (ListItemArray.IsSelected(32))
		{
			trashniggerstwo.SetValueNames(mp5skinnames, mp5skinvalues, 6);
			trashniggerstwo.AddElement(DROPDOWN, 0, 0, "PAINT KIT", &gCvars.mp5skin);
			trashniggerstwo.AddElement(ADDER, 0, 0, "STATRAK", &gCvars.mp5stat, 0, 99);
			trashniggerstwo.AddElement(ADDER, 0, 0, "KIT SEED", &gCvars.mp5seed, 0, 99);
		}

		trashniggerstwo.PostSection();
		trashniggers.PostSection();
		break;
	case COLTAB:
		colortabslide.ClearSection();

		ListItemArray.ClearList();

		ListItemArray.AddItem("menu colors");
		ListItemArray.AddItem("visuals colors");
		ListItemArray.AddItem("radar colors");
		ListItemArray.AddItem("chams colors");
		ListItemArray.AddItem("xqz chams colors");
		ListItemArray.Draw(iUsualX, m_y + 16, m_w - 22, 80, false);

		if (ListItemArray.IsSelected(0))
		{
			colortabslide.Draw(iUsualX, m_y + 98, m_w - 22, 125);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "RED VOLUME", &gCvars.colorsredone, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "GREEN VOLUME", &gCvars.colorsgreenone, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "BLUE VOLUME", &gCvars.colorsblueone, 0, 255);
		}

		if (ListItemArray.IsSelected(1))
		{
			colortabslide.Draw(iUsualX, m_y + 98, m_w - 22, 125);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "RED VOLUME", &gCvars.colorsredtwo, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "GREEN VOLUME", &gCvars.colorsgreentwo, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "BLUE VOLUME", &gCvars.colorsbluetwo, 0, 255);
		}

		if (ListItemArray.IsSelected(2))
		{
			colortabslide.Draw(iUsualX, m_y + 98, m_w - 22, 125);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "RED VOLUME", &gCvars.colorsredTHREE, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "GREEN VOLUME", &gCvars.colorsgreenTHREE, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "BLUE VOLUME", &gCvars.colorsblueTHREE, 0, 255);
		}

		if (ListItemArray.IsSelected(3))
		{
			colortabslide.Draw(iUsualX, m_y + 98, m_w - 22, 125);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "RED VOLUME", &gCvars.colorsredFOUR, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "GREEN VOLUME", &gCvars.colorsgreenFOUR, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "BLUE VOLUME", &gCvars.colorsblueFOUR, 0, 255);
		}

		if (ListItemArray.IsSelected(4))
		{
			colortabslide.Draw(iUsualX, m_y + 98, m_w - 22, 125);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "RED VOLUME", &gCvars.colorsredFIVE, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "GREEN VOLUME", &gCvars.colorsgreenFIVE, 0, 255);
			colortabslide.SetSlider(iCurrSlider, true);
			colortabslide.AddElement(SLIDER, 0, 0, "BLUE VOLUME", &gCvars.colorsblueFIVE, 0, 255);
		}

		break;
	}
}

void cListItem::Draw(int x, int y, int w, int h, bool scrolls)
{
	int iNumOfItems = GetNumberOfItems();

	int slackerx = x + w - 8;

	if (iNumOfItems == 0)
	{
		Draw::FillRGBA(slackerx, y, 8, h, COLOR2);

		Draw::OutlinedRectangle(slackerx, y, 8, h, COLOR6);

		Draw::OutlinedRectangle(x, y, w, h, COLOR2);

		return;
	}

	if (iSelectedIndex >= iNumOfItems)
		iSelectedIndex = (iNumOfItems - 1);

	if (iTopIndex >= iNumOfItems)
		iTopIndex = 0;

	DisplayPerPage(((h / ELEMENT_HEIGHT) - 1));

	int iDisplayed = 0;

	for (int i = iTopIndex; i < iNumOfItems; i++)
	{
		if (iDisplayed > iDisplayPerPage)
			break;

		ListItem_t liItem = GetItemFromIndex(i);

		int iDrawIndex = i - iTopIndex;

		if ((iDrawIndex & 2) == 1)
		{
			Draw::FillRGBA(x, y + iDrawIndex * ELEMENT_HEIGHT, w, ELEMENT_HEIGHT, 255, 255, 255, 255);
		}

		if (g_Mouse.IsOver(x, y + iDrawIndex * ELEMENT_HEIGHT, w, ELEMENT_HEIGHT + 1))
		{
			Draw::FillRGBA(x, y + iDrawIndex * ELEMENT_HEIGHT, w, ELEMENT_HEIGHT, 255, 255, 255, 4);

			if (g_Mouse.HasMouseOneJustBeenReleased())
			{
				this->Select(i);
			}
		}

		if (iSelectedIndex == i)
		{
			Draw::GradientVertical(x, y + iDrawIndex * ELEMENT_HEIGHT, w, ELEMENT_HEIGHT, gCvars.colorsredone * 0.35, gCvars.colorsgreenone * 0.35, gCvars.colorsblueone * 0.35, 255, gCvars.colorsredone, gCvars.colorsgreenone, gCvars.colorsblueone);
		}

		Draw::RenderText(x + 5, y + iDrawIndex * ELEMENT_HEIGHT + 1, COLOR10, false, Fonts::m_WatermarkFont, liItem.szName);

		iDisplayed++;
	}

	if (g_Mouse.IsOver(x, y, w, h))
	{
		if (!IsFocused())
			SetFocus(true);
	}
	else
	{
		if (IsFocused())
			SetFocus(false);
	}

	if (scrolls)
	{
		int iHowMany = iNumOfItems - iDisplayPerPage;
		int iScrollBar = (iHowMany * 3.5);
		int iWhen = 0;

		if (iScrollBar > (h - 20))
		{
			iScrollBar = h - 20;

			for (int nab = 0; ; nab++)
			{
				int iNew = (nab * 3.5);

				if (iNew > (h - 20))
				{
					iWhen = nab;
					break;
				}
			}
		}

		int iDiff = 0;

		if (iWhen > 0)
			iDiff = abs(iHowMany - iWhen) * 3.5;

		int iScrollBarHai = h + 3.5 - iScrollBar;
		int iScrollYAdd = iTopIndex * 3.5 * ((iWhen > 0) ? ((3.5 / iDiff) * 10 + 0.15) : 1);
		int iScrollYPos = y + iScrollYAdd;
		int iSavedScrollYPos = iScrollYPos;
		int iDummy;

		g_Mouse.Drag(g_Mouse.bDragged[1], true, g_Mouse.LeftClick(slackerx, y, 8, h), iDummy, iScrollYPos, g_Mouse.iDiffX[1], g_Mouse.iDiffY[1]);

		if (g_Mouse.bDragged[1] && !g_Menu.IsHandlingItem())
			g_Menu.AddMenuFlag(FL_DISABLEDRAG);

		if (iScrollYPos != iSavedScrollYPos)
		{
			int iNewTopIndex = (iScrollYPos - y);
			iNewTopIndex /= 3.5;
			iNewTopIndex /= ((iWhen > 0) ? ((3.5 / iDiff) * 10 + 0.15) : 1);

			if (iNewTopIndex < 0)
				iNewTopIndex = 0;

			int iLastPossibleTopIndex = abs(iNumOfItems - iDisplayPerPage) - 1;

			if (iNewTopIndex > iLastPossibleTopIndex)
				iNewTopIndex = iLastPossibleTopIndex;

			iScrollYPos = y + (iNewTopIndex * 3.5 * ((iWhen > 0) ? ((3.5 / iDiff) * 10 + 0.15) : 1));

			iTopIndex = iNewTopIndex;
		}

		Draw::FillRGBA(slackerx, iScrollYPos - 2, 8, iScrollBarHai, COLOR1);
		Draw::OutlinedRectangle(slackerx, iScrollYPos - 2, 8, iScrollBarHai, COLOR6);
	}

	Draw::OutlinedRectangle(x, y - 3, w, h, COLOR2);
}

void cMenu::DrawTab(int index, int &setindex, int x, int y, const char *pszTitle)
{
	static int iWidth = 80;
	static int iHeight = 22;

	bool bOverTri = false;

	bool bOverBack = g_Mouse.IsOver(x, y - iHeight, iWidth, iHeight + 1);

	bool bSame = setindex == index;

	if (g_Mouse.IsOver(x, y - iHeight, iWidth, iHeight + 1))
	{
		bOverTri = true;
	}

	for (int i = 0; i <= iHeight; i++)
	{
		if (bSame)
		{
			if (i == iHeight)
				Draw::FillRGBA(x, y - iHeight, iWidth, iHeight + 1, COLOR7);
		}
		else
		{
			if (g_Mouse.HasMouseOneJustBeenReleased() && (bOverBack || bOverTri))
				setindex = index;

			if (i == iHeight)
			{
				if (bOverBack || bOverTri)
					Draw::FillRGBA(x, y - iHeight, iWidth, iHeight + 1, COLOR8);
				else
					Draw::FillRGBA(x, y - iHeight, iWidth, iHeight + 1, COLOR1);
			}
		}
	}

	Draw::OutlinedRectangle(x, y - iHeight, iWidth, iHeight + 1, COLOR3);

	Draw::RenderText((x + (iWidth + iHeight) * 0.5) - 10, (y - iHeight) + 4,COLOR9, true, Fonts::m_WatermarkFont, pszTitle);
}

void cMenu::DrawMenu()
{
	Draw::FillRGBA(m_x + 22, m_y - 22, 80 * 5 + 20, 23, COLOR4);

	DrawTab(LEGITAB, iTabIndex, m_x, m_y, "AIMBOT");
	DrawTab(ESPTAB, iTabIndex, m_x + 97, m_y, "VISUAL");
	DrawTab(MISCTAB, iTabIndex, m_x + 195, m_y, "MISC");
	DrawTab(SKINTAB, iTabIndex, m_x + 291, m_y, "SKINS");
	DrawTab(COLTAB, iTabIndex, m_x + 387, m_y, "COLOR");

	Draw::FillRGBA(m_x, m_y + 1, m_w, m_h, COLOR3);
	Draw::FillRGBA(m_x + 1, m_y + 2, m_w - 2, m_h - 2, COLOR4);
	Draw::FillRGBA(m_x + 6, m_y + 7, m_w - 12, m_h - 12, COLOR3);
	Draw::FillRGBA(m_x + 7, m_y + 8, m_w - 14, m_h - 14, COLOR5);

	Draw::FillRGBA(m_x - 15, m_y + 50, 15, 55, COLOR3);

	if (g_Mouse.OneLeftClick(m_x - 14, m_y + 51, 14, 53))
	{
		CfgSystem::SaveCFG(true, false);
		pClientstate->m_nDeltaTick = -1;
	}

	if (g_Mouse.LeftClick(m_x - 14, m_y + 51, 14, 53))
		Draw::FillRGBA(m_x - 15, m_y + 50, 15, 55, COLOR9);

	Draw::FillRGBA(m_x - 14, m_y + 51, 14, 53, COLOR6);

	Draw::RenderText(m_x - 10, m_y + 51,COLOR9, false, Fonts::m_WatermarkFont,"S");
	Draw::RenderText(m_x - 10, m_y + 63,COLOR9, false, Fonts::m_WatermarkFont,"A");
	Draw::RenderText(m_x - 10, m_y + 75,COLOR9, false, Fonts::m_WatermarkFont,"V");
	Draw::RenderText(m_x - 10, m_y + 87,COLOR9, false, Fonts::m_WatermarkFont,"E");

	Draw::FillRGBA(m_x - 15, m_y + 140, 15, 55, COLOR3);

	if (g_Mouse.OneLeftClick(m_x - 14, m_y + 141, 14, 53))
	{
		CfgSystem::LoadCfg(true, false);
		pClientstate->m_nDeltaTick = -1;
	}

	if (g_Mouse.LeftClick(m_x - 14, m_y + 141, 14, 53))
		Draw::FillRGBA(m_x - 15, m_y + 140, 15, 55, COLOR9);

	Draw::FillRGBA(m_x - 14, m_y + 141, 14, 53, COLOR6);

	Draw::RenderText(m_x - 10, m_y + 140,  COLOR9, false, Fonts::m_WatermarkFont,  "L");
	Draw::RenderText(m_x - 10, m_y + 152,  COLOR9, false, Fonts::m_WatermarkFont, "O");
	Draw::RenderText(m_x - 10, m_y + 164,  COLOR9, false, Fonts::m_WatermarkFont, "A");
	Draw::RenderText(m_x - 10, m_y + 176,  COLOR9, false, Fonts::m_WatermarkFont,  "D");

	Draw::FillRGBA(m_x + m_w, m_y + 50, 15, 55, COLOR3);

	if (g_Mouse.OneLeftClick(m_x + m_w, m_y + 51, 14, 53))
	{
		CfgSystem::SaveCFG(false, true);
		pClientstate->m_nDeltaTick = -1;
	}

	if (g_Mouse.LeftClick(m_x + m_w, m_y + 51, 15, 55))
		Draw::FillRGBA(m_x + m_w, m_y + 50, 15, 55, COLOR9);

	Draw::FillRGBA(m_x + m_w, m_y + 51, 14, 53, COLOR6);

	Draw::RenderText(m_x + m_w + 3, m_y + 51,  COLOR9, false, Fonts::m_WatermarkFont, "S");
	Draw::RenderText(m_x + m_w + 3, m_y + 63,  COLOR9, false, Fonts::m_WatermarkFont, "A");
	Draw::RenderText(m_x + m_w + 3, m_y + 75,  COLOR9, false, Fonts::m_WatermarkFont, "V");
	Draw::RenderText(m_x + m_w + 3, m_y + 87,  COLOR9, false, Fonts::m_WatermarkFont, "E");

	Draw::FillRGBA(m_x + m_w, m_y + 140, 15, 55, COLOR3);

	if (g_Mouse.OneLeftClick(m_x + m_w, m_y + 141, 14, 53))
	{
		CfgSystem::LoadCfg(false, true);
		pClientstate->m_nDeltaTick = -1;
	}

	if (g_Mouse.LeftClick(m_x + m_w, m_y + 141, 15, 55))
		Draw::FillRGBA(m_x + m_w, m_y + 140, 15, 55, COLOR9);

	Draw::FillRGBA(m_x + m_w, m_y + 141, 14, 53, COLOR6);

	Draw::RenderText(m_x + m_w + 3, m_y + 140, COLOR9, false, Fonts::m_WatermarkFont, "L");
	Draw::RenderText(m_x + m_w + 3, m_y + 152, COLOR9, false, Fonts::m_WatermarkFont, "O");
	Draw::RenderText(m_x + m_w + 3, m_y + 164, COLOR9, false, Fonts::m_WatermarkFont, "A");
	Draw::RenderText(m_x + m_w + 3, m_y + 176, COLOR9, false, Fonts::m_WatermarkFont, "D");

	InitMenuElements();
}

void cMenuSection::Draw(int x, int y, int w, int h)
{
	Draw::OutlinedRectangle(x,y,w,h,COLOR2);

	SetSectionPos(x,y);
}

void cMenuSection::DrawAllDropDowns()
{
	int iNumOfDropDowns = vecDropDowns.size();

	int iWhich = -1;

	for (int i2 = (iNumOfDropDowns - 1); i2 >= 0; i2--)
	{
		bool bIsActive = bActiveDropDown[i2];

		if (bIsActive)
		{
			iWhich = i2;

			dwWait = GetTickCount() + 700;
			break;
		}
	}

	for (int i = (iNumOfDropDowns - 1); i >= 0; i--)
	{
		int e_x = vecDropDowns[i].x;
		int e_y = vecDropDowns[i].y;
		int iCount = vecDropDowns[i].iCount;

		bool bIsActive = bActiveDropDown[i];

		char **ppszNames = vecDropDowns[i].ppszNames;
		float *fValues = vecDropDowns[i].fValues;
		float *cvar = vecDropDowns[i].cvar;

		int gayfag = e_x - 1;

		if (bIsActive)
		{
			int string_x = gayfag + (DROPDOWN_WIDTH * 0.5);

			for (int ax = 0; ax < iCount; ax++)
			{
				if (g_Mouse.IsOver(gayfag, e_y + (ax * DROPDOWN_HEIGHT), DROPDOWN_WIDTH, DROPDOWN_HEIGHT))
				{
					if (!g_Menu.IsHandlingItem())
						g_Menu.AddMenuFlag(FL_DISABLEDRAG);

					Draw::FillRGBA(gayfag + 1, e_y + 1 + (ax * DROPDOWN_HEIGHT), DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - (ax == (iCount - 1) ? 1 : 0), COLOR5);

					if (g_Mouse.HasMouseOneJustBeenReleased())
					{
						*cvar = fValues[ax];

						bActiveDropDown[i] = false;
					}
				}
				else
				{
					Draw::FillRGBA(gayfag + 1, e_y + 1 + (ax * DROPDOWN_HEIGHT), DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - (ax == (iCount - 1) ? 1 : 0), COLOR4);

					if (g_Mouse.HasMouseOneJustBeenReleased())
					{
						bActiveDropDown[i] = false;
					}
				}

				if (ax == (iCount - 1))
					Draw::OutlinedRectangle(gayfag, e_y, DROPDOWN_WIDTH, (ax + 1) * DROPDOWN_HEIGHT, COLOR3);

				if (*cvar == fValues[ax])
				{
					Draw::RenderText(string_x, e_y + (ax * DROPDOWN_HEIGHT), COLOR9, true, Fonts::m_ListItemFont, ppszNames[ax]);
				}
				else
				{
					Draw::RenderText(string_x, e_y + (ax * DROPDOWN_HEIGHT), COLOR10, true, Fonts::m_ListItemFont, ppszNames[ax]);
				}
			}
		}
		else
		{
			if (g_Mouse.IsOver(gayfag, e_y, DROPDOWN_WIDTH, DROPDOWN_HEIGHT))
			{
				if (!g_Menu.IsHandlingItem())
					g_Menu.AddMenuFlag(FL_DISABLEDRAG);

				Draw::FillRGBA(gayfag + 1, e_y + 1, DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - 1, COLOR5);

				if (g_Mouse.HasMouseOneJustBeenReleased() && (dwWait < GetTickCount() || iWhich == -1))
				{
					bActiveDropDown[i] = true;
				}
			}
			else
				Draw::FillRGBA(gayfag + 1, e_y + 1, DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - 1, COLOR4);

			Draw::OutlinedRectangle(gayfag, e_y, DROPDOWN_WIDTH, DROPDOWN_HEIGHT, COLOR3);

			int string_x = gayfag + (DROPDOWN_WIDTH * 0.5);
			int string_y = e_y;

			for (int ax = 0; ax < iCount; ax++)
			{
				if (*cvar == fValues[ax])
				{
					Draw::RenderText(string_x, string_y, COLOR10, true, Fonts::m_ListItemFont, ppszNames[ax]);
					break;
				}
			}
		}
	}

	ClearAllElementSpecifics();
}

int GetPressedKey()
{
	for (int i = 1; i < 256; i++)
	{
		if (GetAsyncKeyState(i) & 0x8000)
			return i;
	}
	return -1;
}

const char* ExplainKey(int vk)
{
	static char explaination[16] = { 0 };

    #define	DenyVK(_key) if (vk == _key) return explaination

	DenyVK(VK_INSERT);

	if (char exp = MapVirtualKey(vk, MAPVK_VK_TO_CHAR) & 255)
	{
		if (exp == 32)
			return "Space";
		else if (exp == '\t')
			return "Tab";
		else if (exp == '\b')
			return "Backspace";
		else if (exp == '\n' || exp == '\r')
			return "Enter";
		else
			sprintf(explaination, "%c", exp);
	}
	else
	{
		switch (vk)
		{
		case VK_LBUTTON:	return "LMB";
		case VK_RBUTTON:	return "RMB";
		case VK_MBUTTON:	return "Wheel";
		case VK_XBUTTON1:	return "X1";
		case VK_XBUTTON2:	return "X2";
		case VK_INSERT:		return "Ins";
		case VK_DELETE:		return "Del";
		case VK_LSHIFT:		return "L Shift";
		case VK_RSHIFT:		return "R Shift";
		case VK_LMENU:		return "L Alt";
		case VK_RMENU:		return "R Alt";
		case VK_LCONTROL:	return "L Ctrl";
		case VK_RCONTROL:	return "R Ctrl";
		}
	}

	return explaination;
}

void cMenuSection::AddElement(int iType, int add_to_x, int add_to_y, const char *pszElementName, float *cvar, float min, float max, float step)
{
	int e_x = s_x + 10 + add_to_x;
	int e_y = s_y + 15 + (iSection * ELEMENT_SEPERATION) + add_to_y;

	bool bDropDownActive = false;

	for (int i2 = 0; i2 < 50; i2++)
	{
		bDropDownActive = bActiveDropDown[i2];

		if (bDropDownActive)
			break;
	}

	int notgay;

	if (add_to_x = iRowThree)
	{
		notgay = +3;
	}
	
	if (iType == ONOFF)
	{
		Draw::RenderText(e_x - notgay, e_y, COLOR10, false, Fonts::m_WatermarkFont, pszElementName);

		e_x += CHECKBOX_SEPERATION_FROM_TEXT;

		if (g_Mouse.OneLeftClick(e_x - 3, e_y - 3, CHECKBOX_SIZE + 5, CHECKBOX_SIZE + 5) && !bDropDownActive)
			*cvar = !*cvar;

		e_y += 1;

		Draw::GradientVertical(e_x, e_y, CHECKBOX_SIZE, CHECKBOX_SIZE, 15, 15, 15, 140, 35, 35, 35);

		if (*cvar)
		{
			Draw::GradientVertical(e_x, e_y, CHECKBOX_SIZE, CHECKBOX_SIZE, 35, 35, 35, 220, gCvars.colorsredone, gCvars.colorsgreenone, gCvars.colorsblueone);
		}

		if (g_Mouse.IsOver(e_x, e_y, CHECKBOX_SIZE, CHECKBOX_SIZE))
		{
			Draw::OutlinedRectangle(e_x, e_y, CHECKBOX_SIZE, CHECKBOX_SIZE, COLOR9);

			if (!g_Menu.IsHandlingItem())
				g_Menu.AddMenuFlag(FL_DISABLEDRAG);
		}
		else
			Draw::OutlinedRectangle(e_x, e_y, CHECKBOX_SIZE, CHECKBOX_SIZE, 25,25,25,255);
	}
	else if (iType == DROPDOWN)
	{
		Draw::RenderText(e_x-notgay, e_y, COLOR10, false, Fonts::m_WatermarkFont, pszElementName);

		e_y += 1;

		DropDown_t ddNew;

		ddNew.x = e_x + CHECKBOX_SEPERATION_FROM_TEXT - 20;
		ddNew.y = e_y - 2;
		ddNew.fValues = fValueList;
		ddNew.cvar = cvar;
		ddNew.ppszNames = ppszValueNames;
		ddNew.iCount = iValueCount;

		AddDropDownToDrawList(ddNew);
	}
	else if (iType == SLIDER)
	{
		static int sliderlenght = 420;

		float Scale = max / 418;

		bool bOver = false;

		Draw::RenderText(e_x, e_y - 7, COLOR10, false, Fonts::m_WatermarkFont, "%s %2.2f", pszElementName, *cvar);

		e_y += 8;

		Draw::FillRGBA(e_x + 3, e_y + 6, sliderlenght, 2, 115, 120, 123, 185);

		int mouse_x, mouse_y;
		g_Mouse.GetMousePosition(mouse_x, mouse_y);

		if (mouse_x >= (e_x - 3) && mouse_x <= (e_x + sliderlenght + 3) && mouse_y >= (e_y) && mouse_y <= (e_y + 10) && GetAsyncKeyState(VK_LBUTTON) && (iSliderIndex == -1) && dwWait < GetTickCount() && !bSliderFix[iCurrSlider])
		{
			iSliderIndex = iCurrSlider;
			bSliderFix[iCurrSlider] = true;

			if (!g_Menu.IsHandlingItem())
				g_Menu.AddMenuFlag(FL_DISABLEDRAG);
		}

		if (mouse_x >= (e_x - 1000) && mouse_x <= (e_x + sliderlenght + 1000) && mouse_y >= (e_y - 1000) && mouse_y <= (e_y + 1000) && GetAsyncKeyState(VK_LBUTTON) && !bDropDownActive)
		{
			if (bSliderFix[iCurrSlider])
			{
				*cvar = min + (mouse_x - e_x) * Scale;

				bOver = true;

				if (!g_Menu.IsHandlingItem())
					g_Menu.AddMenuFlag(FL_DISABLEDRAG);
			}
		}
		else if (bSliderFix[iCurrSlider])
		{
			iSliderIndex = -1;
			bSliderFix[iCurrSlider] = false;
		}

		if (*cvar > max)
			*cvar = max;

		if (*cvar < min)
			*cvar = min;

		static int iSizeOf = 6;

		for (int nu = 0; nu <= iSizeOf; nu++)
		{
			Draw::FillRGBA(e_x + (*cvar / Scale) - iSizeOf + nu, e_y + iSizeOf - nu, (iSizeOf + 1) - nu, 1, COLOR4);
			Draw::FillRGBA(e_x + (*cvar / Scale) - iSizeOf + nu, e_y + iSizeOf + nu, (iSizeOf + 1) - nu, 1, COLOR4);
			Draw::FillRGBA(e_x + (*cvar / Scale), e_y + iSizeOf - nu, (iSizeOf + 1) - nu, 1, COLOR4);
			Draw::FillRGBA(e_x + (*cvar / Scale), e_y + iSizeOf + nu, (iSizeOf + 1) - nu, 1, COLOR4);
		}

		if (g_Mouse.IsOver(e_x + (*cvar / Scale) - iSizeOf, e_y - 1, 10, 14) || bOver)
		{
			Draw::RenderLine(e_x + (*cvar / Scale) - (iSizeOf + 1), e_y + iSizeOf, e_x + (*cvar / Scale), e_y - 1, COLOR9);
			Draw::RenderLine(e_x + (*cvar / Scale), e_y - 1, e_x + (*cvar / Scale) + (iSizeOf + 1), e_y + iSizeOf, COLOR9);
			Draw::RenderLine(e_x + (*cvar / Scale) + (iSizeOf + 1), e_y + iSizeOf, e_x + (*cvar / Scale), e_y + (iSizeOf * 2 + 1), COLOR9);
			Draw::RenderLine(e_x + (*cvar / Scale), e_y + (iSizeOf * 2 + 1), e_x + (*cvar / Scale) - (iSizeOf + 1), e_y + iSizeOf, COLOR9);
		}
		else
		{
			Draw::RenderLine(e_x + (*cvar / Scale) - (iSizeOf + 1), e_y + iSizeOf, e_x + (*cvar / Scale), e_y - 1, COLOR6);
			Draw::RenderLine(e_x + (*cvar / Scale), e_y - 1, e_x + (*cvar / Scale) + (iSizeOf + 1), e_y + iSizeOf, COLOR6);
			Draw::RenderLine(e_x + (*cvar / Scale) + (iSizeOf + 1), e_y + iSizeOf, e_x + (*cvar / Scale), e_y + (iSizeOf * 2 + 1), COLOR6);
			Draw::RenderLine(e_x + (*cvar / Scale), e_y + (iSizeOf * 2 + 1), e_x + (*cvar / Scale) - (iSizeOf + 1), e_y + iSizeOf, COLOR6);
		}
	}
	else if (iType == ADDER)
	{
		int gayfag = e_x - 1;

		Draw::RenderText(e_x-notgay, e_y, COLOR10, false, Fonts::m_WatermarkFont, pszElementName);

		e_y += 1;

		gayfag += (CHECKBOX_SEPERATION_FROM_TEXT - 20);

		Draw::FillRGBA(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR7);

		if (g_Mouse.IsOver(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY))
		{
			Draw::OutlinedRectangle(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR9);

			if (g_Mouse.HasMouseOneJustBeenReleased() && !bDropDownActive)
				*cvar -= step;

			if (g_Mouse.IsMouseTwoBeingHeld() && !bDropDownActive)
				*cvar -= 1;
		}
		else
			Draw::OutlinedRectangle(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR4);

		Draw::RenderText(gayfag + ADDER_SIZEX * 0.5, e_y - 1, COLOR9, true, Fonts::m_ListItemFont, "<");

		Draw::RenderText(gayfag - 7 + ADDER_SIZEX + ADDER_SEPERATE_FROM_BOXES * 0.5, e_y - 2, COLOR10, true, Fonts::m_WatermarkFont, "%2.0f", *cvar);

		gayfag += ADDER_SEPERATE_FROM_BOXES;

		Draw::FillRGBA(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR7);

		if (g_Mouse.IsOver(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY))
		{
			Draw::OutlinedRectangle(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR9);

			if (g_Mouse.HasMouseOneJustBeenReleased() && !bDropDownActive)
				*cvar += step;

			if (g_Mouse.IsMouseTwoBeingHeld() && !bDropDownActive)
				*cvar += 1;
		}
		else
			Draw::OutlinedRectangle(gayfag, e_y, ADDER_SIZEX, ADDER_SIZEY, COLOR4);

		Draw::RenderText(gayfag + ADDER_SIZEX * 0.5, e_y - 1, COLOR9, true, Fonts::m_ListItemFont, ">");


		if (*cvar < min)
			*cvar = max;

		if (*cvar > max)
			*cvar = min;
	}
	else if (iType == KEYBIND)
	{
		Draw::RenderText(e_x-notgay, e_y, COLOR10, false, Fonts::m_WatermarkFont, pszElementName);

		e_y - 2;

		int gayfag = e_x + CHECKBOX_SEPERATION_FROM_TEXT - 21;

		int PressedKey = GetPressedKey();

		if (g_Mouse.IsOver(gayfag, e_y, DROPDOWN_WIDTH, DROPDOWN_HEIGHT))
		{
			if (PressedKey > 0 && PressedKey != 0x57 && PressedKey != 0x53 && PressedKey != 0x44 && PressedKey != 0x41 && PressedKey != 0x20 && PressedKey != 0x10 && PressedKey != 0xA0 && PressedKey != 0xA1 && PressedKey != 0x11 && PressedKey != 0xA2 && PressedKey != 0xA3 && PressedKey != VK_INSERT)
				*cvar = PressedKey;
		}

		if (g_Mouse.IsOver(gayfag, e_y, DROPDOWN_WIDTH, DROPDOWN_HEIGHT))
		{
			if (!g_Menu.IsHandlingItem())
				g_Menu.AddMenuFlag(FL_DISABLEDRAG);

			Draw::FillRGBA(gayfag + 1, e_y + 1, DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - 1, COLOR5);
		}
		else
			Draw::FillRGBA(gayfag + 1, e_y + 1, DROPDOWN_WIDTH - 1, DROPDOWN_HEIGHT - 1, COLOR4);

		Draw::SoftOutlinedRectangle(gayfag, e_y, DROPDOWN_WIDTH, DROPDOWN_HEIGHT, COLOR3);

		int string_x = gayfag + (DROPDOWN_WIDTH * 0.5);
		int string_y = e_y;

		Draw::RenderText(string_x, string_y, COLOR10, true, Fonts::m_WatermarkFont, ExplainKey(*cvar));
	}

	PostElement((iType == SLIDER ? 2 : 1));
}