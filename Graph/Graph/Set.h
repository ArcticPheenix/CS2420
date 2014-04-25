/*
Name:	Christopher Kelly
Course:	CS2420
Instructor:	Todd Peterson
Project:	Graph

I hereby declare that all code contained in this project was written solely by me.
*/

#ifndef SET_CLASS_H
#define SET_CLASS_H
#include "list.h"

class Set
{
private:
	list* l;
public:
	Set();
	~Set();
	void insert(int n);
	bool is_in(int n);
	Iterator begin();
};
#endif