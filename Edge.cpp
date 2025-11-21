#include "Edge.h"

Edge::Edge() {

    // Initialize start and end vertices, and weight to default values
    this->startVert = -1;
    this->endVert = -1;
    this->weight = -1;
}

Edge::Edge(int start, int end) {

    // Initialize start and end vertices, and set weight to default value of 1
    this->startVert = start;
    this->endVert = end;
    this->weight = 1;
}

int Edge::getWeight() {
    return this->weight;    // Return the weight of the edge
}

void Edge::setWeight(int newWeight) {
    this->weight = newWeight;   // Set the weight of the edge to the new value
}
