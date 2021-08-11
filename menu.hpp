
enum
{
	FL_DISABLEDRAG = (1 << 1)
};

enum
{
	SKINTAB,
	LEGITAB,
	ESPTAB,
	MISCTAB,
	COLTAB
};

enum
{
	ONOFF,
	DROPDOWN,
	SLIDER,
	KEYBIND,
	ADDER
};

typedef struct
{
	char szName[128];
} ListItem_t;

class cListItem
{
public:
	void Draw(int,int,int,int,bool);

	bool IsSelected(int index)
	{
		return (iSelectedIndex == index);
	}

	int GetNumberOfItems()
	{
		return vecListItems.size();
	}

	void ClearList()
	{
		vecListItems.clear();
	}

	void AddItem(const char *pszName)
	{
		ListItem_t liNew;

		strcpy(liNew.szName, pszName);

		vecListItems.push_back(liNew);
	}

	bool IsFocused()
	{
		return bListInFocus;
	}

	void SetFocus(bool bCondition)
	{
		bListInFocus = bCondition;
	}

	ListItem_t GetItemFromIndex(int index)
	{
		return vecListItems[index];
	}

	void Select(int index)
	{
		iSelectedIndex = index;
	}

	void DisplayPerPage(int amount)
	{
		iDisplayPerPage = amount;
	}

	int HowManyToDisplayPerPage()
	{
		return iDisplayPerPage;
	}

private:
	std::vector<ListItem_t> vecListItems;
	int iTopIndex;
	int iSelectedIndex;
	int iDisplayPerPage;
	bool bListInFocus;
};

typedef struct DropDown_s
{
	int x, y;
	int iCount;
	float *fValues;
	float *cvar;
	char **ppszNames;
} DropDown_t;

class cMenuSection
{
public:
	void Draw(int x, int y, int w, int h);

	void AddElement(int,int,int, const char*,float*,float min = 0,float max = 1,float step = 1);

	void DrawAllDropDowns();

	void PostSection()
	{
		DrawAllDropDowns();
	}

	void ClearSection()
	{
		vecDropDowns.clear();

		RestartSection();
	}

	void RestartSection()
	{
		iSection = 0;
	}

	void PostElement(int increment = 1)
	{
		iSection += increment;
	}
	
	void SetSlider(int &iCurrentSlider, float fLen = 360.0f)
	{
		fLength = fLen;
		
		iCurrentSlider++;
	}

	void SetSectionPos(int x, int y)
	{
		s_x = x;
		s_y = y;
	}

	void SetValueNames(char **szArrayArray, float *fArray, int iCount)
	{
		ppszValueNames = szArrayArray;
		fValueList = fArray;
		iValueCount = iCount;
	}

	void ClearAllElementSpecifics()
	{
		SetValueNames(NULL,NULL,0);
	}

private:
	void AddDropDownToDrawList(DropDown_t ddNew)
	{
		vecDropDowns.push_back(ddNew);
	}

	int iSection;
	int s_x, s_y;

	float *fValueList;
	char **ppszValueNames;
	int iValueCount;
	bool bActiveDropDown[50];
	std::vector<DropDown_t> vecDropDowns;

	float fLength;
};

class cMenu
{
public:
	cMenu(int x, int y, int w, int h);

	void InitMenuElements();

	void DrawMenu();

	void SetMenuPos(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	void GetMenuPos(int &out_x, int &out_y)
	{
		out_x = m_x;
		out_y = m_y;
	}

	void GetMenuSize(int &out_w, int &out_h)
	{
		out_w = m_w;
		out_h = m_h;
	}

	bool IsHandlingItem()
	{
		return (iMenuFlags & FL_DISABLEDRAG);
	}

	void AddMenuFlag(int iFlag)
	{
		iMenuFlags |= iFlag;
	}

	void RemoveMenuFlag(int iFlag)
	{
		iMenuFlags &= ~iFlag;
	}

	int GetTabIndex()
	{
		return iTabIndex;
	}
private:
	void DrawTab(int,int&,int,int,const char*);

	int m_x, m_y, m_w, m_h;
	int iMenuFlags;
	int iTabIndex;
};

inline cMenu g_Menu(400, 200, 467, 236);
inline cListItem ListItemArray;