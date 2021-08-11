

namespace NetVarManager
{
	std::vector<RecvTable*> GetTables();
	RecvTable* GetTable(std::vector<RecvTable*>,const char* );
	int GetOffset(std::vector<RecvTable*>,const char*,const char*);
	int Get_Prop(std::vector<RecvTable*>,const char*,const char*,RecvProp** prop = 0);
	int Get_Prop(std::vector<RecvTable*>,RecvTable*,const char*,RecvProp** prop = 0);
}
