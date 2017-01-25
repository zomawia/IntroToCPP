#include "sstack.h"

void stack::push(int value)
{
	stack *temp = new stack;

	temp->stuff = &value;	
}
