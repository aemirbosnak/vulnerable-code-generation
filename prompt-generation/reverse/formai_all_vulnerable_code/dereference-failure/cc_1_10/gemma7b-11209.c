//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex {
  int index;
  struct Vertex* next;
} Vertex;

void printTopology(Vertex* head) {
  Vertex* current = head;
  while (current) {
    printf("%d ", current->index);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Vertex* graph[MAX_VERTICES];
  for (int i = 0; i < MAX_VERTICES; i++) {
    graph[i] = NULL;
  }

  // Create a few vertices
  Vertex* vertex1 = malloc(sizeof(Vertex));
  vertex1->index = 1;
  vertex1->next = NULL;
  graph[vertex1->index] = vertex1;

  Vertex* vertex2 = malloc(sizeof(Vertex));
  vertex2->index = 2;
  vertex2->next = NULL;
  graph[vertex2->index] = vertex2;

  Vertex* vertex3 = malloc(sizeof(Vertex));
  vertex3->index = 3;
  vertex3->next = NULL;
  graph[vertex3->index] = vertex3;

  // Connect the vertices
  vertex1->next = vertex2;
  vertex2->next = vertex3;

  // Print the topology of the graph
  printTopology(graph[1]);

  return 0;
}