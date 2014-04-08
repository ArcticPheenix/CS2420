#include "Node.h"
#include "Iterator.h"
#include "list.h"

// CONSTRUCTOR
list::list( )
{
    head = nullptr;
}
	
// postcondition: all nodes in the list are destroyed.
list::~list()
{
    Node* tempNode = head;
    while (tempNode != nullptr)
    {
        Node* deleteNode = tempNode;
        tempNode = tempNode->next;
        deleteNode = nullptr;
        delete deleteNode;
    }
}
    
// MODIFICATION MEMBER FUNCTIONS
//postcondition: entry is added to the front of the list
void list::insert_front(const int& entry)
{
	if (this->head == nullptr)
	{
		Node* newNode = new Node(entry);
		head = newNode;
		return;
	}
	else
	{
		Node* newNode = new Node(entry);
		newNode->next = head;
		head = newNode;
		return;
	}
}
    
//postcondition: entry is added to the back of the list
void list::add_back(const int& entry)
{
	if (this->head == nullptr)
	{
		Node* newNode = new Node(entry);
		head = newNode;
		return;
	}
	else
	{
		Node* tempNode = head;
		while (tempNode->next != nullptr)
		{
			tempNode = tempNode->next;
		}
		Node* newNode = new Node(entry);
		tempNode->next = newNode;
	}
}
	
// postcondition: all nodes with data == entry are removed from the list
void list::remove_all(const int& entry)
{
    if (this->head == nullptr) return;  // Null pointer case.
    Node* cursorNode = head;
    Node* previousNode = nullptr;
    while (cursorNode != nullptr)
    {
        // Head data match case.
        if ((cursorNode == head) && (cursorNode->key == entry))
        {
            Node* tempNode = cursorNode;
            this->head = head->next;
            cursorNode = cursorNode->next;
            tempNode = nullptr;
            delete tempNode;
            continue;
        }
        // General data match case.
        else if (cursorNode->key == entry)
        {
            Node* tempNode = cursorNode;
            previousNode->next = cursorNode->next;
            cursorNode = cursorNode->next;
            tempNode = nullptr;
            delete tempNode;
            continue;
        }
        else
        {
            previousNode = cursorNode;
            cursorNode = cursorNode->next;
        }
    }
}
	
// postcondition: an iterator is created pointing to the head of the list
Iterator list::begin(void)
{
    Iterator listItr = Iterator(head);
    return listItr;
}
		
// CONSTANT MEMBER FUNCTIONS
// postcondition: the size of the list is returned
int list::size( ) const
{
    int returnVal = 0;
    Node* tempNode = head;
    while (tempNode != nullptr)
    {
        returnVal++;
        tempNode = tempNode->next;
    }
    return returnVal;
}