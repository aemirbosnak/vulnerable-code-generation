//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10

typedef struct Vertex {
  int index;
  struct Vertex* neighbors;
  struct Vertex* next;
} Vertex;

void insertVertex(Vertex** graph, int index) {
  *graph = (Vertex*)malloc(sizeof(Vertex));
  (*graph)->index = index;
  (*graph)->neighbors = NULL;
  (*graph)->next = NULL;
}

void insertEdge(Vertex* graph, int neighborIndex) {
  Vertex* neighbor = (Vertex*)malloc(sizeof(Vertex));
  neighbor->index = neighborIndex;
  neighbor->neighbors = NULL;
  neighbor->next = graph->neighbors;
  graph->neighbors = neighbor;
}

void printGraph(Vertex* graph) {
  printf("Vertex %d: ", graph->index);
  for (Vertex* neighbor = graph->neighbors; neighbor; neighbor = neighbor->next) {
    printf("-> Neighbor %d ", neighbor->index);
  }
  printf("\n");
}

int main() {
  Vertex** graph = NULL;
  insertVertex(&graph, 0);
  insertVertex(&graph, 1);
  insertVertex(&graph, 2);
  insertVertex(&graph, 3);
  insertVertex(&graph, 4);

  insertEdge(graph[0], 1);
  insertEdge(graph[0], 2);
  insertEdge(graph[1], 2);
  insertEdge(graph[1], 3);
  insertEdge(graph[2], 4);

  printGraph(graph[0]);
  printGraph(graph[1]);
  printGraph(graph[2]);

  return 0;
}