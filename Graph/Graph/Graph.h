#ifndef GRAPH_CLASS_H
#define GRAPH_CLASS_H
#include "Set.h"

class Graph
{
private:
	static const int NUM_OF_NODES = 10;
	int adjacencyMatrix[NUM_OF_NODES][NUM_OF_NODES];
	bool visitTable[NUM_OF_NODES];
public:
	Graph();
	~Graph();
	void add_edge(int weight, int v1, int v2);
	void add_vertex(int v);
	void depthFirstSearch(int v);
	void findShortestPath(int v);
	bool is_edge();
	Set* neighbors(int v);
};

#endif