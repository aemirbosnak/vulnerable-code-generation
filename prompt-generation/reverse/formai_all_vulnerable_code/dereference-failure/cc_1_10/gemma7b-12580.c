//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char name[20];
  struct Node* next;
  struct Node* prev;
  int data;
};

struct Graph {
  struct Node** graph;
  int size;
};

void insertNode(struct Graph* g, char* name, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  strcpy(newNode->name, name);
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (g->size == 0) {
    g->graph = malloc(sizeof(struct Node*));
    g->graph[0] = newNode;
  } else {
    g->graph[g->size] = newNode;
    g->size++;
  }
}

void printGraph(struct Graph* g) {
  for (int i = 0; i < g->size; i++) {
    printf("%s (data: %d) -> ", g->graph[i]->name, g->graph[i]->data);
  }
  printf("\n");
}

int main() {
  struct Graph* g = malloc(sizeof(struct Graph));
  g->size = 0;
  g->graph = NULL;

  insertNode(g, "A", 10);
  insertNode(g, "B", 20);
  insertNode(g, "C", 30);

  printGraph(g);

  return 0;
}