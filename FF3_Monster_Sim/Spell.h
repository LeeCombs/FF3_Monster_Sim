#pragma once
#include <string>

using namespace std;

namespace ff3j {
	enum class SpellType :int { black, white, summon, item, ability, terrain };

	class Spell
	{
	public:
		Spell();
		~Spell();

		void setLevel(unsigned char);
		void setPower(unsigned char);

		int getLevel();
		int getPower();
	protected:
		//
	private:
		//
		unsigned char level, power, accuracy, price, value;
		string name, type, target, status, element;
	};

}


