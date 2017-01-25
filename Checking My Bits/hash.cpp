#include "hash.h"

void hashtable::set(int key, int value)
{
	unsigned int index = getIndex(key);
	things[index].value = value;
}

int hashtable::get(int key)
{
	unsigned int index = getIndex(key);
	return things[index].value;	
}

bool hashtable::isSet(int key)
{
	unsigned int index = getIndex(key);
	return things[index].value != NULL;
}
