#include "hash.h"

void hashtable::set(int key, int value)
{
	unsigned int index = getIndex(key);
	things[index].value = value;
	things[index].isSet = true;
	things[index].key = key;
}

int hashtable::get(int key)
{
	unsigned int index = getIndex(key);
	return things[index].value;	
}

bool hashtable::isSet(int key)
{
	unsigned int index = getIndex(key);
	return things[index].isSet;
}

int hashtable::count()
{
	int count = 0;
	for (int i = 0; i < TBSIZE; ++i) {
		if (things[i].isSet == true) {
			count++;
		}
	}
	return count;
}

bool hashtable::isEmpty()
{
	return (count() == 0);
}

void hashtable::clear()
{
	if (!isEmpty()) {
		for (int i = 0; i < TBSIZE; ++i) {
			if (things[i].isSet == true) {
				things[i].isSet = false;
				things[i].key = NULL;
				things[i].value = NULL;
			}
		}
	}
}
