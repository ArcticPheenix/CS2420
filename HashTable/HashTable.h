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
	dataArray = new int[SIZE];
}

template <typename T>
HashTable<T>::~HashTable()
{
	clean();
}

template <typename T>
int HashTable<T>::hash(std::string key)
{
	//TODO
	// Generate hash value from given key.
	// Ensure that resulting value fits wihin SIZE-1;
	int result = 0;
	return result;
}

template <typename T>
double HashTable<T>::retrieve(std::string key)
{
	//TODO
	// Lookup 'key' in hash table. If 'key' is found, return value.
	double result = 0;
	return result;
}

template <typename T>
void HashTable<T>::clear()
{
	//TODO
	// Iterate over every list in every element of dataArray.
	// Remove lists attached to array elements.
	// Delete array.
}

template <typename T>
void HashTable<T>::insert(std::string key, double value)
{
	//TODO
	// Hash 'key' to find storage location in dataArray.
	// Append key/value pair to list.
}

template <typename T>
double& HashTable<T>::operator[](std::string key)
{
	return retrieve(key);
}
#endif