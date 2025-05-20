//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS  10
#define MAX_VERTICES 100

typedef struct {
  int num_vertices;
  int num_edges;
  int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct {
  int num_colors;
  int color_assignment[MAX_VERTICES];
} Coloring;

// Function to read a graph from a file
Graph *read_graph(char *filename) {
  FILE *fp;
  Graph *graph;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  graph = (Graph *)malloc(sizeof(Graph));
  if (graph == NULL) {
    perror("Error allocating memory for graph");
    fclose(fp);
    return NULL;
  }

  fscanf(fp, "%d %d", &graph->num_vertices, &graph->num_edges);

  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      fscanf(fp, "%d", &graph->adj_matrix[i][j]);
    }
  }

  fclose(fp);

  return graph;
}

// Function to print a graph
void print_graph(Graph *graph) {
  printf("Number of vertices: %d\n", graph->num_vertices);
  printf("Number of edges: %d\n", graph->num_edges);

  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      printf("%d ", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a coloring is valid
int is_valid_coloring(Graph *graph, Coloring *coloring) {
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = i + 1; j < graph->num_vertices; j++) {
      if (graph->adj_matrix[i][j] == 1 && coloring->color_assignment[i] == coloring->color_assignment[j]) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to find the minimum number of colors needed to color a graph
int find_min_colors(Graph *graph) {
  Coloring coloring;
  int min_colors = MAX_COLORS;

  for (int i = 0; i < MAX_COLORS; i++) {
    coloring.num_colors = i;
    if (is_valid_coloring(graph, &coloring)) {
      min_colors = i;
      break;
    }
  }

  return min_colors;
}

// Function to print a coloring
void print_coloring(Graph *graph, Coloring *coloring) {
  printf("Coloring with %d colors:\n", coloring->num_colors);

  for (int i = 0; i < graph->num_vertices; i++) {
    printf("Vertex %d: color %d\n", i, coloring->color_assignment[i]);
  }
}

int main(int argc, char *argv[]) {
  Graph *graph;
  Coloring coloring;
  int min_colors;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <graph_filename>\n", argv[0]);
    return 1;
  }

  graph = read_graph(argv[1]);
  if (graph == NULL) {
    return 1;
  }

  min_colors = find_min_colors(graph);
  if (min_colors == MAX_COLORS) {
    printf("The graph cannot be colored with less than %d colors.\n", MAX_COLORS);
  } else {
    printf("The graph can be colored with %d colors.\n", min_colors);
  }

  return 0;
}