// Jeff Foreman
// CSE 100 03L
// Lab 09: MST

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <limits> // For infinity.

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
	
	vector<int> *parent;
	
	// Constructor. Adds in all the vertices in the graph.
	Graph(int V)
	{
		this->V = V;
		adjacencyList = new list<pair<int,int> >[V];
		parent = new vector<int>(V, -1);
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
		// Root of the MST is vertex 0.
		int root = 0;
		
		// Create a Priority Queue to do automatic sorting of the vertices.
		priority_queue<Vertex, vector<Vertex>, greater<Vertex> > queue;
		
		// Keep track of the keys in a vector, and set a sentinel value of the largest possible int, 
		// which will be greater than all possible values used in the graph.
		vector<int> key(V, numeric_limits<int>::max());
		
		// Keeps track of the parents, with a sentinel value of -1 in the beginning.
		//vector<int> parent(V, -1);
		
		// Keeps track if a vertex is in the MST.
		vector<bool> included(V, false);
		
		// Place the root into the queue to begin the algorithm.
		queue.push(make_pair(0, root));
		key[root] = 0;
		
		while(!queue.empty())
		{
			// Extract the min.
			int u = queue.top().second;
			queue.pop();
			
			// Vertex u is now in the MST.
			included[u] = true;
			
			// Use the STL iterator to get all of the  adjacent vertices to u.
			list<pair<int,int> >::iterator i;
			
			// Do an STL for loop.
			// Use pre-iterator to be able to get the end().
			for(i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i)
			{
				// Get the vertex-weight pair.
				int v = (*i).first;
				int w = (*i).second;
				
				// If the vertex is not in the MST, and is smaller, place in MST.
				if(key[v] > w && included[v] == false)
				{
					// Assign the weight associated with the vertex.
					key[v] = w;
					queue.push(make_pair(key[v], v));
					
					// Since this was found from u, u is the parent of v.
					parent[v] = u;
				} // End if.
				
			} // End i loop.
			
		} // End while loop.
		
		// Print out the results.
		for(int i = 1; i < V; ++i)
			cout << parent[i] << endl;
		
	} // End trim().
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
	
	// Perform Prim's algorithm and print out the MST.
	mst.trim();
	
	return 0;	
}
