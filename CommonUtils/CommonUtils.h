#pragma once

#include <Windows.h>

#include <assert.h>
#include <stdio.h>
#include <tchar.h>


#include "StringUtils.h"

#define DLL_IN __declspec(dllimport)
#define DLL_OUT __declspec(dllexport)

#define EXIT_ON_ERROR

const size_t LOG_BUFF_SIZE = 1024;


LPCTSTR LOG_TEXT = _T("INFO");
LPCTSTR ERROR_TEXT = _T("ERROR");

inline void LOG(LPCTSTR format, ...)
{
	TCHAR buff[LOG_BUFF_SIZE];
	ZeroMemory(buff, sizeof buff);

	va_list args;
	va_start(args, format);
	_vsntprintf_s(buff, LOG_BUFF_SIZE, LOG_BUFF_SIZE, format, args);
	va_end(args);

	_tprintf_s(_T("%s %s\n"), LOG_TEXT, buff);
}


inline void LOG_ERR(LPCTSTR format, ...)
{
	TCHAR buff[LOG_BUFF_SIZE];
	ZeroMemory(buff, sizeof buff);

	va_list args;
	va_start(args, format);
	_vsntprintf_s(buff, LOG_BUFF_SIZE, LOG_BUFF_SIZE, format, args);
	va_end(args);

	_tprintf_s(_T("%s %s\n"), ERROR_TEXT, buff);

#ifdef EXIT_ON_ERROR
	exit(1);
#endif // EXIT_ON_ERROR

}

DLL_IN BOOL GetUserTempDir(LPTSTR dirPath);
DLL_IN void GetWorkingDir(LPTSTR path);
DLL_IN bool IsValidPicName(const TCHAR* picPath);
