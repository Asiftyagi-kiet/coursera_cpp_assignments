/**
 * ShortestPathAlgo.h
 *
 *  Created on: Dec 25, 2016
 *      Author: Michael Melachridis
 *       Email: michael.melachridis@gmail.com
 */

#ifndef SHORTESTPATHALGO_H_
#define SHORTESTPATHALGO_H_

#include "Graph.h"
#include "PriorityQueue.h"
#include <set>

namespace Dijkstra
{
	static const double INFINITY = 9999;

	/**
	 * This class implements the mechanics of Dijkstra’s algorithm
	 *
	 * @author Michael Melachridis
	 */
	class ShortestPathAlgo
	{
		typedef std::vector<Node<int>*> listOfVertices;

	public:

		ShortestPathAlgo(Graph &graph);
		~ShortestPathAlgo() {};

		/**
		 * List of all vertices in G(V,E)
		 * @return list of all vertices
		 */
		const listOfVertices vertices() const;

		/**
		 *
		 * Finds the shortest paths from src to all other vertices
		 *
		 * find shortest path between src-dest (i.e u-w)
		 * @param src	The source vertex
		 * @param dest 	The destination vertex
		 *
		 * @return The sequence of vertices representing shortest path u-v1-v2-…-vn-w.
		 */
		const listOfVertices path(int src, int dest);

		/**
		 * Returns the path cost associated with the shortest path.
		 * @param x Node
		 * @param y Node
		 * @return the path cost
		 */
		double pathSize(int x, int y);

		/**
		 * Prints the shortest path u-v1-v2-…-vn-w.
		 */
		void printShortestPath(int u, int w);

	private:

		void validateVertex(int v) {
			int V = distTo.size();
			assert (v > 0 || v <= V);  // vertex | 0 | (V-1)
		}

		Graph &graph;
		std::vector<double> distTo;        	// distTo[v] = distance  of shortest u->w path
		std::vector<Edge<int>* > edgeTo;   	// edgeTo[v] = last edge on shortest u->w path
		PriorityQueue<double> pq;			// priority queue of vertices
		listOfVertices shortestPath;		// the sequence of vertices representing shortest path u-v1-v2-…-vn-w.
	};
}



#endif /* SHORTESTPATHALGO_H_ */
