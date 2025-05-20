//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10
#define MAX_NODES 100

// Graph data structure
typedef struct graph {
  int num_nodes;
  int num_edges;
  int adj_matrix[MAX_NODES][MAX_NODES];
} graph;

// Node data structure
typedef struct node {
  int color;
  int visited;
} node;

// Function to create a new graph
graph* create_graph(int num_nodes, int num_edges) {
  graph* g = (graph*)malloc(sizeof(graph));
  g->num_nodes = num_nodes;
  g->num_edges = num_edges;

  // Initialize the adjacency matrix to 0
  for (int i = 0; i < num_nodes; i++) {
    for (int j = 0; j < num_nodes; j++) {
      g->adj_matrix[i][j] = 0;
    }
  }

  return g;
}

// Function to add an edge to a graph
void add_edge(graph* g, int node1, int node2) {
  g->adj_matrix[node1][node2] = 1;
  g->adj_matrix[node2][node1] = 1;
}

// Function to print a graph
void print_graph(graph* g) {
  for (int i = 0; i < g->num_nodes; i++) {
    for (int j = 0; j < g->num_nodes; j++) {
      printf("%d ", g->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a graph is bipartite
int is_bipartite(graph* g) {
  // Initialize the colors of all nodes to -1
  int colors[MAX_NODES];
  for (int i = 0; i < g->num_nodes; i++) {
    colors[i] = -1;
  }

  // Queue to store the nodes to be visited
  int queue[MAX_NODES];
  int front = 0;
  int rear = 0;

  // Enqueue the first node
  queue[rear++] = 0;

  // Color the first node with 0
  colors[0] = 0;

  // While there are nodes to be visited
  while (front < rear) {
    // Dequeue the next node
    int node = queue[front++];

    // Iterate over the neighbors of the node
    for (int i = 0; i < g->num_nodes; i++) {
      // If there is an edge between the node and the neighbor
      if (g->adj_matrix[node][i] == 1) {
        // If the neighbor has not been visited
        if (colors[i] == -1) {
          // Color the neighbor with the opposite color of the node
          colors[i] = 1 - colors[node];

          // Enqueue the neighbor
          queue[rear++] = i;
        }
        // If the neighbor has been visited and its color is the same as the node's color
        else if (colors[i] == colors[node]) {
          // The graph is not bipartite
          return 0;
        }
      }
    }
  }

  // The graph is bipartite
  return 1;
}

// Main function
int main() {
  // Create a graph
  graph* g = create_graph(4, 4);

  // Add edges to the graph
  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 2);
  add_edge(g, 2, 3);

  // Print the graph
  printf("Graph:\n");
  print_graph(g);

  // Check if the graph is bipartite
  int is_bip = is_bipartite(g);

  // Print the result
  if (is_bip) {
    printf("The graph is bipartite.\n");
  } else {
    printf("The graph is not bipartite.\n");
  }

  return 0;
}