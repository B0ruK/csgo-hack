


class CESP
{
public:
	void draw(Entities*);
	void drawradar(Entities*);
	void DrawRadarBack();
	void DrawPlayer(Entities*,int);
	void SpecList(Entities*);
	void DrawRadarPoint(Vector,Vector,Vector, playerinfo);
	void drawvelocity(Entities*);
	void DrawBox(const RECT&);
	void Crosshair(Entities*);
	void DrawMonitor(Entities*);
	void DrawHealth(const RECT&,Entities*);

	playerinfo info;
};

inline CESP g_ESP;

