#include "SpellManager.h"

namespace ff3j {

	Spell getSpellByName(std::string name) {
		Spell spell;
		return spell;
	}

	SpellResult castSpell(Monster caster, Monster target) {
		SpellResult res;
		res.damage = 0;
		res.results.push_back("1");
		res.results.push_back("two");
		res.results.push_back("C");
		res.results.push_back("IV");
		return res;
	}
}