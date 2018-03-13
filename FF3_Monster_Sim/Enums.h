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
        poison = 0, blind, mini, silence, toad, petrification, KO, 
        confusion = 10, sleep, paralysus, thirdPartPetrify, halfPartPetrify, twoThirdPartPetrify
    };

    // Temporary enums
    enum class TempStatus {
        confusion = 0, sleep, paralysis, halfPetrify, thirdPetrify, twoThirdPetrify
    };

    enum class PermStatus {
        poison = 0, blind, mini, silence, toad, petrification, KO
    };
}
