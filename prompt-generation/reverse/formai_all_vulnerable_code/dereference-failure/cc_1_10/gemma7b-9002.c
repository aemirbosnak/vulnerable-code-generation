//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Graph {
  Node** adjacencyList;
  int numVertices;
} Graph;

Graph* graph_create(int numVertices) {
  Graph* graph = malloc(sizeof(Graph));
  graph->adjacencyList = malloc(numVertices * sizeof(Node*));
  graph->numVertices = numVertices;

  for (int i = 0; i < numVertices; i++) {
    graph->adjacencyList[i] = NULL;
  }

  return graph;
}

void graph_add_vertex(Graph* graph, int data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  graph->adjacencyList[graph->numVertices++] = node;
}

void graph_add_edge(Graph* graph, int src, int dest) {
  Node* sourceNode = graph->adjacencyList[src];
  Node* destinationNode = graph->adjacencyList[dest];

  if (sourceNode) {
    sourceNode->next = destinationNode;
  } else {
    graph_add_vertex(graph, src);
    sourceNode = graph->adjacencyList[src];
    sourceNode->next = destinationNode;
  }
}

void graph_print(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* node = graph->adjacencyList[i];
    printf("Vertex %d: ", i);
    while (node) {
      printf("-> Vertex %d ", node->data);
      node = node->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = graph_create(5);
  graph_add_vertex(graph, 0);
  graph_add_vertex(graph, 1);
  graph_add_vertex(graph, 2);
  graph_add_vertex(graph, 3);
  graph_add_vertex(graph, 4);

  graph_add_edge(graph, 0, 1);
  graph_add_edge(graph, 0, 2);
  graph_add_edge(graph, 1, 3);
  graph_add_edge(graph, 2, 4);

  graph_print(graph);

  return 0;
}