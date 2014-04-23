#ifndef SET_CLASS_H
#define SET_CLASS_H
#include "list.h"

class Set
{
	list l;
	Set();
	~Set();
	void insert(int n);
	bool is_in(int n);
};
#endif