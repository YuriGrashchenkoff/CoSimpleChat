#include "CounterMessages.h"

CounterMessages::CounterMessages( string name):_name(name)
{
}

CounterMessages::CounterMessages( int count):_count(count)
{
}

int CounterMessages::getCountMessages()
{
	return _count;
}

string CounterMessages::getNikUser()
{
	return string();
}

int CounterMessages::totalMessanges()
{
	return _total;
}

CounterMessages::~CounterMessages()
{
}
