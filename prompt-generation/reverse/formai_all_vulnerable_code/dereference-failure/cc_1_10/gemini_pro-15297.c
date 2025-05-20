//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct node {
  int id;
  int x;
  int y;
  struct edge *edges;
  int num_edges;
} node;

typedef struct edge {
  int id;
  node *node1;
  node *node2;
  int weight;
} edge;

typedef struct graph {
  node *nodes;
  int num_nodes;
  edge *edges;
  int num_edges;
} graph;

graph *create_graph(int num_nodes, int num_edges) {
  graph *g = malloc(sizeof(graph));
  g->nodes = malloc(sizeof(node) * num_nodes);
  g->edges = malloc(sizeof(edge) * num_edges);
  g->num_nodes = num_nodes;
  g->num_edges = num_edges;
  return g;
}

void destroy_graph(graph *g) {
  free(g->nodes);
  free(g->edges);
  free(g);
}

void add_node(graph *g, int id, int x, int y) {
  node *n = &g->nodes[g->num_nodes++];
  n->id = id;
  n->x = x;
  n->y = y;
  n->edges = NULL;
  n->num_edges = 0;
}

void add_edge(graph *g, int id, node *node1, node *node2, int weight) {
  edge *e = &g->edges[g->num_edges++];
  e->id = id;
  e->node1 = node1;
  e->node2 = node2;
  e->weight = weight;
  node1->num_edges++;
  node2->num_edges++;
}

void print_graph(graph *g) {
  for (int i = 0; i < g->num_nodes; i++) {
    node *n = &g->nodes[i];
    printf("Node %d: (%d, %d)\n", n->id, n->x, n->y);
    for (int j = 0; j < n->num_edges; j++) {
      edge *e = &n->edges[j];
      printf("  Edge %d: to node %d, weight %d\n", e->id, e->node2->id, e->weight);
    }
  }
}

int main() {
  graph *g = create_graph(5, 6);
  add_node(g, 0, 0, 0);
  add_node(g, 1, 1, 0);
  add_node(g, 2, 2, 0);
  add_node(g, 3, 0, 1);
  add_node(g, 4, 1, 1);
  add_edge(g, 0, &g->nodes[0], &g->nodes[1], 1);
  add_edge(g, 1, &g->nodes[1], &g->nodes[2], 1);
  add_edge(g, 2, &g->nodes[2], &g->nodes[3], 1);
  add_edge(g, 3, &g->nodes[3], &g->nodes[4], 1);
  add_edge(g, 4, &g->nodes[4], &g->nodes[0], 1);
  add_edge(g, 5, &g->nodes[1], &g->nodes[3], 1);
  print_graph(g);
  destroy_graph(g);
  return 0;
}