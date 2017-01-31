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
	return pool->poolValidity[index] == true;
}

size_t obpool::nextEmpty()
{
	for (int i = 0; i < DEFAULT_POOL_SIZE; ++i)
		if (poolValidity[i] == false)
			return i;
	
	return -1;
}

obpool::obpool()
{
	memset(poolValidity, 0, sizeof(bool) * DEFAULT_POOL_SIZE);
	

	for (int i = 0; i < DEFAULT_POOL_SIZE; ++i) {
		//pool[i] = NULL;
		poolValidity[i] = false;
	}
}

obpool::~obpool()
{
}

obpool::handle obpool::push(int cpy)
{
	handle retval;
	
	size_t tempIndex = nextEmpty();
	
	if (tempIndex >= 0) {
		pool[tempIndex] = cpy;
		poolValidity[tempIndex] = true;
		handle retval(this, tempIndex);
		return retval;
	}

	return retval;
}

void obpool::pop(size_t idx)
{
	pool[idx] = NULL;
	poolValidity[idx] = false;
}

bool obpool::isValid(size_t idx) const
{	
	return poolValidity[idx] == true;
}

int & obpool::at(size_t idx)
{
	return pool[idx];
}

const int & obpool::at(size_t idx) const
{
	return pool[idx];
}
