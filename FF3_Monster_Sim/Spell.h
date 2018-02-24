#pragma once
#include <string>
#include "Enums.h"
#include <vector>

using namespace std;

namespace ff3j {
	enum class SpellType :int { black, white, summon, item, ability, terrain };

	class Spell
	{
	public:
		Spell();
		~Spell();

		// Setters
		void setLevel(unsigned char);
		void setPower(unsigned char);
		void setAccuracy(unsigned char);
		void setName(string);
		void setReflectable(bool);
		void setType(SpellType);
		void setTarget(Target);
		void setElements(std::vector<Element>);

		// Getters
		unsigned char getLevel();
		unsigned char getPower();
		unsigned char getAccuracy();
		string getName();
		bool getReflectable();
		SpellType getType();
		std::vector<Element> getElements();
	protected:
		//
	private:
		//
		unsigned char level = 0;
		unsigned char power = 0;
		unsigned char accuracy = 0;
		bool reflectable;
		string name;

		SpellType type;
		Target target;
		std::vector<Element> elements;

		// TODO: Statuses, both temp and perm.
		
	};

}


