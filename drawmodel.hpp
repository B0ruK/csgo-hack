
void OverridematerialXQZ(Material* mat, float r, float g, float b)
{
	mat->SetFlag(IGNOREZ, true);
	mat->ColorModulate(r / 255, g / 255, b / 255);
	pModelRender->ForcedMaterialOverride(mat);
}

void Overridematerial(Material* mat, float r, float g, float b)
{
	if (gCvars.XQZ)
	{
		mat->SetFlag(IGNOREZ, false);
	}

	mat->ColorModulate(r / 255, g / 255, b / 255);
	pModelRender->ForcedMaterialOverride(mat);
}

void __fastcall hkdraw_model_execute(void* ecx, void* edx, void* ctx, void* state, ModelRenderInfo* info, void* matrix)
{
	auto original = [&](void* _matrix)
	{
		dme_holy_hook.call_original<void>(ecx, edx, ctx, state, info, _matrix);
	};

	static auto material = pMaterialSystem->FindMaterial("debug/debugambientcube");
	static auto smoke = pMaterialSystem->FindMaterial("particle/vistasmokev1/vistasmokev1_smokegrenade");

	if (info && material && smoke)
	{
		auto pEntity = pEntList->GetClientEntity(info->entity_index);
		auto pLocal = pEntList->GetClientEntity(pEngine->GetLocalPlayer());
		const char * ModelName = pModel->GetModelName((void*)info->pModel);

		if (gCvars.bMenu)
		{
			material->SetFlag(ZNEARER, true);
			material->SetFlag(NOCULL, true);
			material->SetFlag(NOFOG, true);
			material->SetFlag(HALFLAMBERT, true);
			smoke->SetFlag(WIREFRAME, gCvars.nosmoke);
		}

		if (gCvars.nosleeve && ModelName && strstr(ModelName, "v_sleeve"))
		{
			return;
		}

		if (pEntity && pLocal && material)
		{
			if ((gCvars.CHAMTEAM || pEntity->GetTeamNum() != pLocal->GetTeamNum()) && gCvars.chams)
			{
				if (pEntity->IsAlive())
				{
					if (gCvars.XQZ)
					{
						OverridematerialXQZ(material, gCvars.colorsredFIVE, gCvars.colorsgreenFIVE, gCvars.colorsblueFIVE);
						original(matrix);
					}
					Overridematerial(material, gCvars.colorsredFOUR, gCvars.colorsgreenFOUR, gCvars.colorsblueFOUR);
				}
			}
		}
	}

	original(matrix);
	pModelRender->ForcedMaterialOverride(nullptr);
}