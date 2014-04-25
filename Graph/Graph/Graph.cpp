#include <iostream>
#include "Graph.h"
Graph::Graph()
{
	// Allocate memory for default graph
	adjacencyMatrix = new int*[NUM_OF_NODES];
	for (int i = 0; i < NUM_OF_NODES; i++)
	{
		adjacencyMatrix[i] = new int[NUM_OF_NODES];
	}
	// Initialize adjacency matrix
	for (int i = 0; i < NUM_OF_NODES; i++)
	{
		for (int j = 0; j < NUM_OF_NODES; j++)
		{
			adjacencyMatrix[i][j] = -1;
		}
	}
	// Initialize visit table
	visitedTable = new bool[NUM_OF_NODES];
	for (int k = 0; k < NUM_OF_NODES; k++)
	{
		visitedTable[k] = false;
	}
}

Graph::Graph(int initSize)
{
	NUM_OF_NODES = initSize;
	// Allocate memory for default graph
	adjacencyMatrix = new int*[NUM_OF_NODES];
	for (int i = 0; i < NUM_OF_NODES; i++)
	{
		adjacencyMatrix[i] = new int[NUM_OF_NODES];
	}
	// Initialize adjacency matrix
	for (int i = 0; i < NUM_OF_NODES; i++)
	{
		for (int j = 0; j < NUM_OF_NODES; j++)
		{
			adjacencyMatrix[i][j] = -1;
		}
	}
	// Initialize visit table
	visitedTable = new bool[NUM_OF_NODES];
	for (int k = 0; k < NUM_OF_NODES; k++)
	{
		visitedTable[k] = false;
	}
}

Graph::~Graph()
{
	for (int i = 0; i < NUM_OF_NODES; ++i)
	{
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;
}

void Graph::resetVisitedTable()
{
	for (int k = 0; k < NUM_OF_NODES; k++)
	{
		visitedTable[k] = false;
	}
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
	// Reset visitedTable
	// Recursively visit each vertex connected to 'v'
	// so long as it hasn't been visited before
	resetVisitedTable();
	std::cout << "Executing Depth First Search: ";
	dfsHelper(v, visitedTable);
}

void Graph::dfsHelper(int v, bool* visitedArray)
{
	if (v >= NUM_OF_NODES) { return; }
	else if (visitedArray[v] == true) { return; }
	else
	{
		visitedArray[v] = true;
		std::cout << v << " ";
		for (int i = 0; i < NUM_OF_NODES; ++i)
		{
			if (adjacencyMatrix[v][i] == -1) { continue; }
			else
			{
				dfsHelper(i, visitedArray);
			}
		}
	}
}

void Graph::findShortestPath(int v)
{
	std::cout << "\nExecuting Dijkstra's algorithm using vertex " << v << std::endl;
	resetVisitedTable();
	int* distanceArray = new int[NUM_OF_NODES];
	for (int i = 0; i < NUM_OF_NODES; ++i)
	{
		distanceArray[i] = -1;
	}

	distanceArray[v] = 0;
	Set* allowedVertices = new Set();
	allowedVertices->insert(v);
	fspHelper(v, allowedVertices, distanceArray, v);

	for (int i = 0; i < NUM_OF_NODES; ++i)
	{
		std::cout << distanceArray[i] << " ";
	}
}

void Graph::fspHelper(int v, Set* allowed, int* distanceArray, int previousVertex)
{
	int sum = 0;
	Set* adjacentSet = this->neighbors(v);
	Iterator asItr = adjacentSet->begin();
	for (asItr; asItr.is_item(); ++asItr)
	{
		if (!(allowed->is_in(*asItr)))
		{
			allowed->insert(*asItr);
			if ((distanceArray[*asItr] == -1) && (previousVertex == v))
			{
				sum = adjacencyMatrix[v][*asItr];
				distanceArray[*asItr] = sum;
			}
			else if ((distanceArray[*asItr] == -1) && (previousVertex != v))
			{
				std::cout << "\nDebug: " << adjacencyMatrix[v][*asItr] << " " << distanceArray[previousVertex] << std::endl;
				sum = 2 + adjacencyMatrix[v][*asItr] + distanceArray[previousVertex];
				distanceArray[*asItr] = sum;
			}
			else
			{
				std::cout << "\nDebug: " << adjacencyMatrix[v][*asItr] << " " << distanceArray[previousVertex] << std::endl;
				sum = adjacencyMatrix[v][*asItr] + distanceArray[previousVertex];
				if (sum < distanceArray[*asItr]) { distanceArray[*asItr] = sum; }
			}
		}
		else
		{
			std::cout << "\nDebug: " << adjacencyMatrix[v][*asItr] << " " << distanceArray[v] << std::endl;
			sum = adjacencyMatrix[v][*asItr] + distanceArray[v];
			if (sum < distanceArray[*asItr]) { distanceArray[*asItr] = sum; }
		}
	}
	asItr = adjacentSet->begin();
	for (asItr; asItr.is_item(); ++asItr)
	{
		fspHelper(*asItr, allowed, distanceArray, v);
	}
}

bool Graph::is_edge(int v1, int v2)
{
	if (adjacencyMatrix[v1][v2] != -1) { return true; }
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