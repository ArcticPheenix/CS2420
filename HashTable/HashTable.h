#ifndef HASHTABLE_CLASS_H
#define HASHTABLE_CLASS_H
#include <string>
template <typename T>
class HashTable
{
private:
	const int SIZE = 26;	// Arbitrary size. Refers to number of letters in English alphabet.
	int* dataArray;
	int hash(string key);
	double retrieve(string key);
public:
	HashTable();
	~HashTable();
	void clear();
	void insert(string key, double value);
	const double operator[](string key) const;
};

template <typename T>
HashTable<T>::HashTable()
{
	//TODO
}

template <typename T>
HashTable<T>::~HashTable()
{
	//TODO
}

template <typename T>
int HashTable<T>::hash(string key)
{
	//TODO
	int result = 0;
	return result;
}

template <typename T>
double HashTable<T>::retrieve(string key)
{
	//TODO
	double result = 0;
	return result;
}

template <typename T>
void HashTable<T>::clear()
{
	//TODO
}

template <typename T>
void HashTable<T>::insert(string key, double value)
{
	//TODO
}

template <typename T>
const double& operator[](string key) const
{
	//TODO
}
#endif