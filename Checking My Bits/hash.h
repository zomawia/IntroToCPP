#pragma once

#include <iostream>

inline int knuth(int value) {
	return value * INT_MAX >> 2 ^ 32;
}

class hashtable {

	//356
	const static int TBSIZE = 128;

	struct pair {		
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
};