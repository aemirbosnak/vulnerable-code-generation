//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Edge {
  int src, dest;
  struct Edge* next;
} Edge;

typedef struct Vertex {
  int num;
  Edge* edges;
} Vertex;

Vertex* createVertex(int num) {
  Vertex* v = (Vertex*)malloc(sizeof(Vertex));
  v->num = num;
  v->edges = NULL;
  return v;
}

void addEdge(Vertex* v1, Vertex* v2) {
  Edge* e = (Edge*)malloc(sizeof(Edge));
  e->src = v1->num;
  e->dest = v2->num;
  e->next = v1->edges;
  v1->edges = e;
}

void mapTopology(Vertex* v) {
  printf("Vertex %d:", v->num);
  for (Edge* e = v->edges; e; e = e->next) {
    printf(" - Edge to Vertex %d", e->dest);
  }
  printf("\n");
}

int main() {
  Vertex* vertices[MAX_VERTICES];
  for (int i = 0; i < MAX_VERTICES; i++) {
    vertices[i] = createVertex(i);
  }

  addEdge(vertices[0], vertices[1]);
  addEdge(vertices[1], vertices[2]);
  addEdge(vertices[2], vertices[3]);
  addEdge(vertices[3], vertices[4]);

  mapTopology(vertices[0]);

  return 0;
}