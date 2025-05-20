//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Vertex {
  int index;
  struct Vertex* next;
} Vertex;

typedef struct Graph {
  int numVertices;
  Vertex**adjList;
} Graph;

Graph* createGraph(int numVertices) {
  Graph* graph = malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjList = malloc(numVertices * sizeof(Vertex*));
  for (int i = 0; i < numVertices; i++) {
    graph->adjList[i] = NULL;
  }
  return graph;
}

void addVertex(Graph* graph, int index) {
  Vertex* vertex = malloc(sizeof(Vertex));
  vertex->index = index;
  vertex->next = graph->adjList[index] = vertex;
}

void printGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Vertex* vertex = graph->adjList[i];
    printf("%d: ", i);
    while (vertex) {
      printf("%d ", vertex->index);
      vertex = vertex->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph(5);
  addVertex(graph, 0);
  addVertex(graph, 1);
  addVertex(graph, 2);
  addVertex(graph, 3);
  addVertex(graph, 4);

  printGraph(graph);

  return 0;
}