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