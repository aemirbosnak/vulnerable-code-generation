//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 10

// Define the data structure for a vertex
typedef struct vertex {
  int data;
  struct vertex *next;
} vertex;

// Define the data structure for a graph
typedef struct graph {
  int num_vertices;
  vertex *vertices[MAX_VERTICES];
} graph;

// Create a new graph
graph *create_graph() {
  graph *g = (graph *)malloc(sizeof(graph));
  g->num_vertices = 0;
  for (int i = 0; i < MAX_VERTICES; i++) {
    g->vertices[i] = NULL;
  }
  return g;
}

// Add a vertex to the graph
void add_vertex(graph *g, int data) {
  if (g->num_vertices >= MAX_VERTICES) {
    printf("Error: Graph is full\n");
    return;
  }
  vertex *new_vertex = (vertex *)malloc(sizeof(vertex));
  new_vertex->data = data;
  new_vertex->next = NULL;
  g->vertices[g->num_vertices++] = new_vertex;
}

// Add an edge between two vertices
void add_edge(graph *g, int v1, int v2) {
  if (v1 < 0 || v1 >= g->num_vertices || v2 < 0 || v2 >= g->num_vertices) {
    printf("Error: Invalid vertex\n");
    return;
  }
  vertex *new_edge = (vertex *)malloc(sizeof(vertex));
  new_edge->data = v2;
  new_edge->next = g->vertices[v1]->next;
  g->vertices[v1]->next = new_edge;
}

// Print the graph
void print_graph(graph *g) {
  for (int i = 0; i < g->num_vertices; i++) {
    printf("%d: ", g->vertices[i]->data);
    vertex *curr = g->vertices[i]->next;
    while (curr != NULL) {
      printf("%d ", curr->data);
      curr = curr->next;
    }
    printf("\n");
  }
}

// Free the graph
void free_graph(graph *g) {
  for (int i = 0; i < g->num_vertices; i++) {
    vertex *curr = g->vertices[i];
    while (curr != NULL) {
      vertex *next = curr->next;
      free(curr);
      curr = next;
    }
  }
  free(g);
}

int main() {
  // Create a new graph
  graph *g = create_graph();

  // Add some vertices to the graph
  add_vertex(g, 1);
  add_vertex(g, 2);
  add_vertex(g, 3);
  add_vertex(g, 4);

  // Add some edges to the graph
  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 2);
  add_edge(g, 1, 3);
  add_edge(g, 2, 3);

  // Print the graph
  print_graph(g);

  // Free the graph
  free_graph(g);

  return 0;
}