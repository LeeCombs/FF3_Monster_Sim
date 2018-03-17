#include "Utils.h"
#include "Spell.h"
#include "Monster.h"
#include <random>

namespace ff3j {


    int calculatePhysicalDamage(Monster attacker, Monster target) {

        //=============================================
        // 1 - Caculate Base Damage
        //=============================================
        int baseDamage = attacker.getAttack();

        //=============================================
        // 2 - Apply base damage bonus and penalties
        //=============================================

        // 2.1 - Additive Bonus
        int additiveBonus = 0;

        // 2.1.1 - Haste
        // if (attacker.hasHaste()) additiveBonus += attacker.hasteAttackBonus;
        baseDamage += additiveBonus;

        // 2.2 - Multiplicate Bonus
        int multiplicativeBonus = 0;

        // 2.2.1 - Elemental Weakness
        // if (target.isweakto(attack.element)) baseDamage *= 2;

        // 2.2.2 - Vulnerable State
        // if (target.isVunerable()) baseDamage *= 2;

        // 2.3 - Multiplicative Penatites

        // 2.3.1 - Elemental Resist
        // if (target.isresist(attack.element)) baseDamage /= 2;

        // 2.3.2 - Toad and Mini
        // if (attacker.hasStatus(Mini || Toad))) baseDamage = 0;

        //=============================================
        // 3 - Apply random range to base
        //=============================================
        baseDamage = Utils::getRandomInt(baseDamage, baseDamage * 1.5);

        //=============================================
        // 4 - Subtract target's defense
        //=============================================

        // 4.1 - Initial Defense
        int defense = target.getDefense();

        // 4.1.2 - Self-Targetting
        // if attacker is targeting ally, defense = 0;

        // 4.2 - Defense Bonuses

        // 4.2.1 - Safe Spell
        // if (target.hasSafe()) defense += target.safeDefenseBonus;

        // 4.2.2 - Defend Command
        // if (target.hasDefended()) defense *= 4;

        // 4.3 - Penalties

        // 4.3.1 - Vulnerable target
        // if (target.isVulnerable()) defense = 0;

        // 4.4 - Base Damage Calculation
        if (defense > 255)
            defense = 255;
        baseDamage -= defense;

        /// 4.5 - Misc
        // if (target.hasMini || target.hasToad) defense && multipliers = 0;


        //=============================================
        // 5 - Calculate net attack Muliplier
        //=============================================

        // 5.1 - Attack Multiplier

        // 5.1.1 - Initial Value
        int atkMult = attacker.getHits();

        // 5.1.2 - Bonuses

        // 5.1.2.1 - Haste

        // if (attacker.hasHaste()) atkMult += attacker.hasteMult;
        if (atkMult > 16)
            atkMult = 16;

        // 5.2 - Hit %

        // 5.2.1 - Initial Value
        int hitChance = attacker.getAccuracy();

        // 5.2.2 - Penalties

        // 5.2.2.1 - Backrow
        // if (physical && (attacker.IsBackRow() || target.IsBackRow()) hitChance /= 2;

        // 5.2.2.2 - Blind
        // if (attacker.hasBlind()) hit /= 2;

        // 5.3 - Defense Multiplier
        int defMult = 0;

        // 5.3.1 - Initial Value
        defMult = target.getBlocks();

        // 5.3.2 - Penalties

        // 5.3.2.1 - Vulnerable
        // if (target.isVulnerable()) defMult = 0;
        
        // 5.4 - Evade %
        int evadeChance = 0;

        // 5.4.1 - Initial Value
        evadeChance = target.getEvasion();

        // 5.5 - Net Attack Multiplier
        int netMult = Utils::rollSuccesses(atkMult, hitChance) - Utils::rollSuccesses(defMult, evadeChance);
        // if (netMult <= 0) return "Miss";

        //=============================================
        // 6 - Multiply base by net attack multipler
        //=============================================
        if (baseDamage > 255)
            baseDamage = 255;

        if (netMult > 16)
            netMult = 16;

        int finalDamage = baseDamage * netMult;

        //=============================================
        // 7 - Apply final damage bonuses/penalities
        //=============================================

        // 7.1 - Minimum Damage
        if (atkMult > 0 && finalDamage <= 0)
            finalDamage = 1;

        // 7.2 - Status Attacks
        for (int i = 0; i < netMult; i++) {
            if (Utils::getRandomInt(0, 99) <= (hitChance - evadeChance)) {
                // Successful hit
                break;
            }
        }

        //=============================================
        // 8 - Finally, return the result
        //=============================================
        return finalDamage;
    }

    int calculateSpellDamage(Monster attacker, Monster target) {

        //=============================================
        // 1 - CALCULATE BASE DAMAGE
        //=============================================

        // 1.1 - Black magic damage

        // 1.2 - White magic damage

        // 1.3 - Call magic damage

        //=============================================
        // 2 - APPLY BASE DAMAGE BONUSES AND PENALTIES
        //=============================================

        // 2.1 - Multiplicative bonus
        // 2.1.1 - Elemental Weakness
        // 2.1.2 - Targets that are toad, mini, buildup

        // 2.2 Penalties
        // 2.2.1 - Elemental resist

        //=============================================
        // 3 - APPLY RANDOM RANGE TO BASE DAMAGE
        //=============================================
       
        
        
        //=============================================
        // 4 - SUBTRACT TARGET'S DEFENSE
        //=============================================
        
        // 4.1 - Initial defense
        // 4.1.1 - Target defense
        // 4.1.2 - Self-targetting

        // 4.2 - Bonuses
        // 4.2.1 - Safe

        // 4.3 - Penalties
        // 4.3.1 - Targets that are toad, mini, buildup

        // 4.4 - Base damage calculation
        
        //=============================================
        // 5 - CALCULATE NET ATTACK MULTIPLIER
        //=============================================
        
        // 5.1 - AtkMult
        // 5.1.1 - Black magic multiplier
        // 5.1.2 - White magic multiplier
        // 5.1.3 - Call magic multiplier
        // 5.1.3 - Item multiplier
        
        // 5.2 - Hit chance
        // 5.2.1 - Initial value
        // 5.2.1.1 - Balck spell hit
        // 5.2.1.2 - White spell hit
        // 5.2.1.3 - Call spell hit
        // 5.2.1.4 - Item hit
        // 5.2.2 - Bonuses
        // 5.2.2.1 - Toad and mini on allies
        // 5.2.3 - Penalties
        // 5.2.3.1 - Blind
        // 5.2.3.2 - Kill spell

        // 5.3 - Defense multiplier
        // 5.3.1 - Initial value
        // 5.3.2 - Penalties
        // 5.3.2.1 - Target it toad or mini
        // 5.3.2.2 - Self-targetting

        // 5.4 - Evade chance
        // 5.4.1 - Initial Value

        // 5.5 - Net attack mult
        
        //=============================================
        // 6 - MULTIPLY BASE DAMAGE BY NET ATTACK MULTIPLIER
        //=============================================
        
        // final damage = base * netmult
        
        //=============================================
        // 7 - APPLY FINAL DAMAGE BONUSES AND PENALTIES
        //=============================================
        
        // 7.1 - Bonuses
        // 7.1.1 - Cure 4

        // 7.2 - Penalties
        // 7.2.1 - Multiple Targets

        // 7.3 - Minimum damage

        // 7.4 - Status Attacks

        //=============================================
        // 8 - Finally, return the result
        //=============================================

        // return finalDamage;
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