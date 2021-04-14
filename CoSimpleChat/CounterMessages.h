#pragma once
#include <string>
using namespace std;

class CounterMessages
{
public:
	explicit CounterMessages(const string& name); // ������� ���� ��������� ������������ 
	explicit CounterMessages(const int count) ;  // ������� ������ ��������� ������������
	int getCountMessages();
	string getNikUser() const;
	int totalMessages();

private:
	int _count=0;
	int _total=0;
	string _name;
};
