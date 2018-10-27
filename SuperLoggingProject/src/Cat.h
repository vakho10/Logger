#pragma once

#include "Logger.h"

#include <string>
#include <sstream>

class Cat {
private:
	Logger* logger = new Logger(LoggingLevel::TRACE, "resources\\cat_log.txt");

	std::string m_name;
	std::string m_sound;
public:
	Cat(std::string name);
	std::string sound();
};