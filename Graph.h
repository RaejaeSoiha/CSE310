#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>

class Graph {
private:
    int numVertices;
    int **adjacencyMatrix; // Adjacency matrix representation

public:
    Graph(int numVertices);                             // Constructor to initialize the graph with a given number of vertices
    void addEdge(int startVertex, int endVertex);       // Method to add an edge between two vertices
    void printAdjacencyMatrix() const;                  // Method to print the adjacency matrix of the graph
    int *getOddDegreeVertices() const;                  // Method to get vertices with odd degrees
    int *singleSourceShortestPath(int source) const;    // Method to find shortest path from a source vertex
    void printShortestPathLengths(int vertex, int *shortestPathLengths) const; // Method to print shortest path lengths from a vertex
    ~Graph();                                           // Destructor to free memory
};

#endif
