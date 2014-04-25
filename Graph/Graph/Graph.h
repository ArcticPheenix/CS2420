#ifndef GRAPH_CLASS_H
#define GRAPH_CLASS_H
#include "Set.h"

class Graph
{
private:
	int NUM_OF_NODES = 10;
	int** adjacencyMatrix;
	bool* visitedTable;
	void resetVisitedTable();
	void dfsHelper(int v, bool* visitedArray);
	void fspHelper(int v, Set* neighborSet, int* distanceArray, int previousVertex);
public:
	Graph();
	Graph(int initSize);
	~Graph();
	void add_edge(int weight, int v1, int v2);
	void add_vertex(int v);
	void depthFirstSearch(int v);
	void findShortestPath(int v);
	bool is_edge(int v1, int v2);
	Set* neighbors(int v);
};

#endif