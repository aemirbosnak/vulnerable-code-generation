//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct Graph {
  Node** adjacencyList;
  int numVertices;
  int numEdges;
};

void insertVertex(struct Graph* graph) {
  graph->numVertices++;
  graph->adjacencyList = realloc(graph->adjacencyList, graph->numVertices * sizeof(Node*));
  graph->adjacencyList[graph->numVertices - 1] = NULL;
}

void insertEdge(struct Graph* graph, int src, int dest) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = dest;
  newNode->next = graph->adjacencyList[src];
  graph->adjacencyList[src] = newNode;
  graph->numEdges++;
}

int main() {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = 0;
  graph->numEdges = 0;
  graph->adjacencyList = NULL;

  insertVertex(graph);
  insertVertex(graph);
  insertVertex(graph);

  insertEdge(graph, 0, 1);
  insertEdge(graph, 1, 2);

  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->adjacencyList[i];
    while (current) {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }

  free(graph);

  return 0;
}