/*
Name: Christopher Kelly
Course:	CS2420
Instructor:	Todd Peterson
Project: HashTable

I hereby declare that all code contain herin was written solely by me.
*/

#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <string>

template <typename T>
class Node
{
public:
	std::string key;
	T value;
	Node<T>* next;
	Node(std::string key, T value);
};

template <typename T>
Node<T>::Node(std::string key, T value)
{
	this->key = key;
	this->value = value;
	this->next = nullptr;
}
#endif