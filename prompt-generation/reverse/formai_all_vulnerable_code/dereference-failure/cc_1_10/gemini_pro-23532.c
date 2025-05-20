//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
  int id;
  int weight;
  struct edge *next;
} edge;

typedef struct {
  int id;
  int num_edges;
  edge *edges;
} node;

typedef struct {
  int num_nodes;
  node *nodes;
} graph;

void create_graph(graph *g) {
  int i;

  g->num_nodes = 0;
  g->nodes = (node *)malloc(sizeof(node) * MAX_NODES);
  for (i = 0; i < MAX_NODES; i++) {
    g->nodes[i].id = i;
    g->nodes[i].num_edges = 0;
    g->nodes[i].edges = NULL;
  }
}

void destroy_graph(graph *g) {
  int i;

  for (i = 0; i < g->num_nodes; i++) {
    edge *e = g->nodes[i].edges;
    while (e) {
      edge *next = e->next;
      free(e);
      e = next;
    }
  }

  free(g->nodes);
}

void add_edge(graph *g, int src, int dst, int weight) {
  edge *e = (edge *)malloc(sizeof(edge));

  e->id = dst;
  e->weight = weight;
  e->next = g->nodes[src].edges;
  g->nodes[src].edges = e;
  g->nodes[src].num_edges++;
}

void print_graph(graph *g) {
  int i;

  for (i = 0; i < g->num_nodes; i++) {
    edge *e = g->nodes[i].edges;
    printf("Node %d:\n", g->nodes[i].id);
    while (e) {
      printf("  - %d (%d)\n", e->id, e->weight);
      e = e->next;
    }
  }
}

int main() {
  graph g;
  int i, j;

  create_graph(&g);

  for (i = 0; i < MAX_NODES; i++) {
    for (j = i + 1; j < MAX_NODES; j++) {
      if (rand() % 2) {
        add_edge(&g, i, j, rand() % 100);
      }
    }
  }

  print_graph(&g);

  destroy_graph(&g);

  return 0;
}