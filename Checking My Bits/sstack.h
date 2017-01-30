#pragma once
#include "hash.h"

template <typename T>
class stack {

private: //what data to store, any helper functions
	unsigned int defaultSIZE = 10;
	T *backing;
	int head;
	size_t capacity;

public:
	stack() {
		backing = new T[defaultSIZE];
		head = 0;
		capacity = defaultSIZE;
	};
	~stack() {
		delete[] backing;
	};
	void push(T value) {
		if (head > capacity)
			reserve(head * 1.5f);
		backing[head] = value;
		head++;
	};

	T pop() {
		head--;
		return backing[head];
	};

	T peek() {
		return backing[head - 1];
	};

	size_t size() {
		return head;
	};

	void reserve(size_t size) {
		T * tempArray = new T[size];

		//copy by element
		for (int i = 0; i < head; ++i)
			tempArray[i] = backing[i];

		//copy memory block
		memcpy_s(tempArray, sizeof(int) * size, backing, sizeof(int) * head);
	};

	void compact() {
		if (capacity > head * 1.5f) {
			capacity = head * 1.5f;
		}
		return;
	};
	size_t volume() {
		return capacity;
	};

	bool empty() {
		return head > 0;
	};
	void clear() {
		head = 0;
	};
};
