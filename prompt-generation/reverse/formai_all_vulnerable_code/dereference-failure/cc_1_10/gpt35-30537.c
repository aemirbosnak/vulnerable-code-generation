//FormAI DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Graph {
  int v;  //number of vertices
  int **adjMatrix; //Adjacency Matrix representation
};

//Allocate memory for Graph and initialize adjacency matrix with zeroes
struct Graph *createGraph(int v) {
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->v = v;
  graph->adjMatrix = malloc(v * sizeof(int *));
  for(int i = 0; i < v; i++) {
    graph->adjMatrix[i] = calloc(v, sizeof(int));
  }
  return graph;
}

//Add edge from source to destination
void addDirectedEdge(struct Graph *graph, int source, int dest) {
  graph->adjMatrix[source][dest] = 1;
}

//Print adjacency matrix
void printAdjacencyMatrix(struct Graph *graph) {
  int v = graph->v;
  printf("Adjacency matrix representation:\n");
  for(int i = 0; i < v; i++) {
    for(int j = 0; j < v; j++) {
      printf("%d ", graph->adjMatrix[i][j]);
    }
    printf("\n");
  }
}

//Free memory allocated for graph and adjacency matrix
void freeGraph(struct Graph *graph) {
  int v = graph->v;
  for(int i = 0; i < v; i++) {
    free(graph->adjMatrix[i]);
  }
  free(graph->adjMatrix);
  free(graph);
}

int main() {
  struct Graph *graph = createGraph(5);
  addDirectedEdge(graph, 0, 1);
  addDirectedEdge(graph, 1, 2);
  addDirectedEdge(graph, 2, 3);
  addDirectedEdge(graph, 3, 4);
  addDirectedEdge(graph, 4, 0);
  printAdjacencyMatrix(graph);
  freeGraph(graph);
  return 0;
}