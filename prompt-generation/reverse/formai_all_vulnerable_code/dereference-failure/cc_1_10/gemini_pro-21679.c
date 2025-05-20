//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

// Graph structure
struct Graph {
  int V;  // Number of vertices
  int E;  // Number of edges
  int **adj;  // Adjacency matrix
};

// Create a new graph
struct Graph* createGraph(int V, int E) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->adj = (int**)malloc(V * sizeof(int*));
  for (int i = 0; i < V; i++) {
    graph->adj[i] = (int*)malloc(V * sizeof(int));
    for (int j = 0; j < V; j++) {
      graph->adj[i][j] = 0;
    }
  }
  return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
  graph->adj[u][v] = 1;
  graph->adj[v][u] = 1;
}

// Print the graph
void printGraph(struct Graph* graph) {
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      printf("%d ", graph->adj[i][j]);
    }
    printf("\n");
  }
}

// Free the graph
void freeGraph(struct Graph* graph) {
  for (int i = 0; i < graph->V; i++) {
    free(graph->adj[i]);
  }
  free(graph->adj);
  free(graph);
}

// Main function
int main() {
  // Create a graph with 4 vertices and 5 edges
  struct Graph* graph = createGraph(4, 5);

  // Add edges to the graph
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);

  // Print the graph
  printGraph(graph);

  // Free the graph
  freeGraph(graph);

  return 0;
}