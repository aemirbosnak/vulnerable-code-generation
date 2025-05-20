//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
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

Network* createNetwork(int numVertices) {
  Network* network = (Network*)malloc(sizeof(Network));
  network->numVertices = numVertices;
  network->graph = (Vertex**)malloc(numVertices * sizeof(Vertex*));
  for (int i = 0; i < numVertices; i++) {
    network->graph[i] = NULL;
  }
  return network;
}

void addEdge(Network* network, int sourceVertex, int targetVertex) {
  Vertex* source = network->graph[sourceVertex];
  if (source == NULL) {
    source = network->graph[sourceVertex] = (Vertex*)malloc(sizeof(Vertex));
    source->index = sourceVertex;
    source->next = NULL;
  }
  source->next = (Vertex*)malloc(sizeof(Vertex));
  source->next->index = targetVertex;
  source->next->next = NULL;
}

void printNetwork(Network* network) {
  for (int i = 0; i < network->numVertices; i++) {
    Vertex* vertex = network->graph[i];
    printf("Vertex %d: ", i);
    while (vertex) {
      printf("-> Vertex %d ", vertex->index);
      vertex = vertex->next;
    }
    printf("\n");
  }
}

int main() {
  Network* network = createNetwork(5);
  addEdge(network, 0, 1);
  addEdge(network, 0, 2);
  addEdge(network, 1, 2);
  addEdge(network, 2, 3);
  addEdge(network, 3, 4);
  addEdge(network, 4, 0);

  printNetwork(network);

  free(network);
  return 0;
}