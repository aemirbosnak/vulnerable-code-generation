//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
  int num_vertices;
  int num_edges;
  int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
  int vertex_colors[MAX_VERTICES];
} Graph;

Graph* create_graph(int num_vertices, int num_edges) {
  Graph* graph = malloc(sizeof(Graph));
  graph->num_vertices = num_vertices;
  graph->num_edges = num_edges;
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      graph->adjacency_matrix[i][j] = 0;
    }
  }
  for (int i = 0; i < num_edges; i++) {
    int vertex1, vertex2;
    scanf("%d %d", &vertex1, &vertex2);
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
  }
  return graph;
}

void free_graph(Graph* graph) {
  free(graph);
}

int is_safe(Graph* graph, int vertex, int color) {
  for (int i = 0; i < graph->num_vertices; i++) {
    if (graph->adjacency_matrix[vertex][i] == 1 && graph->vertex_colors[i] == color) {
      return 0;
    }
  }
  return 1;
}

int graph_color(Graph* graph, int vertex, int num_colors) {
  if (vertex == graph->num_vertices) {
    return 1;
  }
  for (int i = 1; i <= num_colors; i++) {
    if (is_safe(graph, vertex, i)) {
      graph->vertex_colors[vertex] = i;
      if (graph_color(graph, vertex + 1, num_colors)) {
        return 1;
      }
      graph->vertex_colors[vertex] = 0;
    }
  }
  return 0;
}

int main() {
  int num_vertices, num_edges;
  scanf("%d %d", &num_vertices, &num_edges);
  Graph* graph = create_graph(num_vertices, num_edges);
  int num_colors = 3;
  if (graph_color(graph, 0, num_colors)) {
    printf("The graph can be colored with %d colors.\n", num_colors);
    for (int i = 0; i < num_vertices; i++) {
      printf("Vertex %d is colored with color %d.\n", i, graph->vertex_colors[i]);
    }
  } else {
    printf("The graph cannot be colored with %d colors.\n", num_colors);
  }
  free_graph(graph);
  return 0;
}