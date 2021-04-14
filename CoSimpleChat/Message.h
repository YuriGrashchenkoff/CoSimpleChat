#pragma once
#include<string>
using namespace std;  


class Message
{
public:
    Message(const string& message,const  string& fromLetter, const string& toLetter); // ����������� ��������� ������ �� � ���� �� User. � ���� ���������
    Message(const int& dayMessage, const int& monthMessage, const int& yearMessage);// ����������� ���������� ����� �������� ��������
    string getSendFromUser() const;
    string getSendToUser() const; 
    string getMessage() const;
    int getdayMessage() const;
    int getmonthMessage() const;
    int getyearMessage() const;
    ~Message() = default;
private:
	string _message;
	string _fromLetter;
	string _toLetter;
    int _dayMessage;
    int _monthMessage;
    int _yearMessage;
  };


