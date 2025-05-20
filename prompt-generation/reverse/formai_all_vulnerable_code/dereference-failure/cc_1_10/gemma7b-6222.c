//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_Vertices 10

typedef struct Vertex {
  char name[20];
  struct Vertex* neighbors[MAX_Vertices];
  int distance;
} Vertex;

Vertex* createVertex(char* name) {
  Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
  strcpy(vertex->name, name);
  vertex->distance = -1;
  for (int i = 0; i < MAX_Vertices; i++) {
    vertex->neighbors[i] = NULL;
  }
  return vertex;
}

void addNeighbors(Vertex* vertex, Vertex* neighbor) {
  vertex->neighbors[vertex->neighbors[0] == NULL] = neighbor;
}

void printGraph(Vertex* vertex) {
  printf("Vertex: %s\n", vertex->name);
  printf("Distance: %d\n", vertex->distance);
  printf("Neighbors:\n");
  for (int i = 0; vertex->neighbors[i] != NULL; i++) {
    printf("  %s\n", vertex->neighbors[i]->name);
  }
}

int main() {
  Vertex* a = createVertex("A");
  Vertex* b = createVertex("B");
  Vertex* c = createVertex("C");
  Vertex* d = createVertex("D");
  Vertex* e = createVertex("E");

  addNeighbors(a, b);
  addNeighbors(a, c);
  addNeighbors(b, d);
  addNeighbors(c, e);

  printGraph(a);
  printGraph(b);
  printGraph(c);

  return 0;
}