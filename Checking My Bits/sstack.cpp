#include "sstack.h"

void stack::push(int value)
{
	backing[head] = value;
	head++;
}

int stack::pop()
{
	head--;
	return backing[head];
}

int stack::peek()
{
	return 0;
}
