#include "stdafx.h"
#include "Win32Functions.h"

HBITMAP GetScreenBmp()
{
	// ��ȡ��Ļ����
	// ��ȡ���洰�ھ��
	HWND hDesktop = ::GetDesktopWindow();
	// ��ȡ���洰��DC
	HDC hdc = ::GetDC(hDesktop);
	// ��������DC
	HDC mdc = ::CreateCompatibleDC(hdc);
	// ��ȡ�������Ļ�Ŀ�͸�
	DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);
	DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);
	// ��������λͼ
	HBITMAP bmp = ::CreateCompatibleBitmap(hdc, dwWidth, dwHeight);
	// ѡ��λͼ
	HBITMAP holdbmp = (HBITMAP)::SelectObject(mdc, bmp);
	// ���������ݻ��Ƶ�λͼ��
	::BitBlt(mdc, 0, 0, dwWidth, dwHeight, hdc, 0, 0, SRCCOPY);

	// �������
	POINT p;
	//��ȡ��ǰ��Ļ������λ��
	::GetCursorPos(&p);
	//������ͼƬ�ľ��
	HICON hIcon = (HICON)::GetCursor();
	//�������ͼ��
	::DrawIcon(mdc, p.x, p.y, hIcon);

	::SelectObject(mdc, holdbmp);

	// �ͷ��ڴ�
	::DeleteDC(mdc);
	::ReleaseDC(hDesktop, hdc);

	return bmp;
}


__declspec(dllexport) BOOL ScreenShot(LPCTSTR imgSavePath)
{
	_ASSERT(imgSavePath != NULL);
	_ASSERT(_tcsclen(imgSavePath) > 1024);

	_tprintf(_T("saving screenshot to %s\n"), imgSavePath);

	// ��ȡ��Ļ����λͼ���
	HBITMAP hBmp = GetScreenBmp();
	if (NULL == hBmp)
	{
		return FALSE;
	}
	// ����ΪͼƬ
	CImage image;
	image.Attach(hBmp);
	image.Save(imgSavePath);

	// �ͷ�λͼ���
	::DeleteObject(hBmp);

	return TRUE;
}
