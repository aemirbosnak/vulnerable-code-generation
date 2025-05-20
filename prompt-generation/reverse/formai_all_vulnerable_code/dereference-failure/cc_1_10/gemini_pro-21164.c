//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

/* A graph is composed of vertices and edges.
   A graph can be represented as an adjacency matrix,
   an adjacency list, or an incidence matrix. */

typedef struct vertex {
  int id;
  struct vertex *next;
} vertex;

typedef struct edge {
  int id;
  struct vertex *start;
  struct vertex *end;
  struct edge *next;
} edge;

typedef struct graph {
  int num_vertices;
  int num_edges;
  struct vertex *head;
  struct edge *head_edge;
} graph;

/* Create a new graph. */
graph *create_graph(int num_vertices) {
  graph *g = (graph *)malloc(sizeof(graph));
  g->num_vertices = num_vertices;
  g->num_edges = 0;
  g->head = NULL;
  g->head_edge = NULL;
  return g;
}

/* Create a new vertex. */
vertex *create_vertex(int id) {
  vertex *v = (vertex *)malloc(sizeof(vertex));
  v->id = id;
  v->next = NULL;
  return v;
}

/* Create a new edge. */
edge *create_edge(struct vertex *start, struct vertex *end) {
  edge *e = (edge *)malloc(sizeof(edge));
  e->id = 0;
  e->start = start;
  e->end = end;
  e->next = NULL;
  return e;
}

/* Add a vertex to a graph. */
void add_vertex(graph *g, struct vertex *v) {
  if (g->head == NULL) {
    g->head = v;
  } else {
    vertex *curr = g->head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = v;
  }
}

/* Add an edge to a graph. */
void add_edge(graph *g, struct edge *e) {
  if (g->head_edge == NULL) {
    g->head_edge = e;
  } else {
    edge *curr = g->head_edge;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = e;
  }
}

/* Print a graph. */
void print_graph(graph *g) {
  vertex *curr_vertex = g->head;
  while (curr_vertex != NULL) {
    printf("Vertex %d:\n", curr_vertex->id);
    edge *curr_edge = curr_vertex->next;
    while (curr_edge != NULL) {
      printf("  Edge %d: %d -> %d\n", curr_edge->id, curr_edge->start->id,
             curr_edge->end->id);
      curr_edge = curr_edge->next;
    }
    curr_vertex = curr_vertex->next;
  }
}

/* Free a graph. */
void free_graph(graph *g) {
  vertex *curr_vertex = g->head;
  while (curr_vertex != NULL) {
    vertex *next_vertex = curr_vertex->next;
    free(curr_vertex);
    curr_vertex = next_vertex;
  }

  edge *curr_edge = g->head_edge;
  while (curr_edge != NULL) {
    edge *next_edge = curr_edge->next;
    free(curr_edge);
    curr_edge = next_edge;
  }

  free(g);
}

int main() {
  /* Create a graph. */
  graph *g = create_graph(5);

  /* Add vertices to the graph. */
  add_vertex(g, create_vertex(0));
  add_vertex(g, create_vertex(1));
  add_vertex(g, create_vertex(2));
  add_vertex(g, create_vertex(3));
  add_vertex(g, create_vertex(4));

  /* Add edges to the graph. */
  add_edge(g, create_edge(g->head, g->head->next));
  add_edge(g, create_edge(g->head, g->head->next->next));
  add_edge(g, create_edge(g->head->next, g->head->next->next->next));
  add_edge(g, create_edge(g->head->next->next, g->head->next->next->next));
  add_edge(g, create_edge(g->head->next->next->next, g->head));

  /* Print the graph. */
  print_graph(g);

  /* Free the graph. */
  free_graph(g);

  return 0;
}