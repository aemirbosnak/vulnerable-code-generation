//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct Graph {
  Node** adjacencyList;
  int numVertices;
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
}

void traverseGraph(struct Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->adjacencyList[i];
    while (current) {
      printf("(%d, %d) ", i, current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = 0;
  graph->adjacencyList = NULL;

  insertVertex(graph);
  insertVertex(graph);
  insertVertex(graph);

  insertEdge(graph, 0, 1);
  insertEdge(graph, 0, 2);
  insertEdge(graph, 1, 2);

  traverseGraph(graph);

  return 0;
}