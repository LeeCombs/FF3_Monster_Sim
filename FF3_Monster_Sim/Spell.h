#pragma once
#include "Enums.h"
#include <string>
#include <unordered_set>

namespace ff3j {
    enum class SpellType { black, white, summon, item, ability, terrain };
    enum class SpellEffect {
        // Damage
        damage, drainHP,
        // Statuses
        addSleep, addPoison, addBlind, addToad, addMini, addParalysis, addKO, addConfuse,
        addMute, addPetrify, addThirdPetrify, addHalfPetrify, addTwoThirdPetrify,
        // Buffs
        addReflect, addHaste, addProtect, 
        // Healing
        heal, curePoison, cureBlind, cureKO, curePetrify,
        cureMute, cureMini, cureFrog, cureAll,
        // Other
        scanHP, removeReflect, viewMap, singleHP
    };

    class Spell
    {
    public:
        Spell();
        ~Spell();

        void addStatus(Status);
        bool hasStatus(Status);
        void clearStatuses();

        // Setters
        void setLevel(unsigned char);
        void setPower(unsigned char);
        void setAccuracy(unsigned char);
        void setName(std::string);
        void setReflectable(bool);
        void setType(SpellType);
        void setTarget(Target);
        void setElements(std::unordered_set<Element>);
        void setStatuses(std::unordered_set<Status>);

        // Getters
        unsigned char getLevel();
        unsigned char getPower();
        unsigned char getAccuracy();
        std::string getName();
        bool getReflectable();
        SpellType getType();
        Target getTarget();
        std::unordered_set<Element> getElements();
        std::unordered_set<Status> getStatuses();

    protected:
        //
    private:
        //
        unsigned char level = 0;
        unsigned char power = 0;
        unsigned char accuracy = 0;
        bool reflectable = false;
        std::string name;

        SpellType type;
        Target target;
        std::unordered_set<Element> elements = { Element::none };
        std::unordered_set<Status> statuses = {};
        
    };
}
