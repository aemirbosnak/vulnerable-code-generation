//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_EDGES 100

typedef struct Edge {
  int src, dst;
  struct Edge* next;
} Edge;

typedef struct Graph {
  int numVertices;
  int numEdges;
  Edge** adjList;
} Graph;

Graph* createGraph(int numVertices, int numEdges) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->numEdges = numEdges;
  graph->adjList = (Edge**)malloc(numVertices * sizeof(Edge*));
  for (int i = 0; i < numVertices; i++) {
    graph->adjList[i] = NULL;
  }
  return graph;
}

void addEdge(Graph* graph, int src, int dst) {
  Edge* newEdge = (Edge*)malloc(sizeof(Edge));
  newEdge->src = src;
  newEdge->dst = dst;
  newEdge->next = NULL;
  graph->adjList[src] = newEdge;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Edge* edge = graph->adjList[i];
    while (edge) {
      printf("(%d, %d)\n", edge->src, edge->dst);
      edge = edge->next;
    }
  }
}

int main() {
  Graph* graph = createGraph(5, 5);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 0);
  traverseGraph(graph);
  return 0;
}