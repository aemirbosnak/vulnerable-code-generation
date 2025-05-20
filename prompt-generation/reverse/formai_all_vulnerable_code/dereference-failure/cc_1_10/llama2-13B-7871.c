//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define GRAPH_MAX_NODES 1024
#define GRAPH_MAX_EDGES 1024

typedef struct node {
  int label;
  struct node *next;
  struct node *prev;
} Node;

typedef struct edge {
  int label;
  struct node *start;
  struct node *end;
} Edge;

// Graph representation as an adjacency list
Node *graph[GRAPH_MAX_NODES];
int num_nodes = 0;

// Function to add a node to the graph
void add_node(int label) {
  Node *new_node = (Node *) malloc(sizeof(Node));
  new_node->label = label;
  new_node->next = NULL;
  new_node->prev = NULL;
  if (num_nodes == GRAPH_MAX_NODES) {
    printf("Error: Maximum number of nodes reached\n");
    exit(1);
  }
  graph[num_nodes] = new_node;
  num_nodes++;
}

// Function to add an edge to the graph
void add_edge(int start_label, int end_label) {
  Edge *new_edge = (Edge *) malloc(sizeof(Edge));
  new_edge->label = start_label;
  new_edge->start = graph[start_label];
  new_edge->end = graph[end_label];
  if (new_edge->start == NULL || new_edge->end == NULL) {
    printf("Error: Node not found\n");
    exit(1);
  }
  new_edge->start->next = new_edge;
  new_edge->end->prev = new_edge;
  if (num_nodes <= GRAPH_MAX_NODES) {
    graph[num_nodes] = new_edge;
  } else {
    printf("Error: Maximum number of edges reached\n");
    exit(1);
  }
  num_nodes++;
}

// Function to traverse the graph
void traverse(Node *start) {
  if (start == NULL) {
    printf("Error: Start node not found\n");
    exit(1);
  }
  printf("%d -> ", start->label);
  Node *current = start;
  while (current != NULL) {
    printf("%d ", current->label);
    current = current->next;
  }
  printf("\n");
}

int main() {
  // Add some nodes and edges to the graph
  add_node(1);
  add_node(2);
  add_node(3);
  add_node(4);
  add_edge(1, 2);
  add_edge(2, 3);
  add_edge(3, 4);
  add_edge(4, 1);

  // Traverse the graph
  traverse(graph[1]);

  return 0;
}