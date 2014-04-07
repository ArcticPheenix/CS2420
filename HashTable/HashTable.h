#ifndef HASHTABLE_CLASS_H
#define HASHTABLE_CLASS_H
#include <string>
template <typename T>
class HashTable
{
private:
	const int SIZE = 26;	// Arbitrary size. Refers to number of letters in English alphabet.
	int* dataArray;
	int hash(std::string key);
	double retrieve(std::string key);
public:
	HashTable();
	~HashTable();
	void clear();
	void insert(std::string key, double value);
	double& operator[](std::string key);
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
	clean();
}

template <typename T>
int HashTable<T>::hash(std::string key)
{
	//TODO
	int result = 0;
	return result;
}

template <typename T>
double HashTable<T>::retrieve(std::string key)
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
void HashTable<T>::insert(std::string key, double value)
{
	//TODO
}

template <typename T>
double& HashTable<T>::operator[](std::string key)
{
	return retrieve(key);
}
#endif