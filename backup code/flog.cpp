#include "flog.hpp"
#include <sstream>
#include <Windows.h>

namespace ft
{

	Flog* Flog::pInstance = NULL;
	Flog::Flog()
	{
		int logMode = LogMode::CONSOLE;
		string logFile = "default.log";
		file = new ofstream;

		console.color = LogColor::WHITE;
		console.hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(console.hStdout,&console.csbi);
	}

	void Flog::openLog(const bool append)
	{
		if(!file->is_open())
		{
			if(append)
			{
				file->open(logFile,ios::app);
			}else
			{
				file->open(logFile,ios::beg);
			}
		}
	}
	void Flog::closeLog()
	{
		if(file->is_open())	
			file->close();
	}

	Flog& operator<<(Flog& fl, string msg)
	{
		bool writeTime = false;
		if(fl.logMode == LogMode::CONSOLE || fl.logMode == LogMode::CON_LOG)
		{
			if(msg.at(0) == '%' && msg.at(1) == 't')
			{
				writeTime = true;
				msg.erase(0,2);
				clog << fl.time.tell();
			}
			SetConsoleTextAttribute(fl.console.hStdout,fl.console.color);
			clog << msg;
			SetConsoleTextAttribute(fl.console.hStdout,fl.console.csbi.wAttributes);
		}
		if(fl.logMode == LogMode::LOGFILE || fl.logMode == LogMode::CON_LOG)
		{
			if(!fl.file->is_open())
			{
				fl.openLog(false);
			}
			if(fl.file->good())
			{

				if(writeTime)
				{
					*(fl.file) << fl.time.tell();
				}

				*(fl.file) << msg;
			}
		}

		return fl;
	}

	Flog& operator<<(Flog& fl, float msg)
	{
		stringstream stream;
		stream << msg;
		return fl << stream.str();
	}


}