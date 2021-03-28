#include "User.h"
#include <string>
using namespace std;

User::User(string name,  string nik, string password): _userName(name), _userNik(nik), _userPassword(password)
{
	
}

User::~User()
{

}

string User::getUserName()
{
	return _userName;
}

string User::getUserNik()
{
	return _userNik;
}

string User::getUserPassword()
{
	return _userPassword;
}