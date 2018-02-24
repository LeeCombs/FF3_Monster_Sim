#include "stdafx.h"
#include "CppUnitTest.h"
#include "Spell.h"
#include "../FF3_Monster_Sim/Spell.cpp"
#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::placeholders;

namespace UnitTest
{		
	TEST_CLASS(SpellTest)
	{
	public:
		
		TEST_METHOD(GetterSetterTest)
		{
			// Ensure expected behavior
			ff3j::Spell spell;

			// Power
			Assert::AreEqual(0, (int)spell.getPower());
			spell.setPower(10);
			Assert::AreEqual(10, (int)spell.getPower());
			spell.setPower(0);
			Assert::AreEqual(0, (int)spell.getPower());
			spell.setPower(255);
			Assert::AreEqual(255, (int)spell.getPower());
			spell.setPower(256);
			Assert::AreEqual(0, (int)spell.getPower());

			// Accuracy
			Assert::AreEqual(0, (int)spell.getAccuracy());
			spell.setAccuracy(10);
			Assert::AreEqual(10, (int)spell.getAccuracy());
			spell.setAccuracy(0);
			Assert::AreEqual(0, (int)spell.getAccuracy());
			spell.setAccuracy(255);
			Assert::AreEqual(255, (int)spell.getAccuracy());
			spell.setAccuracy(256);
			Assert::AreEqual(0, (int)spell.getAccuracy());

			// Level
			Assert::AreEqual(0, (int)spell.getLevel());
			spell.setLevel(10);
			Assert::AreEqual(10, (int)spell.getLevel());
			spell.setLevel(0);
			Assert::AreEqual(0, (int)spell.getLevel());
			spell.setLevel(255);
			Assert::AreEqual(255, (int)spell.getLevel());
			spell.setLevel(256);
			Assert::AreEqual(0, (int)spell.getLevel());
			
			// TODO:
			// Name
			// Reflectable
			// SpellType
			// Target
			// Elements
		}

		TEST_METHOD(GetterSetterTest)
		{
			//
		}

	private:
		//
	};
}
