// CoSimpleChat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "User.h"
#include <vector>

using namespace std;

int main()
{
    int mode;  //Переменная, в которой хранится выбранный режим
    int j;  //
    
    string name;  //Имя, которое вводит пользователь
    string nik;  //Nik, который вводит пользователь
    string password;  //Пароль, который вводит пользователь
    string chekpassword;  //
    vector <User> users;  //Создаем контейнер для хранения данных пользователей
    
    bool run = true;

    while(run)
    {
 m1:
        cout << "********************************************" << endl;
        cout << "* This is a simple chat. Select an action! *" << endl;
        cout << "********************************************" << endl;
        cout << "   1 - registration, 2 - login, 0 - exit" << endl;
        cout << "--------------------------------------------" << endl;

        cin >> mode;

        switch (mode)
        {
        case 1:  //регистрация
        {
            cout << "Enter a name: " << endl;
            cin >> name;
            cout << "" << endl;

            cout << "Enter a Nik: " << endl;
            cin >> nik;
            cout << "" << endl;

            //Проверка на предмет наличия в базе пользователя с только что введенным ником
            for (int i = 0; i < users.size(); i++)
            {
                if (users[i].getUserNik() == nik)
                {
                    cout << "Nick's busy. Enter another one!" << endl;
                    goto m1;
                }
            }


            cout << "Enter a password: " << endl;
            cin >> password;

            users.push_back(User(name, nik, password));  //помещаем пользователя в контейнер

            cout << "" << endl;
            cout << "--- You have successfully registered! ---" << endl;
            cout << endl;
            goto m1;
        }
        break;

        case 2:  //вход
        {
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
                goto m1;
            }

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
                goto m1;
            }
        }
        break;

        case 0:  //выход
        {
            //run = false;
            cout << "--- See you next time! ---" << endl;
            goto m2;
        }
        break;

        default:
            break;
        }
        //goto m1;

        cout << "***************************" << endl;
        cout << "* What do you want to do? *" << endl;
        cout << "***************************" << endl;
        cout << "1 - write a message" << endl;
        cout << "2 - read message" << endl; 
        cout << "0 - exit" << endl;
        cout << "---------------------------" << endl;

        cin >> mode;

        switch (mode)
        {
        case 1:  //написать сообщение
        {

        }
        break;

        case 2:  //прочитать сообщение
        {

        }
        break;

        case 0:  //выход
        {
            run = false;
            cout << "--- See you next time! ---" << endl;
        }
        break;
        }
    }
m2:
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
