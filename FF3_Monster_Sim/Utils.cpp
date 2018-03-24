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
        Element arr[3];
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

        // 4.1.2 - Self-Targetting
        // if atkr is targeting ally, defense = 0;

        // Apply bonuses (safe and defense command)

        // 4.2.1 - Safe Spell
        defense += target.getSafeBonus();

        // 4.2.2 - Defend Command
        // if (target.hasDefended()) defense *= 4;

        // Penalties

        // 4.3.1 - Vulnerable target
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
        // if (physical && (atkr.IsBackRow() || target.IsBackRow()) hitChance /= 2;

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

    int calculateSpellDamage(Spell spell, Monster atkr, Monster target) {

        //=============================================
        // 1 - CALCULATE BASE DAMAGE
        //=============================================
        int baseDamage = spell.getPower();

        switch (spell.getType()) {
            case SpellType::black:
                baseDamage += atkr.getIntellect() / 2;
                break;
            case SpellType::white:
                // TODO: Non-offensive white magic skips this step
                baseDamage += atkr.getMind() / 2;
                break;
            case SpellType::summon:
                baseDamage += atkr.getIntellect();
                break;
            default:
                // Error
                break;
        }

        //=============================================
        // 2 - APPLY BASE DAMAGE BONUSES AND PENALTIES
        //=============================================

        // 2.1 - Multiplicative bonus

        // 2.1.1 - Elemental Weakness
        // if (target.isWeakTo(spell.elements)) baseDamage *= 2;

        // 2.1.2 - Targets that are toad, mini, buildup
        // if (target.hasStatus(Toad || Mini || Buildup)) baseDamage *= 2;

        // 2.2 Penalties
        // 2.2.1 - Elemental resist
        // if (target.isResistantTo(spell.elements)) baseDamage /= 2;

        //=============================================
        // 3 - APPLY RANDOM RANGE TO BASE DAMAGE
        //=============================================
       
        baseDamage = Utils::getRandomInt(baseDamage, baseDamage * 1.5);
        
        //=============================================
        // 4 - SUBTRACT TARGET'S DEFENSE
        //=============================================
        
        // 4.1 - Initial defense
        int mDef = target.getMagicDefense();

        // 4.1.1 - Self-targetting
        // if (atkr == target || target.isAllyTo(atkr)) mDef = 0;

        // 4.2 - Bonuses
        // 4.2.1 - Safe
        // mDef += target.getSafeValue();

        // 4.3 - Penalties
        // 4.3.1 - Targets that are toad, mini, buildup
        // if (target.hasStatus(Mini || Toad || Buildup)) mDef = 0;

        // 4.4 - Base damage calculation
        baseDamage -= mDef;
        
        //=============================================
        // 5 - CALCULATE NET ATTACK MULTIPLIER
        //=============================================

        // 
        // AtkMult and Hit chance
        //
        int atkMult = 1;
        int hitChance = spell.getAccuracy();

        switch (spell.getType()) {
            case SpellType::black:
            case SpellType::terrain:
                atkMult += (atkr.getIntellect() / 16) + (atkr.getLevel() / 16) + (atkr.getJobLevel() / 32);
                hitChance += atkr.getIntellect() / 2;
                break;
            case SpellType::white:
                atkMult += (atkr.getMind() / 16) + (atkr.getLevel() / 16) + (atkr.getJobLevel() / 32);
                hitChance += atkr.getMind() / 2;
                break;
            case SpellType::summon:
                atkMult += (atkr.getIntellect() / 8) + (((atkr.getJobLevel() / 8)*3)/2);
                hitChance += atkr.getIntellect();
                break;
            case SpellType::item:
                // atkMult is pre-determined by the item
                hitChance = 100;
                break;
            default:
                // Error
                break;
        }

        // Toad, Mini, and Life spells always hit allies
        // if (spell == (Toad || Mini || Life || Life2) && target.isAllyTo(atkr)) hitChance = 100;

        // If atkr is blind and not using an item, halve hit
        if ((spell.getType() != SpellType::item) && atkr.hasStatus(Status::blind))
            hitChance = hitChance / 2;

        // Kill spell misses if the target is too high level
        if (target.getLevel() >= (((atkr.getLevel()/2)*3)/2))
            hitChance = 0;

        //
        // 5.3 - Defense multiplier
        //
        int defMult = target.getMagicBlocks();

        // 5.3.1 - Penalties
        // 5.3.1.1 - Target it toad or mini
        // if (target.hasStatus(Mini || Toad || Buildup)) defMult = 0;
        Status penaltyStatuses[2] = { Status::mini, Status::toad }; // TODO: Buildup
        if (target.hasStatus(penaltyStatuses, 2))
            defMult = 0;

        // 5.3.1.2 - Self-targetting
        // if (atkr == target || target.isAllyTo(atkr)) defMult = 0;

        // 5.4 - Evade chance
        int mEvade = target.getMagicResistance();

        // 5.5 - Net attack mult
        int netMult = Utils::rollSuccesses(atkMult, hitChance) - Utils::rollSuccesses(defMult, mEvade);
        // if (netMult <= 0) return "Ineffective";
        // if (terrain  && missAllTargets()) return "BackFire";
        
        //=============================================
        // 6 - MULTIPLY BASE DAMAGE BY NET ATTACK MULTIPLIER
        //=============================================
        
        // final damage = base * netmult
        int finalDamage = baseDamage * netMult;
        
        //=============================================
        // 7 - APPLY FINAL DAMAGE BONUSES AND PENALTIES
        //=============================================
        
        // 7.1 - Bonuses
        // 7.1.1 - Cure 4
        // if (spell == "Cure4" && !multiTargetting)) target.healFull();
        // else continue on as normal

        // 7.2 - Penalties
        // 7.2.1 - Multiple Targets
        // finalDamage = finalDamage / targetCount;
        // Does NOT apply to auto-all targetting spells (Quake, Meteo, Call spells...)

        // 7.3 - Minimum Damage
        if (atkMult > 0 && finalDamage <= 0)
            finalDamage = 1;

        // 7.4 - Status Attacks
        for (int i = 0; i < netMult; i++) {
            if (Utils::getRandomInt(0, 99) <= (hitChance - mEvade)) {
                // Successful hit
                break;
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