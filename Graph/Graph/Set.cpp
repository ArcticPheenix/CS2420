/*
Name:	Christopher Kelly
Course:	CS2420
Instructor:	Todd Peterson
Project:	Graph

I hereby declare that all code contained in this project was written solely by me.
*/

#include <iostream>
#include "Set.h"

Set::Set()
{
	l = new list();
}

Set::~Set()
{
	l->~list();
	l = nullptr;
	delete l;
}

void Set::insert(int n)
{
	l->add_back(n);
}

bool Set::is_in(int n)
{
	Iterator setItr = l->begin();
	for (int i = 0; i < l->size(); ++i)
	{
		if (*setItr == n) { return true; }
		else { ++setItr; }
	}
	return false;
}
Iterator Set::begin()
{
	return l->begin();
}