#pragma once
#include <string>
using namespace std;

class CounterMessages
{
public:
	CounterMessages(string name); // подсчёт всех сообщений пользователя 
	CounterMessages(int count) ;  // подсчёт старых сообщений пользователя
	int getCountMessages();
	string getNikUser();
	int totalMessanges();
	~CounterMessages();

private:
	int _count=0;
	int _total;
	string _name;
};
