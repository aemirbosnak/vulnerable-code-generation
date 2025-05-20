//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

typedef struct Network {
    int numVertices;
    Vertex** graph;
} Network;

void createNetwork(Network* network) {
    network->numVertices = 0;
    network->graph = NULL;
}

void addVertex(Network* network) {
    network->numVertices++;
    network->graph = realloc(network->graph, network->numVertices * sizeof(Vertex*));
    network->graph[network->numVertices - 1] = malloc(sizeof(Vertex));
    network->graph[network->numVertices - 1]->index = network->numVertices - 1;
    network->graph[network->numVertices - 1]->next = NULL;
}

void addEdge(Network* network, int vertex1, int vertex2) {
    Vertex* vertex1Ptr = network->graph[vertex1];
    Vertex* vertex2Ptr = network->graph[vertex2];

    vertex1Ptr->next = vertex2Ptr;
    vertex2Ptr->next = vertex1Ptr;
}

void printNetwork(Network* network) {
    for (int i = 0; i < network->numVertices; i++) {
        Vertex* vertexPtr = network->graph[i];
        printf("Vertex %d: ", vertexPtr->index);
        while (vertexPtr) {
            printf("-> Vertex %d ", vertexPtr->next->index);
            vertexPtr = vertexPtr->next;
        }
        printf("\n");
    }
}

int main() {
    Network* network = malloc(sizeof(Network));
    createNetwork(network);

    addVertex(network);
    addVertex(network);
    addVertex(network);
    addEdge(network, 0, 1);
    addEdge(network, 1, 2);

    printNetwork(network);

    free(network);

    return 0;
}