//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10
#define MAX_NODES 100

typedef struct node {
  int id;
  int color;
  struct node *next;
} node_t;

typedef struct graph {
  int num_nodes;
  int num_edges;
  node_t *nodes;
} graph_t;

graph_t *create_graph(int num_nodes) {
  graph_t *graph = malloc(sizeof(graph_t));
  graph->num_nodes = num_nodes;
  graph->num_edges = 0;
  graph->nodes = malloc(sizeof(node_t) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    graph->nodes[i].id = i;
    graph->nodes[i].color = -1;
    graph->nodes[i].next = NULL;
  }
  return graph;
}

void add_edge(graph_t *graph, int node1, int node2) {
  node_t *node = &graph->nodes[node1];
  while (node->next != NULL) {
    node = node->next;
  }
  node->next = &graph->nodes[node2];
  graph->num_edges++;
}

int is_safe(graph_t *graph, int node, int color) {
  node_t *adj_node = graph->nodes[node].next;
  while (adj_node != NULL) {
    if (adj_node->color == color) {
      return 0;
    }
    adj_node = adj_node->next;
  }
  return 1;
}

int graph_color(graph_t *graph, int node, int color) {
  if (node == graph->num_nodes) {
    return 1;
  }
  for (int i = 0; i < MAX_COLORS; i++) {
    if (is_safe(graph, node, i)) {
      graph->nodes[node].color = i;
      if (graph_color(graph, node + 1, i)) {
        return 1;
      }
      graph->nodes[node].color = -1;
    }
  }
  return 0;
}

void print_graph(graph_t *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    printf("Node %d: ", graph->nodes[i].id);
    if (graph->nodes[i].color == -1) {
      printf("Uncolored\n");
    } else {
      printf("Colored %d\n", graph->nodes[i].color);
    }
  }
}

int main() {
  graph_t *graph = create_graph(5);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);

  if (graph_color(graph, 0, 0)) {
    printf("Graph colored successfully:\n");
    print_graph(graph);
  } else {
    printf("Graph cannot be colored with %d colors.\n", MAX_COLORS);
  }

  free(graph);
  return 0;
}