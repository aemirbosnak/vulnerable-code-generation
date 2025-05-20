//FormAI DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct Graph {
  int num_vertices;
  int **adj_matrix;
};

// Function to create a new graph
struct Graph* create_graph(int num_vertices) {
  struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
  graph->num_vertices = num_vertices;
  graph->adj_matrix = (int**) malloc(num_vertices * sizeof(int*));

  for (int i = 0; i < num_vertices; i++) {
    graph->adj_matrix[i] = (int*) calloc(num_vertices, sizeof(int));
  }

  return graph;
}

// Function to add edge to the graph
void add_edge(struct Graph *graph, int source, int destination) {
  graph->adj_matrix[source][destination] = 1;
  graph->adj_matrix[destination][source] = 1;
}

// Main function
int main() {
  struct Graph *graph = create_graph(5);

  add_edge(graph, 0, 1);
  add_edge(graph, 0, 4);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 1, 4);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);

  printf("Graph Representation:\n");

  for (int i = 0; i < graph->num_vertices; i++) {
    printf("%d: ", i);

    for (int j = 0; j < graph->num_vertices; j++) {
      printf("%d ", graph->adj_matrix[i][j]);
    }

    printf("\n");
  }

  return 0;
}