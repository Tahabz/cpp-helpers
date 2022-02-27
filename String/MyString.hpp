#if !defined(MYSTRING__HPP)
#define MYSTRING__HPP
#include <iostream>

class MyString : public std::string
{

	std::string _str;

public:
	MyString(std::string input = "");

	void forEach(void (*callback)(int)) const;
	MyString map(int (*callback)(int)) const;
	MyString filter(int (*callback)(int)) const;
	bool every(int (*callback)(int)) const;
	bool some(int (*callback)(int)) const;
	int findIndex(int (*callback)(int)) const;
};

#endif
