//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of vertices and edges in the graph
#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Define the data structure for a vertex
typedef struct vertex {
  int value;           // The value of the vertex
  struct edge *edges;  // A linked list of edges connected to the vertex
} vertex;

// Define the data structure for an edge
typedef struct edge {
  int weight;     // The weight of the edge
  vertex *target; // The target vertex of the edge
  struct edge *next;  // The next edge in the linked list
} edge;

// Define the data structure for a graph
typedef struct graph {
  int num_vertices;   // The number of vertices in the graph
  int num_edges;     // The number of edges in the graph
  vertex *vertices;  // An array of vertices
  edge *edges;      // An array of edges
} graph;

// Create a new graph
graph *create_graph() {
  graph *g = malloc(sizeof(graph));
  g->num_vertices = 0;
  g->num_edges = 0;
  g->vertices = malloc(sizeof(vertex) * MAX_VERTICES);
  g->edges = malloc(sizeof(edge) * MAX_EDGES);
  return g;
}

// Add a vertex to the graph
void add_vertex(graph *g, int value) {
  if (g->num_vertices == MAX_VERTICES) {
    printf("Error: Maximum number of vertices reached\n");
    return;
  }

  g->vertices[g->num_vertices].value = value;
  g->vertices[g->num_vertices].edges = NULL;
  g->num_vertices++;
}

// Add an edge to the graph
void add_edge(graph *g, int source, int target, int weight) {
  if (g->num_edges == MAX_EDGES) {
    printf("Error: Maximum number of edges reached\n");
    return;
  }

  edge *e = &g->edges[g->num_edges];
  e->weight = weight;
  e->target = &g->vertices[target];
  e->next = g->vertices[source].edges;
  g->vertices[source].edges = e;
  g->num_edges++;
}

// Print the graph
void print_graph(graph *g) {
  for (int i = 0; i < g->num_vertices; i++) {
    printf("Vertex %d: ", g->vertices[i].value);
    for (edge *e = g->vertices[i].edges; e != NULL; e = e->next) {
      printf("%d (%d) -> ", e->target->value, e->weight);
    }
    printf("\n");
  }
}

int main() {
  // Create a graph
  graph *g = create_graph();

  // Add vertices to the graph
  add_vertex(g, 1);
  add_vertex(g, 2);
  add_vertex(g, 3);

  // Add edges to the graph
  add_edge(g, 0, 1, 5);
  add_edge(g, 0, 2, 10);
  add_edge(g, 1, 2, 15);

  // Print the graph
  print_graph(g);

  return 0;
}