#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\..\SuperLoggingProject\src\Logger.h"

#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(LoggerTest)
	{
	public:
		TEST_METHOD(FilterTests)
		{
			std::ostringstream* ost = new std::ostringstream();

			// TODO check result
			Sangu::Logger logger = Sangu::Logger(Sangu::LoggingLevel::INFO, ost);
			logger.trace("x");
			logger.debug("x");
			logger.info("x");
			logger.warn("x");
			logger.error("x");
			logger.fatal("x");
			std::string str = ost->str();

			Assert::IsTrue(false); // Fail
		}

	};
}