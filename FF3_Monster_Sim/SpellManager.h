#pragma once
#include "Spell.h"
#include "Monster.h"
#include <vector>
#include <string>
#include <unordered_set>

namespace ff3j {

	// Private vars and methods exist in an anonymous namespace
	namespace {
		const std::string spellData; // TODO: Determine format of data
		const std::string FAILED_SPELL_MESSAGE = "Ineffective";
		bool initialized = false;
	}

	struct SpellResult {
		int damage;
		std::vector<std::string> results;
	};

	void loadData();

	Spell getSpellByName(std::string);
	SpellResult castSpell(Monster, Monster);
	std::unordered_set<std::string> getSpellNames();
}


