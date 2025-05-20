//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  struct Node* next;
  char data;
} Node;

typedef struct Graph {
  struct Node** graph;
  int size;
} Graph;

Graph* createGraph(int size) {
  Graph* graph = malloc(sizeof(Graph));
  graph->graph = malloc(sizeof(struct Node*) * size);
  graph->size = size;
  return graph;
}

void insertNode(Graph* graph, char data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (graph->size == 0) {
    graph->graph[0] = newNode;
  } else {
    graph->graph[graph->size - 1]->next = newNode;
  }

  graph->size++;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->size; i++) {
    struct Node* current = graph->graph[i];
    while (current) {
      printf("%c ", current->data);
      current = current->next;
    }
  }
}

int main() {
  Graph* graph = createGraph(5);
  insertNode(graph, 'a');
  insertNode(graph, 'b');
  insertNode(graph, 'c');
  insertNode(graph, 'd');
  insertNode(graph, 'e');

  traverseGraph(graph);

  return 0;
}