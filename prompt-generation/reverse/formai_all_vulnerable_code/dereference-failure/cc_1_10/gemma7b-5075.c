//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    int index;
    struct Vertex *next;
} Vertex;

typedef struct Network {
    Vertex **vertices;
    int numVertices;
} Network;

void createNetwork(Network *network) {
    network->vertices = (Vertex **)malloc(network->numVertices * sizeof(Vertex));
    for (int i = 0; i < network->numVertices; i++) {
        network->vertices[i] = (Vertex *)malloc(sizeof(Vertex));
        network->vertices[i]->index = i;
        network->vertices[i]->next = NULL;
    }
}

void addEdge(Network *network, int src, int dest) {
    Vertex *vertex = network->vertices[src];
    Vertex *newNode = (Vertex *)malloc(sizeof(Vertex));
    newNode->index = dest;
    newNode->next = NULL;
    vertex->next = newNode;
}

void printTopology(Network *network) {
    for (int i = 0; i < network->numVertices; i++) {
        printf("Vertex %d: ", network->vertices[i]->index);
        Vertex *vertex = network->vertices[i]->next;
        while (vertex) {
            printf("-> Vertex %d ", vertex->index);
            vertex = vertex->next;
        }
        printf("\n");
    }
}

int main() {
    Network *network = (Network *)malloc(sizeof(Network));
    network->numVertices = 5;
    createNetwork(network);
    addEdge(network, 0, 1);
    addEdge(network, 0, 2);
    addEdge(network, 1, 3);
    addEdge(network, 2, 4);
    printTopology(network);

    return 0;
}