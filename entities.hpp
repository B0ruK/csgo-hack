
template <typename t>
t getvfunc(void* class_pointer, size_t index)
{
	return (*(t**)class_pointer)[index];
}

struct Entities
{
	WeaponInfo * GetWpnData();
	bool IsPlayer();
	const Vector & GetAbsOrigin();
	void * GetNetworkable();
	void PreDataUpdate(int);
	bool IsDormant();
	Vector GetOrigin();
	float GetFlashDuration(float);
	int GetIndex();
	float m_flSimulationTime();
	HANDLE GetObserverTargetHandle();
	int GetHealth();
	unsigned char GetLifeState();
	int GetTeamNum();
	Vector GetAimPunchAngle();
	int GetFlags();
	Vector GetVecViewOffset();
	Vector GetEyePosition();
	Vector GetVelocity();
	int GetShotsFired();
	HANDLE GetActiveWeapon();
	bool IsScoped();
	int GetTickBase();
	bool IsAlive();
	UINT * GetWeapons();
	UINT * GetWearables();
	int GetMoveType();
	int * FallbackSeed();
	int * FallbackStatTrak();
	float GetNextPrimaryAttack();
	bool HasAmmo();
	short * GetItemDefinitionIndex();
	int * AccountID();
	void SetModelIndex(int);
	int * ModelIndex();
	int * ItemIDHigh();
	int * FallbackPaintKit();
	int * OwnerXuidLow();
	int * OwnerXuidHigh();
	Vector & GetBonePos(int);
};


inline WeaponInfo* Entities::GetWpnData()
{
	if (!this)
		return nullptr;

	typedef WeaponInfo*(__thiscall* GetWpnData)(void*);
	return getvfunc<GetWpnData>(this, 460)(this);
}

inline bool Entities::IsPlayer()
{
	return getvfunc<bool(__thiscall*)(Entities*)>(this, 157)(this);
}

inline const Vector& Entities::GetAbsOrigin()
{
	typedef const Vector& (__thiscall *GetAbsOrg_t)(PVOID);
	return getvfunc<GetAbsOrg_t>(this, 10)(this);
}

inline void* Entities::GetNetworkable()
{
	typedef void* (__thiscall* GetNetworkableFn)(void*);
	return getvfunc< GetNetworkableFn >(this, 4)(this);
}

inline void Entities::PreDataUpdate(int updateType)
{
	auto pNet = GetNetworkable();
	typedef void(__thiscall* OriginalFn)(PVOID, int);
	return getvfunc<OriginalFn>(pNet, 6)(pNet, updateType);
}

