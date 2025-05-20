//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Vertex {
  int index;
  struct Vertex* next;
} Vertex;

void create_graph(Vertex** graph) {
  *graph = malloc(sizeof(Vertex) * MAX_VERTICES);
  for (int i = 0; i < MAX_VERTICES; i++) {
    graph[i] = NULL;
  }
}

void add_vertex(Vertex** graph, int index) {
  Vertex* new_vertex = malloc(sizeof(Vertex));
  new_vertex->index = index;
  new_vertex->next = NULL;

  if (graph[index] == NULL) {
    graph[index] = new_vertex;
  } else {
    graph[index]->next = new_vertex;
  }
}

void map_topology(Vertex* vertex) {
  printf("Vertex %d: ", vertex->index);
  for (Vertex* neighbor = vertex->next; neighbor; neighbor = neighbor->next) {
    printf("-> Neighbor %d ", neighbor->index);
  }
  printf("\n");
}

int main() {
  Vertex** graph = NULL;
  create_graph(&graph);

  add_vertex(graph, 0);
  add_vertex(graph, 1);
  add_vertex(graph, 2);
  add_vertex(graph, 3);
  add_vertex(graph, 4);

  map_topology(graph[0]);
  map_topology(graph[2]);

  return 0;
}