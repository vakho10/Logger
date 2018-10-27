#include "Logger.h"
#include "Cat.h"

int main() {

	Logger* logger = new Logger();
	logger->setFilter(LoggingLevel::TRACE);
	logger->addFileLog("resources\\log.txt");

	// Cat logic
	Cat* cat = new Cat("Piso");
	std::cout << cat->sound() << std::endl;

	delete logger;
	logger = NULL;

	system("PAUSE");
}