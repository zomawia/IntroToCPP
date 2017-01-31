#include <iostream>
#include <assert.h>
#include "queue.h"
#include "oobpool.h"

void main() {

	obpool <int> pool;

	auto han = pool.push(3);
	assert(han.value() == 3);
	assert(han.isValid());

	assert(pool.get(0) == han);

	auto han2 = pool.push(5);
	assert(han2.value() == 5);
	assert(han2.isValid());

	auto han3 = pool.push(7);
	assert(han3.value() == 7);
	assert(han3.isValid());
	
	auto han4 = pool.push(9);
	assert(han4.value() == 9);
	assert(han4.isValid());

	han3.free();

	int expected[] = { 3,5,9 };
	size_t i = 0;
	for (auto iter = pool.begin(); iter != pool.end(); ++iter) {
		assert(expected[i] == *iter);
		i++;
	}

	system("pause");
}