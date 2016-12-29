/**
 * ShortestPathAlgo.cpp
 *
 *  Created on: Dec 25, 2016
 *      Author: Michael Melachridis
 *       Email: michael.melachridis@gmail.com
 */

#include "ShortestPathAlgo.h"
#include "IndexMinPQ.h"

#include <vector>
#include <iostream>
#include <queue>

namespace Dijkstra
{
	ShortestPathAlgo::ShortestPathAlgo(Graph &graph) :
			graph(graph),
			distTo(std::vector<double>(graph.getV()+1, INF)),
			edgeTo(std::vector<Edge<int>* >(graph.getV()+1)),
			pq(graph.getV()+1)
	{
	}

	const ShortestPathAlgo::listOfVertices ShortestPathAlgo::vertices() const {
		listOfVertices v(graph.getV());

		for (unsigned int i = 1; i < graph.getAdjacencyList().size(); ++i) {
			Graph::listOfEdgesConstItr it = graph.getAdjacencyList()[i].begin();

			while (it != graph.getAdjacencyList()[i].end()) {
				v.push_back((*it)->getX());
				++it;
			}
		}
		return v;
	}

	ShortestPathAlgo::listOfVertices ShortestPathAlgo::path(int src, int dest) {

		listOfVertices shortestPath;
		std::vector< std::list<Edge<int>* > > adj = graph.getAdjacencyList();

		validateVertex(src);

		pq.push(src, 0);
		distTo[src] = 0;

		while (!pq.isEmpty()) {

			int u = pq.top();
			pq.pop();

			Graph::listOfEdgesConstItr itr = adj[u].begin(); // neighbors
			while (itr != adj[u].end()) {

				// Get vertex label and weight of current adjacent
				int y = (*itr)->getY()->getValue();
				double w = (*itr)->getWeight();

				// relax
				if (distTo[y] > distTo[u] + w) {
					distTo[y] = distTo[u] + w;
					pq.push(y, distTo[y]);
					edgeTo[y] = (*itr);

					if (pq.contains(y)) {
						pq.changePriority(y, distTo[y]);
					} else {
						pq.push(y, distTo[y]);
					}
				}
				++itr;
			}
		}

		// Print shortest distances stored in distTo
		std::cout << "Vertex   Distance from Source" << std::endl;
		for (unsigned int i = 0; i < distTo.size(); ++i) {
			std::cout << i << "\t\t" << distTo[i] << std::endl;
		}

		std::cout << "--------------------------------" << std::endl;
	}

	double ShortestPathAlgo::pathSize(int x, int y) {
		validateVertex(x);
		validateVertex(y);

		double path_size = 0;
		for (int i = 0; i < distTo.size(); ++i) {
			if (i >= x && i <= y)
				path_size += distTo[i];
		}
		return path_size;
	}
}

