//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node;

typedef struct graph {
  int num_vertices;
  int num_edges;
  int **adj_matrix;
  node **adj_list;
} graph;

graph *create_graph(int num_vertices) {
  graph *g = (graph *)malloc(sizeof(graph));
  g->num_vertices = num_vertices;
  g->num_edges = 0;
  g->adj_matrix = (int **)malloc(sizeof(int *) * num_vertices);
  for (int i = 0; i < num_vertices; i++) {
    g->adj_matrix[i] = (int *)malloc(sizeof(int) * num_vertices);
    for (int j = 0; j < num_vertices; j++) {
      g->adj_matrix[i][j] = 0;
    }
  }
  g->adj_list = (node **)malloc(sizeof(node *) * num_vertices);
  for (int i = 0; i < num_vertices; i++) {
    g->adj_list[i] = NULL;
  }
  return g;
}

void add_edge(graph *g, int u, int v) {
  if (u < 0 || u >= g->num_vertices || v < 0 || v >= g->num_vertices) {
    return;
  }
  g->adj_matrix[u][v] = 1;
  g->adj_matrix[v][u] = 1;
  g->num_edges++;

  // Add the edge to the adjacency list
  node *new_node = (node *)malloc(sizeof(node));
  new_node->value = v;
  new_node->next = g->adj_list[u];
  g->adj_list[u] = new_node;

  new_node = (node *)malloc(sizeof(node));
  new_node->value = u;
  new_node->next = g->adj_list[v];
  g->adj_list[v] = new_node;
}

void print_graph(graph *g) {
  for (int i = 0; i < g->num_vertices; i++) {
    printf("Vertex %d: ", i);
    node *curr = g->adj_list[i];
    while (curr != NULL) {
      printf("%d ", curr->value);
      curr = curr->next;
    }
    printf("\n");
  }
}

int main() {
  graph *g = create_graph(5);
  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 2);
  add_edge(g, 1, 3);
  add_edge(g, 2, 3);
  add_edge(g, 2, 4);
  add_edge(g, 3, 4);

  print_graph(g);

  return 0;
}