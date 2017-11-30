// Jeff Foreman
// CSE 100 03L
// Lab 09: MST

#include <iostream>

using namespace std;

// A vertice and its associated weight.
class Vertice
{
	public:
	
	// ID number of the vertice.
	int verticeID;
	
	// Weight of the vertice.
	int weight;
	
	// Constructor.
	Vertice(int verticeID, int weight)
	{
		this->verticeID = verticeID;
		this->weight = weight;
	}
};

// Representation of a graph.
class Graph
{
	int V;
}

int main()
{
	// Number of vertices in the graph.
	int V;
	
	// Number of edges in the graph.
	int E;
	
	// Take in the number of vertices and edges for the graph.
	cin >> V >> E;
	
	return 0;	
}
