#pragma once

#include <Windows.h>
#include <tchar.h>

const int LH_PATH_SIZE = 1024;

extern "C" __declspec(dllexport)  BOOL GetUserTempDir(LPTSTR dirPath);