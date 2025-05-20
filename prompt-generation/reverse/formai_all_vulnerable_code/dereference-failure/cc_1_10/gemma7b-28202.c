//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10

typedef struct Vertex {
  int index;
  struct Vertex* next;
} Vertex;

typedef struct Graph {
  int numVertices;
  Vertex** adjacencyList;
} Graph;

Graph* createGraph() {
  Graph* graph = malloc(sizeof(Graph));
  graph->numVertices = 0;
  graph->adjacencyList = NULL;
  return graph;
}

void addVertex(Graph* graph) {
  graph->numVertices++;
  graph->adjacencyList = realloc(graph->adjacencyList, graph->numVertices * sizeof(Vertex*));
  graph->adjacencyList[graph->numVertices - 1] = malloc(sizeof(Vertex));
  graph->adjacencyList[graph->numVertices - 1]->index = graph->numVertices - 1;
  graph->adjacencyList[graph->numVertices - 1]->next = NULL;
}

void addEdge(Graph* graph, int src, int dest) {
  Vertex* vertex = graph->adjacencyList[src];
  Vertex* newVertex = malloc(sizeof(Vertex));
  newVertex->index = dest;
  newVertex->next = NULL;
  vertex->next = newVertex;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Vertex* vertex = graph->adjacencyList[i];
    printf("Vertex %d: ", vertex->index);
    while (vertex) {
      printf("-> ");
      vertex = vertex->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph();
  addVertex(graph);
  addVertex(graph);
  addVertex(graph);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  traverseGraph(graph);
  return 0;
}