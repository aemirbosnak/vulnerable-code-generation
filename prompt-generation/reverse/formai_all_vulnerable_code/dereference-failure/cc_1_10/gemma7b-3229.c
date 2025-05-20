//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Graph {
  Node** graph;
  int numVertices;
} Graph;

void insertVertex(Graph* g, int data) {
  g->numVertices++;
  g->graph = (Node**)realloc(g->graph, g->numVertices * sizeof(Node*));
  g->graph[g->numVertices - 1] = (Node*)malloc(sizeof(Node));
  g->graph[g->numVertices - 1]->data = data;
  g->graph[g->numVertices - 1]->next = NULL;
}

void insertEdge(Graph* g, int src, int dest) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = dest;
  newNode->next = NULL;

  insertVertex(g, src);

  g->graph[src]->next = newNode;
}

int main() {
  Graph* g = (Graph*)malloc(sizeof(Graph));
  g->numVertices = 0;
  g->graph = NULL;

  insertVertex(g, 1);
  insertVertex(g, 2);
  insertVertex(g, 3);
  insertVertex(g, 4);
  insertVertex(g, 5);

  insertEdge(g, 1, 2);
  insertEdge(g, 2, 3);
  insertEdge(g, 3, 4);
  insertEdge(g, 4, 5);

  for (int i = 0; i < g->numVertices; i++) {
    printf("%d ", g->graph[i]->data);
  }

  printf("\n");

  for (int i = 0; i < g->numVertices; i++) {
    for (Node* node = g->graph[i]->next; node; node = node->next) {
      printf("%d ", node->data);
    }
  }

  return 0;
}