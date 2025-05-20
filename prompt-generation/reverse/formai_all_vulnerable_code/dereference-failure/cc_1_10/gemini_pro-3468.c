//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Node {
  int value;
  struct Node *next;
};

struct Graph {
  int num_nodes;
  int num_edges;
  struct Node *adj_list[MAX_NODES];
};

struct Graph *create_graph(int num_nodes) {
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->num_nodes = num_nodes;
  graph->num_edges = 0;

  for (int i = 0; i < num_nodes; i++) {
    graph->adj_list[i] = NULL;
  }

  return graph;
}

void add_edge(struct Graph *graph, int src, int dest) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->value = dest;
  new_node->next = graph->adj_list[src];
  graph->adj_list[src] = new_node;

  graph->num_edges++;
}

void print_graph(struct Graph *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    printf("Node %d: ", i);
    struct Node *current = graph->adj_list[i];
    while (current != NULL) {
      printf("%d ", current->value);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  // Create a graph with 5 nodes.
  struct Graph *graph = create_graph(5);

  // Add edges to the graph.
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 4);

  // Print the graph.
  print_graph(graph);

  return 0;
}