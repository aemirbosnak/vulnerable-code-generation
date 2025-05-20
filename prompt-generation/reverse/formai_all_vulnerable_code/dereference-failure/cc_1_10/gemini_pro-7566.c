//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10
#define MAX_NODES 100

typedef struct {
  int num_nodes;
  int num_edges;
  int adj_matrix[MAX_NODES][MAX_NODES];
} Graph;

typedef struct {
  int num_colors;
  int colors[MAX_NODES];
} Coloring;

Graph *create_graph(int num_nodes, int num_edges) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->num_nodes = num_nodes;
  graph->num_edges = num_edges;

  for (int i = 0; i < num_nodes; i++) {
    for (int j = 0; j < num_nodes; j++) {
      graph->adj_matrix[i][j] = 0;
    }
  }

  return graph;
}

void add_edge(Graph *graph, int node1, int node2) {
  graph->adj_matrix[node1][node2] = 1;
  graph->adj_matrix[node2][node1] = 1;
}

Coloring *create_coloring(Graph *graph) {
  Coloring *coloring = (Coloring *)malloc(sizeof(Coloring));
  coloring->num_colors = 0;

  for (int i = 0; i < graph->num_nodes; i++) {
    coloring->colors[i] = -1;
  }

  return coloring;
}

int is_valid_coloring(Graph *graph, Coloring *coloring) {
  for (int i = 0; i < graph->num_nodes; i++) {
    for (int j = i + 1; j < graph->num_nodes; j++) {
      if (graph->adj_matrix[i][j] == 1 && coloring->colors[i] == coloring->colors[j]) {
        return 0;
      }
    }
  }

  return 1;
}

int color_graph(Graph *graph, Coloring *coloring, int num_colors) {
  if (coloring->num_colors == graph->num_nodes) {
    return is_valid_coloring(graph, coloring);
  }

  for (int i = 0; i < num_colors; i++) {
    coloring->colors[coloring->num_colors] = i;
    coloring->num_colors++;

    if (color_graph(graph, coloring, num_colors)) {
      return 1;
    }

    coloring->num_colors--;
  }

  return 0;
}

int main() {
  Graph *graph = create_graph(4, 3);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);

  Coloring *coloring = create_coloring(graph);

  if (color_graph(graph, coloring, 3)) {
    printf("Graph can be colored with 3 colors.\n");
  } else {
    printf("Graph cannot be colored with 3 colors.\n");
  }

  return 0;
}