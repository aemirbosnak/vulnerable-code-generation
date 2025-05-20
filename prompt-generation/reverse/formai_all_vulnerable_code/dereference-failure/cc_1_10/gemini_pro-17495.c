//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the graph structure
typedef struct Graph {
  int num_nodes;
  int num_edges;
  int **adj_matrix;
} Graph;

// Create a new graph
Graph *create_graph(int num_nodes) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->num_nodes = num_nodes;
  graph->num_edges = 0;
  graph->adj_matrix = (int **)malloc(sizeof(int *) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    graph->adj_matrix[i] = (int *)calloc(num_nodes, sizeof(int));
  }
  return graph;
}

// Destroy the graph
void destroy_graph(Graph *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    free(graph->adj_matrix[i]);
  }
  free(graph);
}

// Add an edge to the graph
void add_edge(Graph *graph, int node1, int node2) {
  if (node1 < 0 || node1 >= graph->num_nodes || node2 < 0 || node2 >= graph->num_nodes) {
    return;
  }
  graph->adj_matrix[node1][node2] = 1;
  graph->adj_matrix[node2][node1] = 1;
  graph->num_edges++;
}

// Print the graph
void print_graph(Graph *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    for (int j = 0; j < graph->num_nodes; j++) {
      printf("%d", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Find the path from node1 to node2 using BFS
int *bfs(Graph *graph, int node1, int node2) {
  int *visited = (int *)calloc(graph->num_nodes, sizeof(int));
  int *queue = (int *)malloc(sizeof(int) * graph->num_nodes);
  int front = 0;
  int rear = 0;
  queue[rear++] = node1;
  visited[node1] = 1;
  int *path = (int *)malloc(sizeof(int) * graph->num_nodes);
  path[0] = node1;
  while (front != rear) {
    int node = queue[front++];
    if (node == node2) {
      return path;
    }
    for (int i = 0; i < graph->num_nodes; i++) {
      if (graph->adj_matrix[node][i] && !visited[i]) {
        queue[rear++] = i;
        visited[i] = 1;
        path[rear] = i;
      }
    }
  }
  return NULL;
}

// Find the path from node1 to node2 using DFS
int *dfs(Graph *graph, int node1, int node2) {
  int *visited = (int *)calloc(graph->num_nodes, sizeof(int));
  int *stack = (int *)malloc(sizeof(int) * graph->num_nodes);
  int top = 0;
  stack[top++] = node1;
  visited[node1] = 1;
  int *path = (int *)malloc(sizeof(int) * graph->num_nodes);
  path[0] = node1;
  while (top != 0) {
    int node = stack[--top];
    if (node == node2) {
      return path;
    }
    for (int i = 0; i < graph->num_nodes; i++) {
      if (graph->adj_matrix[node][i] && !visited[i]) {
        stack[top++] = i;
        visited[i] = 1;
        path[top] = i;
      }
    }
  }
  return NULL;
}

// Main function
int main() {
  // Create a graph with 7 nodes representing the post-apocalyptic world
  Graph *graph = create_graph(7);

  // Add edges to the graph representing the connections between the nodes
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 5);
  add_edge(graph, 4, 6);

  // Find the path from node 0 to node 6 using BFS
  int *path = bfs(graph, 0, 6);
  if (path) {
    printf("Path from node 0 to node 6 using BFS:");
    for (int i = 0; path[i] != -1; i++) {
      printf(" %d", path[i]);
    }
    printf("\n");
  } else {
    printf("No path from node 0 to node 6 using BFS\n");
  }

  // Find the path from node 0 to node 6 using DFS
  path = dfs(graph, 0, 6);
  if (path) {
    printf("Path from node 0 to node 6 using DFS:");
    for (int i = 0; path[i] != -1; i++) {
      printf(" %d", path[i]);
    }
    printf("\n");
  } else {
    printf("No path from node 0 to node 6 using DFS\n");
  }

  // Destroy the graph
  destroy_graph(graph);

  return 0;
}