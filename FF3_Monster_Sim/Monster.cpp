#include "Monster.h"
#include "Utils.h"
#include <string>
#include <stdexcept>

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


    bool Monster::hasStatus(const Status &s) {
        return Utils::SetContains(statuses, s);
    }
    bool Monster::hasStatus(const Status sArr[], const int length) {
        for (int i = 0; i < length; i++)
            if (Utils::SetContains(statuses, sArr[i]))
                return true;
        return false;
    }
    bool Monster::addStatus(const Status &s) {
        // Bosses are immune to status effects
        if (isBoss || Utils::SetContains(statusImmunities, s))
            return false;

        // TODO: Add status sprite of the status, if it's new
        return statuses.insert(s).second;
    }
    void Monster::removeStatus(const Status &s) {
        // TODO: Remove status sprite of status removed, if it exists
        statuses.erase(s);
    }

    bool Monster::isWeakTo(const Element &e) {
        return Utils::SetContains(weaknesses, e);
    }
    bool Monster::isWeakTo(const Element eArr[], const int length) {
        for (int i = 0; i < length; i++)
            if (Utils::SetContains(weaknesses, eArr[i]))
                return true;
        return false;
    }
    bool Monster::isWeakTo(const std::unordered_set<Element> &eSet) {
        for (auto e : eSet)
            if (Utils::SetContains(weaknesses, e))
                return true;
        return false;
    }

    bool Monster::isResistantTo(const Element &e) {
        return Utils::SetContains(resistances, e);
    }
    bool Monster::isResistantTo(const Element eArr[], const int length) {
        for (int i = 0; i < length; i++)
            if (Utils::SetContains(resistances, eArr[i]))
                return true;
        return false;
    }
    bool Monster::isResistantTo(const std::unordered_set<Element> &eSet) {
        for (auto e : eSet)
            if (Utils::SetContains(resistances, e))
                return true;
        return false;
    }


    bool Monster::isVulnerable() {
        Status vulnStatuses[2] = { Status::mini, Status::toad };
        return hasStatus(vulnStatuses, 2);
    }


    //=================================
    // Getters 
    //=================================

    std::string Monster::getName() { return name; };
    unsigned char Monster::getId() { return id; };
    unsigned char Monster::getLevel() { return level; };
    unsigned char Monster::getExp() { return exp; };
    unsigned char Monster::getGil() { return gil; };
    MonsterType Monster::getMonsterType() { return monsterType; };
    bool Monster::getIsBoss() { return isBoss; };
    unsigned short Monster::getHP() { return hp; };
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
    Status Monster::getAttackStatus() { return attackStatus; };
    std::unordered_set<Element> Monster::getAttackElements() { return attackElements; };
    std::unordered_set<Element> Monster::getResistances() { return resistances; };
    std::unordered_set<Element> Monster::getWeaknesses() { return weaknesses; };
    std::unordered_set<Status> Monster::getStatusImmunities() { return statusImmunities; };

    // In-battle getters

    unsigned char Monster::getHasteDmgBonus() { return hasteDmgBonus; }
    unsigned char Monster::getHasteHitBonus() { return hasteHitBonus; }
    unsigned char Monster::getSafeBonus() { return safeBonus; }

    //=================================
    // Setters 
    //=================================

    // TODO: I'm assuming most of these will be hidden and 
    // only accessible through the constructor.
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
    void Monster::setAttackStatus(Status s) { attackStatus = s; };
    void Monster::setAttackElements(std::unordered_set<Element> us) { attackElements = us; };
    void Monster::setResistances(std::unordered_set<Element> us) { resistances = us; };
    void Monster::setWeaknesses(std::unordered_set<Element> us) { weaknesses = us; };
    void Monster::setStatusImmunities(std::unordered_set<Status> us) { statusImmunities = us; };

    // In battle
    void Monster::setHasteDmgBonus(unsigned char hb) { hasteDmgBonus = hb; }
    void Monster::setHasteHitBonus(unsigned char hb) { hasteHitBonus = hb; }
    void Monster::setSafeBonus(unsigned char sb) { safeBonus = sb; }


    //=================================
    // Helpers 
    //=================================
}
