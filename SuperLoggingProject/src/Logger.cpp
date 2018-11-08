#include "Logger.h"

Sangu::Logger::Logger() {
}

Sangu::Logger::Logger(LoggingLevel level) {
	this->setFilter(level);
}

Sangu::Logger::Logger(std::ostream* ost) {
	this->setOutputStream(ost);
}

Sangu::Logger::Logger(LoggingLevel level, std::ostream* ost) {
	this->setFilter(level);
	this->setOutputStream(ost);
}

Sangu::Logger::~Logger() {
	// Don't call delete on cout!
	if (this->ost != std::_Ptr_cout) {
		delete this->ost;
	}
	this->ost = NULL;
}

std::string Sangu::Logger::levelToString(LoggingLevel level) {
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

void Sangu::Logger::log(LoggingLevel level, std::string message) {
	if (m_level <= level) {
		*ost << "[" << levelToString(level) << "]: " << message << std::endl;
	}
}

void Sangu::Logger::trace(std::string message)
{
	this->log(LoggingLevel::TRACE, message);
}

void Sangu::Logger::debug(std::string message)
{
	this->log(LoggingLevel::DEBUG, message);
}

void Sangu::Logger::info(std::string message)
{
	this->log(LoggingLevel::INFO, message);
}

void Sangu::Logger::warn(std::string message)
{
	this->log(LoggingLevel::WARN, message);
}

void Sangu::Logger::error(std::string message)
{
	this->log(LoggingLevel::ERROR, message);
}

void Sangu::Logger::fatal(std::string message)
{
	this->log(LoggingLevel::FATAL, message);
}

void Sangu::Logger::setFilter(LoggingLevel level)
{
	m_level = level;
}

void Sangu::Logger::setOutputStream(std::ostream* ost)
{
	this->ost = ost;
}
