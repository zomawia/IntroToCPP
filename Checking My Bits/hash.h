#pragma once

#include <iostream>

inline int knuth(int value) {
	return value * INT_MAX >> 2 ^ 32;
}

inline unsigned int JSHash(const std::string &str) {
	unsigned int hash = 187156461;

	for (std::size_t i = 0; i < str.length(); i++) {
		hash ^= ((hash << 5) + str[i] + (hash >> 2));
	}

	return (hash & 0x7FFFFFF);
}

class hashtable {

	//356
	const static int TBSIZE = 128;

	struct pair {
		bool isSet = false;
		int key;
		int value;
	};

	//backing array
	pair things[TBSIZE];

	int getIndex(int key) { return knuth(key) % TBSIZE; }

public:
	void set(int key, int value);
	int get(int key);

	bool isSet(int key);

	// Return number of elements in the hashmap. This is not that same as your capacity,
	// which is the total number of elements that your hashmap can contain.
	int count();

	//This returns TRUE if there is at least one element stored in your hashmap.
	//Otherwise, this returns FALSE.
	bool isEmpty();

	// This removes all elements from the hashmap!
	void clear();
};