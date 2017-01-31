#include <iostream>
#include <assert.h>
#include "queue.h"
#include "oobpool.h"

void main() {

	obpool <int> pool;

	obpool<int>::handle han = pool.push(5);
	assert(han.value() == 5);
	assert(han.isValid());

	assert(pool.isValid(0) == true);
	assert(pool.isValid(1) == false);
	assert(pool.isValid(2) == false);

	obpool<int>::handle han2 = pool.push(3);
	assert(han2.value() == 3);

	pool.pop(han.getIndex());
	assert(!han.isValid());

	assert(pool.isValid(1) == true);

	system("pause");
}