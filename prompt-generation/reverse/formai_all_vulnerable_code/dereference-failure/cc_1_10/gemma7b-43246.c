//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Graph {
  Node** graph;
  int size;
} Graph;

Graph* createGraph(int size) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->graph = (Node**)malloc(size * sizeof(Node*));
  graph->size = size;
  return graph;
}

void addNode(Graph* graph, char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (graph->size == 0) {
    graph->graph[0] = newNode;
  } else {
    graph->graph[graph->size - 1]->next = newNode;
  }
  graph->size++;
}

void printGraph(Graph* graph) {
  for (int i = 0; i < graph->size; i++) {
    Node* current = graph->graph[i];
    while (current) {
      printf("%c ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph(MAX);
  addNode(graph, 'a');
  addNode(graph, 'b');
  addNode(graph, 'c');
  addNode(graph, 'd');
  addNode(graph, 'e');

  printGraph(graph);

  return 0;
}