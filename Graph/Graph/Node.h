#ifndef LIST_NODE_H
#define LIST_NODE_H

struct Node
{
	int data;
	Node *next;

	// Constructor
	// Postcondition: 
	Node (int d);
};
#endif