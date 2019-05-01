#include "stdafx.h"
#include "Win32Functions.h"

HBITMAP GetScreenBmp()
{
	// 获取屏幕截屏
	// 获取桌面窗口句柄
	HWND hDesktop = ::GetDesktopWindow();
	// 获取桌面窗口DC
	HDC hdc = ::GetDC(hDesktop);
	// 创建兼容DC
	HDC mdc = ::CreateCompatibleDC(hdc);
	// 获取计算机屏幕的宽和高
	DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);
	DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);
	// 创建兼容位图
	HBITMAP bmp = ::CreateCompatibleBitmap(hdc, dwWidth, dwHeight);
	// 选中位图
	HBITMAP holdbmp = (HBITMAP)::SelectObject(mdc, bmp);
	// 将窗口内容绘制到位图上
	::BitBlt(mdc, 0, 0, dwWidth, dwHeight, hdc, 0, 0, SRCCOPY);

	// 绘制鼠标
	POINT p;
	//获取当前屏幕的鼠标的位置
	::GetCursorPos(&p);
	//获得鼠标图片的句柄
	HICON hIcon = (HICON)::GetCursor();
	//绘制鼠标图标
	::DrawIcon(mdc, p.x, p.y, hIcon);

	::SelectObject(mdc, holdbmp);

	// 释放内存
	::DeleteDC(mdc);
	::ReleaseDC(hDesktop, hdc);

	return bmp;
}


__declspec(dllexport) BOOL ScreenShot(LPCTSTR imgSavePath)
{
	_ASSERT(imgSavePath != NULL);
	_ASSERT(_tcsclen(imgSavePath) > 1024);

	_tprintf(_T("saving screenshot to %s\n"), imgSavePath);

	// 获取屏幕截屏位图句柄
	HBITMAP hBmp = GetScreenBmp();
	if (NULL == hBmp)
	{
		return FALSE;
	}
	// 保存为图片
	CImage image;
	image.Attach(hBmp);
	image.Save(imgSavePath);

	// 释放位图句柄
	::DeleteObject(hBmp);

	return TRUE;
}
