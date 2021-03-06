#if !defined(ITERABLE_HPP)
#define ITERABLE_HPP
#include <stdio.h>
#include <iostream>
template <typename T>
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

	Iterable() : _iter(), length(0) { return; };

	Iterable forEach(void (*callback)(T value, size_t index)) const
	{
		for (size_t i = 0; i < this->length; i++)
			callback((this->_iter)[i], i);
		return *this;
	};

	T *getValue() const
	{
		return this->_iter;
	};

	Iterable filter(bool (*callback)(T value, size_t index)) const
	{
		Iterable newIter;

		for (size_t i = 0; i < this->length; i++)
		{
			bool res = callback((this->_iter)[i], i);
			if (res)
				newIter.pushBack(this->_iter[i]);
		}
		return newIter;
	};

	Iterable map(T (*callback)(T value, size_t index)) const
	{
		Iterable newIter;
		for (size_t i = 0; i < this->length; i++)
		{
			newIter.pushBack(callback(this->_iter[i], i));
		}
		return newIter;
	};

	bool every(bool (*callback)(T value, size_t index)) const
	{
		for (size_t i = 0; i < this->length; i++)
		{
			bool res = callback((this->_iter)[i], index);
			if (!res)
				return false;
		}
		return true;
	};

	bool some(bool (*callback)(T value, size_t index)) const
	{
		for (size_t i = 0; i < this->length; i++)
		{
			bool res = callback((this->_iter)[i]);
			if (res)
				return true;
		}
		return false;
	};

	size_t findIndex(bool (*callback)(T value, size_t index)) const
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
		// T *tmpIter = (T *)malloc(sizeof(T) * (this->length + 1));

		T *tmpIter = new T[sizeof(T) * (this->length + 1)];
		i = 0;
		while (i < this->length)
		{
			tmpIter[i] = this->_iter[i];
			i += 1;
		}
		tmpIter[i] = input;
		delete[] this->_iter;
		this->_iter = tmpIter;
		this->length += 1;
		return *this;
	};

	template <typename X = T>
	X reduce(X (*callback)(X acc, T curr, size_t index), X acc)
	{
		for (size_t i = 0; i < this->length; i++)
		{
			acc = callback(acc, this->_iter[i], i);
		}
		return acc;
	}
};

#endif // ITERABLE_HPP
