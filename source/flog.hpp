/*
Super simple logger class.
Can output time and date.
Can output in colour.
Can output to console as well as file.
*/

#ifndef _FLOG_HPP_
#define _FLOG_HPP_
#include <string>
#include <iostream>
#include "time.hpp"
#include "flog_data.hpp"

using namespace std;
namespace ft
{
	//Log enumerations.
	class Flog
	{
	private:
		int logMode;
		Time time;
		Console console;
		string logFileName;
		ofstream* file;

		Flog(){}
	public:	
		static Flog& out(){ 
			static Flog instance;
			return instance;
		}
		~Flog(){
			closeLog();
			if(file)
				delete file;
		}
		//A simple initiation function. Instead of ctor.
		void flogInit();
		//set functions.
		void setLogMode(const LogMode _logMode) {logMode = _logMode;}
		void setColor(const WORD _logColor) {console.color = _logColor;}
		void setLogFile(const string _logFileName) {logFileName = _logFileName;}
		//openLog and closeLog do not need to be called manually.
		void openLog(const bool append);
		void closeLog();

		//operator overloading for safe type printing.
		friend Flog& operator<<(Flog& o, string formatString);		
	};
}

#endif