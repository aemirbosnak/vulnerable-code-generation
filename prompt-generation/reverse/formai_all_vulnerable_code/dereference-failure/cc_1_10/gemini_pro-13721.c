//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 20
#define MAX_EDGES 100

typedef struct _node {
  int vertex;
  struct _node *next;
} Node;

typedef struct _graph {
  int num_vertices;
  int num_edges;
  Node *adj_list[MAX_VERTICES];
} Graph;

Graph *create_graph(int num_vertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->num_vertices = num_vertices;
  graph->num_edges = 0;
  for (int i = 0; i < num_vertices; i++) {
    graph->adj_list[i] = NULL;
  }
  return graph;
}

void destroy_graph(Graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    Node *p = graph->adj_list[i];
    while (p != NULL) {
      Node *q = p->next;
      free(p);
      p = q;
    }
  }
  free(graph);
}

void add_edge(Graph *graph, int u, int v) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->vertex = v;
  p->next = graph->adj_list[u];
  graph->adj_list[u] = p;
  graph->num_edges++;
}

void print_graph(Graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    printf("%d: ", i);
    Node *p = graph->adj_list[i];
    while (p != NULL) {
      printf("%d ", p->vertex);
      p = p->next;
    }
    printf("\n");
  }
}

int main() {
  Graph *graph = create_graph(MAX_VERTICES);
  // Add edges to the graph
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 1, 4);
  add_edge(graph, 2, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 4);

  // Print the graph
  print_graph(graph);

  // Destroy the graph
  destroy_graph(graph);

  return 0;
}