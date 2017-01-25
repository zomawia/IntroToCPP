#pragma once
#include "hash.h"

class stack {
private: //what data to store, any helper functions

	int *stuff;

	stack *prev, *next;

	int get();
	

public:
	void push(int value);

	int pop();

	int peek();

	size_t size();

	bool empty();
	void clear();
};
