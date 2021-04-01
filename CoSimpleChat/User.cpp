#include "User.h"
#include <string>
using namespace std;

User::User(const string& name,const string& nik,const string& password): _userName(name), _userNik(nik), _userPassword(password)
{
	
}

User::~User()
{

}

string User::getUserName() const
{
	return _userName;
}

string User::getUserNik() const
{
	return _userNik;
}

string User::getUserPassword() const
{
	return _userPassword;
}