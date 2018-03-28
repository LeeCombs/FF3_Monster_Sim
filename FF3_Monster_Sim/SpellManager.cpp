#include "SpellManager.h"
#include "Utils.h"
#include <stdlib.h>
#include <random>

namespace ff3j {

    void loadData() {
        // Read spellData.json and populate things
    }

    Spell getSpellByName(std::string name) {
        // Go through spellData and find the appropriate spell
        Spell spell;
        return spell;
    }

    SpellResult castSpell(Spell spell, Monster caster, Monster target) {
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