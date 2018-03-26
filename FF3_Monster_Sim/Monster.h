#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include "Enums.h"

namespace ff3j {

    enum class MonsterType {
        none, undead, dividing
    };

    class Monster {

    public:
        Monster();
        ~Monster();

        //=================================
        // Publics 
        //=================================

        bool hasStatus(const Status &s);
        bool hasStatus(const Status[], const int length);
        bool addStatus(const Status &s);
        void removeStatus(const Status &s);

        bool isWeakTo(const Element &e);
        bool isWeakTo(const Element[], const int length);
        bool isWeakTo(const std::unordered_set<Element> &eSet);

        bool isResistantTo(const Element &e);
        bool isResistantTo(const Element[], const int length);
        bool isResistantTo(const std::unordered_set<Element> &eSet);

        // Return whether or not the monster has a status that makes it vulnerable
        // These include Mini, Toad, and Buildup (in specific cases)
        bool isVulnerable();


        //=================================
        // Setters 
        //=================================

        // TODO: I'm assuming most of these will be hidden and 
        // only accessible through the constructor.
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
        void setResistances(std::unordered_set<Element>);
        void setWeaknesses(std::unordered_set<Element>);
        void setStatusImmunities(std::unordered_set<Status>);

        // In battle
        void setHasteDmgBonus(unsigned char);
        void setHasteHitBonus(unsigned char);
        void setSafeBonus(unsigned char);

        //=================================
        // Getters 
        //=================================

        // Combat stats
        std::string getName();
        unsigned char getId();
        unsigned char getLevel();
        unsigned char getExp();
        unsigned char getGil();
        MonsterType getMonsterType();
        bool getIsBoss();
        unsigned short getHP();
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
        std::unordered_set<Element> getResistances();
        std::unordered_set<Element> getWeaknesses();
        std::unordered_set<Status> getStatusImmunities();

        // In battle
        unsigned char getHasteDmgBonus();
        unsigned char getHasteHitBonus();
        unsigned char getSafeBonus();

    protected:
        //

    private:
        std::string name = "DEFAULT NAME";
        unsigned char id = 0;
        unsigned char level = 0;
        unsigned short exp = 0;
        unsigned short gil = 0;
        MonsterType monsterType = MonsterType::none;
        bool isBoss = false;

        //=================================
        // Combat stats
        //=================================
        unsigned short hp = 0;
        unsigned char jobLevel = 0;
        unsigned char intellect = 0;
        unsigned char mind = 0;
        unsigned char attack = 0;
        unsigned char hits = 0;
        unsigned char accuracy = 0;
        unsigned char defense = 0;
        unsigned char blocks = 0;
        unsigned char evasion = 0;
        unsigned char magicDefense = 0;
        unsigned char magicBlocks = 0;
        unsigned char magicResistance = 0;
        Status attackStatus = Status::none;
        std::unordered_set<Element> attackElements = {};
        std::unordered_set<Element> resistances = {};
        std::unordered_set<Element> weaknesses = {};
        std::unordered_set<Status> statusImmunities = {};
        std::vector<std::string> moveset;

        //=================================
        // In combat
        //=================================
        std::unordered_set<Status> statuses = {};
        unsigned char petrifyTracker = 0;
        unsigned char hasteDmgBonus = 0;
        unsigned char hasteHitBonus = 0;
        unsigned char safeBonus = 0;
    };
}
