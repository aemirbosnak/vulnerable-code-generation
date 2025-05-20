//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Node {
  int index;
  struct Node* next;
} Node;

void mapTopology(int** graph, int numVertices) {
  Node** nodes = malloc(numVertices * sizeof(Node*));
  for (int i = 0; i < numVertices; i++) {
    nodes[i] = NULL;
  }

  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      if (graph[i][j] == 1) {
        Node* newNode = malloc(sizeof(Node));
        newNode->index = j;
        newNode->next = nodes[i];
        nodes[i] = newNode;
      }
    }
  }

  for (int i = 0; i < numVertices; i++) {
    Node* current = nodes[i];
    while (current) {
      printf("%d ", current->index);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  int numVertices = 5;
  int** graph = malloc(numVertices * sizeof(int*));
  for (int i = 0; i < numVertices; i++) {
    graph[i] = malloc(numVertices * sizeof(int));
  }

  graph[0][1] = 1;
  graph[0][2] = 1;
  graph[1][2] = 1;
  graph[1][3] = 1;
  graph[2][3] = 1;
  graph[3][4] = 1;

  mapTopology(graph, numVertices);

  return 0;
}