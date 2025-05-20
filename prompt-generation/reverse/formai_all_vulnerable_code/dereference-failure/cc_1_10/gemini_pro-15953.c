//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
  int id;
  char *label;
  int num_edges;
  struct edge **edges;
} node;

typedef struct edge {
  int id;
  node *source;
  node *destination;
  char *label;
} edge;

typedef struct graph {
  int num_nodes;
  int num_edges;
  node *nodes[MAX_NODES];
  edge *edges[MAX_EDGES];
} graph;

graph *create_graph() {
  graph *g = (graph *)malloc(sizeof(graph));
  g->num_nodes = 0;
  g->num_edges = 0;
  return g;
}

void add_node(graph *g, node *n) {
  g->nodes[g->num_nodes] = n;
  g->num_nodes++;
}

void add_edge(graph *g, edge *e) {
  g->edges[g->num_edges] = e;
  g->num_edges++;
}

void print_graph(graph *g) {
  for (int i = 0; i < g->num_nodes; i++) {
    node *n = g->nodes[i];
    printf("Node %d: %s\n", n->id, n->label);
    for (int j = 0; j < n->num_edges; j++) {
      edge *e = n->edges[j];
      printf("  Edge %d: %s -> %s\n", e->id, e->source->label, e->destination->label);
    }
  }
}

int main() {
  graph *g = create_graph();

  node *n1 = (node *)malloc(sizeof(node));
  n1->id = 1;
  n1->label = "Node 1";
  n1->num_edges = 0;
  n1->edges = NULL;
  add_node(g, n1);

  node *n2 = (node *)malloc(sizeof(node));
  n2->id = 2;
  n2->label = "Node 2";
  n2->num_edges = 0;
  n2->edges = NULL;
  add_node(g, n2);

  edge *e1 = (edge *)malloc(sizeof(edge));
  e1->id = 1;
  e1->source = n1;
  e1->destination = n2;
  e1->label = "Edge 1";
  add_edge(g, e1);

  print_graph(g);

  return 0;
}