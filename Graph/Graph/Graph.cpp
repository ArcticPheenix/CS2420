#include "Graph.h"
Graph::Graph()
{
	// Initialize adjacency matrix
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			adjacencyMatrix[i][j] = -1;
		}
	}
	// Initialize visit table
	for (int k = 0; k < 7; k++)
	{
		visitTable[k] = false;
	}
}

Graph::~Graph()
{

}

void Graph::add_edge(int weight, int v1, int v2)
{

}

void Graph::add_vertex(int v)
{

}

bool Graph::is_edge()
{
	return false;
}

void Graph::depthFirstSearch(int v)
{

}