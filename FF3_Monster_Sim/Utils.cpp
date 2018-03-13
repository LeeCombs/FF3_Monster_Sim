#include "Utils.h"
#include <random>

namespace Utils {

	//============================
	// Random numbers
	//============================
	int getRandomInt(int min, int max) {
		std::uniform_int_distribution<int> distr(min, max + 1);
		return distr(mt);
	}
}