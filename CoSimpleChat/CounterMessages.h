#pragma once
#include <string>
using namespace std;

class CounterMessages
{
public:
	CounterMessages(string name); // ������� ���� ��������� ������������ 
	CounterMessages(int count) ;  // ������� ������ ��������� ������������
	int getCountMessages();
	string getNikUser();
	int totalMessanges();
	~CounterMessages();

private:
	int _count=0;
	int _total;
	string _name;
};
