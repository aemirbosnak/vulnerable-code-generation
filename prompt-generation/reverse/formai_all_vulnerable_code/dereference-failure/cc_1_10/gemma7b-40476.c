//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10

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
  g->graph = realloc(g->graph, g->numVertices * sizeof(Node*));
  g->graph[g->numVertices - 1] = malloc(sizeof(Node));
  g->graph[g->numVertices - 1]->data = data;
  g->graph[g->numVertices - 1]->next = NULL;
}

void insertEdge(Graph* g, int src, int dest) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = dest;
  newNode->next = NULL;

  Node* prevNode = g->graph[src];
  if (prevNode == NULL) {
    g->graph[src] = newNode;
  } else {
    while (prevNode->next) {
      prevNode = prevNode->next;
    }
    prevNode->next = newNode;
  }
}

void traverseGraph(Graph* g) {
  for (int i = 0; i < g->numVertices; i++) {
    Node* current = g->graph[i];
    printf("Vertex %d: ", i);
    while (current) {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* g = malloc(sizeof(Graph));
  g->numVertices = 0;
  g->graph = NULL;

  insertVertex(g, 0);
  insertVertex(g, 1);
  insertVertex(g, 2);
  insertVertex(g, 3);
  insertVertex(g, 4);

  insertEdge(g, 0, 1);
  insertEdge(g, 0, 2);
  insertEdge(g, 1, 2);
  insertEdge(g, 2, 3);
  insertEdge(g, 3, 4);

  traverseGraph(g);

  free(g);

  return 0;
}