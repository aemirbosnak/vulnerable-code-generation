//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: brave
// Brave Graph Representation

// Define the graph structure
struct Graph {
  int num_vertices;
  int *edges;
};

// Define a function to create a new graph
struct Graph* create_graph(int num_vertices) {
  struct Graph* g = malloc(sizeof(struct Graph));
  g->num_vertices = num_vertices;
  g->edges = malloc(num_vertices * num_vertices * sizeof(int));
  return g;
}

// Define a function to add an edge to the graph
void add_edge(struct Graph* g, int v1, int v2) {
  g->edges[v1 * g->num_vertices + v2] = 1;
}

// Define a function to print the graph
void print_graph(struct Graph* g) {
  for (int i = 0; i < g->num_vertices; i++) {
    for (int j = 0; j < g->num_vertices; j++) {
      if (g->edges[i * g->num_vertices + j]) {
        printf("%d -> %d ", i, j);
      }
    }
    printf("\n");
  }
}

int main() {
  // Create a new graph with 5 vertices
  struct Graph* g = create_graph(5);

  // Add edges to the graph
  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 3);
  add_edge(g, 2, 4);

  // Print the graph
  print_graph(g);

  // Free the graph memory
  free(g->edges);
  free(g);

  return 0;
}