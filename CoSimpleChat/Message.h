#pragma once
#include<string>
using namespace std;  


class Message
{
public:
    Message(const string& message,const  string& fromLetter, const string& toLetter); // конструктор принимает логины от и кому от User. И само сообщение
       
    string getSendFromUser() const;
    string getSendToUser() const; 
    string getMessage() const;
    ~Message() = default;
private:
	string _message;
	string _fromLetter;
	string _toLetter;
  };


