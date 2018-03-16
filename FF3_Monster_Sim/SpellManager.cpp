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

        // Calculate hit chance, damage, and multiplier

        // TODO: Toad, Mini, Life, Life2 have 100% to hit on allies
        int hitChance = spell.getAccuracy();
        int damage = spell.getPower();
        int magicAtkMult = 1;
        switch (spell.getType()) {
            case SpellType::black:
            case SpellType::terrain:
                hitChance += caster.getIntellect() / 2;
                damage += caster.getIntellect() / 2;
                magicAtkMult += (caster.getIntellect() / 16) + (caster.getLevel() / 16) + (caster.getJobLevel() / 32);
                break;
            case SpellType::white:
                hitChance += caster.getMind() / 2;
                // TODO: Non-offensive white spells ignore this step (Cure, Haste, Safe)
                damage += caster.getMind() / 2;
                magicAtkMult += (caster.getMind() / 16) + (caster.getLevel() / 16) + (caster.getJobLevel() / 32);
                break;
            case SpellType::summon:
                hitChance += caster.getIntellect();
                damage += caster.getIntellect();
                magicAtkMult += (caster.getIntellect() / 8) + (((caster.getJobLevel() / 8)*3)/2);
                break;
            case SpellType::item:
                hitChance = 100;
                // lookup magicAtkMult
                break;
            default:
                // TODO: How to handle Item and Ability types
                // Item should always have 100%
                break;
        }



        return res;
    }

    std::unordered_set<std::string> getSpellNames() {
        // Go through spellData and return a list of names found
        std::unordered_set<std::string> names;
        names.insert("Name");
        return names;
    }
}
