/*
Name:	Christopher Kelly
Course:	CS2420
Instructor:	Todd Peterson
Project:	Graph

I hereby declare that all code contained in this project was written solely by me.
*/

#include <iostream>
#include "Graph.h"

int main()
{
	Graph* dfs = new Graph(7);
	Graph* dijkstra = new Graph(6);

	// Create edges for dfs graph
	dfs->add_edge(1, 0, 1);
	dfs->add_edge(1, 0, 4);
	dfs->add_edge(1, 1, 3);
	dfs->add_edge(1, 2, 0);
	dfs->add_edge(1, 3, 0);
	dfs->add_edge(1, 3, 5);
	dfs->add_edge(1, 3, 6);
	dfs->add_edge(1, 6, 1);

	// Create edges for dijkstra graph
	dijkstra->add_edge(2, 0, 1);
	dijkstra->add_edge(9, 0, 5);
	dijkstra->add_edge(8, 1, 2);
	dijkstra->add_edge(15, 1, 3);
	dijkstra->add_edge(6, 1, 5);
	dijkstra->add_edge(1, 2, 3);
	dijkstra->add_edge(3, 5, 4);
	dijkstra->add_edge(3, 4, 3);
	dijkstra->add_edge(7, 4, 2);

	// Perform depth-first search on dfs graph
	dfs->depthFirstSearch(0);

	// Perform Dijkstra's algorithm on each node of the dijkstra graph
	for (int i = 0; i < 6; ++i)
	{
		dijkstra->findShortestPath(i);
	}

	system("PAUSE");
	return 0;
}