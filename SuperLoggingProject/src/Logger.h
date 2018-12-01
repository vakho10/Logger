#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

#include "LoggingLevel.h"

namespace Sangu
{
	class Logger
	{
	private:		
		std::ostream* ost = std::_Ptr_cout;
		LoggingLevel m_level = LoggingLevel::INFO;
		
		std::string levelToString(LoggingLevel level);
				
		void log(LoggingLevel level, std::string message);
	public:
		Logger();
		Logger(LoggingLevel level);
		Logger(std::ostream* ost);
		Logger(LoggingLevel level, std::ostream* ost);
		~Logger();

		void trace(std::string message);
		void debug(std::string message);
		void info(std::string message);
		void warn(std::string message);
		void error(std::string message);
		void fatal(std::string message);

		void setFilter(LoggingLevel level);
		void setOutputStream(std::ostream* ost);
	};
}