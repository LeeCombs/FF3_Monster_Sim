#include "Utils.h"
#include "Spell.h"
#include "Monster.h"
#include <random>

namespace ff3j {


    int calculatePhysicalDamage(Monster atkr, Monster target) {

        //=============================================
        // Determine base damage
        //=============================================

        int baseDamage = atkr.getAttack() + atkr.getHasteDmgBonus();

        // Apply bonuses (elemental weakness and vulnerable)
        if (target.isWeakTo(atkr.getAttackElements()))
            baseDamage *= 2;

        if (target.isVulnerable())
            baseDamage *= 2;

        // Apply penalities (elemental resistance and toad/mini)
        if (target.isResistantTo(atkr.getAttackElements()))
            baseDamage = baseDamage / 2;
        if (atkr.hasStatus(Status::mini) || atkr.hasStatus(Status::toad))
            baseDamage = 0;

        // Apply random range to base damage
        baseDamage = Utils::getRandomInt(baseDamage, baseDamage * 1.5);

        //=============================================
        // Subtract target's defense
        //=============================================

        int defense = target.getDefense();

        // Aly or self-Targetting
        // defense = 0;

        // Apply bonuses (safe and defense command)
        defense += target.getSafeBonus();
        // if (target.hasDefended()) defense *= 4;

        // Apply penalties (vulnerable)
        if (target.isVulnerable())
            defense = 0;

        baseDamage -= defense;

        //=============================================
        // Calculate net attack Muliplier
        //=============================================

        // Determine attacker's attack multiplier and hit chance
        int atkMult = atkr.getHits() + atkr.getHasteHitBonus();
        int hitChance = atkr.getAccuracy();

        // Enforce a 16-hit cap
        if (atkMult > 16)
            atkMult = 16;

        // Apply Penalties (back row and blind)
        // if (atkr.IsBackRow() || target.IsBackRow()) hitChance /= 2;

        if (atkr.hasStatus(Status::blind))
            hitChance = hitChance / 2;

        // Determine target's defense multiplier
        int defMult = target.getBlocks();
        int evadeChance = target.getEvasion();

        if (target.isVulnerable())
            defMult = 0;

        // Determine the net attack multiplier
        int netMult = Utils::rollSuccesses(atkMult, hitChance) - Utils::rollSuccesses(defMult, evadeChance);
        // if (netMult <= 0) return "Miss";

        //=============================================
        // Calculate final damage
        //=============================================
        if (baseDamage > 255)
            baseDamage = 255;

        int finalDamage = baseDamage * netMult;

        // Minimum Damage
        if (atkMult > 0 && finalDamage <= 0)
            finalDamage = 1;

        // Attempt to apply status effects if the attack has them
        if (atkr.getAttackStatus() != Status::none) {
            for (int i = 0; i < netMult; i++) {
                if (Utils::getRandomInt(0, 99) <= (hitChance - evadeChance)) {
                    // Successful hit
                    // TODO: Apply appropriate status based on attackStatus
                    break;
                }
            }
        }

        // Finally, return the result
        return finalDamage;
    }

