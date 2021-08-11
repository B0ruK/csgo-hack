
#include "cmove.hpp"

bool __fastcall hkcreate_move(void* ecx, void* edx, float frame_time, UserCmd* cmd)
{
	if (cmd && cmd->command_number)
	{
		DoStuff(cmd);
	}

	return cm_holy_hook.call_original<bool>(ecx, edx, frame_time, cmd);
}
