#include "Graph.h"
#include "PriorityQueue.h"
#include "ShortestPathAlgo.h"
#include <string>

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

	PriorityQueue<int> pq(6);
	pq.push(6, 6.2);
	pq.push(2, 1.5);
	pq.push(3, 2.1);
	pq.push(1, 3.1);
	pq.push(4, 4.1);
	pq.push(5, 5.1);

	std::cout << pq << std::endl;
	std::cout << pq.top() << " contains 9: " << (pq.contains(9) == true ? "TRUE" : "FALSE") << std::endl;

	std::cout << std::endl;
	std::cout << "Dijkstra shortest path algorithm demo" << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;

	Graph graph(5);
	graph.addEdge(1,2,6);
	graph.addEdge(1,4,1);
	graph.addEdge(2,3,5);
	graph.addEdge(2,4,2);
	graph.addEdge(2,5,2);
	graph.addEdge(3,2,5);
	graph.addEdge(3,5,5);
	graph.addEdge(4,1,1);
	graph.addEdge(4,2,2);
	graph.addEdge(4,5,1);
	graph.addEdge(5,2,2);
	graph.addEdge(5,3,5);
	graph.addEdge(5,4,1);

	std::cout << graph << std::endl;

	ShortestPathAlgo shortestPath(graph);
	shortestPath.path(1, 3);

	std::cout << "path cost from 1 to 3: " << shortestPath.pathSize(1, 3) << std::endl;

	return 0;
}
