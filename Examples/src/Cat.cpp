#include "Cat.h"

Cat::Cat(std::string name)
{
	m_name = name;
	m_sound = "Meow!";
}

std::string Cat::sound()
{
	std::stringstream messageSstream;
	messageSstream << "Called sound method of Cat with sound: " << m_sound;
	std::string message = messageSstream.str();
	logger->info(message);
	return m_sound;
}
