//FormAI DATASET v1.0 Category: Graph representation ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

// Graph Structure
typedef struct Graph {
  int V;         // Number of vertices
  int E;         // Number of edges
  int **adj;     // 2D adjacency matrix
}Graph;

// Creates and returns a new Graph.
Graph* graph_create(int V) {
  Graph* g = (Graph*) malloc(sizeof(Graph));   // Allocate space for Graph
  
  g->V = V;                                    // Initialize vertices
  g->E = 0;                                    // Initialize edges
  
  // Create adjacency matrix
  g->adj = (int**) calloc(V, sizeof(int*));    // Allocate space for each row
  for(int i=0; i<V; i++)                       // Allocate space for each column
    g->adj[i] = (int*) calloc(V, sizeof(int));
    
  return g;
}

// Adds an edge to the Graph
void graph_add_edge(Graph* g, int u, int v) {
  g->adj[u][v] = 1;
  g->adj[v][u] = 1;
  g->E++;
}

// Prints the adjacency matrix of the Graph
void graph_print(Graph* g) {
  printf("Adjacency Matrix:\n");
  for(int i=0; i<g->V; i++) {
    for(int j=0; j<g->V; j++)
      printf("%d ", g->adj[i][j]);
    printf("\n");
  }
}

// Main Function
int main() {
  Graph* g = graph_create(5);
  
  graph_add_edge(g, 0, 1);
  graph_add_edge(g, 0, 4);
  graph_add_edge(g, 1, 2);
  graph_add_edge(g, 1, 3);
  graph_add_edge(g, 1, 4);
  graph_add_edge(g, 2, 3);
  graph_add_edge(g, 3, 4);
  
  graph_print(g);
  
  free(g);    // Free dynamically allocated space
  return 0;
}