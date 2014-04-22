#ifndef GRAPH_CLASS_H
#define GRAPH_CLASS_H
#include "Set.h"

class Graph
{
private:
	int adjacencyMatrix[7][7];
	bool visitTable[7];
public:
	Graph();
	~Graph();
	void add_edge(int weight, int v1, int v2);
	void add_vertex(int v);
	bool is_edge();
	void depthFirstSearch(int v);
};

#endif