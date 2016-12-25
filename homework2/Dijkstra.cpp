#include "Graph.h"

using namespace Dijkstra;

int main(int argc, char** argv)
{
	std::cout << "Dijkstra's algorithm Demo" << std::endl;

	Graph myGraph(5);

	myGraph.addEdge(1,3);
	myGraph.addEdge(2,3);
	myGraph.addEdge(3,1);
	myGraph.addEdge(3,2);
	myGraph.addEdge(3,4);
	myGraph.addEdge(3,5);
	myGraph.addEdge(4,3);
	myGraph.addEdge(5,3);

	std::cout << myGraph << std::endl;
	std::cout << "Is 1 adjacent to 2? " << ( (myGraph.isAdjacent(1, 2) == true) ? "TRUE" : "FALSE") << std::endl;
	std::cout << "Is 1 adjacent to 3? " << ( (myGraph.isAdjacent(1, 3) == true) ? "TRUE" : "FALSE") << std::endl;

	Graph g(4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(2,1);
	g.addEdge(3,1);
	g.addEdge(3,2);
	g.addEdge(3,4);
	g.addEdge(4,1);
	g.addEdge(4,2);
	g.addEdge(4,3);

	std::cout << g << std::endl;

	Graph randomG(10);

	randomG.generateRandomGraph(0.1, 1, 10);

	std::cout << randomG << std::endl;

	return 0;
}
