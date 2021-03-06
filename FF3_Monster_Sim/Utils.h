#pragma once
#include <unordered_set>
#include <random>
#include "Monster.h"
#include "Spell.h"

namespace ff3j {
    int calculateDamage(Monster, Monster);
    int calculateSpellDamage(Spell spell, Monster atkr, Monster target, int targetCount);
}

namespace Utils {
    //============================
    // Dealing with containers
    //============================
    template<typename T>
    bool inline SetContains(std::unordered_set<T> set, T item) {
        std::unordered_set<T>::const_iterator got = set.find(item);
        return !(got == set.end());
    }

    //============================
    // Random numbers
    //============================
    namespace {
        static std::random_device rd;
        static std::mt19937 mt(rd());
    }
    int getRandomInt(int min, int max);


    int rollSuccesses(int rolls, int successRate); // TODO: This name sucks
};