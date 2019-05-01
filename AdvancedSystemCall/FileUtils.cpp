#include "Utils.h"

BOOL GetUserTempDir(LPTSTR dirPath)
{
	LPCTSTR path = _T("C:\\abc");

	_tcscpy_s(dirPath, MAX_PATH_SIZE, path);
	return TRUE;
}
