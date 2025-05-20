//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
  int num_vertices;
  int num_edges;
  int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph *create_graph(int num_vertices) {
  Graph *graph = malloc(sizeof(Graph));
  graph->num_vertices = num_vertices;
  graph->num_edges = 0;
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      graph->adj[i][j] = 0;
    }
  }
  return graph;
}

void add_edge(Graph *graph, int source, int destination) {
  if (source < 0 || source >= graph->num_vertices) {
    printf("Invalid source vertex\n");
    return;
  }
  if (destination < 0 || destination >= graph->num_vertices) {
    printf("Invalid destination vertex\n");
    return;
  }
  graph->adj[source][destination] = 1;
  graph->num_edges++;
}

void print_graph(Graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      printf("%d ", graph->adj[i][j]);
    }
    printf("\n");
  }
}

int main() {
  Graph *graph = create_graph(5);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);
  print_graph(graph);
  return 0;
}