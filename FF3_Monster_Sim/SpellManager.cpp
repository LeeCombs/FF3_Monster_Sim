#include "SpellManager.h"

namespace ff3j {

	Spell getSpellByName(std::string name) {
		Spell spell;
		return spell;
	}

	SpellResult castSpell(int caster, int target) {
		SpellResult res;
		res.damage = 0;
		res.results.push_back("?");
		return res;
	}
}