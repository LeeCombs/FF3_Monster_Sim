#pragma once
#include <unordered_set>

namespace Utils {
	template<typename T>
	bool inline SetContains(std::unordered_set<T> set, T item) {
		std::unordered_set<T>::const_iterator got = set.find(item);
		return !(got == set.end());
	}
};

