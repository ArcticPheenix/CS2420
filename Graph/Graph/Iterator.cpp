/*
Name:	Christopher Kelly
Course:	CS2420
Instructor:	Todd Peterson
Project:	Graph

I hereby declare that all code contained in this project was written solely by me.
*/

#include "Node.h"
#include "Iterator.h"

// Constructor
Iterator::Iterator (Node *np)
{
    n = np;
}
    
// precondition: is_item is true
// post condition n points to the next item in the list
void Iterator::operator++()
{
    if (is_item())
    {
        n = n->next;
        return;
    }
    else return;
}
    
// precondition:
// postcondition: returns true if there is a valid item
bool Iterator::is_item()
{
    if (n != nullptr) return true;
    else return false;
}
    
// precondition: is_item == true
// postcondition returns data that n is pointing at
int Iterator::operator* ()
{
    return n->data;
}