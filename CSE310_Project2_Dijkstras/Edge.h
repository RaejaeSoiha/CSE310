#ifndef EDGE_H
#define EDGE_H

class Edge {
private:
    int startVert;  // start vertex of the edge
    int endVert;    // End vertex of the edge
    int weight;     // Weight of the edge

public:
    Edge();                 // Default constructor
    Edge(int, int);         // Constrcutor with start and end vertices
    int getWeight();        // Method to get the weight of the edge
    void setWeight(int);    // Methos to set the weight of the edge
};

#endif
