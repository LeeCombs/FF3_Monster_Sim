#include "stdafx.h"
#include "CppUnitTest.h"
#include "../FF3_Monster_Sim/Monster.h"
#include "../FF3_Monster_Sim/Monster.cpp"
#include "../FF3_Monster_Sim/Utils.h"
#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::placeholders;
using namespace std;
using namespace ff3j;

namespace UnitTest {
    TEST_CLASS(MonsterTest) {
    public:

        TEST_METHOD(GetterSetterTest) {
            // Ensure getters and setters act as expected
            Monster mon;

            // This is going to suck
        }

        TEST_METHOD(StatDefaults) {
            // Ensure a monster has certain default stats
            Monster mon;

            Assert::IsTrue("DEFAULT NAME" == mon.getName());
            Assert::AreEqual(0, (int)mon.getId());
            Assert::AreEqual(0, (int)mon.getLevel());
            Assert::AreEqual(0, (int)mon.getExp());
            Assert::AreEqual(0, (int)mon.getGil());
            Assert::IsTrue(MonsterType::none == mon.getMonsterType());
            Assert::IsFalse(mon.getIsBoss());
            Assert::AreEqual(0, (int)mon.getHP());
            Assert::AreEqual(0, (int)mon.getJobLevel());
            Assert::AreEqual(0, (int)mon.getIntellect());
            Assert::AreEqual(0, (int)mon.getMind());
            Assert::AreEqual(0, (int)mon.getAttack());
            Assert::AreEqual(0, (int)mon.getHits());
            Assert::AreEqual(0, (int)mon.getAccuracy());
            Assert::AreEqual(0, (int)mon.getDefense());
            Assert::AreEqual(0, (int)mon.getBlocks());
            Assert::AreEqual(0, (int)mon.getEvasion());
            Assert::AreEqual(0, (int)mon.getMagicDefense());
            Assert::AreEqual(0, (int)mon.getMagicBlocks());
            Assert::AreEqual(0, (int)mon.getMagicResistance());
            Assert::IsTrue(Status::none == mon.getAttackStatus());
            Assert::IsTrue(mon.getAttackElements().empty());
            Assert::IsTrue(mon.getResistances().empty());
            Assert::IsTrue(mon.getWeaknesses().empty());
            Assert::IsTrue(mon.getStatusImmunities().empty());
        }

        TEST_METHOD(LoadMonsterTest) {
            // Load a known monster from data and ensure its stats loaded properly
        }

        TEST_METHOD(StatusTest) {
            // Ensure a standard enemy with no immunities
            Monster mon;
            Assert::IsFalse(mon.hasStatus(Status::blind));
            Assert::IsTrue(mon.addStatus(Status::blind));
            Assert::IsFalse(mon.addStatus(Status::blind));
            Assert::IsTrue(mon.hasStatus(Status::blind));
            mon.removeStatus(Status::blind);
            Assert::IsFalse(mon.hasStatus(Status::blind));

            // TODO: Load a monster with blind immunity and ensure it cannot be added
            // TODO: Load a boss monster and ensure no status effects can be added
        }

    private:
        //
    };
}
