//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: random
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_VERTS 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Graph {
  Node** graph;
  int numVertices;
} Graph;

Graph* createGraph() {
  Graph* graph = malloc(sizeof(Graph));
  graph->numVertices = 0;
  graph->graph = NULL;
  return graph;
}

void insertVertex(Graph* graph, int data) {
  graph->numVertices++;
  graph->graph = realloc(graph->graph, graph->numVertices * sizeof(Node*));
  graph->graph[graph->numVertices - 1] = malloc(sizeof(Node));
  graph->graph[graph->numVertices - 1]->data = data;
  graph->graph[graph->numVertices - 1]->next = NULL;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->graph[i];
    while (current) {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph();
  insertVertex(graph, 1);
  insertVertex(graph, 2);
  insertVertex(graph, 3);
  insertVertex(graph, 4);
  insertVertex(graph, 5);

  traverseGraph(graph);

  return 0;
}