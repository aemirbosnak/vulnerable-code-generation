//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Graph structure using linked lists
struct Node {
  int data;
  struct Node* next;
};

// Function to create a graph
struct Node* createGraph(int* vertices, int numVertices) {
  struct Node* graph = NULL;
  for (int i = 0; i < numVertices; i++) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = vertices[i];
    node->next = graph;
    graph = node;
  }
  return graph;
}

// Function to add an edge to the graph
void addEdge(struct Node** graph, int v1, int v2) {
  struct Node* node1 = *graph;
  struct Node* node2 = *graph;
  while (node1 != NULL) {
    if (node1->data == v1) {
      node1->next = node2;
      break;
    }
    node1 = node1->next;
  }
  if (node1 == NULL) {
    printf("Error: Vertex %d not found\n", v1);
  }
  node2->next = node1;
}

// Function to traverse the graph
void traverse(struct Node* graph) {
  while (graph != NULL) {
    printf("%d ", graph->data);
    graph = graph->next;
  }
  printf("\n");
}

int main() {
  int vertices[] = {1, 2, 3, 4, 5};
  int numVertices = sizeof(vertices) / sizeof(vertices[0]);
  struct Node* graph = createGraph(vertices, numVertices);

  // Add edges to the graph
  addEdge(&graph, 1, 2);
  addEdge(&graph, 2, 3);
  addEdge(&graph, 3, 4);
  addEdge(&graph, 4, 5);

  // Traverse the graph
  traverse(graph);

  return 0;
}