#include "CommonUtils.h"
#include "Win32Functions.h"

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

// startup parameters defination
static TCHAR g_ScreenShotSavePath[LH_MAX_PATH];
static TCHAR g_WorkingDir[LH_MAX_PATH];
static BOOL g_IsMonitorKeyboard;

// end startup parameters defination

// Note that the calling code will then have to deallocate this memory, otherwise you will have a memory leak.
wchar_t *CharToWchar(const char *origChars)
{
	assert(origChars != NULL);
	assert(strlen(origChars) > 0);

	const size_t oriCharsLen = strlen(origChars) + 1;

	wchar_t* convertedChars = new wchar_t[LH_MAX_PATH];
	size_t numOfConvertedChar;
	mbstowcs_s(&numOfConvertedChar, convertedChars, oriCharsLen, origChars, LH_MAX_PATH);

	return convertedChars;
}

inline bool findArgument(list<string> arguList, string argu)
{
	return find(begin(arguList), end(arguList), argu) != end(arguList);
}

void ConsumeStartupParameters(const int ac, char **av)
{
	list<string> arguMonitorKbdList = { "--recor-keyboard", "-k", "/k" };
	list<string> arguPicPathList = {"--pic-path", "-p", "/p"};

	printf("ac=%d\n", ac);

	if (ac < 2)
	{
		LOG_ERR(_T("please setup pic save path"));
		exit(1);
	}



	for (int i = 1; i < ac; i++)
	{
		av += 1;		
		string t(*av);
		transform(t.begin(), t.end(), t.begin(), ::tolower);
		// check g_IsMonitorKeyboard
		if (findArgument(arguMonitorKbdList, t))
		{
			g_IsMonitorKeyboard = true;
			continue;
		}

		// parse g_ScreenShotSavePath
		if (findArgument(arguPicPathList, t))
		{
			i += 1;
			av += 1;
			wchar_t *tp = CharToWchar(*av);
			_tcscpy_s(g_ScreenShotSavePath, LH_MAX_PATH, tp);
			_tprintf(_T("save path => %s\n"), g_ScreenShotSavePath);
			continue;
		}

	}
}

void ApplyStartupParameters()
{
	ScreenShot(g_ScreenShotSavePath);
}

int main(int argc, char **argv) 
{

#if 0
	TCHAR tmp[LH_MAX_PATH];
	TCHAR userTmpDir[LH_PATH_SIZE];
	if (!GetUserTempDir(userTmpDir)) {
		LOG_ERR(_T("failed get user temp dir"));
	}
	LOG(_T("path is %s"), userTmpDir);

#endif

#if 1
	GetWorkingDir(g_WorkingDir);
	_tprintf(_T("working dir => %s"), g_WorkingDir);

	ConsumeStartupParameters(argc, argv);
	ApplyStartupParameters();
#endif
	return 0;
}