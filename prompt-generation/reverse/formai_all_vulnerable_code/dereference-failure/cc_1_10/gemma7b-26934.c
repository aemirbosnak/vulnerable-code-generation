//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct Graph {
  Node** graph;
  int numVertices;
  int numEdges;
};

void insertVertex(struct Graph* graph) {
  graph->numVertices++;
  graph->graph = realloc(graph->graph, graph->numVertices * sizeof(Node*));
  graph->graph[graph->numVertices - 1] = NULL;
}

void insertEdge(struct Graph* graph, int src, int dest) {
  graph->numEdges++;
  graph->graph[src]->next = malloc(sizeof(Node));
  graph->graph[src]->next->data = dest;
  graph->graph[src]->next->next = NULL;
}

void traverseGraph(struct Graph* graph) {
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
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = 0;
  graph->numEdges = 0;
  graph->graph = NULL;

  insertVertex(graph);
  insertVertex(graph);
  insertVertex(graph);

  insertEdge(graph, 0, 1);
  insertEdge(graph, 1, 2);

  traverseGraph(graph);

  free(graph);

  return 0;
}