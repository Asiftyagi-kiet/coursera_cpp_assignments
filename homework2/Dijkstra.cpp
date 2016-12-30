#include "Graph.h"
#include "PriorityQueue.h"
#include "ShortestPathAlgo.h"

using namespace Dijkstra;

int main(int argc, char** argv)
{
	std::cout << std::endl;
	std::cout << "Dijkstra shortest path algorithm demo" << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;

	Graph randomG(10);
	randomG.generateRandomGraph(1, 1, 10);
	std::cout << randomG << std::endl;

	ShortestPathAlgo shortestPath(randomG);
	shortestPath.printShortestPath(1, 10);

	return 0;
}
