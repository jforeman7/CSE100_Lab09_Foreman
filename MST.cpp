// Jeff Foreman
// CSE 100 03L
// Lab 09: MST

#include <iostream>

using namespace std;

class Vertice
{
	int verticeID;
	int weight;
	
	public:
	Vertice(int verticeID, int weight)
	{
		this->verticeID = verticeID;
		this->weight = weight;
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
