//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 100

typedef struct Graph {
  int numVertices;
  int **adjList;
} Graph;

Graph *createGraph() {
  Graph *graph = malloc(sizeof(Graph));
  graph->numVertices = 0;
  graph->adjList = NULL;
  return graph;
}

void addVertex(Graph *graph) {
  graph->numVertices++;
  graph->adjList = realloc(graph->adjList, graph->numVertices * sizeof(int *));
  graph->adjList[graph->numVertices - 1] = NULL;
}

void addEdge(Graph *graph, int src, int dest) {
  graph->adjList[src] = realloc(graph->adjList[src], (graph->numVertices) * sizeof(int));
  graph->adjList[src][graph->numVertices - 1] = dest;
}

int graphColor(Graph *graph) {
  int *colors = malloc(graph->numVertices * sizeof(int));
  for (int i = 0; i < graph->numVertices; i++) {
    colors[i] = -1;
  }

  for (int i = 0; i < graph->numVertices; i++) {
    for (int j = 0; j < graph->numVertices; j++) {
      if (graph->adjList[i][j] && colors[i] == colors[j]) {
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  Graph *graph = createGraph();
  addVertex(graph);
  addVertex(graph);
  addVertex(graph);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);

  if (graphColor(graph)) {
    printf("Graph coloring successful.\n");
  } else {
    printf("Graph coloring failed.\n");
  }

  return 0;
}