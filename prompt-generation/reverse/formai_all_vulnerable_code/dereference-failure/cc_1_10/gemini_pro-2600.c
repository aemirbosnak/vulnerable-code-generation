//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>

typedef void (*VoidFun)(void *);

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct Graph {
  Node *head;
  VoidFun fun;
} Graph;

void visit(void *data) {
  printf("%d\n", *(int *)data);
}

Graph *init(VoidFun fun) {
  Graph *graph = malloc(sizeof(Graph));
  graph->head = NULL;
  graph->fun = fun;
  return graph;
}

void add(Graph *graph, void *data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = graph->head;
  graph->head = node;
}

void forEach(Graph *graph) {
  Node *current = graph->head;
  while (current != NULL) {
    graph->fun(current->data);
    current = current->next;
  }
}

int main() {
  Graph *graph = init(visit);

  int a = 1;
  int b = 2;
  int c = 3;

  add(graph, &a);
  add(graph, &b);
  add(graph, &c);

  forEach(graph);

  return 0;
}