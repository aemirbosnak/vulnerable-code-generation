//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
  int data;
  struct Node* next;
};

struct Graph {
  struct Node** adjacencyList;
  int numVertices;
};

void insertNode(struct Graph* graph, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (graph->adjacencyList == NULL) {
    graph->adjacencyList = (struct Node**)malloc(MAX * sizeof(struct Node*));
    graph->numVertices = 0;
  }

  graph->adjacencyList[graph->numVertices++] = newNode;
}

void traverseGraph(struct Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    struct Node* current = graph->adjacencyList[i];
    while (current) {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->adjacencyList = NULL;
  graph->numVertices = 0;

  insertNode(graph, 10);
  insertNode(graph, 20);
  insertNode(graph, 30);
  insertNode(graph, 40);
  insertNode(graph, 50);

  traverseGraph(graph);

  return 0;
}