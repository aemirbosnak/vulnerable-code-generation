//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Graph {
  int **adjList;
  int numVertices;
  int numEdges;
} Graph;

Graph* createGraph() {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->adjList = (int**)malloc(MAX_Vertices * sizeof(int*));
  graph->numVertices = 0;
  graph->numEdges = 0;
  return graph;
}

void addEdge(Graph* graph, int u, int v) {
  graph->adjList[u] = (int*)realloc(graph->adjList[u], (graph->numEdges + 1) * sizeof(int));
  graph->adjList[u][graph->numEdges] = v;
  graph->numEdges++;
}

void graphColoring(Graph* graph) {
  int* color = (int*)malloc(graph->numVertices * sizeof(int));
  for (int i = 0; i < graph->numVertices; i++) {
    color[i] = -1;
  }

  int chromaticNumber = 0;
  for (int i = 0; i < graph->numVertices; i++) {
    int available = 1;
    for (int j = 0; j < graph->numEdges; j++) {
      if (color[graph->adjList[i][j]] == color[i]) {
        available = 0;
      }
    }

    if (available) {
      color[i] = chromaticNumber;
      chromaticNumber++;
    }
  }

  printf("The chromatic number of the graph is: %d\n", chromaticNumber);
  free(color);
}

int main() {
  Graph* graph = createGraph();
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);

  graphColoring(graph);

  free(graph);
  return 0;
}