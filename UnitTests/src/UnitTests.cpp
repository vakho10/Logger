#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\..\SuperLoggingProject\src\Logger.h"

#include <sstream>
#include <string>
#include <functional>

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
			Sangu::Logger logger = Sangu::Logger(ost);
			logger.setFilter(Sangu::LoggingLevel::INFO); // Testing this method
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

		TEST_METHOD(OutputStreamTests) {
			std::ostringstream* ost = new std::ostringstream();
			Sangu::Logger logger = Sangu::Logger();
			logger.setOutputStream(ost); // Testing this method
			logger.info("x");
			logger.info("x");
			std::string str = ost->str();

			// Check number of occurrences
			int numberOfLines = std::count(str.begin(), str.end(), '\n');
			Assert::AreEqual(2, numberOfLines);
		}

		TEST_METHOD(LogMethodExceptionTest) {
			std::ostringstream* ost = new std::ostringstream();
			Sangu::Logger logger = Sangu::Logger(ost);
			
			// Expect exception
			Assert::ExpectException<std::invalid_argument>([&logger] {				
				logger.info("");
			});

			// No exception expected
			logger.info("Some text");
			Assert::IsFalse(ost->str().empty());
		}

		TEST_METHOD(SetOutputStreamExceptionTest) {
			Sangu::Logger logger = Sangu::Logger();

			// Expect exception
			Assert::ExpectException<std::invalid_argument>([&logger] {
				logger.setOutputStream(nullptr);
			});

			// No exception expected
			std::ostringstream* ost = new std::ostringstream();
			logger.setOutputStream(ost);
			logger.info("Some text");
			Assert::IsFalse(ost->str().empty());
		}

	};
}