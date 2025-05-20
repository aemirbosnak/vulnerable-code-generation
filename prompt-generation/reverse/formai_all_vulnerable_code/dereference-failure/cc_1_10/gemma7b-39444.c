//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 10
#define MAX_EDGES 20

typedef struct Vertex {
  int index;
  struct Vertex* neighbors;
} Vertex;

typedef struct Edge {
  int src, dst;
  struct Edge* next;
} Edge;

void createVertex(Vertex** v) {
  *v = (Vertex*)malloc(sizeof(Vertex));
  (*v)->index = MAX_VERTS;
  (*v)->neighbors = NULL;
}

void createEdge(Edge** e, int src, int dst) {
  *e = (Edge*)malloc(sizeof(Edge));
  (*e)->src = src;
  (*e)->dst = dst;
  (*e)->next = NULL;
}

void mapTopology(Vertex* v) {
  printf("Vertex %d: ", v->index);
  for (Edge* e = v->neighbors; e; e = e->next) {
    printf("-> Vertex %d ", e->dst);
  }
  printf("\n");
}

int main() {
  Vertex* vertices = NULL;
  Edge* edges = NULL;

  createVertex(&vertices);
  createVertex(&vertices);
  createVertex(&vertices);

  createEdge(&edges, 0, 1);
  createEdge(&edges, 1, 2);
  createEdge(&edges, 2, 0);

  mapTopology(vertices);

  return 0;
}