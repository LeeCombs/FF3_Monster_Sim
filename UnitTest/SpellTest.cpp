#include "stdafx.h"
#include "CppUnitTest.h"
#include "Spell.h"
#include "../FF3_Monster_Sim/Spell.cpp"
#include <functional>
#include "Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::placeholders;

using namespace ff3j;

namespace UnitTest
{		
	TEST_CLASS(SpellTest)
	{
	public:
		
		TEST_METHOD(GetterSetterTest)
		{
			// Ensure getters and setters act as expected
			Spell spell;

			// Power
			spell.setPower(10);
			Assert::AreEqual(10, (int)spell.getPower());
			spell.setPower(0);
			Assert::AreEqual(0, (int)spell.getPower());
			spell.setPower(255);
			Assert::AreEqual(255, (int)spell.getPower());
			spell.setPower(256);
			Assert::AreEqual(0, (int)spell.getPower());

			// Accuracy
			spell.setAccuracy(10);
			Assert::AreEqual(10, (int)spell.getAccuracy());
			spell.setAccuracy(0);
			Assert::AreEqual(0, (int)spell.getAccuracy());
			spell.setAccuracy(255);
			Assert::AreEqual(255, (int)spell.getAccuracy());
			spell.setAccuracy(256);
			Assert::AreEqual(0, (int)spell.getAccuracy());

			// Level
			spell.setLevel(10);
			Assert::AreEqual(10, (int)spell.getLevel());
			spell.setLevel(0);
			Assert::AreEqual(0, (int)spell.getLevel());
			spell.setLevel(255);
			Assert::AreEqual(255, (int)spell.getLevel());
			spell.setLevel(256);
			Assert::AreEqual(0, (int)spell.getLevel());
			
			// Name
			spell.setName("Name");
			Assert::IsTrue(spell.getName() == "Name");

			// Reflectable
			spell.setReflectable(true);
			Assert::IsTrue(spell.getReflectable());
			spell.setReflectable(false);
			Assert::IsFalse(spell.getReflectable());

			// SpellType
			spell.setType(SpellType::black);
			Assert::IsTrue(SpellType::black == spell.getType());

			// Target
			spell.setTarget(Target::enemy);
			Assert::IsTrue(Target::enemy == spell.getTarget());

			// Elements
			unordered_set<Element> expectedElements = { Element::air, Element::dark };
			spell.setElements(expectedElements);
			Assert::IsTrue(expectedElements == spell.getElements());


			// TODO:
			// Effects
		}

		TEST_METHOD(SpellDefaults)
		{
			// Ensure defaults are expected values
			Spell spell;

			Assert::AreEqual(0, (int)spell.getPower());
			Assert::AreEqual(0, (int)spell.getAccuracy());
			Assert::AreEqual(0, (int)spell.getLevel());
			Assert::IsFalse(spell.getReflectable());
			Assert::IsTrue(Utils::SetContains<Element>(spell.getElements(), Element::none));
		}

	private:
		//
	};
}