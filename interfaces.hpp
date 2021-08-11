

extern void InitialiseInterfaces();

inline void* pClientmode;
inline GlobalVars* pGlobalVars;
inline EngineClient* pEngine;
inline EntityList* pEntList;
inline MaterialSystem* pMaterialSystem;
inline ModelInfo* pModel;
inline CLient* pClient;
inline Enginetrace* pEngineTrace;
inline PlayerInfo* pPlayerinfo;
inline ClientState* pClientstate;
inline Panel* pPanel;
inline Surface* pSurface;
inline ModelRender* pModelRender;
inline Overlay* pOverlay;

struct InterfaceNode
{
	void* (*fnGet)();
	const char* szName;
	InterfaceNode* pNext;
};