#pragma once

namespace ff3j {
    enum class Element {
        none = 0, recovery, dark, lightning, ice, fire, air, earth, holy
    };

    enum class Target {
        enemy = 0, ally, singleEnemy, singleAlly, allEnemies, allAllies 
    };

    // 0-9: Permanent status, >=10: Temporary Status
    enum class Status {
        none = 0,
        poison = 1, blind, mini, silence, toad, petrification, KO, 
        confusion = 10, sleep, paralysus, thirdPartPetrify, halfPartPetrify, twoThirdPartPetrify
    };

    // Temporary enums
    enum class TempStatus {
        none = 0, confusion, sleep, paralysis, halfPetrify, thirdPetrify, twoThirdPetrify
    };

    enum class PermStatus {
        none = 0, poison, blind, mini, silence, toad, petrification, KO
    };
}
