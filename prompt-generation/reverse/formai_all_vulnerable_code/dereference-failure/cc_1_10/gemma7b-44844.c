//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Graph {
  struct Node** graph;
  int size;
};

void insertNode(struct Graph* graph, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (graph->size == 0) {
    graph->graph = (struct Node**)malloc(MAX * sizeof(struct Node*));
    graph->size = MAX;
  }

  graph->graph[graph->size - 1] = newNode;
  graph->size++;
}

void traverseGraph(struct Graph* graph) {
  for (int i = 0; i < graph->size; i++) {
    struct Node* current = graph->graph[i];
    printf("Node data: %d\n", current->data);
  }
}

int main() {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->size = 0;
  graph->graph = NULL;

  insertNode(graph, 10);
  insertNode(graph, 20);
  insertNode(graph, 30);
  insertNode(graph, 40);
  insertNode(graph, 50);

  traverseGraph(graph);

  return 0;
}