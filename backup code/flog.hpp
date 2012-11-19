#ifndef _FLOG_HPP_
#define _FLOG_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "log_structs.hpp"
#include "f_exception.hpp"
#include "time.hpp"

#define FLOG *Flog

using namespace std;
namespace ft
{
	class Flog
	{
	private:
		Time time;
		Console console;
		int logMode;
		string logFile;
		ofstream* file;

		static Flog *pInstance;
		Flog();
	public:

		static Flog* getInstance(){
			if(!pInstance)
				pInstance = new Flog();
			return pInstance;
		}
		static Flog log(){
			return *pInstance;
		}

		~Flog(){
			delete pInstance;
			if(file->is_open())
				file->close();
		}
		
		void setLogMode(const int _logMode){logMode = _logMode;}
		void setColor(const WORD _logColor){console.color = _logColor;}
		void changeLogFile(const string _logFile){logFile = _logFile;}
		void openLog(const bool append);
		void closeLog();

		//operator overloading. The main reason for all get functions
		friend Flog& operator<<(Flog& fl, string msg);
		//friend Flog& operator<<(Flog& fl, int msg);
		friend Flog& operator<<(Flog& fl, float msg);
	
		Flog* operator=(Flog* fl)
		{
			pInstance = fl->pInstance;
			return this;
		} 
	
	};

}

#endif