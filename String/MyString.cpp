#include <iostream>
#include "MyString.hpp"
#include <string.h>

MyString::MyString(std::string input) : std::string(input)
{
	return;
}

void MyString::forEach(void (*callback)(int)) const
{
	for (size_t i = 0; i < this->length(); i++)
		callback((*this)[i]);
}

MyString MyString::map(int (*callback)(int)) const
{
	MyString newStr("");

	for (size_t i = 0; i < this->length(); i++)
	{
		newStr.push_back(callback((*this)[i]));
	}
	return newStr;
}

MyString MyString::filter(int (*callback)(int)) const
{
	MyString newStr;

	for (size_t i = 0; i < this->length(); i++)
	{
		bool res = callback((*this)[i]);
		if (res)
			newStr.push_back((*this)[i]);
	}
	return newStr;
}

bool MyString::every(int (*callback)(int)) const
{
	MyString newStr;

	for (size_t i = 0; i < this->length(); i++)
	{
		bool res = callback((*this)[i]);
		if (!res)
			return false;
	}
	return true;
}

bool MyString::some(int (*callback)(int)) const
{
	MyString newStr;

	for (size_t i = 0; i < this->length(); i++)
	{
		bool res = callback((*this)[i]);
		if (res)
			return true;
	}
	return false;
}

int MyString::findIndex(int (*callback)(int)) const
{
	MyString newStr;

	for (size_t i = 0; i < this->length(); i++)
	{
		bool res = callback((*this)[i]);
		if (res)
			return i;
	}
	return -1;
}
