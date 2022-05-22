#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class myvector
{
private:
	T* elem;
	int sz;
	int capacity;

public:
	myvector();
	myvector(int s);
	~myvector();

	T operator[](int n);
	myvector& operator=(const myvector& v);
	int size();
	int getCapacity();

	void reserve(int newalloc);
	void push_back(T& elem);
	void addAt(T&, int);
	void print();
	// other methods
};

template <typename T>
myvector<T>::myvector()
	: capacity(0), sz(0), elem(NULL)
{
}

template <typename T>
myvector<T>::myvector(int s)
{
	if (sz > 0)
		capacity += s;
	elem = new T[capacity];
	for (int i = 0; i < sz; i++)
		elem[i] = -1;
}

template <typename T>
myvector<T>::~myvector()
{
	if (elem != NULL)
		delete[] elem;
	sz = 0;
	capacity = 0;
}

template <typename T>
int myvector<T>::size()
{
	return this->sz;
}

template <typename T>
int myvector<T>::getCapacity()
{
	return this->capacity;
}

template <typename T>
T myvector<T>::operator[](int n)
{
	try
	{
		if (n<0 || n>sz - 1)
		{
			throw invalid_argument("Index out of bound!");
		}
		return elem[n];
	}
	catch (invalid_argument e)
	{
		cout << e.what() << endl;
	}
}

template <typename T>
myvector<T>& myvector<T>::operator=(const myvector<T>& v)
{
	if (this != &v)
	{
		delete[] elem;
		this->sz = v.sz;
		this->capacity = v.capacity;
		elem = new T[sz];
		for (int i = 0; i < sz; i++)
		{
			elem[i] = v.elem[i];
		}
	}
	return *this;
}

template <typename T>
void myvector<T>::reserve(int newalloc)
{
	if (newalloc < capacity)
		return;
	capacity = newalloc;
	T* temp = new T[capacity];
	for (int i = 0; i < sz; i++)
	{
		temp[i] = elem[i];
	}
	delete[] elem;
	elem = temp;
}

template <typename T>
void myvector<T>::addAt(T& d,int index)
{
	if (sz == capacity)
	{
		reserve(capacity * 2);
	}
	sz++;
	for (int i = sz - 1; i >= index; i--) 
	{
		elem[i + 1] = elem[i];
	}
	elem[index] = d;
}

template <typename T>
void myvector<T>::push_back(T& d)
{
	if (capacity == 0)
		reserve(2);
	if (sz == capacity)
	{
		reserve(capacity * 2);
	}
	elem[sz] = d;
	sz++;
}

template <typename T>
void myvector<T>::print()
{
	for (int i = 0; i < sz; ++i)
		cout << elem[i] << " ";
}
#endif
