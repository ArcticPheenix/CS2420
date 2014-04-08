#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <string>

struct Node
{
	std::string key;
	double value;
	Node *next;

	// Constructor
	// Postcondition: 
	Node (std::string key, double value);
};
#endif