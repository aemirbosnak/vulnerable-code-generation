//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10

typedef struct Vertex {
  int index;
  struct Vertex* next;
  char name[20];
} Vertex;

typedef struct Graph {
  int numVertices;
  Vertex** graph;
} Graph;

Graph* createGraph() {
  Graph* graph = malloc(sizeof(Graph));
  graph->numVertices = 0;
  graph->graph = NULL;
  return graph;
}

void addVertex(Graph* graph, char* name) {
  Vertex* vertex = malloc(sizeof(Vertex));
  vertex->index = graph->numVertices++;
  vertex->next = NULL;
  strcpy(vertex->name, name);
  if (graph->graph == NULL) {
    graph->graph = malloc(sizeof(Vertex*) * MAX_Vertices);
  }
  graph->graph[vertex->index] = vertex;
}

void printVertices(Graph* graph) {
  for (Vertex* vertex = graph->graph[0]; vertex; vertex = vertex->next) {
    printf("%s ", vertex->name);
  }
  printf("\n");
}

int main() {
  Graph* graph = createGraph();
  addVertex(graph, "Alice");
  addVertex(graph, "Bob");
  addVertex(graph, "Charlie");
  printVertices(graph);
  return 0;
}