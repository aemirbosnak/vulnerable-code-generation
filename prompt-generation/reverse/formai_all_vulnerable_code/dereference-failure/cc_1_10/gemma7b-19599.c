//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex {
  int index;
  struct Vertex* adjacentVertices;
} Vertex;

void graph_init(Vertex** graph, int numVertices) {
  *graph = malloc(numVertices * sizeof(Vertex));
  for (int i = 0; i < numVertices; i++) {
    (*graph)[i].index = i;
    (*graph)[i].adjacentVertices = NULL;
  }
}

void graph_add_edge(Vertex* vertex, int targetVertex) {
  Vertex* newVertex = malloc(sizeof(Vertex));
  newVertex->index = targetVertex;
  newVertex->adjacentVertices = vertex->adjacentVertices;
  vertex->adjacentVertices = newVertex;
}

void graph_traverse(Vertex* vertex) {
  printf("Vertex: %d ", vertex->index);
  for (Vertex* adjacentVertex = vertex->adjacentVertices; adjacentVertex; adjacentVertex = adjacentVertex->adjacentVertices) {
    printf("-> Vertex: %d ", adjacentVertex->index);
  }
  printf("\n");
}

int main() {
  Vertex** graph;
  graph_init(&graph, MAX_VERTICES);

  graph_add_edge(graph[0], graph[1]);
  graph_add_edge(graph[0], graph[2]);
  graph_add_edge(graph[1], graph[3]);
  graph_add_edge(graph[2], graph[4]);

  graph_traverse(graph[0]);
  graph_traverse(graph[1]);

  free(graph);

  return 0;
}