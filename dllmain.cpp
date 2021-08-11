
#include "include.hpp"

c_holy_hook pt_holy_hook;
c_holy_hook fsn_holy_hook;
c_holy_hook cm_holy_hook;
c_holy_hook dme_holy_hook;

#include "drawmodel.hpp"
#include "framestage.hpp"
#include "clientmode.hpp"
#include "varhook.hpp"
#include "paintraverse.hpp"

int __stdcall DllMain(void*, int r, void*)
{
	if (r == 1)
	{
		InitialiseInterfaces();
		Offsets::GetOffsets();
		NetvarHook();

		pt_holy_hook.create(pPanel, 41, hkPaintTraverse, 5);
		fsn_holy_hook.create(pClient, 37, hkframe_stage_notify, 9);
		cm_holy_hook.create(pClientmode, 24, hkcreate_move, 9);
		dme_holy_hook.create(pModelRender, 21, hkdraw_model_execute, 6);

		Draw::InitFonts();
	}

	return 1;
}
