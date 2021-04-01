#pragma once
#include <string>
using namespace std;

//Класс, содержащий в себе персональные данные пользователя
class User
{
public:
	User(const string& name, const string& nik, const string& password);  //Конструктор
	virtual ~User(); //Деструктор

	string getUserName() const;  //Возвращает имя пользователя
	string getUserNik() const;  //Возвращает ник
	string getUserPassword() const; //Возвращает пароль
		
private:
	string _userName;
	string _userNik;
	string _userPassword;
};

