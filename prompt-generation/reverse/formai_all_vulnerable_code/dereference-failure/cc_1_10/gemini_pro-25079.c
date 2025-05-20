//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Graph data structure
typedef struct Graph {
  int num_nodes;
  int num_edges;
  int** adj_matrix;
} Graph;

// Function to create a new graph with n nodes and m edges
Graph* create_graph(int n, int m) {
  // Allocate memory for the graph
  Graph* graph = malloc(sizeof(Graph));
  if (graph == NULL) {
    return NULL;
  }

  // Initialize the number of nodes and edges
  graph->num_nodes = n;
  graph->num_edges = m;

  // Allocate memory for the adjacency matrix
  graph->adj_matrix = malloc(n * sizeof(int*));
  if (graph->adj_matrix == NULL) {
    free(graph);
    return NULL;
  }

  // Initialize the adjacency matrix
  for (int i = 0; i < n; i++) {
    graph->adj_matrix[i] = malloc(n * sizeof(int));
    if (graph->adj_matrix[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(graph->adj_matrix[j]);
      }
      free(graph->adj_matrix);
      free(graph);
      return NULL;
    }

    for (int j = 0; j < n; j++) {
      graph->adj_matrix[i][j] = 0;
    }
  }

  // Return the graph
  return graph;
}

// Function to free the memory allocated for a graph
void free_graph(Graph* graph) {
  // Free the adjacency matrix
  for (int i = 0; i < graph->num_nodes; i++) {
    free(graph->adj_matrix[i]);
  }
  free(graph->adj_matrix);

  // Free the graph
  free(graph);
}

// Function to add an edge to a graph
bool add_edge(Graph* graph, int u, int v) {
  // Check if the nodes are valid
  if (u < 0 || u >= graph->num_nodes || v < 0 || v >= graph->num_nodes) {
    return false;
  }

  // Add the edge to the adjacency matrix
  graph->adj_matrix[u][v] = 1;
  graph->adj_matrix[v][u] = 1;

  // Return true if the edge was added successfully
  return true;
}

// Function to check if a graph is connected
bool is_connected(Graph* graph) {
  // Create a queue to perform a breadth-first search
  int* queue = malloc(graph->num_nodes * sizeof(int));
  if (queue == NULL) {
    return false;
  }

  // Initialize the queue
  int front = 0;
  int rear = 0;
  queue[rear++] = 0;

  // Mark all nodes as unvisited
  bool* visited = malloc(graph->num_nodes * sizeof(bool));
  if (visited == NULL) {
    free(queue);
    return false;
  }

  for (int i = 0; i < graph->num_nodes; i++) {
    visited[i] = false;
  }

  // Perform a breadth-first search
  while (front != rear) {
    // Dequeue the next node from the queue
    int u = queue[front++];

    // Mark the node as visited
    visited[u] = true;

    // Enqueue all unvisited neighbors of the node
    for (int v = 0; v < graph->num_nodes; v++) {
      if (graph->adj_matrix[u][v] == 1 && !visited[v]) {
        queue[rear++] = v;
      }
    }
  }

  // Free the queue and the visited array
  free(queue);
  free(visited);

  // Return true if all nodes were visited
  for (int i = 0; i < graph->num_nodes; i++) {
    if (!visited[i]) {
      return false;
    }
  }

  return true;
}

// Function to check if a graph is bipartite
bool is_bipartite(Graph* graph) {
  // Check if the graph is connected
  if (!is_connected(graph)) {
    return false;
  }

  // Initialize the color of all nodes to -1
  int* color = malloc(graph->num_nodes * sizeof(int));
  if (color == NULL) {
    return false;
  }

  for (int i = 0; i < graph->num_nodes; i++) {
    color[i] = -1;
  }

  // Perform a breadth-first search to color the nodes
  int* queue = malloc(graph->num_nodes * sizeof(int));
  if (queue == NULL) {
    free(color);
    return false;
  }

  int front = 0;
  int rear = 0;
  queue[rear++] = 0;
  color[0] = 0;

  while (front != rear) {
    // Dequeue the next node from the queue
    int u = queue[front++];

    // Color the unvisited neighbors of the node
    for (int v = 0; v < graph->num_nodes; v++) {
      if (graph->adj_matrix[u][v] == 1 && color[v] == -1) {
        queue[rear++] = v;
        color[v] = 1 - color[u];
      } else if (graph->adj_matrix[u][v] == 1 && color[v] == color[u]) {
        free(color);
        free(queue);
        return false;
      }
    }
  }

  // Free the queue and the color array
  free(queue);
  free(color);

  // Return true if the graph is bipartite
  return true;
}

// Function to print the adjacency matrix of a graph
void print_adj_matrix(Graph* graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    for (int j = 0; j < graph->num_nodes; j++) {
      printf("%d ", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a graph with 5 nodes and 6 edges
  Graph* graph = create_graph(5, 6);

  // Add edges to the graph
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);

  // Print the adjacency matrix of the graph
  printf("Adjacency matrix:\n");
  print_adj_matrix(graph);

  // Check if the graph is connected
  printf("Is the graph connected? %s\n", is_connected(graph) ? "Yes" : "No");

  // Check if the graph is bipartite
  printf("Is the graph bipartite? %s\n", is_bipartite(graph) ? "Yes" : "No");

  // Free the memory allocated for the graph
  free_graph(graph);

  return 0;
}