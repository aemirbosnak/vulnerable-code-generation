//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define MAX_LABEL_LENGTH 100

typedef struct node {
  int id;
  char *label;
  int x;
  int y;
} node_t;

typedef struct edge {
  int source;
  int target;
  int weight;
  char *label;
} edge_t;

typedef struct graph {
  int num_nodes;
  node_t *nodes;
  int num_edges;
  edge_t *edges;
} graph_t;

graph_t *create_graph() {
  graph_t *graph = malloc(sizeof(graph_t));
  graph->num_nodes = 0;
  graph->nodes = malloc(sizeof(node_t) * MAX_NODES);
  graph->num_edges = 0;
  graph->edges = malloc(sizeof(edge_t) * MAX_EDGES);
  return graph;
}

void destroy_graph(graph_t *graph) {
  free(graph->nodes);
  free(graph->edges);
  free(graph);
}

void add_node(graph_t *graph, int id, char *label, int x, int y) {
  if (graph->num_nodes >= MAX_NODES) {
    fprintf(stderr, "Error: too many nodes\n");
    return;
  }
  graph->nodes[graph->num_nodes].id = id;
  graph->nodes[graph->num_nodes].label = strdup(label);
  graph->nodes[graph->num_nodes].x = x;
  graph->nodes[graph->num_nodes].y = y;
  graph->num_nodes++;
}

void add_edge(graph_t *graph, int source, int target, int weight, char *label) {
  if (graph->num_edges >= MAX_EDGES) {
    fprintf(stderr, "Error: too many edges\n");
    return;
  }
  graph->edges[graph->num_edges].source = source;
  graph->edges[graph->num_edges].target = target;
  graph->edges[graph->num_edges].weight = weight;
  graph->edges[graph->num_edges].label = strdup(label);
  graph->num_edges++;
}

void print_graph(graph_t *graph) {
  printf("Nodes:\n");
  for (int i = 0; i < graph->num_nodes; i++) {
    printf("  %d %s (%d, %d)\n", graph->nodes[i].id, graph->nodes[i].label, graph->nodes[i].x, graph->nodes[i].y);
  }
  printf("Edges:\n");
  for (int i = 0; i < graph->num_edges; i++) {
    printf("  %d -> %d (%d) %s\n", graph->edges[i].source, graph->edges[i].target, graph->edges[i].weight, graph->edges[i].label);
  }
}

int main() {
  graph_t *graph = create_graph();
  add_node(graph, 1, "Node 1", 100, 100);
  add_node(graph, 2, "Node 2", 200, 200);
  add_node(graph, 3, "Node 3", 300, 300);
  add_edge(graph, 1, 2, 10, "Edge 1-2");
  add_edge(graph, 2, 3, 20, "Edge 2-3");
  add_edge(graph, 3, 1, 30, "Edge 3-1");
  print_graph(graph);
  destroy_graph(graph);
  return 0;
}