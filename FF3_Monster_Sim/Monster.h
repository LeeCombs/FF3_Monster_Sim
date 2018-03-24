#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include "Enums.h"

namespace ff3j {

    enum class MonsterType {
        Undead, Dividing
    };

    class Monster {

    public:
        Monster();
        ~Monster();

        //=================================
        // Publics 
        //=================================

        bool hasStatus(const Status &s);
        bool hasStatus(Status[], const int length);
        bool isWeakTo(const Element &e);
        bool isWeakTo(Element[], const int length);
        bool isWeakTo(const std::unordered_set<Element> &eSet);
        bool isResistantTo(const Element &e);
        bool isResistantTo(Element[], const int length);
        bool isResistantTo(const std::unordered_set<Element> &eSet);

        // Return whether or not the monster has a status that makes it vulnerable
        // These include Mini, Toad, and Buildup (in specific cases)
        bool isVulnerable();

        //=================================
        // Setters 
        //=================================

        void setName(std::string);
        void setHP(unsigned short);
        void setId(unsigned char);
        void setLevel(unsigned char);
        void setExp(unsigned char);
        void setGil(unsigned char);
        void setJobLevel(unsigned char);
        void setIntellect(unsigned char);
        void setMind(unsigned char);
        void setAttack(unsigned char);
        void setHits(unsigned char);
        void setAccuracy(unsigned char);
        void setDefense(unsigned char);
        void setBlocks(unsigned char);
        void setEvasion(unsigned char);
        void setMagicDefense(unsigned char);
        void setMagicBlocks(unsigned char);
        void setMagicResistance(unsigned char);
        void setAttackStatus(Status);
        void setAttackElements(std::unordered_set<Element>);

        // In battle
        void setHasteDmgBonus(unsigned char);
        void setHasteHitBonus(unsigned char);
        void setSafeBonus(unsigned char);

        //=================================
        // Getters 
        //=================================

        // Combat stats
        std::string getName();
        unsigned short getHP();
        unsigned char getId();
        unsigned char getLevel();
        unsigned char getExp();
        unsigned char getGil();
        unsigned char getJobLevel();
        unsigned char getIntellect();
        unsigned char getMind();
        unsigned char getAttack();
        unsigned char getHits();
        unsigned char getAccuracy();
        unsigned char getDefense();
        unsigned char getBlocks();
        unsigned char getEvasion();
        unsigned char getMagicDefense();
        unsigned char getMagicBlocks();
        unsigned char getMagicResistance();
        Status getAttackStatus();
        std::unordered_set<Element> getAttackElements();

        // In battle
        unsigned char getHasteDmgBonus();
        unsigned char getHasteHitBonus();
        unsigned char getSafeBonus();

    protected:
        //

    private:
        std::string name;
        unsigned char id;
        unsigned char level;
        unsigned short exp;
        unsigned short gil;
        std::string monsterType;
        bool isBoss;

        //=================================
        // Combat stats
        //=================================
        unsigned short hp;
        unsigned char jobLevel;
        unsigned char intellect;
        unsigned char mind;
        unsigned char attack;
        unsigned char hits;
        unsigned char accuracy;
        unsigned char defense;
        unsigned char blocks;
        unsigned char evasion;
        unsigned char magicDefense;
        unsigned char magicBlocks;
        unsigned char magicResistance;
        Status attackStatus;
        std::unordered_set<Element> attackElements;
        std::unordered_set<Element> resistances;
        std::unordered_set<Element> weaknesses;
        std::unordered_set<Status> statusImmunities;
        std::vector<std::string> moveset;

        //=================================
        // In combat
        //=================================
        std::unordered_set<Status> statuses;
        unsigned char petrifyTracker;

        unsigned char hasteDmgBonus = 0;
        unsigned char hasteHitBonus = 0;
        unsigned char safeBonus = 0;
    };
}
