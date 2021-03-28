#include "Message.h"





Message::Message(string fromLetter, string toLetter, string message):_fromLetter(fromLetter),_toLetter(toLetter), _message(message)
{
}

string Message::getSendFromUser()
{
	return _fromLetter;
}

string Message::getSendToUser()
{
	return _toLetter;
}

string Message::getMessage()
{
	return _message;
}
