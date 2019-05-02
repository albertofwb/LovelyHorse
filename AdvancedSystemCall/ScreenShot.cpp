#include "stdafx.h"

HBITMAP GetScreenBmp()
{
	HWND hDesktop = ::GetDesktopWindow();
	HDC hdc = ::GetDC(hDesktop);
	HDC mdc = ::CreateCompatibleDC(hdc);

	DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);
	DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

	HBITMAP bmp = ::CreateCompatibleBitmap(hdc, dwWidth, dwHeight);
	HBITMAP holdbmp = (HBITMAP)::SelectObject(mdc, bmp);
	::BitBlt(mdc, 0, 0, dwWidth, dwHeight, hdc, 0, 0, SRCCOPY);

	POINT p;
	::GetCursorPos(&p);
	HICON hIcon = (HICON)::GetCursor();
	::DrawIcon(mdc, p.x, p.y, hIcon);

	::SelectObject(mdc, holdbmp);

	::DeleteDC(mdc);
	::ReleaseDC(hDesktop, hdc);

	return bmp;
}


DLL_OUT BOOL ScreenShot(LPCTSTR imgSavePath)
{
	_ASSERT(imgSavePath != NULL);
	_ASSERT(_tcsclen(imgSavePath) <= LH_MAX_PATH);

	_tprintf(_T("saving screenshot to %s\n"), imgSavePath);

	HBITMAP hBmp = GetScreenBmp();
	if (NULL == hBmp)
	{
		return FALSE;
	}

	CImage image;
	image.Attach(hBmp);
	image.Save(imgSavePath);

	::DeleteObject(hBmp);

	return TRUE;
}
