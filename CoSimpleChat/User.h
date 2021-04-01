#pragma once
#include <string>
using namespace std;

//�����, ���������� � ���� ������������ ������ ������������
class User
{
public:
	User(const string& name, const string& nik, const string& password);  //�����������
	virtual ~User(); //����������

	string getUserName() const;  //���������� ��� ������������
	string getUserNik() const;  //���������� ���
	string getUserPassword() const; //���������� ������
		
private:
	string _userName;
	string _userNik;
	string _userPassword;
};

