//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 100
#define MAX_Edges 1000

typedef struct Node {
  int index;
  struct Node* next;
} Node;

typedef struct Graph {
  int numVertices;
  Node** adjacencyList;
} Graph;

Graph* createGraph() {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = 0;
  graph->adjacencyList = (Node**)malloc(MAX_Vertices * sizeof(Node*));
  return graph;
}

void addEdge(Graph* graph, int src, int dest) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->index = dest;
  newNode->next = NULL;
  graph->adjacencyList[src] = newNode;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->adjacencyList[i];
    while (current) {
      printf("Edge: %d -> %d\n", i, current->index);
      current = current->next;
    }
  }
}

int main() {
  Graph* graph = createGraph();
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);

  traverseGraph(graph);

  return 0;
}