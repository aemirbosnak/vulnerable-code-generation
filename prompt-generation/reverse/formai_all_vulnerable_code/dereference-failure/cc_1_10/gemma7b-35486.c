//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Edge {
  int src, dst;
  struct Edge* next;
} Edge;

typedef struct Vertex {
  char name[20];
  Edge* edges;
  struct Vertex* next;
} Vertex;

Vertex* createVertex(char* name) {
  Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
  strcpy(vertex->name, name);
  vertex->edges = NULL;
  vertex->next = NULL;
  return vertex;
}

Edge* createEdge(int src, int dst) {
  Edge* edge = (Edge*)malloc(sizeof(Edge));
  edge->src = src;
  edge->dst = dst;
  edge->next = NULL;
  return edge;
}

void mapTopology(Vertex* vertex) {
  printf("%s:", vertex->name);
  for (Edge* edge = vertex->edges; edge; edge = edge->next) {
    printf(" - %s", edge->dst);
  }
  printf("\n");
}

int main() {
  Vertex* vertices[MAX_VERTICES];
  for (int i = 0; i < MAX_VERTICES; i++) {
    vertices[i] = NULL;
  }

  Edge* edges[MAX_EDGES];
  for (int i = 0; i < MAX_EDGES; i++) {
    edges[i] = NULL;
  }

  // Create some vertices
  vertices[0] = createVertex("A");
  vertices[1] = createVertex("B");
  vertices[2] = createVertex("C");

  // Create some edges
  edges[0] = createEdge(0, 1);
  edges[1] = createEdge(1, 2);
  edges[2] = createEdge(2, 0);

  // Map the topology
  mapTopology(vertices[0]);
  mapTopology(vertices[1]);
  mapTopology(vertices[2]);

  return 0;
}