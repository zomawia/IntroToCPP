#include "oobpool.h"

obpool::handle::handle()
{
	pool = nullptr;
	index = 0;
}

obpool::handle::handle(obpool * poolPtr, size_t poolIdx)
{
	pool = poolPtr;
	index = poolIdx;
}

int & obpool::handle::value() const
{
	// TODO: insert return statement here
	return pool->pool[index];
	
}

void obpool::handle::free()
{
	pool->pop(index);
	pool->pool[index] = NULL;
}

int obpool::handle::getIndex() const
{
	return index;
}

bool obpool::handle::isValid() const
{
	return pool->poolValidity[index] != NULL;
}

size_t obpool::nextEmpty()
{
	for (int i = 0; i < DEFAULT_POOL_SIZE; ++i)
		if (pool[i] != NULL) {
			//i = DEFAULT_POOL_SIZE;
			return pool[i];
			
		}		
	
	return -1;
}

obpool::obpool()
{
	
}

obpool::~obpool()
{
}

obpool::handle obpool::push(int cpy)
{
	handle retval;
	

}

void obpool::pop(size_t idx)
{
}

bool obpool::isValid(size_t idx) const
{	
	return poolValidity[idx] == 0;
}

int & obpool::at(size_t idx)
{
	return pool[idx];
}

const int & obpool::at(size_t idx) const
{
	// TODO: insert return statement here
}
