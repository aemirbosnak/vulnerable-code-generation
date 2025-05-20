//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  struct Node* next;
  char data;
} Node;

typedef struct Graph {
  struct Node** adjacencyList;
  int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
  Graph* graph = malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjacencyList = malloc(sizeof(struct Node*) * numVertices);
  for (int i = 0; i < numVertices; i++) {
    graph->adjacencyList[i] = NULL;
  }
  return graph;
}

void addEdge(Graph* graph, char source, char destination) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = destination;
  newNode->next = graph->adjacencyList[source];
  graph->adjacencyList[source] = newNode;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    struct Node* current = graph->adjacencyList[i];
    while (current) {
      printf("%c ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph(5);
  addEdge(graph, 'a', 'b');
  addEdge(graph, 'a', 'c');
  addEdge(graph, 'b', 'd');
  addEdge(graph, 'c', 'e');

  traverseGraph(graph);

  return 0;
}