inline bool Entities::IsDormant()
{
	auto pNet = GetNetworkable();
	typedef bool(__thiscall* OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(pNet, 9)(pNet);
}

inline Vector Entities::GetOrigin()
{
	return *(Vector*)((uintptr_t)this + offsets.DT_BaseEntity.m_vecOrigin);
}

inline float Entities::GetFlashDuration(float Duration)
{
	return *(float*)((uintptr_t)this + offsets.DT_CSPlayer.m_flFlashDuration) = Duration;
}

inline int Entities::GetIndex()
{
	return *(int*)((DWORD)this + offsets.DT_BaseEntity.m_bIsAutoaimTarget + 0x4);
}

inline float Entities::m_flSimulationTime()
{
	return *(float*)((uintptr_t)this + offsets.DT_BaseEntity.m_flSimulationTime);
}

inline HANDLE Entities::GetObserverTargetHandle()
{
	return *(HANDLE*)((uintptr_t)this + offsets.DT_BasePlayer.m_hObserverTarget);
}

inline int Entities::GetHealth()
{
	return *(int*)((uintptr_t)this + offsets.DT_BasePlayer.m_iHealth);
}

inline unsigned char Entities::GetLifeState()
{
	return *(unsigned char*)((uintptr_t)this + offsets.DT_BasePlayer.m_lifeState);
}

inline int Entities::GetTeamNum()
{
	return *(int*)((uintptr_t)this + offsets.DT_BaseEntity.m_iTeamNum);
}

inline Vector Entities::GetAimPunchAngle()
{
	return *(Vector*)((uintptr_t)this + offsets.DT_BasePlayer.m_aimPunchAngle);
}

inline int Entities::GetFlags()
{
	return *(int*)((uintptr_t)this + offsets.DT_BasePlayer.m_fFlags);
}

inline Vector Entities::GetVecViewOffset()
{
	return *(Vector*)((uintptr_t)this + offsets.DT_BasePlayer.m_vecViewOffset);
}

inline Vector Entities::GetEyePosition()
{
	return GetAbsOrigin() + GetVecViewOffset();
}

inline Vector Entities::GetVelocity()
{
	return *(Vector*)((uintptr_t)this + offsets.DT_BasePlayer.m_vecVelocity);
}

inline int Entities::GetShotsFired()
{
	return *(int*)((uintptr_t)this + offsets.DT_CSPlayer.m_iShotsFired);
}

inline HANDLE Entities::GetActiveWeapon()
{
	return *(HANDLE*)((uintptr_t)this + offsets.DT_BaseCombatCharacter.m_hActiveWeapon);
}

inline bool Entities::IsScoped()
{
	return *(bool*)((uintptr_t)this + offsets.DT_CSPlayer.m_bIsScoped);
}

inline int Entities::GetTickBase()
{
	return *(unsigned int*)((uintptr_t)this + offsets.DT_BasePlayer.m_nTickBase);
}

inline bool Entities::IsAlive()
{
	return (GetLifeState() == 0 && GetHealth() > 0);
}

inline UINT* Entities::GetWeapons()
{
	return (UINT*)((DWORD)this + offsets.DT_BaseCombatCharacter.m_hMyWeapons);
}

inline UINT* Entities::GetWearables()
{
	return (UINT*)((DWORD)this + offsets.DT_BaseCombatCharacter.m_hMyWearables);
}

inline int Entities::GetMoveType()
{
	return *(int*)((DWORD)this + offsets.DT_BaseEntity.m_nRenderMode + 1);
}

inline int* Entities::FallbackSeed()
{
	return (int*)((uintptr_t)this + offsets.DT_BaseAttributableItem.m_nFallbackSeed);
}

inline int* Entities::FallbackStatTrak()
{
	return (int*)((uintptr_t)this + offsets.DT_BaseAttributableItem.m_nFallbackStatTrak);
}

inline float Entities::GetNextPrimaryAttack()
{
	return *(float*)((uintptr_t)this + offsets.DT_BaseCombatWeapon.m_flNextPrimaryAttack);
}

inline bool Entities::HasAmmo()
{
	return ((*(PINT)((DWORD)this + offsets.DT_BaseCombatWeapon.m_iClip1)) > 0);
}

inline short* Entities::GetItemDefinitionIndex()
{
	return (short*)((uintptr_t)this + offsets.DT_BaseAttributableItem.m_iItemDefinitionIndex);
}

inline int* Entities::AccountID()
{
	return (int*)((uintptr_t)this + offsets.DT_BaseAttributableItem.m_iAccountID);
}

inline void Entities::SetModelIndex(int index)
{
	*(int*)((DWORD)this + offsets.DT_BaseViewModel.m_nModelIndex) = index;
}

inline int* Entities::ModelIndex()
{
	return (int*)((uintptr_t)this + offsets.DT_BaseViewModel.m_nModelIndex);
}

inline int* Entities::ItemIDHigh()
{
	return (int*)((uintptr_t)this + offsets.DT_BaseAttributableItem.m_iItemIDHigh);
}

inline int* Entities::FallbackPaintKit()
{
	return (int*)((uintptr_t)this + offsets.DT_BaseAttributableItem.m_nFallbackPaintKit);
}

inline int* Entities::OwnerXuidLow()
{
	return (int*)((uintptr_t)this + offsets.DT_BaseAttributableItem.m_OriginalOwnerXuidLow);
}

inline int* Entities::OwnerXuidHigh()
{
	return (int*)((uintptr_t)this + offsets.DT_BaseAttributableItem.m_OriginalOwnerXuidHigh);
}

inline Vector& Entities::GetBonePos(int bone)
{
	static Vector v;

	DWORD boneMatrix = *(DWORD*)(this + offsets.DT_BaseAnimating.m_nForceBone + 28);

	v.x = *(float*)(boneMatrix + (bone * 48 + 12));
	v.y = *(float*)(boneMatrix + (bone * 48 + 28));
	v.z = *(float*)(boneMatrix + (bone * 48 + 44));

	return v;
}