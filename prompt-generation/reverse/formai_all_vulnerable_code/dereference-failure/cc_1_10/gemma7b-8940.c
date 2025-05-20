//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

typedef struct Network {
    Vertex** graph;
    int numVertices;
} Network;

Network* createNetwork(int numVertices) {
    Network* network = (Network*)malloc(sizeof(Network));
    network->graph = (Vertex**)malloc(numVertices * sizeof(Vertex));
    network->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        network->graph[i] = NULL;
    }

    return network;
}

void addVertex(Network* network, int index) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = network->graph[index] = vertex;
}

void mapTopology(Network* network) {
    for (int i = 0; i < network->numVertices; i++) {
        Vertex* vertex = network->graph[i];
        printf("Vertex %d: ", vertex->index);
        while (vertex) {
            printf("-> ");
            vertex = vertex->next;
        }
        printf("\n");
    }
}

int main() {
    Network* network = createNetwork(5);
    addVertex(network, 0);
    addVertex(network, 1);
    addVertex(network, 2);
    addVertex(network, 3);
    addVertex(network, 4);

    mapTopology(network);

    return 0;
}