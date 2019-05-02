#include"pch.h"

void TestIsValidPicName()
{
	const WCHAR* pathList[] = {
		L"abc.jpg", L"ddd.png", 0
	};

	const WCHAR **p = pathList;
	while (*p != 0)
	{
		ASSET_TRUE(IsValidPicName(*p));
		p += 1;
	}
}