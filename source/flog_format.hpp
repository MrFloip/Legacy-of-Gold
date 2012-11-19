#ifndef _FLOG_FORMAT_HPP_
#define _FLOG_FORMAT_HPP_
#include <sstream>
#include "flog.hpp"

using std::stringstream;

namespace ft
{
	class Format
	{
	public:
		template <typename T>
		static string getString(T uType){
			stringstream stream;
			stream << uType;
			return stream.str();
		}
	};
}

#endif