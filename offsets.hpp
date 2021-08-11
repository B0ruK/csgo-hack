
struct COffsets
{
	struct
	{
		std::ptrdiff_t m_aimPunchAngle;
		std::ptrdiff_t m_vecViewOffset;
		std::ptrdiff_t m_nTickBase;
		std::ptrdiff_t m_vecVelocity;
		std::ptrdiff_t m_iHealth;
		std::ptrdiff_t m_lifeState;
		std::ptrdiff_t m_fFlags;
		std::ptrdiff_t m_hObserverTarget;
	} DT_BasePlayer;

	struct
	{
		std::ptrdiff_t m_flSimulationTime;
		std::ptrdiff_t m_nRenderMode;
		std::ptrdiff_t m_iTeamNum;
		std::ptrdiff_t m_bIsAutoaimTarget;
		std::ptrdiff_t m_bSpotted;
		std::ptrdiff_t m_vecOrigin;
	} DT_BaseEntity;

	struct
	{
		std::ptrdiff_t m_hActiveWeapon;
		std::ptrdiff_t m_hMyWeapons;
		std::ptrdiff_t m_hMyWearables;
	} DT_BaseCombatCharacter;

	struct
	{
		std::ptrdiff_t m_iShotsFired;
		std::ptrdiff_t m_bIsScoped;
		std::ptrdiff_t m_flFlashDuration;
	} DT_CSPlayer;

	struct
	{
		std::ptrdiff_t m_iItemDefinitionIndex;
		std::ptrdiff_t m_iItemIDHigh;
		std::ptrdiff_t m_iAccountID;
		std::ptrdiff_t m_nFallbackPaintKit;
		std::ptrdiff_t m_nFallbackSeed;
		std::ptrdiff_t m_flFallbackWear;
		std::ptrdiff_t m_nFallbackStatTrak;
		std::ptrdiff_t m_OriginalOwnerXuidLow;
		std::ptrdiff_t m_OriginalOwnerXuidHigh;
	} DT_BaseAttributableItem;

	struct
	{
		std::ptrdiff_t m_nModelIndex;
	} DT_BaseViewModel;

	struct
	{
		std::ptrdiff_t m_flNextPrimaryAttack;
		std::ptrdiff_t m_iClip1;
	} DT_BaseCombatWeapon;

	struct
	{
		std::ptrdiff_t m_nForceBone;
	} DT_BaseAnimating;

};

namespace Offsets
{
	void GetOffsets();
}

inline COffsets offsets;
