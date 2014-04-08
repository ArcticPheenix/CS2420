#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <string>

template <typename T>
class Node
{
	std::string key;
	double value;
	Node<T>* next;

	// Constructor
	// Postcondition: 
	Node (std::string key, double value);
};

template <typename T>
Node<T>::Node(std::string key, double value)
{
	this->key = key;
	this->value = value;
	this->next = nullptr;
}
#endif