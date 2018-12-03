#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LottoTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(sixNumbers)
		{
			assert(myNumbers.size() == 6);
		}

		TEST_METHOD(noDups)
		{
			std::sort(myNumbers.begin(), myNumbers.end());
			assert(std::unique(myNumbers.begin(), myNumbers.end()) == myNumbers.end());
		}

		TEST_METHOD(boundsHigh)
		{
			for (int i = 0; i < myNumbers.size(); i++)
				assert(myNumbers[i] < 48);
		}

		TEST_METHOD(boundsLow)
		{
			for (int i = 0; i < myNumbers.size(); i++)
				assert(myNumbers[i] > 0);
		}

	private:
		std::vector<int> myNumbers = { 1, 2, 3, 4, 5, 6 };

	};
}