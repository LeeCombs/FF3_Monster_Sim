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

	void Spell::setLevel(unsigned char uc) { level = uc; }
	void Spell::setPower(unsigned char uc) { power = uc; }
	void Spell::setAccuracy(unsigned char uc) { accuracy = uc; }
	void Spell::setName(string s) { name = s; }
	void Spell::setReflectable(bool b) { reflectable = b; }
	void Spell::setType(SpellType st) { type = st; }
	void Spell::setTarget(Target t) { target = t; }
	void Spell::setElements(std::unordered_set<Element> e) { elements = e; }
	void Spell::setStatuses(std::unordered_set<Status> s) { statuses = s; }

	//-----------------------------
	// Getters
	// ----------------------------

	unsigned char Spell::getLevel() { return level; }
	unsigned char Spell::getPower() { return power; }
	unsigned char Spell::getAccuracy() { return accuracy; }
	string Spell::getName() { return name; }
	bool Spell::getReflectable() { return reflectable; }
	SpellType Spell::getType() { return type; }
	Target Spell::getTarget() { return target; }
	std::unordered_set<Element> Spell::getElements() { return elements; }
	std::unordered_set<Status> Spell::getStatuses() { return statuses; }
}

