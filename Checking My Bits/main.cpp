#include <iostream>
#include <assert.h>
#include "queue.h"

void main() {

	queue <int> Q;

	Q.reserve(4);

	Q.push(5);
	Q.push(1);
	Q.push(2);
	Q.push(6);

	std::cout << Q.top() << std::endl;

	system("pause");
}