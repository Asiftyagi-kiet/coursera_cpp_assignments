/**
 * ShortestPathAlgo.cpp
 *
 *  Created on: Dec 25, 2016
 *      Author: Michael Melachridis
 *       Email: michael.melachridis@gmail.com
 */

#include "ShortestPathAlgo.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

namespace Dijkstra
{
	ShortestPathAlgo::ShortestPathAlgo(Graph &graph) :
			graph(graph),
			distTo(std::vector<double>(graph.getV()+1, INFINITY)),
			edgeTo(std::vector<Edge<int>* >(graph.getV()+1)),
			pq(graph.getV()+1),
			shortestPath(std::vector<Node<int>*>())
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

	const ShortestPathAlgo::listOfVertices ShortestPathAlgo::path(int src, int dest) {

		std::vector< std::list<Edge<int>* > > adj = graph.getAdjacencyList();

		validateVertex(src);

		pq.push(src, 0);
		distTo[src] = 0;

		while (!pq.isEmpty()) {

			int u = pq.top();
			pq.pop();

			int previous = 0;

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

					if (u != previous) { // workaround to store unique nodes in seq
						previous = u;
						shortestPath.push_back((*itr)->getX());
					}

					if (pq.contains(y)) {
						pq.changePriority(y, distTo[y]);
					} else {
						pq.push(y, distTo[y]);
					}
				}
				++itr;
			}
		}
		return shortestPath;
	}

	double ShortestPathAlgo::pathSize(int x, int y) {
		validateVertex(x);
		validateVertex(y);

		double path_size = 0;
		for (int i = 0; i < (int) distTo.size(); ++i) {
			if (i >= x && i <= y)
				path_size += distTo[i];
		}
		return path_size;
	}

	void ShortestPathAlgo::printShortestPath(int u, int w) {
		validateVertex(u);
		validateVertex(w);

		std::stringstream ss;
		ss << std::setprecision(2);

		const std::vector<Node<int>*>  sp = path(u, w);

		// Print shortest distances stored in distTo
		ss << "Vertex   Distance from Source" << std::endl;
		for (unsigned int i = 0; i < distTo.size(); ++i) {
			ss << i << "\t\t" << distTo[i] << std::endl;
		}

		ss << "--------------------" << std::endl;

		ss << "path cost from " << u << " to " << w << ": " << pathSize(1, 3) << std::endl;

		ss << "shortest path sequence from " << u << " to " << w << ": ";
		std::vector<Node<int>*>::const_iterator it;
		for (it = sp.begin(); it != sp.end(); ++it) {
			ss << (*it)->getValue() << "->";
		}
		ss << w << std::endl;

		std::cout << ss.str();
	}
}

