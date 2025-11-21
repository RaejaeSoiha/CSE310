#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
private:
    int index;  // Index of the vertex
    int degree; // Degree of the vertex

public:
    Vertex();               // Default constructor
    int getIndex();         // Method to get the index of the vertex
    int getDegree();        // Method to get the degree of the vertex
    void setIndex(int);     // Method to set the index of the vertex
    void setDegree(int);    // Method to set the degree of the vertex
};

#endif
