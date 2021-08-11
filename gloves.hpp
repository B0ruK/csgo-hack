
void GloveChanger(Entities* pLocal)
{
	UINT* pWeapons = pLocal->GetWeapons();

	if (!pWeapons)
		return;

	UINT* pWareables = pLocal->GetWearables();

	if (!pWareables)
		return;

	if (!pEntList->GetClientEntityFromHandle((PVOID)pWareables[0]))
	{
		for (ClientClass* pClass = pClient->GetAllClasses(); pClass; pClass = pClass->NextClass)
		{
			if (pClass->GetClassID == ClassIds::GetWearables)
			{
				int iEntry = pEntList->GetHighestEntityIndex() + 1;
				int iSerial = rand() % 0x1000;

				if (pClass->m_pCreateFn(iEntry, iSerial))
				{
					pWareables[0] = iEntry | (iSerial << 16);
					break;
				}
			}
		}

		if (!pWareables[0])
			return;

		Entities* glove = (Entities*)pEntList->GetClientEntityFromHandle((PVOID)pWareables[0]);

		if (!glove)
			return;

		if (glove)
		{
			if (gCvars.gloves == 0)
			{
				if (*glove->GetItemDefinitionIndex() != GLOVE_STUDDED_BLOODHOUND || *glove->FallbackPaintKit() != gCvars.glovekit1)
				{
					glove->SetModelIndex(pModel->GetModelIndex("models/weapons/v_models/arms/glove_bloodhound/v_glove_bloodhound.mdl"));
					*glove->GetItemDefinitionIndex() = GLOVE_STUDDED_BLOODHOUND;
					*glove->FallbackPaintKit() = gCvars.glovekit1;
					*glove->ItemIDHigh() = -1;
					glove->PreDataUpdate(0);
				}
			}
			if (gCvars.gloves == 1)
			{
				if (*glove->GetItemDefinitionIndex() != GLOVE_SPORTY || *glove->FallbackPaintKit() != gCvars.glovekit2)
				{
					glove->SetModelIndex(pModel->GetModelIndex("models/weapons/v_models/arms/glove_sporty/v_glove_sporty.mdl"));
					*glove->GetItemDefinitionIndex() = GLOVE_SPORTY;
					*glove->FallbackPaintKit() = gCvars.glovekit2;
					*glove->ItemIDHigh() = -1;
					glove->PreDataUpdate(0);
				}
			}
			if (gCvars.gloves == 2)
			{
				if (*glove->GetItemDefinitionIndex() != GLOVE_SLICK || *glove->FallbackPaintKit() != gCvars.glovekit3)
				{
					glove->SetModelIndex(pModel->GetModelIndex("models/weapons/v_models/arms/glove_slick/v_glove_slick.mdl"));
					*glove->GetItemDefinitionIndex() = GLOVE_SLICK;
					*glove->FallbackPaintKit() = gCvars.glovekit3;
					*glove->ItemIDHigh() = -1;
					glove->PreDataUpdate(0);
				}
			}
			if (gCvars.gloves == 3)
			{
				if (*glove->GetItemDefinitionIndex() != GLOVE_LEATHER_WRAP || *glove->FallbackPaintKit() != gCvars.glovekit4)
				{
					glove->SetModelIndex(pModel->GetModelIndex("models/weapons/v_models/arms/glove_handwrap_leathery/v_glove_handwrap_leathery.mdl"));
					*glove->GetItemDefinitionIndex() = GLOVE_LEATHER_WRAP;
					*glove->FallbackPaintKit() = gCvars.glovekit4;
					*glove->ItemIDHigh() = -1;
					glove->PreDataUpdate(0);
				}
			}
			if (gCvars.gloves == 4)
			{
				if (*glove->GetItemDefinitionIndex() != GLOVE_MOTORCYCLE || *glove->FallbackPaintKit() != gCvars.glovekit5)
				{
					glove->SetModelIndex(pModel->GetModelIndex("models/weapons/v_models/arms/glove_motorcycle/v_glove_motorcycle.mdl"));
					*glove->GetItemDefinitionIndex() = GLOVE_MOTORCYCLE;
					*glove->FallbackPaintKit() = gCvars.glovekit5;
					*glove->ItemIDHigh() = -1;
					glove->PreDataUpdate(0);
				}
			}
			if (gCvars.gloves == 5)
			{
				if (*glove->GetItemDefinitionIndex() != GLOVE_SPECIALIST || *glove->FallbackPaintKit() != gCvars.glovekit6)
				{
					glove->SetModelIndex(pModel->GetModelIndex("models/weapons/v_models/arms/glove_specialist/v_glove_specialist.mdl"));
					*glove->GetItemDefinitionIndex() = GLOVE_SPECIALIST;
					*glove->FallbackPaintKit() = gCvars.glovekit6;
					*glove->ItemIDHigh() = -1;
					glove->PreDataUpdate(0);
				}
			}
		}
	}
}
