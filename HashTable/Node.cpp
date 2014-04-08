#include "Node.h"

Node::Node(std::string key, double value)
{
    this->key = key;
	this->value = value;
    this->next = nullptr;
}