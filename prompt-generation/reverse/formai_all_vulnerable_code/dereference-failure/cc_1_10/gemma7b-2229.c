//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct Graph {
  int numVertices;
  Node** adjacencyList;
};

void insertVertex(struct Graph* graph, int data) {
  graph->numVertices++;
  graph->adjacencyList = (Node**)realloc(graph->adjacencyList, graph->numVertices * sizeof(Node*));
  graph->adjacencyList[graph->numVertices - 1] = (Node*)malloc(sizeof(Node));
  graph->adjacencyList[graph->numVertices - 1]->data = data;
  graph->adjacencyList[graph->numVertices - 1]->next = NULL;
}

void insertEdge(struct Graph* graph, int src, int dest) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = dest;
  newNode->next = NULL;
  insertVertex(graph, src);
  graph->adjacencyList[src]->next = newNode;
}

int main() {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = 0;
  graph->adjacencyList = NULL;

  insertVertex(graph, 1);
  insertVertex(graph, 2);
  insertVertex(graph, 3);
  insertVertex(graph, 4);

  insertEdge(graph, 1, 2);
  insertEdge(graph, 2, 3);
  insertEdge(graph, 3, 4);

  for (int i = 0; i < graph->numVertices; i++) {
    Node* node = graph->adjacencyList[i];
    while (node) {
      printf("(%d, %d) ", graph->adjacencyList[i]->data, node->data);
      node = node->next;
    }
    printf("\n");
  }

  return 0;
}