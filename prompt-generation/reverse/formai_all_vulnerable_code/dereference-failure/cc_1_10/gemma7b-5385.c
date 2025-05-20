//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>

// Define graph structure
typedef struct Graph {
  int **adjList;
  int numVertices;
} Graph;

// Create a graph
Graph* createGraph(int numVertices) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjList = (int**)malloc(numVertices * sizeof(int*));
  for (int i = 0; i < numVertices; i++) {
    graph->adjList[i] = (int*)malloc(sizeof(int) * numVertices);
  }
  return graph;
}

// Add an edge to a graph
void addEdge(Graph* graph, int src, int dest) {
  graph->adjList[src][dest] = 1;
}

// Traverse a graph using DFS
void traverseGraph(Graph* graph, int currentVertex, int visitedVertices[]) {
  visitedVertices[currentVertex] = 1;
  for (int i = 0; i < graph->numVertices; i++) {
    if (graph->adjList[currentVertex][i] && visitedVertices[i] == 0) {
      traverseGraph(graph, i, visitedVertices);
    }
  }
}

int main() {
  Graph* graph = createGraph(5);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 0);

  int visitedVertices[5] = {0};
  traverseGraph(graph, 0, visitedVertices);

  for (int i = 0; i < 5; i++) {
    if (visitedVertices[i] == 1) {
      printf("%d ", i);
    }
  }

  return 0;
}