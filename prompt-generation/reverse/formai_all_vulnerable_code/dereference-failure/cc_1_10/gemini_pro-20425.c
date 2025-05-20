//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
  int num_vertices;
  int num_edges;
  int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} graph;

graph* create_graph(int num_vertices, int num_edges) {
  graph* g = (graph*)malloc(sizeof(graph));
  g->num_vertices = num_vertices;
  g->num_edges = num_edges;
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      g->adjacency_matrix[i][j] = 0;
    }
  }
  return g;
}

void destroy_graph(graph* g) {
  free(g);
}

int add_edge(graph* g, int u, int v) {
  if (u < 0 || u >= g->num_vertices || v < 0 || v >= g->num_vertices) {
    return -1;
  }
  g->adjacency_matrix[u][v] = 1;
  g->adjacency_matrix[v][u] = 1;
  return 0;
}

int remove_edge(graph* g, int u, int v) {
  if (u < 0 || u >= g->num_vertices || v < 0 || v >= g->num_vertices) {
    return -1;
  }
  g->adjacency_matrix[u][v] = 0;
  g->adjacency_matrix[v][u] = 0;
  return 0;
}

int is_valid_coloring(graph* g, int* colors) {
  for (int i = 0; i < g->num_vertices; i++) {
    for (int j = i + 1; j < g->num_vertices; j++) {
      if (g->adjacency_matrix[i][j] == 1 && colors[i] == colors[j]) {
        return 0;
      }
    }
  }
  return 1;
}

int color_graph(graph* g, int* colors, int num_colors) {
  if (num_colors < 1) {
    return -1;
  }
  int min_num_colors = num_colors;
  for (int i = 0; i < g->num_vertices; i++) {
    for (int j = 0; j < num_colors; j++) {
      colors[i] = j;
      if (is_valid_coloring(g, colors)) {
        min_num_colors = j;
      }
    }
  }
  return min_num_colors;
}

int main() {
  int num_vertices, num_edges;
  printf("Enter the number of vertices and edges: ");
  scanf("%d %d", &num_vertices, &num_edges);
  graph* g = create_graph(num_vertices, num_edges);
  for (int i = 0; i < num_edges; i++) {
    int u, v;
    printf("Enter the endpoints of the edge: ");
    scanf("%d %d", &u, &v);
    add_edge(g, u, v);
  }
  int num_colors;
  printf("Enter the number of colors: ");
  scanf("%d", &num_colors);
  int* colors = (int*)malloc(sizeof(int) * num_vertices);
  int min_num_colors = color_graph(g, colors, num_colors);
  if (min_num_colors == -1) {
    printf("The graph cannot be colored with the given number of colors.\n");
  } else {
    printf("The graph can be colored with %d colors.\n", min_num_colors);
    for (int i = 0; i < num_vertices; i++) {
      printf("Vertex %d is colored with color %d.\n", i, colors[i]);
    }
  }
  destroy_graph(g);
  free(colors);
  return 0;
}