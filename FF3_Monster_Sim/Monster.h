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

        //=================================
        // Getters 
        //=================================
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
        Element attackElement;
        Status statusAttack;
        std::unordered_set<Element> resistances;
        std::unordered_set<Element> weaknesses;
        std::unordered_set<Status> statusImmunities;
        std::vector<std::string> moveset;

        //=================================
        // In-combat vars
        //=================================
        std::unordered_set<Status> statuses;
        unsigned char petrifyTracker;

    };
}
