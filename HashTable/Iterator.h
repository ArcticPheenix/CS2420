// Template CLASS PROVIDED: Iterator 

#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H
#include "Node.h"

class Iterator
{
private:
	Node* n;
public:
	// Constructor
	Iterator (Node *np);
        
	// precondition: is_item is true
	// post condition n points to the next item in the list
	void operator++();
        
	// precondition: 
	// postcondition: returns true if there is a valid item
	bool is_item();
        
	// precondition: is_item == true
	// postcondition returns data that n is pointing at
	std::string operator* ();
};
#endif