#include <iostream>
#include <assert.h>
#include "hash.h"

void main() {

	hashtable tb;
	tb.set(1, 10);

	assert(tb.get(1) == 10);

	assert(tb.isSet(1));
	system("pause");
}