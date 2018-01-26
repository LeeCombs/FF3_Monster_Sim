#include "stdafx.h"
#include "CppUnitTest.h"
#include "Monster.h"
#include "../FF3_Monster_Sim/Monster.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Monster mon;
			Assert::AreEqual(75, mon.size);
		}
	};
}
