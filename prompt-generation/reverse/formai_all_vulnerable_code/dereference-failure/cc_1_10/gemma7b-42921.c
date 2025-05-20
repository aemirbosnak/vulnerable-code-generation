//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define GRAPH_MAX_SIZE 10

typedef struct Graph {
  int **adjList;
  int numVertices;
  int numEdges;
} Graph;

Graph *graphCreate() {
  Graph *graph = malloc(sizeof(Graph));
  graph->adjList = NULL;
  graph->numVertices = 0;
  graph->numEdges = 0;
  return graph;
}

void graphAddVertex(Graph *graph) {
  graph->numVertices++;
  graph->adjList = realloc(graph->adjList, graph->numVertices * sizeof(int *));
  graph->adjList[graph->numVertices - 1] = NULL;
}

void graphAddEdge(Graph *graph, int srcVertex, int destVertex) {
  graph->numEdges++;
  graph->adjList[srcVertex] = realloc(graph->adjList[srcVertex], (graph->numEdges + 1) * sizeof(int));
  graph->adjList[srcVertex][graph->numEdges] = destVertex;
}

void graphPrint(Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    printf("Vertex %d: ", i);
    for (int j = 0; graph->adjList[i] && j < graph->adjList[i][0]; j++) {
      printf("-> Vertex %d ", graph->adjList[i][j + 1]);
    }
    printf("\n");
  }
}

int main() {
  Graph *graph = graphCreate();
  graphAddVertex(graph);
  graphAddVertex(graph);
  graphAddVertex(graph);
  graphAddEdge(graph, 0, 1);
  graphAddEdge(graph, 0, 2);
  graphAddEdge(graph, 1, 2);
  graphPrint(graph);

  free(graph);
  return 0;
}