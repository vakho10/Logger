#include <sstream>

#include "..\..\SuperLoggingProject\src\Logger.h"
#include "Cat.h"

int main() {

	Sangu::Logger* logger = new Sangu::Logger();
	logger->setFilter(Sangu::LoggingLevel::TRACE);

	// Cat logic
	Cat* cat = new Cat("Piso");
	std::cout << cat->sound() << std::endl;

	delete logger;
	logger = NULL;
	
	system("pause");
}