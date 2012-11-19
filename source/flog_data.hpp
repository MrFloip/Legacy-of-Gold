#ifndef CONSOLE_H_
#define CONSOLE_H_
#include <Windows.h>

namespace ft
{
	enum LogMode
	{
		CONSOLE,
		LOGFILE,
		CON_LOG
	};
	
	//Static value enumeration for color.
	enum LogColor
	{
		INTENSITY = 0x08,
		WHITE = 0x0F,
		BLACK = 0x00,
		RED = 0x04,
		BLUE = 0x01,
		GREEN = 0x02,
	};

	struct Console
	{
		WORD color;
		HANDLE hStdout;
		HWND hWnd;
		RECT rect;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
	};

}


#endif