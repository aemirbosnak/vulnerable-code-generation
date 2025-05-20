//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR 4

typedef struct Graph {
  int **adjList;
  int numVertices;
  int **color;
} Graph;

void graphColor(Graph *graph) {
  int i, j, k, currentColor = 0, visited = 0, conflict = 0;

  for (i = 0; i < graph->numVertices; i++) {
    for (j = 0; j < graph->adjList[i][0]; j++) {
      if (graph->color[j] == currentColor) {
        conflict = 1;
      }
    }

    if (!conflict) {
      graph->color[i] = currentColor;
      visited = 1;
    }

    if (visited == graph->numVertices) {
      currentColor++;
      visited = 0;
    }
  }

  if (currentColor == MAX_COLOR) {
    printf("No solution found.\n");
  } else {
    printf("The optimal coloring is:\n");
    for (i = 0; i < graph->numVertices; i++) {
      printf("Vertex %d colored with %d.\n", i, graph->color[i]);
    }
  }
}

int main() {
  Graph *graph = malloc(sizeof(Graph));
  graph->numVertices = 5;
  graph->adjList = malloc(graph->numVertices * sizeof(int *));
  graph->color = malloc(graph->numVertices * sizeof(int));

  graph->adjList[0] = malloc(2 * sizeof(int));
  graph->adjList[0][0] = 1;
  graph->adjList[0][1] = 2;

  graph->adjList[1] = malloc(2 * sizeof(int));
  graph->adjList[1][0] = 0;
  graph->adjList[1][1] = 3;

  graph->adjList[2] = malloc(2 * sizeof(int));
  graph->adjList[2][0] = 1;
  graph->adjList[2][1] = 4;

  graph->adjList[3] = malloc(2 * sizeof(int));
  graph->adjList[3][0] = 2;
  graph->adjList[3][1] = 4;

  graph->adjList[4] = malloc(2 * sizeof(int));
  graph->adjList[4][0] = 0;
  graph->adjList[4][1] = 3;

  graphColor(graph);

  free(graph->adjList);
  free(graph->color);
  free(graph);

  return 0;
}