//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: mathematical
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
  g->graph = realloc(g->graph, g->numVertices * MAX);
  g->graph[g->numVertices - 1] = malloc(sizeof(Node));
  g->graph[g->numVertices - 1]->data = data;
  g->graph[g->numVertices - 1]->next = NULL;
}

void insertEdge(Graph* g, int src, int dest) {
  Node* node = g->graph[src]->next;
  g->graph[src]->next = malloc(sizeof(Node));
  g->graph[src]->next->data = dest;
  g->graph[src]->next->next = node;
}

void printGraph(Graph* g) {
  for (int i = 0; i < g->numVertices; i++) {
    printf("%d: ", g->graph[i]->data);
    Node* node = g->graph[i]->next;
    while (node) {
      printf("%d ", node->data);
      node = node->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* g = malloc(sizeof(Graph));
  g->graph = NULL;
  g->numVertices = 0;

  insertVertex(g, 1);
  insertVertex(g, 2);
  insertVertex(g, 3);
  insertVertex(g, 4);
  insertVertex(g, 5);

  insertEdge(g, 1, 2);
  insertEdge(g, 1, 3);
  insertEdge(g, 2, 4);
  insertEdge(g, 3, 5);

  printGraph(g);

  free(g);

  return 0;
}