//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Graph {
  int numVertices;
  int numEdges;
  struct Edge **edges;
} Graph;

typedef struct Edge {
  int srcVertex;
  int destVertex;
  struct Edge *nextEdge;
} Edge;

Graph *createGraph(int numVertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->numEdges = 0;
  graph->edges = (struct Edge **)malloc(numVertices * sizeof(struct Edge *));
  for (int i = 0; i < numVertices; i++) {
    graph->edges[i] = NULL;
  }
  return graph;
}

void addEdge(Graph *graph, int srcVertex, int destVertex) {
  Edge *edge = (Edge *)malloc(sizeof(Edge));
  edge->srcVertex = srcVertex;
  edge->destVertex = destVertex;
  edge->nextEdge = NULL;

  graph->edges[srcVertex] = edge;
  graph->numEdges++;
}

int main() {
  Graph *graph = createGraph(5);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 0);

  for (int i = 0; i < graph->numVertices; i++) {
    for (Edge *edge = graph->edges[i]; edge; edge = edge->nextEdge) {
      printf("%d -> %d\n", edge->srcVertex, edge->destVertex);
    }
  }

  return 0;
}