#ifndef LIST_NODE_H
#define LIST_NODE_H

namespace list_1
{
	struct Node
	{
		int data;
		Node *next;

		// Constructor
		// Postcondition: 
		Node (int d);
	};
}
#endif