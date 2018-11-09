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

		/*
			1) Set level to INFO
			2) Print each level of logs into the string stream
			3) Read string stream and check if new lines are exactly four
		*/
		TEST_METHOD(FilterTests)
		{
			std::ostringstream* ost = new std::ostringstream();
			Sangu::Logger logger = Sangu::Logger(Sangu::LoggingLevel::INFO, ost);
			logger.trace("x");
			logger.debug("x");
			logger.info("x");
			logger.warn("x");
			logger.error("x");
			logger.fatal("x");
			std::string str = ost->str();

			// Check number of occurrences
			int numberOfLines = std::count(str.begin(), str.end(), '\n');
			Assert::AreEqual(4, numberOfLines);
		}

	};
}