//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 5
#define MAX_C 3

typedef struct Graph {
  int **adj;
  int **color;
  int numVertices;
  int numColors;
} Graph;

Graph* createGraph(int numVertices, int numColors) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->numColors = numColors;
  graph->adj = (int**)malloc(numVertices * sizeof(int*));
  graph->color = (int**)malloc(numVertices * sizeof(int*));
  for (int i = 0; i < numVertices; i++) {
    graph->adj[i] = (int*)malloc(numVertices * sizeof(int));
    graph->color[i] = (int*)malloc(numColors * sizeof(int));
  }
  return graph;
}

void addEdge(Graph* graph, int u, int v) {
  graph->adj[u][v] = 1;
}

void graphColoring(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    graph->color[i][0] = -1;
  }
  for (int i = 0; i < graph->numColors; i++) {
    for (int j = 0; j < graph->numVertices; j++) {
      graph->color[j][i] = 0;
    }
  }

  int chromaticNumber = 0;
  for (int i = 0; i < graph->numVertices; i++) {
    int availableColors = 0;
    for (int j = 0; j < graph->numColors; j++) {
      if (graph->color[i][j] == 0) {
        availableColors++;
      }
    }
    if (availableColors > chromaticNumber) {
      chromaticNumber = availableColors;
    }
  }

  printf("Chromatic number: %d\n", chromaticNumber);
}

int main() {
  Graph* graph = createGraph(5, 3);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  graphColoring(graph);

  return 0;
}