    int calculateSpellDamage(Spell spell, Monster atkr, Monster target, int targetCount) {

        //=============================================
        // Determine base damage
        //=============================================

        int baseDamage = spell.getPower();

        switch (spell.getType()) {
            case SpellType::black:
                baseDamage += atkr.getIntellect() / 2;
                break;
            case SpellType::whiteOffensive:
                baseDamage += atkr.getMind() / 2;
                break;
            case SpellType::whiteBuff:
                // Buffs get no additional damage
                break;
            case SpellType::call:
                baseDamage += atkr.getIntellect();
                break;
            default:
                // Error
                break;
        }

        // Apply bonuses (elemental weakness, toad/mini/etc)
        if (target.isWeakTo(spell.getElements()))
            baseDamage *= 2;

        if (target.isVulnerable())
            baseDamage *= 2;

        // Apply penalties (elemental resistance)
        if (target.isResistantTo(spell.getElements()))
            baseDamage = baseDamage / 2;

        // Apply random range to base damage
        baseDamage = Utils::getRandomInt(baseDamage, baseDamage * 1.5);
        
        //=============================================
        // Subtract target's defense
        //=============================================
        
        int mDef = target.getMagicDefense();

        // Ally or self-targetting
        // if atkr is targeting ally, defense = 0;

        // Apply bonuses (safe) and penalities (vulnerable)
        mDef += target.getSafeBonus();
        if (target.isVulnerable())
            mDef = 0;

        baseDamage -= mDef;
        
        //=============================================
        // Calculate net attack Muliplier
        //=============================================

        // Determine attacker's attack multiplier and hit chance
        int atkMult = 1;
        int hitChance = spell.getAccuracy();

        switch (spell.getType()) {
            case SpellType::black:
            case SpellType::terrain:
                atkMult += (atkr.getIntellect() / 16) + (atkr.getLevel() / 16) + (atkr.getJobLevel() / 32);
                hitChance += atkr.getIntellect() / 2;
                break;
            case SpellType::whiteOffensive:
            case SpellType::whiteBuff: // TODO: Ensure whiteBuff is actually included here, and not ignored
                atkMult += (atkr.getMind() / 16) + (atkr.getLevel() / 16) + (atkr.getJobLevel() / 32);
                hitChance += atkr.getMind() / 2;
                break;
            case SpellType::call:
                atkMult += (atkr.getIntellect() / 8) + (((atkr.getJobLevel() / 8)*3)/2);
                hitChance += atkr.getIntellect();
                break;
            case SpellType::item:
                // TODO: atkMult is pre-determined by the item
                hitChance = 100;
                break;
            default:
                // Error
                break;
        }

        // Enforce a 16-hit cap
        if (atkMult > 16)
            atkMult = 16;

        // Toad, Mini, and Life spells always hit allies
        // if (spell == (Toad || Mini || Life || Life2) && target.isAllyTo(atkr)) hitChance = 100;

        // If atkr is blind and not using an item, halve hit
        if ((spell.getType() != SpellType::item) && atkr.hasStatus(Status::blind))
            hitChance = hitChance / 2;

        // Kill spell misses if the target is too high level
        if (target.getLevel() >= (((atkr.getLevel()/2)*3)/2))
            hitChance = 0;

        // Determine target's defense multiplier
        int defMult = target.getMagicBlocks();
        int mEvade = target.getMagicResistance();

        // Apply penalties (vulnerable)
        if (target.isVulnerable())
            defMult = 0;
        // TODO: Is evade chance included here?

        // Ally or self-targetting
        // if (atkr == target || target.isAllyTo(atkr)) defMult = 0;

        // Determine the net attack multiplier
        int netMult = Utils::rollSuccesses(atkMult, hitChance) - Utils::rollSuccesses(defMult, mEvade);
        // if (netMult <= 0) return "Ineffective";
        // if (terrain  && missAllTargets()) return "BackFire";

        //=============================================
        // Calculate final damage
        //=============================================

        if (baseDamage > 255)
            baseDamage = 255;
        
        int finalDamage = baseDamage * netMult;
        
        // Cure 4 - Full heals target is casting as single-target, otherwise continue normally
        // if (spell == "Cure4" && !multiTargetting)) target.healFull();

        // Penalties (Multiple targets, does not apply to all-targgeting spells (Quake, Meteo, Call...)
        // if (spell.targetting() != "AE" || "AA") finalDamage = finalDamage / targetCount;

        // Minimum Damage
        if (atkMult > 0 && finalDamage <= 0)
            finalDamage = 1;

        // Attempt to apply status effects if the spell has them
        if (!spell.getStatuses().empty()) {
            for (int i = 0; i < netMult; i++) {
                if (Utils::getRandomInt(0, 99) <= (hitChance - mEvade)) {
                    // Successful hit
                    // TODO: Apply appropriate status
                    break;
                }
            }
        }

        // Finally, return the result
        return finalDamage;
    }
}

namespace Utils {
	//============================
	// Get a random number between min and max (inclusive)
	//============================
	int getRandomInt(int min, int max) {
		std::uniform_int_distribution<int> distr(min, max + 1);
		return distr(mt);
	}


    //============================
    // Calculate number of successes of 
    // a given  number of rolls and odds
    //============================
    int rollSuccesses(int rolls, int successRate) {
        int successes = 0;
        for (int i = 0; i < rolls; i++)
            if (Utils::getRandomInt(0, 99) <= successRate)
                successes++;
        return successes;
    }

}