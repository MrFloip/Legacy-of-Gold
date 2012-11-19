#include <fstream>
#include <Windows.h>
#include "flog.hpp"
#include "f_exception.hpp"

namespace ft
{
	void Flog::flogInit()
	{
		logMode = CONSOLE;
		logFileName = "default.log";
		file = new ofstream;

		SMALL_RECT windowSize = {0,0,65,700};
		console.hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		console.hWnd = GetConsoleWindow();
		GetWindowRect(console.hWnd, &console.rect);
		GetConsoleScreenBufferInfo(console.hStdout,&console.csbi);

		MoveWindow(console.hWnd,1,1,800,1000,TRUE);

	}
	void Flog::openLog(const bool append)
	{
		if(!file->is_open())
		{
			if(append)
				file->open(logFileName.c_str(),ios::app);
			else
				file->open(logFileName.c_str(),ios::beg);
		}
	}


	void Flog::closeLog()
	{
		if(file->is_open())
			file->close();
	}

	Flog& operator<<(Flog& o,string fstring)
	{
		bool fileWriteTime = false;
		if(o.logMode == CONSOLE || o.logMode == CON_LOG)
		{
			if(fstring.at(0) == '%' && fstring.at(1) == 't')
			{
				fileWriteTime = true;
				fstring.erase(0,2);
				clog << o.time.tell();
			}
			SetConsoleTextAttribute(o.console.hStdout,o.console.color);
			clog << fstring;
			SetConsoleTextAttribute(o.console.hStdout,o.console.csbi.wAttributes);
		}
		if(o.logMode == LOGFILE || o.logMode == CON_LOG)
		{
			if(!o.file->is_open())
				o.file->open(o.logFileName.c_str());
			if(o.file->is_open())
			{
				if(fileWriteTime)
					*o.file << o.time.tell();
				*o.file << fstring;
			}
			else
				throw FException("Error, exception: In namespace Flog; out& operator<<(out&, string msg)",0);
		}
		return o;
	}
}