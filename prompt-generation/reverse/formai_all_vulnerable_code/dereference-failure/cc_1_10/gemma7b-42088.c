//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
  char name[MAX];
  struct Node* next;
} Node;

typedef struct Graph {
  Node** graph;
  int size;
} Graph;

void insertNode(Graph* g, char* name) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (g->size == 0) {
    g->graph = malloc(sizeof(Node*) * MAX);
    g->size = MAX;
  }

  g->graph[g->size++] = newNode;
}

void traverseGraph(Graph* g) {
  for (int i = 0; i < g->size; i++) {
    Node* current = g->graph[i];
    printf("%s ", current->name);
  }
  printf("\n");
}

int main() {
  Graph* g = malloc(sizeof(Graph));
  g->size = 0;
  g->graph = NULL;

  insertNode(g, "A");
  insertNode(g, "B");
  insertNode(g, "C");
  insertNode(g, "D");

  traverseGraph(g);

  return 0;
}