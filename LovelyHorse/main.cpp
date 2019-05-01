/*
	@Create Date: May 1st 2019
	@Author:	: Albert Wang
	@Email		: albertofwb@gmail.com

	NOTICE:
		please do not install this program on people's computer unless you
	get their permission. Because this program will make screenshots and send
	them to remote server which infringe on the privacy of others


	I made this program for practicing windpwes hacker programming skills.
	I also want make it a interesting network program so the beginners who are interested at network security
	can find a  a program containing a series of interesting hacking techniques which may inspire them to go further
	rather not the textbook style bored samples just makes people sleepy.

	The most code of this program are referenced of a book called 《windows黑客编程技术详解》
*/

#include <stdio.h>
#include <windows.h>
#include <tchar.h>

#include "Win32Functions.h"


int main(int argc, char *argv[]) 
{
	ScreenShot(_T("D:\\a.png"));

	return 0;
}