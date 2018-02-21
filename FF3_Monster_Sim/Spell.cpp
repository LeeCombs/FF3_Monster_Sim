#include "Spell.h"

namespace ff3j {

	Spell::Spell()
	{
		// Constructor
	}


	Spell::~Spell()
	{
		// Destructor
	}

	//-----------------------------
	// Setters
	// ----------------------------

	void Spell::setLevel(unsigned char value) {
		level = value;
	}

	void Spell::setPower(unsigned char value) {
		power = value;
	}

	//-----------------------------
	// Getters
	// ----------------------------

	int Spell::getLevel() {
		return level;
	}

	int Spell::getPower() {
		return power;
	}
}

