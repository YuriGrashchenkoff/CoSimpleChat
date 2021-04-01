#include "CounterMessages.h"


CounterMessages::CounterMessages(const string& name):_name(name)
{
}

CounterMessages::CounterMessages(const int count):_count(count)
{
}

int CounterMessages::getCountMessages()
{
	return _count;
}

const string& CounterMessages::getNikUser()
{
	return string();
}

int CounterMessages::totalMessages()
{
	return _total;
}

