//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 10

typedef struct Vertex {
  int index;
  struct Vertex* next;
  char name[20];
} Vertex;

typedef struct Graph {
  int numVertices;
  Vertex** adjList;
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

void addVertex(Graph* graph, char* name) {
  Vertex* vertex = malloc(sizeof(Vertex));
  vertex->index = graph->numVertices++;
  vertex->next = NULL;
  strcpy(vertex->name, name);

  graph->adjList[vertex->index] = vertex;
}

void addEdge(Graph* graph, int srcIndex, int destIndex) {
  Vertex* srcVertex = graph->adjList[srcIndex];
  Vertex* destVertex = graph->adjList[destIndex];

  srcVertex->next = destVertex;
}

void printGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Vertex* vertex = graph->adjList[i];
    printf("Vertex %d: %s\n", vertex->index, vertex->name);

    printf("  Edges:");
    for (Vertex* neighbor = vertex->next; neighbor; neighbor = neighbor->next) {
      printf("  %d", neighbor->index);
    }

    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph(5);

  addVertex(graph, "Alice");
  addVertex(graph, "Bob");
  addVertex(graph, "Charlie");
  addVertex(graph, "Dave");
  addVertex(graph, "Eve");

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);

  printGraph(graph);

  return 0;
}