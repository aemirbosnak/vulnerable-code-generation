//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char name[20];
  struct Node* next;
} Node;

typedef struct Graph {
  Node** graph;
  int size;
} Graph;

Graph* createGraph() {
  Graph* g = malloc(sizeof(Graph));
  g->graph = NULL;
  g->size = 0;
  return g;
}

void addNode(Graph* g, char* name) {
  Node* n = malloc(sizeof(Node));
  strcpy(n->name, name);
  n->next = NULL;

  if (g->graph == NULL) {
    g->graph = &n;
  } else {
    g->graph[g->size++] = n;
  }
}

void printGraph(Graph* g) {
  for (Node* n = g->graph[0]; n; n = n->next) {
    printf("%s ", n->name);
  }
  printf("\n");
}

int main() {
  Graph* g = createGraph();
  addNode(g, "a");
  addNode(g, "b");
  addNode(g, "c");
  addNode(g, "d");

  printGraph(g);

  return 0;
}