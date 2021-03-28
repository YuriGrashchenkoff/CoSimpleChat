// CoSimpleChat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "User.h"
#include "Message.h"
#include <vector>
#include <string>

using namespace std;

bool run = true;
bool run1 = true;
vector <User> users;  //Создаем контейнер для хранения данных пользователей

string VerifyingRecipient(vector <User>& ollUsers) // проверяем есть ли пользователь которому мы будем писать сообщение
{
	size_t size = ollUsers.size();
	string toUser;
	while (true)
	{
		cout << "Enter the recipient's nickname:\n";
		cout << "If you want to send the message all enter - all:\n";
		cin >> toUser;
		for (int i = 0; i < size; ++i)
		{
			if (toUser == ollUsers[i].getUserNik() || toUser == "all")
			{
				return toUser;
			}
		}
		cout << "\n\tThere is no such user";
	}
}


void  readMessage(string user, vector<Message>& allmess) // чтение всех сообщений для пользователя
{
	int count = 0;
	size_t size = allmess.size();
	for (int i = 0; i < size; ++i)
	{
		if (allmess[i].getSendToUser() == user || allmess[i].getSendToUser() == "all")
		{
			cout << "From whom: " << allmess[i].getSendFromUser() << endl;
			cout << "Message: " << allmess[i].getMessage() << std::endl;
			++count;
		}
	}
	if (count == 0)
	{
		cout << "There are no messages for you!" << endl;
	}
}

void  readMessageUser(string user, vector<Message>& allmess)// чтение сообщений от определённого пользователя
{
	int count = 0;
	string fromUser;
	cout << "Enter the nickname of the user whose messages you want to read\n";
	cin >> fromUser;
	size_t size = allmess.size();
	for (int i = 0; i < size; ++i)
	{
		if (allmess[i].getSendToUser() == user || allmess[i].getSendToUser() == "all")
		{
			if (fromUser == allmess[i].getSendFromUser())
			{
				cout << "From whom: " << allmess[i].getSendFromUser() << endl;
				cout << "Message: " << allmess[i].getMessage() << std::endl;
				++count;
			}
		}

	}
}

string regUser()  //Функция регистрации пользователя
{
	bool run_ = false;
	string name;  //Имя, которое вводит пользователь
	string nik;  //Nik, который вводит пользователь
	string password;  //Пароль, который вводит пользователь

	do
	{
		run_ = false;
		cout << "Enter a Nik: " << endl;
		cin >> nik;
		cout << "" << endl;

		//Проверка на предмет наличия в базе пользователя с только что введенным ником
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].getUserNik() == nik)
			{
				cout << "Nick's busy. Enter another one!" << endl;
				cout << "" << endl;
				run_ = true;
			}

		}

	} while (run_);

	cout << "Enter a name: " << endl;
	cin >> name;
	cout << "" << endl;

	cout << "Enter a password: " << endl;
	cin >> password;

	users.push_back(User(name, nik, password));  //помещаем пользователя в контейнер

	cout << "" << endl;
	cout << "--- You have successfully registered! ---" << endl;
	cout << endl;

	return name;
}

string loginUser()  //Функция входа
{
	bool run_ = false;
	string name;  //Имя, которое вводит пользователь
	string nik;  //Nik, который вводит пользователь
	string password;  //Пароль, который вводит пользователь
	string chekpassword;  //
	int j;  //

	do
	{
		run_ = false;
		cout << "Enter your nickname:" << endl;
		cin >> nik;
		cout << "" << endl;

		j = -1;

		for (int i = 0; i < users.size(); i++)  //ищем пользователя с таким ником
		{
			if (users[i].getUserNik() == nik)
			{
				j = i;
			}
		}

		if (j == -1)  //если в база не оказалось такого ника
		{
			cout << "There is no user with this nickname!" << endl;
			cout << "" << endl;
			run_ = true;
		}

	} while (run_);

	chekpassword = users[j].getUserPassword();  //запрашиваем пароль для этого ника из контейнера

	cout << "Enter password:" << endl;
	cin >> password;
	cout << "" << endl;

	if (chekpassword == password)  //Сравниваем пароли,если совпадают
	{
		cout << "--- You have successfully logged in! ---" << endl;
		cout << "" << endl;
	}
	else  //иначе выходим
	{
		cout << "Bed password!" << endl;
		cout << "" << endl;
	}

	run = false;
	run1 = true;

	return name;
}

void exitProg() //функция выхода
{
	cout << "--- See you next time! ---" << endl;
	run = false;
	run1 = false;
}

int listUsers(int index, vector <User>& ollUsers) // вывод списка пользователей
{
	size_t size = ollUsers.size();
	if (size > index)  // если пользователей увеличилось, выводим обновлённый список
	{
		cout << "\t\t\t\t\t\t\t\tList of users:\n";
		for (int i = 0; i < size; ++i)
		{
			cout << "\t\t\t\t\t\t" << i + 1 << ") " << ollUsers[i].getUserNik() << endl;
		}
		return ++index;
	}
	else if (size == 0)
	{
		cout << "\t\t\t\t\t\tNo users yet\n"; // пользователей пока нет
	}
	return index;
}


int main()
{
	int mode;  //Переменная, в которой хранится выбранный режим
	string nik;  //Nik, который вводит пользователь
	string toUser; // поле получателя
	string message;// вводимое пользователем сообщение
	string getname;  //Сюда возвращается имя из функции
	vector <Message> ollMessage; // Хранение всех сообщений
	int count = 0; // контроль вывода списка пользователей


	while (run)
	{

		cout << "********************************************" << endl;
		cout << "* This is a simple chat. Select an action! *" << endl;
		cout << "********************************************" << endl;
		cout << "   1 - registration, 2 - login, 0 - exit" << endl;
		cout << "--------------------------------------------" << endl;
		count = listUsers(count, users);// вывод списка пользователей
		cin >> mode;

		switch (mode)
		{
		case 1:  //регистрация
		{
			getname = regUser();
			run1 = true;
			break;
		}


		case 2:  //вход
		{
			getname = loginUser();
			break;
		}


		case 0:  //выход
		{
			exitProg();
			break;
		}


		}




		while (run1)
		{
			cout << "***************************" << endl;
			cout << "* What do you want to do? *" << endl;
			cout << "***************************" << endl;
			cout << "1 - write a message  " << endl;
			cout << "2 - read message     " << endl;
			cout << "3 - read message User" << endl;
			cout << "0 - exit" << endl;
			cout << "---------------------------" << endl;

			cin >> mode;

			switch (mode)
			{
			case 1:  //написать сообщение
			{
				toUser = VerifyingRecipient(users);
				cout << "\nEnter a message:\n";
				cin >> message;
				ollMessage.push_back(Message(nik, toUser, message));
				break;
			}


			case 2:  //прочитать сообщения
			{
				readMessage(nik, ollMessage);
				break;
			}


			case 3:  // прочитать сообщения от определённого пользователя
			{
				readMessageUser(nik, ollMessage);
				break;
			}


			case 0:  //выход из кейса сообщений
			{
				run1 = false;
			    break;
			}

			}

		}
	}
	return 0;
}
