//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Graph {
  Node** graph;
  int size;
} Graph;

void createGraph(Graph* graph) {
  graph->graph = (Node**)malloc(graph->size * sizeof(Node*));
  for (int i = 0; i < graph->size; i++) {
    graph->graph[i] = NULL;
  }
}

void addNode(Graph* graph, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (graph->graph[graph->size - 1] == NULL) {
    graph->graph[graph->size - 1] = newNode;
  } else {
    graph->graph[graph->size - 1]->next = newNode;
  }

  graph->size++;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->size; i++) {
    Node* current = graph->graph[i];
    while (current) {
      printf("%d ", current->data);
      current = current->next;
    }
  }
}

int main() {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->size = MAX;
  createGraph(graph);

  addNode(graph, 1);
  addNode(graph, 2);
  addNode(graph, 3);
  addNode(graph, 4);
  addNode(graph, 5);

  traverseGraph(graph);

  return 0;
}