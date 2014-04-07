#include <string>
#ifndef HASHTABLE_CLASS_H
#define HASHTABLE_CLASS_H

template <typename T>
class HashTable
{
private:
	const int SIZE = 26;	// Arbitrary size. Refers to number of letters in English alphabet.
	int* dataArray;
	int hash(String key);
	double retrieve(String key);
public:
	HashTable();
	~HashTable();
	void clear();
	void insert(String key, double value);
	const double& operator[](String key) const;
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
int HashTable<T>::hash(String key)
{
	//TODO
}

template <typename T>
double HashTable<T>::retrieve(String key)
{
	//TODO
}

template <typename T>
void HashTable<T>::clear()
{
	//TODO
}

template <typename T>
void HashTable<T>::insert(String key, double value)
{
	//TODO
}

template <typename T>
const double& operator[](String key) const
{
	//TODO
}
#endif