//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph
typedef struct Graph {
  int V; // Number of vertices
  int E; // Number of edges
  int **adj; // Adjacency matrix
} Graph;

// Function to create a new graph
Graph *createGraph(int V, int E) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->V = V;
  graph->E = E;
  graph->adj = (int **)malloc(V * sizeof(int *));
  for (int i = 0; i < V; i++) {
    graph->adj[i] = (int *)malloc(V * sizeof(int));
    for (int j = 0; j < V; j++) {
      graph->adj[i][j] = 0;
    }
  }
  return graph;
}

// Function to add an edge to a graph
void addEdge(Graph *graph, int u, int v) {
  graph->adj[u][v] = 1;
  graph->adj[v][u] = 1;
}

// Function to check if a graph is bipartite
int isBipartite(Graph *graph) {
  int *color = (int *)malloc(graph->V * sizeof(int));
  for (int i = 0; i < graph->V; i++) {
    color[i] = -1;
  }

  // Queue to store the vertices to be colored
  int queue[graph->V];
  int front = 0, rear = 0;

  // Color the first vertex with color 0
  color[0] = 0;
  queue[rear++] = 0;

  while (front != rear) {
    int u = queue[front++];

    // Iterate over all adjacent vertices of u
    for (int v = 0; v < graph->V; v++) {
      if (graph->adj[u][v] && color[v] == -1) {
        // Color the adjacent vertex with the opposite color of u
        color[v] = 1 - color[u];
        queue[rear++] = v;
      } else if (graph->adj[u][v] && color[v] == color[u]) {
        // If there is an edge between u and v and they have the same color, then the graph is not bipartite
        return 0;
      }
    }
  }

  // If all vertices have been colored without any conflicts, then the graph is bipartite
  return 1;
}

// Function to print the graph
void printGraph(Graph *graph) {
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      printf("%d ", graph->adj[i][j]);
    }
    printf("\n");
  }
}

// Driver code
int main() {
  // Create a graph
  Graph *graph = createGraph(4, 4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  // Print the graph
  printf("Graph:\n");
  printGraph(graph);

  // Check if the graph is bipartite
  int is_bipartite = isBipartite(graph);

  // Print the result
  if (is_bipartite) {
    printf("Graph is bipartite\n");
  } else {
    printf("Graph is not bipartite\n");
  }

  return 0;
}