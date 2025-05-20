//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Node {
  int index;
  struct Node* next;
} Node;

void mapNetworkTopology(Node** graph) {
  for (int i = 0; i < MAX_VERTICES; i++) {
    graph[i] = NULL;
  }

  for (Node* node = graph[0]; node; node = node->next) {
    graph[node->index] = node;
  }
}

int main() {
  Node** graph = (Node**)malloc(MAX_VERTICES * sizeof(Node*));

  Node* node1 = (Node*)malloc(sizeof(Node));
  node1->index = 0;
  node1->next = NULL;

  Node* node2 = (Node*)malloc(sizeof(Node));
  node2->index = 1;
  node2->next = NULL;

  Node* node3 = (Node*)malloc(sizeof(Node));
  node3->index = 2;
  node3->next = NULL;

  node1->next = node2;
  node2->next = node3;

  mapNetworkTopology(graph);

  for (int i = 0; i < MAX_VERTICES; i++) {
    if (graph[i]) {
      printf("Vertex %d has connections: ", i);
      for (Node* node = graph[i]; node; node = node->next) {
        printf("%d ", node->index);
      }
      printf("\n");
    }
  }

  return 0;
}