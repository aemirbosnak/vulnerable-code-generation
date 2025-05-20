//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct {
  int num_vertices;
  int num_edges;
  int **adj_matrix;
} graph_t;

typedef struct {
  int vertex;
  int color;
} vertex_color_t;

// Function to create a new graph with the specified number of vertices and edges
graph_t *create_graph(int num_vertices, int num_edges) {
  graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
  graph->num_vertices = num_vertices;
  graph->num_edges = num_edges;
  graph->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
  for (int i = 0; i < num_vertices; i++) {
    graph->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
    for (int j = 0; j < num_vertices; j++) {
      graph->adj_matrix[i][j] = 0;
    }
  }
  return graph;
}

// Function to add an edge to the graph
void add_edge(graph_t *graph, int vertex1, int vertex2) {
  graph->adj_matrix[vertex1][vertex2] = 1;
  graph->adj_matrix[vertex2][vertex1] = 1;
}

// Function to print the adjacency matrix of the graph
void print_adj_matrix(graph_t *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      printf("%d ", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to check if the graph is properly colored
int is_graph_colored(graph_t *graph, vertex_color_t *vertex_colors) {
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = i + 1; j < graph->num_vertices; j++) {
      if (graph->adj_matrix[i][j] == 1 && vertex_colors[i].color == vertex_colors[j].color) {
        return 0;
      }
    }
  }
  return 1;
}

// Function to color the graph using the greedy algorithm
void color_graph_greedy(graph_t *graph, vertex_color_t *vertex_colors) {
  int available_colors[MAX_COLORS];
  for (int i = 0; i < MAX_COLORS; i++) {
    available_colors[i] = 1;
  }

  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      if (graph->adj_matrix[i][j] == 1) {
        available_colors[vertex_colors[j].color] = 0;
      }
    }

    for (int j = 0; j < MAX_COLORS; j++) {
      if (available_colors[j] == 1) {
        vertex_colors[i].color = j;
        break;
      }
    }

    for (int j = 0; j < graph->num_vertices; j++) {
      if (graph->adj_matrix[i][j] == 1) {
        available_colors[vertex_colors[j].color] = 1;
      }
    }
  }
}

// Function to print the coloring of the graph
void print_graph_coloring(graph_t *graph, vertex_color_t *vertex_colors) {
  for (int i = 0; i < graph->num_vertices; i++) {
    printf("Vertex %d: Color %d\n", vertex_colors[i].vertex, vertex_colors[i].color);
  }
}

int main() {
  // Create a graph with 6 vertices and 9 edges
  graph_t *graph = create_graph(6, 9);

  // Add edges to the graph
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 0, 3);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 4);
  add_edge(graph, 2, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 4);
  add_edge(graph, 4, 5);

  // Create an array to store the colors of the vertices
  vertex_color_t vertex_colors[graph->num_vertices];
  for (int i = 0; i < graph->num_vertices; i++) {
    vertex_colors[i].vertex = i;
    vertex_colors[i].color = -1;
  }

  // Color the graph using the greedy algorithm
  color_graph_greedy(graph, vertex_colors);

  // Check if the graph is properly colored
  if (is_graph_colored(graph, vertex_colors)) {
    printf("The graph is properly colored.\n");
  } else {
    printf("The graph is not properly colored.\n");
  }

  // Print the coloring of the graph
  print_graph_coloring(graph, vertex_colors);

  return 0;
}