/*
Name:	Christopher Kelly
Course:	CS2420
Instructor:	Todd Peterson
Project:	Graph

I hereby declare that all code contained in this project was written solely by me.
*/

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