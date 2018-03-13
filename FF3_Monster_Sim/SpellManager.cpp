#include "SpellManager.h"
#include "Utils.h"
#include <stdlib.h>
#include <random>

namespace ff3j {

    int GetDamage(Spell spell) {
        // Calculate damage

        /* TODO:
         * This needs to be run through the planning process as there is
         * like 100 things happening here from a bunch of different sources.
         */

        //=============================================
        // 1 - Get Base Damage
        //=============================================
        int baseDamage = spell.getPower();

        //=============================================
        // 2 - Apply base damage bonus and penalties
        //=============================================
        // baseDamage = (baseDamage + additiveBonuses) * multiplicativeBonuses
        // if (actor.hasStatus(Mini || Toad)) && physical)
        // - baseDamage = 0;

        //=============================================
        // 3 - Apply random range to base
        //=============================================
        baseDamage = Utils::getRandomInt(baseDamage, baseDamage * 1.5);

        //=============================================
        // 4 - Subtract target's defense
        //=============================================
        Monster target;
        // baseDamage -= target.getMagicDefense();

        //=============================================
        // 5 - Get net attack Muliplier
        //=============================================
        int totalHits = 0;
        // totalHits = Actor.RollHits() - Target.RollBlocks()
        
        // If kill spell...
        // - if (target.level) >= (((attacker.level)/2)*3)/2)
        // -- magicHit = 0;

        // Toad, Mini, Life, Life2
        // 100% accuracy against team, normal against enemies

        // if (physical && (attacker.IsBackRow() || target.IsBackRow())
        // - hit% = hit% / 2;

        //=============================================
        // 6 - Multiply base by net attack multipler
        //=============================================
        int finalDamage = baseDamage * totalHits;

        //=============================================
        // 7 Apply final damage bonuses/penalities
        //=============================================
        // finalDamage = finalDamage * (fdBonuses)

        return finalDamage;
    }

    void loadData() {
        // Read spellData.json and populate things
    }

    Spell getSpellByName(std::string name) {
        // Go through spellData and find the appropriate spell
        Spell spell;
        return spell;
    }

    SpellResult castSpell(Monster caster, Monster target) {
        SpellResult res;
        res.damage = 0;
        res.results.push_back("1");
        res.results.push_back("two");
        res.results.push_back("C");
        res.results.push_back("IV");
        return res;
    }

    std::unordered_set<std::string> getSpellNames() {
        // Go through spellData and return a list of names found
        std::unordered_set<std::string> names;
        names.insert("Name");
        return names;
    }
}
