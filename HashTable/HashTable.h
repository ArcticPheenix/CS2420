/*
Name: Christopher Kelly
Course:	CS2420
Instructor:	Todd Peterson
Project: HashTable

I hereby declare that all code contain herin was written solely by me.
*/

#ifndef HASHTABLE_CLASS_H
#define HASHTABLE_CLASS_H
#include <string>
#include "Node.h"
template <typename T>
class HashTable
{
private:
	static const int SIZE = 26;	// Arbitrary size. Refers to number of letters in English alphabet.
	Node<T>* dataArray[SIZE];
	int hash(std::string key);
	T retrieve(std::string key);
public:
	HashTable();
	~HashTable();
	void clear();
	void insert(std::string key, T value);
	T operator[](std::string key);
};

template <typename T>
HashTable<T>::HashTable()
{
	//this->dataArray = new Node<T>*[SIZE];
	
	// Initialize node* in each element to nullptr.
	for (int i = 0; i < SIZE; i++)
	{
		this->dataArray[i] = nullptr;
	}
}

template <typename T>
HashTable<T>::~HashTable()
{
	clear();
	//delete[] dataArray;
}

// Generate hash value from given key.
// Ensure that resulting value fits wihin SIZE-1.
template <typename T>
int HashTable<T>::hash(std::string key)
{
	const int HASH_MULTIPLIER = 4091;	// Prime value to assist with lowered collision probabilities.
	int arraySize = SIZE;
	int asciiValue = 0;
	int result = 0;
	for (unsigned i = 0; i < key.size(); i++)
	{
		asciiValue = asciiValue + (int)key[i];
	}
	result = (asciiValue * HASH_MULTIPLIER) % arraySize;
	return result;
}

template <typename T>
T HashTable<T>::retrieve(std::string key)
{
	// Lookup 'key' in hash table. If 'key' is found, return value.
	int indexValue = hash(key);
	if ((indexValue < 0) || (indexValue >= SIZE)) { return 0; }
	Node<T>* tempNode = this->dataArray[indexValue];
	while (tempNode != nullptr)
	{
		if (tempNode->key == key) { return tempNode->value; }
		else { tempNode = tempNode->next; }
	}
	T result = 0;
	return result;
}

// Iterate over every list in every element of dataArray.
// Remove lists attached to array elements.
// Delete array.
template <typename T>
void HashTable<T>::clear()
{
	for (int i = 0; i < SIZE; i++)
	{
		Node<T>* tempNode = dataArray[i];
		Node<T>* tempNode2 = nullptr;
		if (tempNode == nullptr) { continue; }
		while (tempNode != nullptr)
		{
			tempNode2 = tempNode->next;
			delete tempNode;
			tempNode = tempNode2;
		}
	}
}

// Hash 'key' to find storage location in dataArray.
// Append key/value pair to list.
template <typename T>
void HashTable<T>::insert(std::string key, T value)
{
	int hashValue = hash(key);
	Node<T>* tempNode = dataArray[hashValue];
	if (tempNode == nullptr)
	{
		tempNode = new Node<T>(key, value);
		dataArray[hashValue] = tempNode;
	}
	else
	{
		while (tempNode->next != nullptr)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = new Node<T>(key, value);
	}
}

template <typename T>
T HashTable<T>::operator[](std::string key)
{
	return retrieve(key);
}
#endif