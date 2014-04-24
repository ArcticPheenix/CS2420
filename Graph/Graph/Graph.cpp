#include <iostream>
#include "Graph.h"
Graph::Graph()
{
	// Initialize adjacency matrix
	for (int i = 0; i < NUM_OF_NODES; i++)
	{
		for (int j = 0; j < NUM_OF_NODES; j++)
		{
			adjacencyMatrix[i][j] = -1;
		}
	}
	// Initialize visit table
	for (int k = 0; k < NUM_OF_NODES; k++)
	{
		visitTable[k] = false;
	}
}

Graph::~Graph()
{

}

void Graph::add_edge(int weight, int v1, int v2)
{
	// Validate param values
	// If valid, create edge from vertex 1, to vertex 2
	if ((v1 < NUM_OF_NODES) && (v2 < NUM_OF_NODES) && (weight > -1))
	{
		adjacencyMatrix[v1][v2] = weight;
		std::cout << "Added edge from " << v1 << " to " << v2 << " with a weight of " << weight << std::endl;
	}
	// Invalid values detected
	else
	{
		std::cout << "Invalid values given" << std::endl;
		std::cout << "Weight: " << weight << " V1: " << v1 << " V2: " << v2 << std::endl;
	}
}

void Graph::add_vertex(int v)
{

}

void Graph::depthFirstSearch(int v)
{

}

void Graph::findShortestPath(int v)
{

}

bool Graph::is_edge()
{
	return false;
}

Set* Graph::neighbors(int v)
{
	Set* neighbors = new Set();
	for (int i = 0; i < NUM_OF_NODES; ++i)
	{
		if (adjacencyMatrix[v][i] == -1) { continue; }
		neighbors->insert(i);
	}
	return neighbors;
}