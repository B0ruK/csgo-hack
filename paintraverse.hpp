#pragma once


void __fastcall hkPaintTraverse(void* ecx, void* edx, unsigned int vguiPanel, bool forceRepaint, bool allowForce)
{
	pt_holy_hook.call_original<decltype(&hkPaintTraverse)>(ecx, edx, vguiPanel, forceRepaint, allowForce);

	static unsigned int FocusOverlayPanel = 0;

	static bool FoundPanel = false;

	if (!FoundPanel)
	{
		PCHAR szPanelName = (PCHAR)pPanel->GetName(vguiPanel);

		if (strstr(szPanelName, "FocusOverlayPanel"))
		{
			FocusOverlayPanel = vguiPanel;
			FoundPanel = true;
		}
	}
	else if (FocusOverlayPanel == vguiPanel)
	{
		AddToDrawList(vguiPanel);
	}
}
