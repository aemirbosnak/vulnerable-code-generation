//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
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
  return graph;
}

void graph_add_edge(Graph* graph, char source, char destination) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = destination;
  newNode->next = NULL;

  Node* tail = graph->adjacencyList[source] ? graph->adjacencyList[source] : (graph->adjacencyList[source] = newNode);
  tail->next = newNode;
}

void graph_traverse(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->adjacencyList[i];
    while (current) {
      printf("%c ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = graph_create(5);
  graph_add_edge(graph, 'A', 'B');
  graph_add_edge(graph, 'A', 'C');
  graph_add_edge(graph, 'B', 'D');
  graph_add_edge(graph, 'C', 'E');

  graph_traverse(graph);

  free(graph->adjacencyList);
  free(graph);

  return 0;
}