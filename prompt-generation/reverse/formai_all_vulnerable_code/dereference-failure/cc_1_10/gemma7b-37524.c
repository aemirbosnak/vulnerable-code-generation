//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Node {
  int index;
  struct Node* next;
} Node;

void create_graph(Node** graph, int num_vertices) {
  graph = (Node**)malloc(num_vertices * sizeof(Node));
  for (int i = 0; i < num_vertices; i++) {
    graph[i] = NULL;
  }
}

void add_edge(Node** graph, int src, int dest) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->index = dest;
  newNode->next = graph[src];
  graph[src] = newNode;
}

void print_topology(Node** graph) {
  for (int i = 0; i < MAX_VERTICES; i++) {
    Node* current = graph[i];
    while (current) {
      printf("%d ", current->index);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  Node** graph = NULL;
  create_graph(&graph, MAX_VERTICES);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 5);
  add_edge(graph, 4, 6);

  print_topology(graph);

  return 0;
}