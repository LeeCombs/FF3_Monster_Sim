#include "stdafx.h"
#include "CppUnitTest.h"
#include "Spell.h"
#include "../FF3_Monster_Sim/Spell.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			ff3j::Spell spell;
			spell.setPower(0);
			Assert::AreEqual(0, spell.getPower());
			spell.setPower(256);
			Assert::AreEqual(0, spell.getPower());
		}
	};
}
