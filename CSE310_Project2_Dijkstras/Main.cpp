
#include "Graph.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    int numOfVertices;          // Variable to store the number of vertices
    int numOfEdges;             // Variable to store the number of edges

    std::istream* input = &std::cin;  // Default to reading from stdin

    // Check if a filename is provided as a command-line argument
    if (argc > 1) {
        std::ifstream* inputFile = new std::ifstream(argv[1]); // Open the provided file
        if (!*inputFile) {
            std::cerr << "Error: Unable to open " << argv[1] << std::endl; // Display error message if file cannot be opened
            delete inputFile;
            return 1; // Return with error status
        }
        input = inputFile; // Read input from the file
    }

    *input >> numOfVertices >> numOfEdges; // Read the number of vertices and edges

    Graph graph(numOfVertices); // Create a graph object with the specified number of vertices

    for (int i = 0; i < numOfEdges; ++i) {
        int startVertex, endVertex;
        *input >> startVertex >> endVertex; // Read each edge
        graph.addEdge(startVertex, endVertex); // Add the edge to the graph
    }

    if (input != &std::cin) {
        delete input; // Close the file if opened
    }

    std::cout << "The adjacency matrix of G:" << std::endl;
    graph.printAdjacencyMatrix(); // Print the adjacency matrix of the graph

    int *oddDegreeVertices = graph.getOddDegreeVertices(); // Get the odd degree vertices in the graph
    std::cout << "\n\tThe odd degree vertices in G:" << std::endl;
    std::cout << "O = { ";
    for (int i = 0; oddDegreeVertices[i] != -1; ++i) {
        std::cout << oddDegreeVertices[i] << " "; // Print the odd degree vertices
    }
    std::cout << "}\n" << std::endl;

    for (int i = 0; oddDegreeVertices[i] != -1; ++i) {
        int vertex = oddDegreeVertices[i];
        std::cout << "Single source shortest path lengths from node " << vertex << std::endl;
        int *shortestPathLengths = graph.singleSourceShortestPath(vertex); // Compute shortest path lengths from the current vertex
        for (int j = 1; j <= numOfVertices; ++j) {
            std::cout << "  " << j << ": " << shortestPathLengths[j] << std::endl; // Print shortest path lengths
        }
        delete[] shortestPathLengths; // Deallocate memory for shortest path lengths array
        std::cout << std::endl;
    }
    delete[] oddDegreeVertices; // Deallocate memory for odd degree vertices array

    return 0;
}
