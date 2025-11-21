
#include "Vertex.h"

Vertex::Vertex() {
    // Initialize index and degree to defaul values
    this->index = -1;
    this->degree = -1;
}

int Vertex::getIndex() {
    return this->index;     // return the index of the vertex
}

int Vertex::getDegree() {
    return this->degree;    // return the degree of the vertex
}

void Vertex::setIndex(int index) {
    this->index = index;    // Set the intex of the vertex
}

void Vertex::setDegree(int deg) {
    this->degree = deg;     // Set the degree of the vertex
}
