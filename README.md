# Coursera: C++ For C Programmers, Part A

## Homework 1: Convert a C program to C++
     
## Homework 2: Implement Dijkstra's Algorithm
    This implementation is adjacency list based. Adjacency list variant use memory in proportion to the number edges, which might save a lot of memory if the adjacency matrix is sparse. It is fast to iterate over all edges, but finding the presence or absence specific edge is slightly slower than with the matrix. Adjacency matrices on the other hand use more space in order to provide constant lookup time.
    It uses 4 basic ADTs: The Node, Edge, Graph and PriorityQueue implemented as template classes.
    PriorityQueue class models a structure called a min priority queue (min heap), where lower priority numbers correspond to higher effective properties (https://en.wikipedia.org/wiki/Priority_queue).
    The Graph::generateRandomGraph funtion uses Monte Carlo metod (https://en.wikipedia.org/wiki/Monte_Carlo_method) in order to produce random data for the Graph.

