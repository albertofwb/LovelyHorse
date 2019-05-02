#include "stdafx.h"

DLL_OUT BOOL GetUserTempDir(LPTSTR dirPath)
{
	_tcscpy_s(dirPath, LH_MAX_PATH, _T("C:\\users\\temp"));
	return TRUE;
}

DLL_OUT void GetWorkingDir(LPTSTR path)
{
	GetModuleFileName(NULL, path, LH_MAX_PATH);
	LPTSTR pos =_tcsrchr(path, _T('\\'));

	assert(pos != NULL);
	*pos = 0;
}

DLL_OUT bool IsValidPicName(const TCHAR* picPath)
{
	const TCHAR *supportPicSuffixList[] = {
		_T("bmp"), 
		_T("png"),
		_T("jpg"),
		0
	};
	const TCHAR* suffix = _tcsrchr(picPath, _T('.')) + 1;
	const TCHAR **p = supportPicSuffixList;

	while (*p != 0)
	{
		if (!_tcscmp(*p, suffix)) {
			return true;
		}
		p += 1;
	}

	return false;
}
