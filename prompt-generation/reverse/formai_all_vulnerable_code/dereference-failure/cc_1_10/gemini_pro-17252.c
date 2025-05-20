//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct vertex {
  int value;
  struct vertex *next;
} vertex_t;

typedef struct graph {
  int num_vertices;
  vertex_t *vertices[MAX_VERTICES];
} graph_t;

graph_t *create_graph() {
  graph_t *graph = malloc(sizeof(graph_t));
  graph->num_vertices = 0;
  for (int i = 0; i < MAX_VERTICES; i++) {
    graph->vertices[i] = NULL;
  }
  return graph;
}

void add_vertex(graph_t *graph, int value) {
  if (graph->num_vertices >= MAX_VERTICES) {
    printf("Error: Graph is full\n");
    return;
  }

  vertex_t *vertex = malloc(sizeof(vertex_t));
  vertex->value = value;
  vertex->next = NULL;

  graph->vertices[graph->num_vertices++] = vertex;
}

void add_edge(graph_t *graph, int source, int destination) {
  if (source >= graph->num_vertices || destination >= graph->num_vertices) {
    printf("Error: Invalid vertex\n");
    return;
  }

  vertex_t *vertex = malloc(sizeof(vertex_t));
  vertex->value = destination;
  vertex->next = graph->vertices[source]->next;

  graph->vertices[source]->next = vertex;
}

void print_graph(graph_t *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    printf("%d: ", graph->vertices[i]->value);
    for (vertex_t *vertex = graph->vertices[i]->next; vertex != NULL; vertex = vertex->next) {
      printf("%d ", vertex->value);
    }
    printf("\n");
  }
}

int main() {
  graph_t *graph = create_graph();

  add_vertex(graph, 0);
  add_vertex(graph, 1);
  add_vertex(graph, 2);
  add_vertex(graph, 3);

  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 3);

  print_graph(graph);

  return 0;
}