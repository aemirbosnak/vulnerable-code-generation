//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Graph {
  struct Node** adjacencyList;
  int numVertices;
};

void insertVertex(struct Graph* graph, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (graph->adjacencyList == NULL) {
    graph->adjacencyList = malloc(sizeof(struct Node*));
    graph->adjacencyList[0] = newNode;
    graph->numVertices = 1;
  } else {
    graph->adjacencyList[graph->numVertices] = newNode;
    graph->numVertices++;
  }
}

void traverseGraph(struct Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    struct Node* current = graph->adjacencyList[i];
    printf("%d ", current->data);
    while (current->next) {
      current = current->next;
      printf("%d ", current->data);
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->adjacencyList = NULL;
  graph->numVertices = 0;

  insertVertex(graph, 10);
  insertVertex(graph, 20);
  insertVertex(graph, 30);
  insertVertex(graph, 40);
  insertVertex(graph, 50);

  traverseGraph(graph);

  return 0;
}