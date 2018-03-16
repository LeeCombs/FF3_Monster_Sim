#include "Monster.h"
#include <string>

namespace ff3j {

    Monster::Monster() {
        //
    }

    Monster::~Monster() {
        //
    }

    //=================================
    // Publics 
    //=================================

    //=================================
    // Getters 
    //=================================
    std::string Monster::getName() { return name; };
    unsigned short Monster::getHP() { return hp; };
    unsigned char Monster::getId() { return id; };
    unsigned char Monster::getLevel() { return level; };
    unsigned char Monster::getExp() { return exp; };
    unsigned char Monster::getGil() { return gil; };
    unsigned char Monster::getJobLevel() { return jobLevel; };

    unsigned char Monster::getIntellect() { return intellect; };
    unsigned char Monster::getMind() { return mind; };

    unsigned char Monster::getAttack() { return attack; };
    unsigned char Monster::getHits() { return hits; };
    unsigned char Monster::getAccuracy() {return accuracy; };

    unsigned char Monster::getDefense() { return defense; };
    unsigned char Monster::getBlocks() { return blocks; };
    unsigned char Monster::getEvasion() { return evasion; };

    unsigned char Monster::getMagicDefense() { return magicDefense; };
    unsigned char Monster::getMagicBlocks() { return magicBlocks; };
    unsigned char Monster::getMagicResistance() { return magicResistance; };


    //=================================
    // Setters 
    //=================================
    void Monster::setName(std::string n) { name = n; };
    void Monster::setHP(unsigned short us) { hp = us; };
    void Monster::setId(unsigned char uc) { id = uc; };
    void Monster::setLevel(unsigned char uc) { level = uc; };
    void Monster::setExp(unsigned char uc) { exp = uc; };
    void Monster::setGil(unsigned char uc) { gil = uc; };
    void Monster::setJobLevel(unsigned char uc) { jobLevel = uc; };

    void Monster::setIntellect(unsigned char uc) { intellect = uc; };
    void Monster::setMind(unsigned char uc) { mind = uc; };

    void Monster::setAttack(unsigned char uc) { attack = uc; };
    void Monster::setHits(unsigned char uc) { hits = uc; };
    void Monster::setAccuracy(unsigned char uc) { accuracy = uc; };

    void Monster::setDefense(unsigned char uc) { defense = uc; };
    void Monster::setBlocks(unsigned char uc) { blocks = uc; };
    void Monster::setEvasion(unsigned char uc) { evasion = uc; };

    void Monster::setMagicDefense(unsigned char uc) { magicDefense = uc; };
    void Monster::setMagicBlocks(unsigned char uc) { magicBlocks = uc; };
    void Monster::setMagicResistance(unsigned char uc) { magicResistance = uc; };

    //=================================
    // Helpers 
    //=================================
}
