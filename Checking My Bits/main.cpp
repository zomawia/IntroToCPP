#include <iostream>
#include <assert.h>
#include "hash.h"

void main() {

	hashtable tb;
	tb.set(1, 10);
	tb.set(13, 11);
	tb.set(157, 21);
	tb.set(17, 441);

	assert(tb.isSet(1));
	//assert(tb.count() == 3);

	std::cout << "Count: " << tb.count() << std::endl;

	std::cout << "tb.get = " << tb.get(157) << std::endl;

	tb.clear();
	
	std::cout << "Count: " << tb.count() << std::endl;

	

	system("pause");
}