
struct RecvProp;

struct RecvProxyData
{
	const RecvProp* m_pRecvProp;
	BYTE  Pad[4];
	int   m_Int;
};

struct RecvTable
{
	RecvProp		*m_pProps;
	int				m_nProps;
	BYTE            Pad[4];
	char			*m_pNetTableName;
};

struct RecvProp
{
	char	  *m_pVarName;
	BYTE      PPad[28];
	void*	  m_ProxyFn;
	BYTE      CPad[4];
	RecvTable *m_pDataTable;
	int		  m_Offset;
	BYTE      Pad[12];
};

using CreateClass = void*(__cdecl*)(int,int);

using RecvVarProxyFn = void(__cdecl*)(RecvProxyData*,void*,void*);

struct ClientClass
{
	CreateClass   m_pCreateFn;
	BYTE          Pad[8];
	RecvTable*	  GetTable;
	ClientClass*  NextClass;
	int           GetClassID;
};
