#include "stdafx.h"

__declspec(dllexport)  BOOL GetUserTempDir(LPTSTR dirPath)
{
	_tcscpy_s(dirPath, LH_PATH_SIZE, _T("C:\\users\\temp"));
	return TRUE;
}