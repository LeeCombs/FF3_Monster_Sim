#pragma once
#include <vector>
#include <string>
#include "Spell.h"

namespace ff3j {

	// Private vars and methods exist in an anonymous namespace
	namespace {

	}

	struct SpellResult {
		int damage;
		std::vector<std::string> results;
	};

	Spell getSpellByName(std::string);
	SpellResult castSpell(int, int);
}


