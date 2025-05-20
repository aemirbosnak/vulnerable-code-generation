//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Graph {
  Node** adjacencyList;
  int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjacencyList = (Node**)malloc(sizeof(Node*) * numVertices);
  for (int i = 0; i < numVertices; i++) {
    graph->adjacencyList[i] = NULL;
  }
  return graph;
}

void addEdge(Graph* graph, int srcVertex, int destVertex) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = destVertex;
  newNode->next = graph->adjacencyList[srcVertex];
  graph->adjacencyList[srcVertex] = newNode;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->adjacencyList[i];
    while (current) {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph(5);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  traverseGraph(graph);

  return 0;
}