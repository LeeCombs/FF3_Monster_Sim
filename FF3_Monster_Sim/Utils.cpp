#include "Utils.h"
#include "Spell.h"
#include "Monster.h"
#include <random>

namespace ff3j {


    int calculateDamage(Monster attacker, Monster target) {
        // Calculate damage

        /* TODO:
        * This needs to be run through the planning process as there is
        * like 100 things happening here from a bunch of different sources.
        */

        // if (target.hasWall() && target.isenemyteam) 
        //      pick a target on attacker's team, and roll as if attacking ally
        //      target.removeWall()

        bool isPhysical = false;
        int attackDamage = 0; // Spell power or Attacker power

        //=============================================
        // 1 - Get Base Damage
        //=============================================
        int baseDamage = attackDamage;

        //=============================================
        // 2 - Apply base damage bonus and penalties
        //=============================================
        int additiveBonuses = 0;
        int multiplicativeBonuses = 0; // Or penalities

        baseDamage = (baseDamage + additiveBonuses) * multiplicativeBonuses;

        // if (Target.IsBuildingUp()) baseDamage *= 2 (except non-offensive white)
        // if (actor.hasCheer()) baseDamage += 10 * cheerStacks;
        // if (actor.hasHaste()) baseDamage += hasteDamage

        // if (target.isweakto(attack.element)) baseDamage *= 2;
        // if (target.isresist(attack.element)) baseDamage /= 2;
        // if (target.hasStatus(Mini || Toad)) baseDamage *= 2; Not non-offensive white

        // if (actor.hasStatus(Mini || Toad)) && physical) baseDamage = 0;

        //=============================================
        // 3 - Apply random range to base
        //=============================================
        baseDamage = Utils::getRandomInt(baseDamage, baseDamage * 1.5);

        //=============================================
        // 4 - Subtract target's defense
        //=============================================
        int defense = 0;
        // If spell, get magicDefense
        // If physical, get defense

        // if (targetting.self() && physical) defense = 0;
        // if (targetting.ally()) magicDefense = 0; magicDefenseMult = 0;
        
        // if (target.hasMini || target.hasToad) defense && multipliers = 0;

        // if (target.hassafe()) defense += safeDefense; magicDefense += safeDefense;
        
        // Defense command: defense *= 4;
        // Buildup command: defense = 0, defenseMult = 0, magicDefense = 0;

        if (defense > 255)
            defense = 255;

        baseDamage -= defense;

        //=============================================
        // 5 - Calculate net attack Muliplier
        //=============================================
        int atkMult = 0;

        // if (attacker.hasBlind()) hit /= 2; magicHit /= 2;
        
        // if (physical) totalHits = calculateTotalHits(attacker) - calculateTotalBlocks(target);
        // if (spell) totalHits = calculateTotalSpellHits(spell) - calculateTotalMagicBlocks(target);

        // If kill spell...
        // - if (target.level >= ((attacker.level/2)*3)/2) magicHit = 0;

        // Toad, Mini, Life, Life2
        // 100% accuracy against team, normal against enemies

        // if (physical && actor.hashaste()) atkMult += hasteMult;

        // if (physical && (attacker.IsBackRow() || target.IsBackRow()) hit /= 2;

        // if (spell==whitewind && hits) target.hp = (spell.power...spell.power * 2) return;

        //=============================================
        // 6 - Multiply base by net attack multipler
        //=============================================
        if (baseDamage > 255)
            baseDamage = 255;

        if (atkMult > 16)
            atkMult = 16;

        int finalDamage = baseDamage * atkMult;

        // if (spell==haste) target.addHaste(finalDamage, atkMult)
        // if (spell==safe) target.addSafe(finalDamage)

        //=============================================
        // 7 Apply final damage bonuses/penalities
        //=============================================
        int fdBonus = 1;

        // If manually multi-targetting, finalDamage /= numTargets
        // This does not apply to spells that always hit all targets

        // Jump command: fdBonus = 3;
        // Buildup command: (1) fdBonus = 2; (2) fdBonus = 3; (3) Overload, halve caster hp

        finalDamage = finalDamage * fdBonus;

        // If there's a hit, the minimum damage is always 1
        if (atkMult > 0 && finalDamage <= 0) finalDamage = 1;

        return finalDamage;
    }


    int calculateTotalHits(Monster mon) {
        int totalHits = 0;
        for (int i = 0; i < mon.getHits(); i++)
            if (Utils::getRandomInt(0, 99) < mon.getAccuracy())
                totalHits++;
        return totalHits;
    }

    int calculateTotalSpellHits(Spell spell) {
        int totalHits = 0;
        for (int i = 0; i < spell.getLevel(); i++)
            if (Utils::getRandomInt(0, 99) < spell.getAccuracy())
                totalHits++;
        return totalHits;
    }

    int calculateTotalBlocks(Monster mon) {
        int totalBlocks = 0;
        for (int i = 0; i < mon.getBlocks(); i++)
            if (Utils::getRandomInt(0, 99) < mon.getEvasion())
                totalBlocks++;
        return totalBlocks;
    }

    int calculateTotalMagicBlocks(Monster mon) {
        int totalBlocks = 0;
        for (int i = 0; i < mon.getMagicBlocks(); i++)
            if (Utils::getRandomInt(0, 99) < mon.getMagicResistance())
                totalBlocks++;
        return totalBlocks;
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
}