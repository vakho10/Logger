#include "Logger.h"

Logger::Logger() {
}

Logger::Logger(LoggingLevel level) {
	this->setFilter(level);
}

Logger::Logger(LoggingLevel level, std::string filePath) {	
	this->setFilter(level);
	this->addFileLog(filePath);
}

Logger::Logger(std::string filePath) {
	this->addFileLog(filePath);
}

Logger::~Logger()
{
	m_ofs->close();
}

std::string Logger::levelToString(LoggingLevel level) {
	std::string retValue;
	switch (level)
	{
	case TRACE: retValue = "trace";
		break;
	case DEBUG: retValue = "debug";
		break;
	case INFO: retValue = "info";
		break;
	case WARN: retValue = "warn";
		break;
	case ERROR: retValue = "error";
		break;
	case FATAL: retValue = "fatal";
		break;
	default: retValue = std::to_string(level);
		break;
	}
	return retValue;
}

void Logger::log(LoggingLevel level, std::string message) {
	if (m_level <= level) {
		std::cout << "[" << levelToString(level) << "]: " << message << std::endl;
		if (m_ofs) {
			(*m_ofs) << "[" << levelToString(level) << "]: " << message << std::endl;			
		}
	}
}

void Logger::trace(std::string message)
{
	this->log(LoggingLevel::TRACE, message);
}

void Logger::debug(std::string message)
{
	this->log(LoggingLevel::DEBUG, message);
}

void Logger::info(std::string message)
{
	this->log(LoggingLevel::INFO, message);
}

void Logger::warn(std::string message)
{
	this->log(LoggingLevel::WARN, message);
}

void Logger::error(std::string message)
{
	this->log(LoggingLevel::ERROR, message);
}

void Logger::fatal(std::string message)
{
	this->log(LoggingLevel::FATAL, message);
}

void Logger::setFilter(LoggingLevel level)
{
	m_level = level;
}

void Logger::addFileLog(std::string filePath)
{
	this->m_ofs = new std::ofstream(filePath);
}
