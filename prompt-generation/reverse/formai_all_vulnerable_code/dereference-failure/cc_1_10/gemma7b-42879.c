//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

typedef struct Network {
    int numVertices;
    Vertex** adjacencyList;
} Network;

void createNetwork(Network* network) {
    network->numVertices = MAX_VERTICES;
    network->adjacencyList = (Vertex**)malloc(network->numVertices * sizeof(Vertex*));
    for (int i = 0; i < network->numVertices; i++) {
        network->adjacencyList[i] = NULL;
    }
}

void addVertex(Network* network, int index) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;

    network->adjacencyList[index] = vertex;
}

void addEdge(Network* network, int sourceIndex, int destinationIndex) {
    Vertex* sourceVertex = network->adjacencyList[sourceIndex];
    Vertex* destinationVertex = network->adjacencyList[destinationIndex];

    sourceVertex->next = destinationVertex;
}

void printNetwork(Network* network) {
    for (int i = 0; i < network->numVertices; i++) {
        Vertex* vertex = network->adjacencyList[i];
        printf("Vertex %d: ", vertex->index);
        Vertex* neighbor = vertex->next;
        while (neighbor) {
            printf("Neighbor %d ", neighbor->index);
            neighbor = neighbor->next;
        }
        printf("\n");
    }
}

int main() {
    Network* network = (Network*)malloc(sizeof(Network));
    createNetwork(network);

    addVertex(network, 0);
    addVertex(network, 1);
    addVertex(network, 2);
    addVertex(network, 3);

    addEdge(network, 0, 1);
    addEdge(network, 1, 2);
    addEdge(network, 2, 3);

    printNetwork(network);

    return 0;
}