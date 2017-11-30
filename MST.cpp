// Jeff Foreman
// CSE 100 03L
// Lab 09: MST

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// A vertice and its associated weight.
class Vertex
{
	public:
	
	// ID number of the vertex.
	int vertexID;
	
	// Weight of the vertex.
	int weight;
	
	// Constructor.
	Vertex(int vertexID, int weight)
	{
		this->vertexID = vertexID;
		this->weight = weight;
	}
};

// Representation of a graph.
class Graph
{
	public:
	
	// Number of vertices in the graph.
	int V;
	
	// List of the vertices in the graph.
	list<Vertex> *adjacencyList;
	
	// Constructor. Adds in all the vertices in the graph.
	Graph(int V)
	{
		this->V = V;
		adjacencyList = new list<Vertex>[V];
	}
	
	// Inserts in an edge between two vertices, and the associated cost to travel between them.
	void insertEdge(int u, int v, int w)
	{
		Vertex vertexU(u,w);
		Vertex vertexV(v,w);
		
		adjacencyList[u].push_back(vertexV);
		adjacencyList[v].push_back(vertexU);
	}
};

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
