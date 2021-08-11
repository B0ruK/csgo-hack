#include "include.hpp"

void Offsets::GetOffsets()
{
	std::vector<RecvTable *> tables = NetVarManager::GetTables();

	offsets.DT_BasePlayer.m_aimPunchAngle = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_aimPunchAngle");
	offsets.DT_BasePlayer.m_vecViewOffset = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_vecViewOffset[0]");
	offsets.DT_BasePlayer.m_nTickBase = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_nTickBase");
	offsets.DT_BasePlayer.m_vecVelocity = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_vecVelocity[0]");
	offsets.DT_BasePlayer.m_iHealth = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_iHealth");
	offsets.DT_BasePlayer.m_lifeState = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_lifeState");
	offsets.DT_BasePlayer.m_fFlags = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_fFlags");
	offsets.DT_BasePlayer.m_hObserverTarget = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_hObserverTarget");
	offsets.DT_BaseEntity.m_flSimulationTime = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_flSimulationTime");
	offsets.DT_BaseEntity.m_nRenderMode = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_nRenderMode");
	offsets.DT_BaseEntity.m_iTeamNum = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_iTeamNum");
	offsets.DT_BaseEntity.m_bIsAutoaimTarget = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_bIsAutoaimTarget");
	offsets.DT_BaseCombatCharacter.m_hActiveWeapon = NetVarManager::GetOffset(tables, "DT_BaseCombatCharacter", "m_hActiveWeapon");
	offsets.DT_BaseCombatCharacter.m_hMyWeapons = NetVarManager::GetOffset(tables, "DT_BaseCombatCharacter", "m_hMyWeapons") / 2;
	offsets.DT_BaseCombatCharacter.m_hMyWearables = NetVarManager::GetOffset(tables, "DT_BaseCombatCharacter", "m_hMyWearables");
	offsets.DT_CSPlayer.m_bIsScoped = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_bIsScoped");
	offsets.DT_BaseAttributableItem.m_iItemDefinitionIndex = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_iItemDefinitionIndex");
	offsets.DT_BaseAttributableItem.m_iItemIDHigh = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_iItemIDHigh");
	offsets.DT_BaseAttributableItem.m_iAccountID = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_iAccountID");
	offsets.DT_BaseAttributableItem.m_nFallbackPaintKit = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_nFallbackPaintKit");
	offsets.DT_BaseAttributableItem.m_nFallbackSeed = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_nFallbackSeed");
	offsets.DT_BaseAttributableItem.m_flFallbackWear = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_flFallbackWear");
	offsets.DT_BaseAttributableItem.m_nFallbackStatTrak = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_nFallbackStatTrak");
	offsets.DT_BaseAttributableItem.m_OriginalOwnerXuidLow = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_OriginalOwnerXuidLow");
	offsets.DT_BaseAttributableItem.m_OriginalOwnerXuidHigh = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_OriginalOwnerXuidHigh");
	offsets.DT_BaseViewModel.m_nModelIndex = NetVarManager::GetOffset(tables, "DT_BaseViewModel", "m_nModelIndex");
	offsets.DT_BaseCombatWeapon.m_flNextPrimaryAttack = NetVarManager::GetOffset(tables, "DT_BaseCombatWeapon", "m_flNextPrimaryAttack");
	offsets.DT_BaseCombatWeapon.m_iClip1 = NetVarManager::GetOffset(tables, "DT_BaseCombatWeapon", "m_iClip1");
	offsets.DT_BaseAnimating.m_nForceBone = NetVarManager::GetOffset(tables, "DT_BaseAnimating", "m_nForceBone");
	offsets.DT_BaseEntity.m_bSpotted = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_bSpotted");
	offsets.DT_BaseEntity.m_vecOrigin = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_vecOrigin");
	offsets.DT_CSPlayer.m_iShotsFired = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_iShotsFired");
	offsets.DT_CSPlayer.m_flFlashDuration = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_flFlashDuration");
}
