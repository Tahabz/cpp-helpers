#if !defined(ITERABLE_HPP)
#define ITERABLE_HPP
#include <stdio.h>
#include <iostream>
template <typename T, typename B>
class Iterable
{
private:
	T *_iter;
	size_t length;

public:
	Iterable(T *input, size_t length) : _iter(input), length(length)
	{
		return;
	};

	Iterable(size_t length) : length(length)
	{
		this->_iter = (T *)malloc(sizeof(T) * length);
		return;
	};

	Iterable() : _iter(), length(0) { return; };

	// ~Iterable()
	// {
	// 	delete this->_iter;
	// 	return;
	// };

	Iterable forEach(void (*callback)(B)) const
	{
		for (size_t i = 0; i < this->length; i++)
			callback((this->_iter)[i]);
		return *this;
	};

	T *getValue() const
	{
		return this->_iter;
	};

	Iterable filter(B (*callback)(B)) const
	{
		Iterable newIter;

		for (size_t i = 0; i < this->length; i++)
		{
			bool res = callback((this->_iter)[i]);
			if (res)
				newIter.pushBack((this->_iter)[i]);
		}
		return newIter;
	};

	Iterable map(B (*callback)(B)) const
	{
		Iterable newIter;
		for (size_t i = 0; i < this->length; i++)
		{
			newIter.pushBack(callback((this->_iter)[i]));
		}
		return newIter;
	};

	bool every(B (*callback)(B)) const
	{
		for (size_t i = 0; i < this->length; i++)
		{
			bool res = callback((this->_iter)[i]);
			if (!res)
				return false;
		}
		return true;
	};

	bool some(B (*callback)(B)) const
	{
		for (size_t i = 0; i < this->length; i++)
		{
			bool res = callback((this->_iter)[i]);
			if (res)
				return true;
		}
		return false;
	};

	B findIndex(B (*callback)(B)) const
	{
		for (size_t i = 0; i < this->length; i++)
		{
			bool res = callback((this->_iter)[i]);
			if (res)
				return i;
		}
		return -1;
	};

	Iterable pushBack(T input)
	{
		size_t i;
		T *tmpIter = (T *)malloc(sizeof(T) * (this->length + 1));

		i = 0;
		while (i < this->length)
		{
			tmpIter[i] = this->_iter[i];
			i += 1;
		}
		tmpIter[i] = input;
		this->_iter = tmpIter;
		this->length += 1;
		return *this;
	};
};

#endif // ITERABLE_HPP
