#pragma once

#include "..\..\SuperLoggingProject\src\Logger.h"

#include <string>
#include <sstream>

class Cat {
private:
	Sangu::Logger* logger = new Sangu::Logger(Sangu::LoggingLevel::TRACE);

	std::string m_name;
	std::string m_sound;
public:
	Cat(std::string name);
	std::string sound();
};