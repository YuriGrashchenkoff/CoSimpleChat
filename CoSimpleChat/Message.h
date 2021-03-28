#pragma once
#include <iostream>
#include<string>
#include "User.h"
using namespace std;


class Message
{
public:
    Message( string fromLetter,string toLetter,string message); // ����������� ��������� ������ �� � ���� �� User. � ���� ���������
       
    string getSendFromUser();
    string getSendToUser();
    string getMessage();
    
    ~Message() {};
  
private:
	string _message;
	string _fromLetter;
	string _toLetter;
  };


