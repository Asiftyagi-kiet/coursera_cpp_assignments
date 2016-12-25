/**
 * PriorityQueue.h
 *
 *  Created on: Dec 25, 2016
 *      Author: Michael Melachridis
 *       Email: michael.melachridis@gmail.com
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <vector>
#include <algorithm>
#include <sstream>

namespace Dijkstra
{
	/**
	 *	This class models a structure called a priority queue.
	 *	Lower priority numbers correspond to higher effective properties
	 *
	 *	@see https://en.wikipedia.org/wiki/Priority_queue
	 *
	 *	@author Michael Melachridis
	 */
	template <typename T>
	class PriorityQueue
	{
	public:

		/**
		 * Initializes a new empty priority queue
		 */
		PriorityQueue() : heap(std::vector<HeapEntry<T>* >()) {}

		~PriorityQueue() {
			for (unsigned int i = 0; i < heap.size(); i++) {
				delete heap[i];
			}
			this->clear();
		}

		/**
		 * Adds element to the queue with the specified priority.
		 * @param element the element to be added
		 * @param priority its priority
		 */
		void push(T element, double priority) {
			heap.push_back(new HeapEntry<T>(element, priority));
			std::push_heap(heap.begin(), heap.end(), GreaterThanComparator<HeapEntry<T>* >());
		}

		/**
		 * Removes and returns the highest priority value
		 * @return he highest priority value
		 */
		void pop() {
			std::pop_heap(heap.begin(), heap.end(), GreaterThanComparator<HeapEntry<T>* >());
			heap.pop_back();
		}

		/**
		 * Changes the priority of queue element.
		 *
		 * @param element 	The node element
		 * @param priority	the new priority
		 */
		void changePriority(T element, double priority) {

		}

		/**
		 * removes the top element of the queue.
		 */
		void minPrioirty();

		/**
		 * Checks if queue contains element
		 *
		 * @param element the element to be checked upon
		 * @return <code>true</code> if it does and <code>false</code> otherwise
		 */
		bool contains(T element);

		/**
		 * Returns the top element of the queue.
		 * @return the top element of the queue
		 */
		T& top() {
			return heap[0]->value;
		}

		/**
		 * Return the number of queue elements.
		 * @return the number of queue elements
		 */
		int size() {
			return heap.size();
		}

		/**
		 * Removes all elements from the priority queue.
		 */
		void clear() {
			heap.clear();
		}

		/**
		 * Checks if the priority queue contains no elements.
		 * @return Returns <code>true</code> if the priority queue contains no elements,
		 *         and <code>false</code> otherwise
		 */
		bool isEmpty() const {
			return heap.empty();
		}

		/**
		 *	Prints out the priority queue
		 */
		friend std::ostream& operator<<(std::ostream& os, const PriorityQueue<T>& pq) {
			std::stringstream ss;
			typename std::vector<HeapEntry<T>* >::const_iterator itr = pq.heap.begin();
			while (itr!= pq.heap.end()) {
				ss << *((*itr)->value) << "(" << (*itr)->priority << ")" << std::endl;
				++itr;
			}
			return (os << ss.str());
		}

	private:

		/**
		 * HeapEntry type used for each queue element
		 */
		template <typename E>
	    class HeapEntry
		{
	    public:
	    	HeapEntry() : value(NULL), priority(0.0) {}
	    	HeapEntry(T value, double priority) : value(value), priority(priority) {}
	    	E value;
	    	double priority;
	    };

		template <typename O>
	    class GreaterThanComparator
		{
	    public:
			inline bool operator()(const O& entry1, const O& entry2) {
				return (entry1->priority > entry2->priority);
			}
	    };

		std::vector<HeapEntry<T>* > heap;
	};
}


#endif /* PRIORITYQUEUE_H_ */
