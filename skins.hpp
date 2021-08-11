
bool isWeaponKnife(int weaponid)
{
	if (weaponid == WEAPON_KNIFE_T || weaponid == WEAPON_KNIFE_CT)
		return true;

	return false;
}

void SkinChanger(Entities* pLocal)
{
	UINT* hWeapons = pLocal->GetWeapons();

	if (!hWeapons)
		return;

	playerinfo LocalPlayerInfo;

	if (!pEngine->GetPlayerInfo(pEngine->GetLocalPlayer(), &LocalPlayerInfo))
		return;

	for (size_t i = 0; hWeapons[i] != 0xFFFFFFFF; i++)
	{
		Entities* pWeapon = (Entities*)pEntList->GetClientEntity(hWeapons[i] & 0xFFF);

		if (!pWeapon)
			continue;

		int weapon = *pWeapon->GetItemDefinitionIndex();

		switch (weapon)
		{
		case WEAPON_AK47:
		{
			*pWeapon->FallbackPaintKit() = gCvars.ak47skin;

			if (gCvars.ak47stats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.ak47stats;
			}

			if (gCvars.ak47seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.ak47seed;
			}
		}
		break;
		case WEAPON_M4A1:
		{
			*pWeapon->FallbackPaintKit() = gCvars.m4a4skin;

			if (gCvars.m4a4stats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.m4a4stats;
			}

			if (gCvars.m4a4seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.m4a4seed;
			}
		}
		break;
		case WEAPON_DUALS:
		{
			*pWeapon->FallbackPaintKit() = gCvars.dualskin;

			if (gCvars.dualstats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.dualstats;
			}

			if (gCvars.dualseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.dualseed;
			}
		}
		break;
		case WEAPON_M4A1S:
		{
			*pWeapon->FallbackPaintKit() = gCvars.m4a1skin;

			if (gCvars.m4a1stats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.m4a1stats;
			}

			if (gCvars.m4a1seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.m4a1seed;
			}
		}
		break;
		case WEAPON_AWP:
		{
			*pWeapon->FallbackPaintKit() = gCvars.awpskin;

			if (gCvars.awpstats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.awpstats;
			}

			if (gCvars.awpseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.awpseed;
			}
		}
		break;
		case WEAPON_MP5SD:
		{
			*pWeapon->FallbackPaintKit() = gCvars.mp5skin;

			if (gCvars.mp5stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.mp5stat;
			}

			if (gCvars.mp5seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.mp5seed;
			}
		}
		break;
		case WEAPON_USPS:
		{
			*pWeapon->FallbackPaintKit() = gCvars.uspskin;

			if (gCvars.uspstats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.uspstats;
			}

			if (gCvars.uspseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.uspseed;
			}
		}
		break;
		case WEAPON_GLOCK:
		{
			*pWeapon->FallbackPaintKit() = gCvars.glockskin;

			if (gCvars.glockstats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.glockstats;
			}

			if (gCvars.glockseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.glockseed;
			}
		}
		break;
		case WEAPON_DEAGLE:
		{
			*pWeapon->FallbackPaintKit() = gCvars.deagleskin;

			if (gCvars.deaglestats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.deaglestats;
			}

			if (gCvars.deagleseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.deagleseed;
			}
		}
		break;
		case WEAPON_FIVE7:
		{
			*pWeapon->FallbackPaintKit() = gCvars.fivesevenskin;

			if (gCvars.fivesevenstat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.fivesevenstat;
			}

			if (gCvars.fivesevenseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.fivesevenseed;
			}
		}
		break;
		case WEAPON_AUG:
		{
			*pWeapon->FallbackPaintKit() = gCvars.augskin;

			if (gCvars.augstats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.augstats;
			}

			if (gCvars.augseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.augseed;
			}
		}
		break;
		case WEAPON_FAMAS:
		{
			*pWeapon->FallbackPaintKit() = gCvars.famasskin;

			if (gCvars.famasstat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.famasstat;
			}

			if (gCvars.famasseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.famasseed;
			}
		}
		break;
		case WEAPON_G3SG1:
		{
			*pWeapon->FallbackPaintKit() = gCvars.g3sg1skin;

			if (gCvars.g3sg1stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.g3sg1stat;
			}

			if (gCvars.g3sg1seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.g3sg1seed;
			}
		}
		break;
		case WEAPON_GALIL:
		{
			*pWeapon->FallbackPaintKit() = gCvars.galilskin;

			if (gCvars.galilstats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.galilstats;
			}

			if (gCvars.galilseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.galilseed;
			}
		}
		break;
		case WEAPON_M249:
		{
			*pWeapon->FallbackPaintKit() = gCvars.m249skin;

			if (gCvars.m249stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.m249stat;
			}

			if (gCvars.m249seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.m249seed;
			}
		}
		break;
		case WEAPON_MAC10:
		{
			*pWeapon->FallbackPaintKit() = gCvars.mac10skin;

			if (gCvars.mac10stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.mac10stat;
			}

			if (gCvars.mac10seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.mac10seed;
			}
		}
		break;
		case WEAPON_P90:
		{
			*pWeapon->FallbackPaintKit() = gCvars.p90skin;

			if (gCvars.p90stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.p90stat;
			}

			if (gCvars.p90seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.p90seed;
			}
		}
		break;
		case WEAPON_UMP45:
		{
			*pWeapon->FallbackPaintKit() = gCvars.umpskin;

			if (gCvars.umpstat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.umpstat;
			}

			if (gCvars.umpseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.umpseed;
			}
		}
		break;
		case WEAPON_XM1014:
		{
			*pWeapon->FallbackPaintKit() = gCvars.xm1000skin;

			if (gCvars.xm1000stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.xm1000stat;
			}

			if (gCvars.xm1000seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.xm1000seed;
			}
		}
		break;
		case WEAPON_BIZON:
		{
			*pWeapon->FallbackPaintKit() = gCvars.bizonskin;

			if (gCvars.bizonstat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.bizonstat;
			}

			if (gCvars.bizonseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.bizonseed;
			}
		}
		break;
		case WEAPON_MAG7:
		{
			*pWeapon->FallbackPaintKit() = gCvars.mag7skin;

			if (gCvars.mag7stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.mag7stat;
			}

			if (gCvars.mag7seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.mag7seed;
			}
		}
		break;
		case WEAPON_NEGEV:
		{
			*pWeapon->FallbackPaintKit() = gCvars.negevskin;

			if (gCvars.negevstat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.negevstat;
			}

			if (gCvars.negevseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.negevseed;
			}
		}
		break;
		case WEAPON_SAWEDOFF:
		{
			*pWeapon->FallbackPaintKit() = gCvars.sawedskin;

			if (gCvars.sawedstat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.sawedstat;
			}

			if (gCvars.sawedseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.sawedseed;
			}
		}
		break;
		case WEAPON_TEC9:
		{
			*pWeapon->FallbackPaintKit() = gCvars.tecskin;

			if (gCvars.tecstat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.tecstat;
			}

			if (gCvars.tecseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.tecseed;
			}
		}
		break;
		case WEAPON_P2000:
		{
			*pWeapon->FallbackPaintKit() = gCvars.p2000skin;

			if (gCvars.p2000stats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.p2000stats;
			}

			if (gCvars.p2000seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.p2000seed;
			}
		}
		break;
		case WEAPON_MP7:
		{
			*pWeapon->FallbackPaintKit() = gCvars.mp7skin;

			if (gCvars.mp7stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.mp7stat;
			}

			if (gCvars.mp7seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.mp7seed;
			}
		}
		break;
		case WEAPON_MP9:
		{
			*pWeapon->FallbackPaintKit() = gCvars.mp9skin;

			if (gCvars.mp9stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.mp9stat;
			}

			if (gCvars.mp9seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.mp9seed;
			}
		}
		break;
		case WEAPON_NOVA:
		{
			*pWeapon->FallbackPaintKit() = gCvars.novaskin;

			if (gCvars.novastat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.novastat;
			}

			if (gCvars.novaseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.novaseed;
			}
		}
		break;
		case WEAPON_P250:
		{
			*pWeapon->FallbackPaintKit() = gCvars.p250skin;

			if (gCvars.p250stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.p250stat;
			}

			if (gCvars.p250seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.p250seed;
			}
		}
		break;
		case WEAPON_SCAR20:
		{
			*pWeapon->FallbackPaintKit() = gCvars.scarskin;

			if (gCvars.scarstat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.scarstat;
			}

			if (gCvars.scarseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.scarseed;
			}
		}
		break;
		case WEAPON_SG553:
		{
			*pWeapon->FallbackPaintKit() = gCvars.sg553skin;

			if (gCvars.sg553stats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.sg553stats;
			}

			if (gCvars.sg553seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.sg553seed;
			}
		}
		break;
		case WEAPON_SCOUT:
		{
			*pWeapon->FallbackPaintKit() = gCvars.scoutskin;

			if (gCvars.scoutstats > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.scoutstats;
			}

			if (gCvars.scoutseed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.scoutseed;
			}
		}
		break;
		case WEAPON_REVOLVER:
		{
			*pWeapon->FallbackPaintKit() = gCvars.r8skin;

			if (gCvars.r8stat > 0)
			{
				*pWeapon->FallbackStatTrak() = gCvars.r8stat;
			}

			if (gCvars.r8seed > 0)
			{
				*pWeapon->FallbackSeed() = gCvars.r8seed;
			}
		}
		}

		if (gCvars.knife == 1)
		{
			if (isWeaponKnife(weapon))
			{
				*pWeapon->ModelIndex() = pModel->GetModelIndex("models/weapons/v_knife_bayonet.mdl");
				*pWeapon->GetItemDefinitionIndex() = WEAPON_KNIFE_BAYONET;
				*pWeapon->FallbackPaintKit() = gCvars.knifeskin;
			}
		}
		else if (gCvars.knife == 2)
		{
			if (isWeaponKnife(weapon))
			{
				*pWeapon->ModelIndex() = pModel->GetModelIndex("models/weapons/v_knife_flip.mdl");
				*pWeapon->GetItemDefinitionIndex() = WEAPON_KNIFE_FLIP;
				*pWeapon->FallbackPaintKit() = gCvars.knifeskin;
			}

		}
		else if (gCvars.knife == 3)
		{
			if (isWeaponKnife(weapon))
			{
				*pWeapon->ModelIndex() = pModel->GetModelIndex("models/weapons/v_knife_gut.mdl");
				*pWeapon->GetItemDefinitionIndex() = WEAPON_KNIFE_GUT;
				*pWeapon->FallbackPaintKit() = gCvars.knifeskin;
			}
		}
		else if (gCvars.knife == 4)
		{
			if (isWeaponKnife(weapon))
			{
				*pWeapon->ModelIndex() = pModel->GetModelIndex("models/weapons/v_knife_karam.mdl");
				*pWeapon->GetItemDefinitionIndex() = WEAPON_KNIFE_KARAMBIT;
				*pWeapon->FallbackPaintKit() = gCvars.knifeskin;
			}
		}
		else if (gCvars.knife == 5)
		{
			if (isWeaponKnife(weapon))
			{
				*pWeapon->ModelIndex() = pModel->GetModelIndex("models/weapons/v_knife_m9_bay.mdl");
				*pWeapon->GetItemDefinitionIndex() = WEAPON_KNIFE_M9BAYONET;
				*pWeapon->FallbackPaintKit() = gCvars.knifeskin;
			}
		}

		if (LocalPlayerInfo.xuid_low != *pWeapon->OwnerXuidLow())
			continue;

		if (LocalPlayerInfo.xuid_high != *pWeapon->OwnerXuidHigh())
			continue;

		*pWeapon->ItemIDHigh() = -1;
		*pWeapon->AccountID() = LocalPlayerInfo.xuid_low;
	}
}
