//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Node {
  int index;
  struct Node* next;
  char data[MAX_VERTICES];
} Node;

typedef struct Graph {
  int numVertices;
  Node** adjacencyList;
} Graph;

Graph* createGraph(int numVertices) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));

  for (int i = 0; i < numVertices; i++) {
    graph->adjacencyList[i] = NULL;
  }

  return graph;
}

void addVertex(Graph* graph, int index, char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->index = index;
  newNode->next = NULL;
  newNode->data[0] = data;

  if (graph->adjacencyList[index] == NULL) {
    graph->adjacencyList[index] = newNode;
  } else {
    graph->adjacencyList[index]->next = newNode;
  }
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->adjacencyList[i];
    while (current) {
      printf("Vertex: %d, Data: %c\n", current->index, current->data[0]);
      current = current->next;
    }
  }
}

int main() {
  Graph* graph = createGraph(5);
  addVertex(graph, 0, 'a');
  addVertex(graph, 1, 'b');
  addVertex(graph, 2, 'c');
  addVertex(graph, 3, 'd');
  addVertex(graph, 4, 'e');

  traverseGraph(graph);

  return 0;
}