#include <iostream>
#include <assert.h>
#include "queue.h"
#include "oobpool.h"

void main() {

	//queue <int> Q;

	//Q.reserve(4);

	//Q.push(5);
	//Q.push(1);
	//Q.push(2);
	//Q.push(6);

	//std::cout << Q.top() << std::endl;

	//Q.clear();

	//std::cout << Q.top() << std::endl;

	obpool pool;

	obpool::handle han = pool.push(5);
	assert(han.value() == 5);
	assert(han.isValid());

	assert(pool.isValid(0) == true);
	assert(pool.isValid(1) == false);
	assert(pool.isValid(2) == false);

	obpool::handle han2 = pool.push(3);
	assert(han2.value() == 3);

	pool.pop(han.getIndex());
	assert(!han.isValid());

	assert(pool.isValid(1) == true);

	system("pause");
}