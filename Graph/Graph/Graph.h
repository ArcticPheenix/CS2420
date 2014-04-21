#ifndef GRAPH_CLASS_H
#define GRAPH_CLASS_H
#include "Set.h"

class Graph
{
	Graph();
	~Graph();
	void add_edge(int weight, int v1, int v2);
	void add_vertex(int v);
	bool is_edge();
	void depthFirstSearch(int v);
};

#endif