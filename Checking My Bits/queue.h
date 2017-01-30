#pragma once
#include "LinkedList.h"
#include <iostream>

template <typename T>
class queue {
public:
	queue() {
		stuff = new LinkedList<T>[defaultSize];
		//stuff->size = 0;
		capacity = defaultSize;
	}
	~queue() {	delete[] stuff; }

	//access functions
	void push(int value) {	stuff->add_back(value);	}
	int pop() {
		int retval;
		retval = stuff->front();
		stuff->del_front();
		return retval;
	}
	int top() {	return stuff->front(); }

	void reserve(size_t size) {
		LinkedList <T> *tempArray = new LinkedList <T>[size];

		memcpy_s(tempArray, sizeof(T) * size, stuff, sizeof(T) * stuff->size());
	}
	void compact() {
		//todo;
	}

	
	//accessory functions
	bool empty() { return stuff->size() > 0; }
	void clear() { stuff->clear(); }
	size_t size() const { return stuff->size() };

private:
	size_t defaultSize = 10;	
	LinkedList <T> *stuff;	
	size_t capacity;

};
