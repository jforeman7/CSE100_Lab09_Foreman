// Jeff Foreman
// CSE 100 03L
// Lab 09: MST

#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

// A vertice and its associated weight.
// Uses typedef for compatiblity with Priority Queue.
typedef pair<int, int> Vertex;

// Representation of a graph.
class Graph
{
	public:
	
	// Number of vertices in the graph.
	int V;
	
	// List of the vertices in the graph.
	list<pair<int,int> > *adjacencyList;
	
	// Constructor. Adds in all the vertices in the graph.
	Graph(int V)
	{
		this->V = V;
		adjacencyList = new list<pair<int,int> >[V];
	}
	
	// Inserts in an edge between two vertices, and the associated cost to travel between them.
	void insertEdge(int u, int v, int w)
	{
		// Add vertex 'u' to the adjacency list of vertex 'v', and then vice versa for 'u'.
		adjacencyList[v].push_back(make_pair(u, w));
		adjacencyList[u].push_back(make_pair(v, w));	
	}
	
	// Trim the base graph to make into a MST using Prim's algorithm.
	void trim()
	{
		priority_queue<Vertex, vector<Vertex>, greater<Vertex> > queue;
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
	
	// Create the graph.
	Graph mst(V);
	
	// Vertex u, v, and weight w.
	int u, v, w;
	
	// Add in the edges between the vertices.
	for(int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		mst.insertEdge(u, v, w);
	}
	
	return 0;	
}
