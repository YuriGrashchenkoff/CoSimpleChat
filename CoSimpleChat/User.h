#pragma once
#include <string>
using namespace std;

//Класс, содержащий в себе персональные данные пользователя
class User
{
public:
	User(string name, string nik, string password);  //Конструктор
	virtual ~User(); //Деструктор

	string getUserName();  //Возвращает имя пользователя
	string getUserNik();  //Возвращает ник
	string getUserPassword(); //Возвращает пароль
		
private:
	string _userName;
	string _userNik;
	string _userPassword;
};

