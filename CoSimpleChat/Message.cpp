#include "Message.h"


Message::Message(const string& message, const string& fromLetter, const string& toLetter): _message(message), _fromLetter(fromLetter), _toLetter(toLetter)
{
}

string Message::getSendFromUser() const
{
	return _fromLetter;
}

string Message::getSendToUser() const
{
	return _toLetter;
}

string Message::getMessage() const
{
	return _message;
}
