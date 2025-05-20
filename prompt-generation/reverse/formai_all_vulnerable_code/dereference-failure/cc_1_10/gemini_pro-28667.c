//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
  int id;
  char *label;
  int x;
  int y;
  int z;
} vertex_t;

typedef struct {
  int id;
  int source;
  int destination;
  int weight;
} edge_t;

typedef struct {
  int num_vertices;
  int num_edges;
  vertex_t vertices[MAX_VERTICES];
  edge_t edges[MAX_EDGES];
} graph_t;

graph_t *create_graph() {
  graph_t *g = (graph_t *)malloc(sizeof(graph_t));
  g->num_vertices = 0;
  g->num_edges = 0;
  return g;
}

void add_vertex(graph_t *g, int id, char *label, int x, int y, int z) {
  vertex_t v;
  v.id = id;
  v.label = strdup(label);
  v.x = x;
  v.y = y;
  v.z = z;
  g->vertices[g->num_vertices++] = v;
}

void add_edge(graph_t *g, int id, int source, int destination, int weight) {
  edge_t e;
  e.id = id;
  e.source = source;
  e.destination = destination;
  e.weight = weight;
  g->edges[g->num_edges++] = e;
}

void print_graph(graph_t *g) {
  int i;
  printf("Vertices:\n");
  for (i = 0; i < g->num_vertices; i++) {
    printf("  %d: %s (%d, %d, %d)\n", g->vertices[i].id, g->vertices[i].label, g->vertices[i].x, g->vertices[i].y, g->vertices[i].z);
  }
  printf("Edges:\n");
  for (i = 0; i < g->num_edges; i++) {
    printf("  %d: %d -> %d (%d)\n", g->edges[i].id, g->edges[i].source, g->edges[i].destination, g->edges[i].weight);
  }
}

void free_graph(graph_t *g) {
  int i;
  for (i = 0; i < g->num_vertices; i++) {
    free(g->vertices[i].label);
  }
  free(g);
}

int main() {
  graph_t *g = create_graph();

  add_vertex(g, 1, "Vertex 1", 0, 0, 0);
  add_vertex(g, 2, "Vertex 2", 10, 0, 0);
  add_vertex(g, 3, "Vertex 3", 0, 10, 0);
  add_vertex(g, 4, "Vertex 4", 10, 10, 0);
  add_vertex(g, 5, "Vertex 5", 0, 0, 10);

  add_edge(g, 1, 1, 2, 10);
  add_edge(g, 2, 2, 3, 20);
  add_edge(g, 3, 3, 4, 30);
  add_edge(g, 4, 4, 5, 40);
  add_edge(g, 5, 5, 1, 50);

  print_graph(g);

  free_graph(g);

  return 0;
}