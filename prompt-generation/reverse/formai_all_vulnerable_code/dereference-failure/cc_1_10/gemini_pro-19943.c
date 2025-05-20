//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct edge {
  int u;
  int v;
  int weight;
} edge;

typedef struct graph {
  int num_vertices;
  int num_edges;
  edge *edges;
} graph;

graph *create_graph(int num_vertices) {
  graph *g = (graph *)malloc(sizeof(graph));
  g->num_vertices = num_vertices;
  g->num_edges = 0;
  g->edges = (edge *)malloc(sizeof(edge) * MAX_VERTICES);
  return g;
}

void add_edge(graph *g, int u, int v, int weight) {
  g->edges[g->num_edges].u = u;
  g->edges[g->num_edges].v = v;
  g->edges[g->num_edges].weight = weight;
  g->num_edges++;
}

void print_graph(graph *g) {
  for (int i = 0; i < g->num_edges; i++) {
    printf("%d %d %d\n", g->edges[i].u, g->edges[i].v, g->edges[i].weight);
  }
}

int main() {
  graph *g = create_graph(5);
  add_edge(g, 0, 1, 10);
  add_edge(g, 0, 2, 20);
  add_edge(g, 1, 2, 30);
  add_edge(g, 1, 3, 40);
  add_edge(g, 2, 3, 50);
  add_edge(g, 3, 4, 60);
  add_edge(g, 4, 0, 70);

  print_graph(g);

  return 0;
}