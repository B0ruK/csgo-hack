

RecvVarProxyFn oRecvnModelIndex;
void Hooked_RecvProxy_Viewmodel(RecvProxyData *pData, void *pStruct, void *pOut)
{
	if (gCvars.knife > 0 && gCvars.skinchanger)
	{
		int default_t = pModel->GetModelIndex("models/weapons/v_knife_default_t.mdl");
		int default_ct = pModel->GetModelIndex("models/weapons/v_knife_default_ct.mdl");
		int iKarambit = pModel->GetModelIndex("models/weapons/v_knife_karam.mdl");
		int iBayonet = pModel->GetModelIndex("models/weapons/v_knife_bayonet.mdl");
		int iFlip = pModel->GetModelIndex("models/weapons/v_knife_flip.mdl");
		int iGut = pModel->GetModelIndex("models/weapons/v_knife_gut.mdl");
		int iM9Bayonet = pModel->GetModelIndex("models/weapons/v_knife_m9_bay.mdl");

		Entities* pLocal = pEntList->GetClientEntity(pEngine->GetLocalPlayer());

		if (pLocal)
		{
			if (pLocal->IsAlive() && (pData->m_Int == default_t || pData->m_Int == default_ct))
			{
				if (gCvars.knife == 1)
				{
					pData->m_Int = iBayonet;
				}
				else if (gCvars.knife == 2)
				{
					pData->m_Int = iFlip;
				}
				else if (gCvars.knife == 3)
				{
					pData->m_Int = iGut;
				}
				else if (gCvars.knife == 4)
				{
					pData->m_Int = iKarambit;
				}
				else if (gCvars.knife == 5)
				{
					pData->m_Int = iM9Bayonet;
				}
			}
		}
	}

	oRecvnModelIndex(pData, pStruct, pOut);
}

void NetvarHook()
{
	ClientClass *pClass = pClient->GetAllClasses();

	while (pClass)
	{
		const char *pszName = pClass->GetTable->m_pNetTableName;

		if (!strcmp(pszName, "DT_BaseViewModel"))
		{
			for (int i = 0; i < pClass->GetTable->m_nProps; i++)
			{
				RecvProp *pProp = &(pClass->GetTable->m_pProps[i]);
				const char *name = pProp->m_pVarName;
				if (!strcmp(name, "m_nModelIndex"))
				{
					oRecvnModelIndex = (RecvVarProxyFn)pProp->m_ProxyFn;
					pProp->m_ProxyFn = Hooked_RecvProxy_Viewmodel;
				}
			}
		}

		pClass = pClass->NextClass;
	}
}