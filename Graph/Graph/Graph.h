#ifndef GRAPH_CLASS_H
#define GRAPH_CLASS_H
#include "Set.h"

class Graph
{
private:
	static const int NUM_OF_NODES = 10;
	int adjacencyMatrix[NUM_OF_NODES][NUM_OF_NODES];
	bool visitedTable[NUM_OF_NODES];
	void resetVisitedTable();
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