//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Graph {
  int V;
  int E;
  int** adjMatrix;
};

struct Graph* createGraph(int V, int E) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->adjMatrix = malloc(V * sizeof(int*));
  for (int i = 0; i < V; i++) {
    graph->adjMatrix[i] = malloc(V * sizeof(int));
    for (int j = 0; j < V; j++) {
      graph->adjMatrix[i][j] = 0;
    }
  }
  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  graph->adjMatrix[src][dest] = 1;
  graph->adjMatrix[dest][src] = 1;
}

void printGraph(struct Graph* graph) {
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      printf("%d ", graph->adjMatrix[i][j]);
    }
    printf("\n");
  }
}

bool isSafe(struct Graph* graph, int v, int color, int* colorArr) {
  for (int i = 0; i < graph->V; i++) {
    if (graph->adjMatrix[v][i] == 1 && colorArr[i] == color) {
      return false;
    }
  }
  return true;
}

bool graphColoring(struct Graph* graph, int* colorArr, int v) {
  if (v == graph->V) {
    return true;
  }

  for (int c = 1; c <= graph->V; c++) {
    if (isSafe(graph, v, c, colorArr)) {
      colorArr[v] = c;
      if (graphColoring(graph, colorArr, v + 1)) {
        return true;
      }
      colorArr[v] = 0;
    }
  }

  return false;
}

int main() {
  struct Graph* graph = createGraph(4, 3);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);

  int* colorArr = malloc(graph->V * sizeof(int));
  for (int i = 0; i < graph->V; i++) {
    colorArr[i] = 0;
  }

  if (graphColoring(graph, colorArr, 0)) {
    printf("Graph can be colored with the following colors:\n");
    for (int i = 0; i < graph->V; i++) {
      printf("Vertex %d -> Color %d\n", i, colorArr[i]);
    }
  } else {
    printf("Graph cannot be colored with the given number of colors.\n");
  }

  free(colorArr);
  free(graph);
  return 0;
}