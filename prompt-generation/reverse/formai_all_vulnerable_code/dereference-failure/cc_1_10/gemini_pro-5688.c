//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph
struct Graph {
  int V;          // Number of vertices
  int E;          // Number of edges
  int **adj;      // Adjacency matrix
  int *color;     // Color of each vertex
};

// Function to create a graph
struct Graph* createGraph(int V, int E) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;

  // Create the adjacency matrix
  graph->adj = (int**)malloc(V * sizeof(int*));
  for (int i = 0; i < V; i++) {
    graph->adj[i] = (int*)malloc(V * sizeof(int));
    for (int j = 0; j < V; j++) {
      graph->adj[i][j] = 0;
    }
  }

  // Create the color array
  graph->color = (int*)malloc(V * sizeof(int));
  for (int i = 0; i < V; i++) {
    graph->color[i] = 0;
  }

  return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
  graph->adj[u][v] = 1;
  graph->adj[v][u] = 1;
}

// Function to check if the graph is bipartite
int isBipartite(struct Graph* graph) {
  for (int i = 0; i < graph->V; i++) {
    if (graph->color[i] == 0) {
      if (!dfs(graph, i, 1)) {
        return 0;
      }
    }
  }
  return 1;
}

// Function to perform DFS on the graph
int dfs(struct Graph* graph, int v, int color) {
  graph->color[v] = color;
  for (int i = 0; i < graph->V; i++) {
    if (graph->adj[v][i] && graph->color[i] == color) {
      return 0;
    } else if (graph->adj[v][i] && graph->color[i] == 0) {
      if (!dfs(graph, i, -color)) {
        return 0;
      }
    }
  }
  return 1;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      printf("%d ", graph->adj[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a graph
  struct Graph* graph = createGraph(4, 4);

  // Add edges to the graph
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  // Print the graph
  printGraph(graph);

  // Check if the graph is bipartite
  if (isBipartite(graph)) {
    printf("The graph is bipartite.\n");
  } else {
    printf("The graph is not bipartite.\n");
  }

  return 0;
}