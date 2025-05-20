//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph.
#define MAX_VERTICES 100

// Define the data type for a vertex.
typedef struct vertex {
  int value;
  struct vertex *next;
} vertex_t;

// Define the data type for a graph.
typedef struct graph {
  int num_vertices;
  vertex_t *vertices[MAX_VERTICES];
} graph_t;

// Create a new graph.
graph_t *create_graph() {
  graph_t *graph = malloc(sizeof(graph_t));
  graph->num_vertices = 0;
  for (int i = 0; i < MAX_VERTICES; i++) {
    graph->vertices[i] = NULL;
  }
  return graph;
}

// Add a vertex to the graph.
void add_vertex(graph_t *graph, int value) {
  // Check if the graph is full.
  if (graph->num_vertices == MAX_VERTICES) {
    printf("Error: The graph is full.\n");
    return;
  }

  // Create a new vertex.
  vertex_t *vertex = malloc(sizeof(vertex_t));
  vertex->value = value;
  vertex->next = NULL;

  // Add the vertex to the graph.
  graph->vertices[graph->num_vertices++] = vertex;
}

// Add an edge between two vertices.
void add_edge(graph_t *graph, int source, int destination) {
  // Check if the source and destination vertices are valid.
  if (source < 0 || source >= graph->num_vertices) {
    printf("Error: Invalid source vertex.\n");
    return;
  }
  if (destination < 0 || destination >= graph->num_vertices) {
    printf("Error: Invalid destination vertex.\n");
    return;
  }

  // Create a new edge.
  vertex_t *edge = malloc(sizeof(vertex_t));
  edge->value = destination;
  edge->next = graph->vertices[source]->next;

  // Add the edge to the source vertex.
  graph->vertices[source]->next = edge;
}

// Print the graph.
void print_graph(graph_t *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    vertex_t *vertex = graph->vertices[i];
    printf("Vertex %d: ", vertex->value);
    while (vertex != NULL) {
      printf("%d ", vertex->value);
      vertex = vertex->next;
    }
    printf("\n");
  }
}

// Free the graph.
void free_graph(graph_t *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    vertex_t *vertex = graph->vertices[i];
    while (vertex != NULL) {
      vertex_t *next = vertex->next;
      free(vertex);
      vertex = next;
    }
  }
  free(graph);
}

int main() {
  // Create a new graph.
  graph_t *graph = create_graph();

  // Add vertices to the graph.
  add_vertex(graph, 0);
  add_vertex(graph, 1);
  add_vertex(graph, 2);
  add_vertex(graph, 3);
  add_vertex(graph, 4);

  // Add edges to the graph.
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 4);

  // Print the graph.
  print_graph(graph);

  // Free the graph.
  free_graph(graph);

  return 0;
}