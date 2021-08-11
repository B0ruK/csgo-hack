
class CIniWriter
{
public:
	CIniWriter(const char* szFileName)
	{
		memset(m_szFileName, 0x00, 255);
		memcpy(m_szFileName, szFileName, strlen(szFileName));
	}
	void WriteFloat(char* szKey, float fltValue)
	{
		char szValue[255];
		sprintf(szValue, "%f", fltValue);
		WritePrivateProfileStringA("", szKey, szValue, m_szFileName);
	}

	float ReadFloat(char* szKey)
	{
		char szResult[255];
		float fltResult;
		GetPrivateProfileStringA("", szKey, "0.00f", szResult, 255, m_szFileName);
		fltResult = atof(szResult);
		return fltResult;
	}
private:
	char m_szFileName[255];
};