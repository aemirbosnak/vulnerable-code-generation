//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Vertex {
  int index;
  struct Vertex* next;
} Vertex;

Vertex* createVertex(int index) {
  Vertex* vertex = malloc(sizeof(Vertex));
  vertex->index = index;
  vertex->next = NULL;
  return vertex;
}

void addEdge(Vertex* vertex1, Vertex* vertex2) {
  vertex1->next = vertex2;
}

void traverseGraph(Vertex* vertex) {
  printf("%d ", vertex->index);
  Vertex* neighbor = vertex->next;
  while (neighbor) {
    printf("%d ", neighbor->index);
    neighbor = neighbor->next;
  }
  printf("\n");
}

int main() {
  Vertex* vertices[MAX_VERTICES];
  for (int i = 0; i < MAX_VERTICES; i++) {
    vertices[i] = NULL;
  }

  // Create a graph
  vertices[0] = createVertex(0);
  vertices[1] = createVertex(1);
  vertices[2] = createVertex(2);
  vertices[3] = createVertex(3);
  vertices[4] = createVertex(4);

  addEdge(vertices[0], vertices[1]);
  addEdge(vertices[0], vertices[2]);
  addEdge(vertices[1], vertices[3]);
  addEdge(vertices[2], vertices[4]);

  // Traverse the graph
  traverseGraph(vertices[0]);

  return 0;
}