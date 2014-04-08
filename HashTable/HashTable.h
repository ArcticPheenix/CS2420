#ifndef HASHTABLE_CLASS_H
#define HASHTABLE_CLASS_H
#include <string>
#include "Node.h"
template <typename T>
class HashTable
{
private:
	const int SIZE = 26;	// Arbitrary size. Refers to number of letters in English alphabet.
	Node* dataArray;
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
	dataArray = new Node[SIZE];
	
	// Initialize node* in each element to nullptr.
	for (int i = 0; i < SIZE; i++)
	{
		dataArray[i] = nullptr;
	}
}

template <typename T>
HashTable<T>::~HashTable()
{
	clear();
}

// Generate hash value from given key.
// Ensure that resulting value fits wihin SIZE-1.
template <typename T>
int HashTable<T>::hash(std::string key)
{
	const int HASH_MULTIPLIER = 4091;	// Prime value to assist with lowered collision probabilities.
	int asciiValue = 0;
	int result = 0;
	for (int i = 0; i < key.size(); i++)
	{
		asciiValue = asciiValue + (int)key[i];
	}
	result = (asciiValue * HASH_MULTIPLIER) % SIZE;
	return result;
}

template <typename T>
double HashTable<T>::retrieve(std::string key)
{
	// Lookup 'key' in hash table. If 'key' is found, return value.
	int indexValue = hash(key);
	if ((indexValue < 0) || (indexValue >= SIZE)) { return; }
	Node* tempNode = dataArray[indexValue];
	while (tempNode != nullptr)
	{
		if (tempNode->key == key) { return tempNode->value; }
		else { tempNode = tempNode->next; }
	}
	double result = 0;
	return result;
}

// Iterate over every list in every element of dataArray.
// Remove lists attached to array elements.
// Delete array.
template <typename T>
void HashTable<T>::clear()
{
	//TODO
}

// Hash 'key' to find storage location in dataArray.
// Append key/value pair to list.
template <typename T>
void HashTable<T>::insert(std::string key, double value)
{
	int hashValue = hash(key);
	Node* tempNode = dataArray[hashValue];
	if (tempNode == nullptr)
	{
		tempNode = new Node(key, value);
	}
	else
	{
		while (tempNode->next != nullptr)
		{
			tempNode = tempNode->next;
		}
		tempNode = new Node(key, value);
	}
}

template <typename T>
double& HashTable<T>::operator[](std::string key)
{
	return retrieve(key);
}
#endif