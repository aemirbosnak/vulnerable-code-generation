//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct Edge {
  int src, dst;
  struct Edge* next;
} Edge;

typedef struct Vertex {
  int num;
  struct Vertex* neighbors;
} Vertex;

Vertex* createVertex(int num) {
  Vertex* vertex = malloc(sizeof(Vertex));
  vertex->num = num;
  vertex->neighbors = NULL;
  return vertex;
}

Edge* createEdge(int src, int dst) {
  Edge* edge = malloc(sizeof(Edge));
  edge->src = src;
  edge->dst = dst;
  edge->next = NULL;
  return edge;
}

void drawTopology(Vertex* vertices, Edge* edges) {
  for (Vertex* vertex = vertices; vertex; vertex = vertex->neighbors) {
    printf("%d:", vertex->num);
    for (Edge* edge = vertex->neighbors; edge; edge = edge->next) {
      printf(" ----> %d", edge->dst);
    }
    printf("\n");
  }
}

int main() {
  Vertex* vertices = createVertex(0);
  vertices = createVertex(1);
  vertices = createVertex(2);
  vertices = createVertex(3);
  vertices = createVertex(4);

  Edge* edges = createEdge(0, 1);
  edges = createEdge(1, 2);
  edges = createEdge(2, 3);
  edges = createEdge(3, 4);

  drawTopology(vertices, edges);

  return 0;
}