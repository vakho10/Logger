#include <sstream>

#include "..\..\SuperLoggingProject\src\Logger.h"
#include "Cat.h"

void foo(int i);

int main() {

	Sangu::Logger* logger = new Sangu::Logger();
	logger->setFilter(Sangu::LoggingLevel::TRACE);

	try
	{
		logger->setOutputStream(NULL);
		logger->info("asdf");
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//// Cat logic
	//Cat* cat = new Cat("Piso");
	//std::cout << cat->sound() << std::endl;

	//delete logger;
	//logger = NULL;

	system("pause");
}

void foo(int i) {
	std::cout << i << std::endl;
}