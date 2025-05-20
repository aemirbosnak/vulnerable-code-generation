//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Vertex {
  int index;
  struct Vertex* next;
} Vertex;

void create_graph(Vertex** graph) {
  *graph = malloc(MAX_VERTICES * sizeof(Vertex));
  for (int i = 0; i < MAX_VERTICES; i++) {
    graph[i] = NULL;
  }
}

void add_edge(Vertex** graph, int src, int dst) {
  Vertex* v = graph[src];
  if (v == NULL) {
    v = graph[src] = malloc(sizeof(Vertex));
    v->index = src;
    v->next = NULL;
  }
  v->next = malloc(sizeof(Vertex));
  v->next->index = dst;
  v->next->next = NULL;
}

void map_topology(Vertex* graph) {
  for (Vertex* v = graph; v; v = v->next) {
    printf("%d ", v->index);
  }
  printf("\n");
}

int main() {
  Vertex** graph;
  create_graph(&graph);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);
  map_topology(graph[0]);
  map_topology(graph[1]);
  map_topology(graph[2]);

  return 0;
}