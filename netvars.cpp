#include "include.hpp"

std::vector<RecvTable*> NetVarManager::GetTables()
{
	std::vector<RecvTable*> tables;

	ClientClass* clientClass = pClient->GetAllClasses();
	if (!clientClass)
		return std::vector<RecvTable*>();

	while (clientClass)
	{
		RecvTable* recvTable = clientClass->GetTable;
		tables.push_back(recvTable);

		clientClass = clientClass->NextClass;
	}

	return tables;
}

RecvTable* NetVarManager::GetTable(std::vector<RecvTable*> tables, const char* tableName)
{
	if (tables.empty())
		return NULL;

	for (unsigned long i = 0; i < tables.size(); i++)
	{
		RecvTable* table = tables[i];

		if (!table)
			continue;

		if (strcmp(table->m_pNetTableName, tableName) == 0)
			return table;
	}

	return NULL;
}

int NetVarManager::GetOffset(std::vector<RecvTable*> tables, const char* tableName, const char* propName)
{
	int offset = Get_Prop(tables, tableName, propName);
	if (!offset)
		return 0;

	return offset;
}

int NetVarManager::Get_Prop(std::vector<RecvTable*> tables, const char* tableName, const char* propName, RecvProp** prop)
{
	RecvTable* recvTable = GetTable(tables, tableName);
	if (!recvTable)
		return 0;

	int offset = Get_Prop(tables, recvTable, propName, prop);
	if (!offset)
		return 0;

	return offset;
}

int NetVarManager::Get_Prop(std::vector<RecvTable*> tables, RecvTable* recvTable, const char* propName, RecvProp** prop)
{
	int extraOffset = 0;

	for (int i = 0; i < recvTable->m_nProps; ++i) {
		RecvProp* recvProp = &recvTable->m_pProps[i];
		RecvTable* child = recvProp->m_pDataTable;

		if (child && (child->m_nProps > 0))
		{
			int tmp = Get_Prop(tables, child, propName, prop);
			if (tmp)
				extraOffset += (recvProp->m_Offset + tmp);
		}

		if (strcmp(recvProp->m_pVarName, propName))
			continue;

		if (prop)
			*prop = recvProp;

		return (recvProp->m_Offset + extraOffset);
	}

	return extraOffset;
}
