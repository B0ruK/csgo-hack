
#include "skins.hpp"
#include "gloves.hpp"

enum ClientFrameStage
{
	POSTDATAUPDATE_START = 2
};

void __fastcall hkframe_stage_notify(void* ecx, void* edx, int stage)
{
	fsn_holy_hook.call_original<decltype(&hkframe_stage_notify)>(ecx, edx, stage);

	if (stage == POSTDATAUPDATE_START)
	{
		Entities *local = pEntList->GetClientEntity(pEngine->GetLocalPlayer());

		if (local && local->IsAlive())
		{
			if (gCvars.skinchanger)
			{
				GloveChanger(local);
				SkinChanger(local);
			}
		}
	}
}