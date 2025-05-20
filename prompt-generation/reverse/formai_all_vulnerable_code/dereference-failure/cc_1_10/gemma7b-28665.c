//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Vertex {
  int index;
  struct Vertex* next;
} Vertex;

typedef struct Graph {
  Vertex** graph;
  int numVertices;
} Graph;

Graph* createGraph() {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->graph = (Vertex**)malloc(MAX_VERTICES * sizeof(Vertex));
  graph->numVertices = 0;

  return graph;
}

void addVertex(Graph* graph, int index) {
  graph->numVertices++;

  graph->graph[index] = (Vertex*)malloc(sizeof(Vertex));
  graph->graph[index]->index = index;
  graph->graph[index]->next = NULL;
}

void addEdge(Graph* graph, int srcIndex, int destIndex) {
  Vertex* srcVertex = graph->graph[srcIndex];
  Vertex* destVertex = graph->graph[destIndex];

  srcVertex->next = destVertex;
}

void printGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Vertex* vertex = graph->graph[i];

    printf("Vertex %d: ", vertex->index);

    Vertex* neighbor = vertex->next;
    while (neighbor) {
      printf("-> Neighbor %d ", neighbor->index);
      neighbor = neighbor->next;
    }

    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph();

  addVertex(graph, 0);
  addVertex(graph, 1);
  addVertex(graph, 2);
  addVertex(graph, 3);

  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph);

  return 0;
}