#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "LoggingLevel.h"

class Logger {
private:
	LoggingLevel m_level = LoggingLevel::INFO;
	std::ofstream* m_ofs = NULL;

	std::string levelToString(LoggingLevel level);
	void log(LoggingLevel level, std::string message);
public:
	Logger();
	Logger(LoggingLevel level);
	Logger(LoggingLevel level, std::string filePath);
	Logger(std::string filePath);
	~Logger();

	void trace(std::string message);
	void debug(std::string message);
	void info(std::string message);
	void warn(std::string message);
	void error(std::string message);
	void fatal(std::string message);

	void setFilter(LoggingLevel level);
	void addFileLog(std::string filePath);
};