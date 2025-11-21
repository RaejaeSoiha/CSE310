
#include "Graph.h"
#include <climits>

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;                
    adjacencyMatrix = new int*[numVertices + 1];    
    for (int i = 0; i <= numVertices; ++i) {
        adjacencyMatrix[i] = new int[numVertices + 1];
        for (int j = 0; j <= numVertices; ++j) {
            adjacencyMatrix[i][j] = 0;              
        }
    }
}

void Graph::addEdge(int startVertex, int endVertex) {
    adjacencyMatrix[startVertex][endVertex] = 1;    
    adjacencyMatrix[endVertex][startVertex] = 1;    
}

void Graph::printAdjacencyMatrix() const {
    for (int i = 1; i <= numVertices; ++i) {
        for (int j = 1; j <= numVertices; ++j) {
            std::cout << std::setw(2) << adjacencyMatrix[i][j] << " ";  
        }
        std::cout << std::endl;
    }
}

int* Graph::getOddDegreeVertices() const {
    int *oddDegreeVertices = new int[numVertices];      
    int count = 0;                                      
    for (int i = 1; i <= numVertices; ++i) {
        int degree = 0;                                
        for (int j = 1; j <= numVertices; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                degree++;                              
            }
        }
        if (degree % 2 != 0) {
            oddDegreeVertices[count++] = i;             
        }
    }
    oddDegreeVertices[count] = -1;                      
    return oddDegreeVertices;   
}

int* Graph::singleSourceShortestPath(int source) const {
    int *distances = new int[numVertices + 1];          
    bool *visited = new bool[numVertices + 1];          

    for (int i = 1; i <= numVertices; ++i) {
        distances[i] = (i == source) ? 0 : INT_MAX;     // Initialize distances to infinity, except for the source vertex
        visited[i] = false; 
    }

    distances[source] = 0;                              

    for (int i = 1; i <= numVertices; ++i) {
        int currentVertex = -1;
        for (int j = 1; j <= numVertices; ++j) {
            if (!visited[j] && (currentVertex == -1 || distances[j] < distances[currentVertex])) {
                currentVertex = j;
            }
        }
        visited[currentVertex] = true;
        for (int j = 1; j <= numVertices; ++j) {
            if (adjacencyMatrix[currentVertex][j] == 1) {
                if (distances[currentVertex] + 1 < distances[j] || distances[j] == -1) {
                    distances[j] = distances[currentVertex] + 1;
                }
            }
        }
    }
    delete[] visited;
    return distances;   
}

void Graph::printShortestPathLengths(int vertex, int *shortestPathLengths) const {
    std::cout << "\nSingle source shortest path lengths from node " << vertex << std::endl;
    for (int j = 1; j <= numVertices; ++j) {
        std::cout << std::setw(3) << j << ": " << std::setw(2) << shortestPathLengths[j] << std::endl;  
    }
    std::cout << std::endl;
}

Graph::~Graph() {
    for (int i = 0; i <= numVertices; ++i) {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
}
