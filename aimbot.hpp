

class caimbot
{
public:
	void Main(UserCmd*,Entities*);

	bool IsVisible(Vector&,Vector&,Entities*,Entities*);

	bool GetHitboxpos(Entities*,Entities*,Vector&);

	void Main_RCS(UserCmd*,Entities*);

	void triggerbot(UserCmd*,Entities*,int);
private:
	void Reset()
	{
		iTarget = -1;
		fBestTarget = 99999.9f;
		vTarget.Zero();
		vFinal.Zero();
	}

	void ResetRCS()
	{
		iRCSTarget = -1;
		fBestRCSTarget = 99999.9f;
		vRCSTarget.Zero();
		vRCSFinal.Zero();
	}

	bool HasTarget()
	{
		return (iTarget != -1);
	}

	bool HasTargetRCS()
	{
		return (iRCSTarget != -1);
	}

	playerinfo info;

	Vector vMax;
	Vector vMin;

	int iTarget;
	int iRCSTarget;

	float fBestTarget;
	float fBestRCSTarget;

	Vector vTarget;
	Vector vRCSTarget;

	Vector vFinal;
	Vector vRCSFinal;

	Vector vEyePos;
};

inline caimbot g_aimbot;