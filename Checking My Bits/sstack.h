#pragma once
#include "hash.h"

class stack {
private: //what data to store, any helper functions

	const static int SIZE = 10;
	int backing[SIZE];
	int head = 0;
	

public:
	void push(int value);

	int pop();

	int peek();

	size_t size();

	bool empty();
	void clear();
};
