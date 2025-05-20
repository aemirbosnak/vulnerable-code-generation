//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph {
  int V;            // Number of vertices
  int E;            // Number of edges
  int **adj;        // Adjacency matrix
  int *color;       // Color of each vertex
  int *degree;      // Degree of each vertex
};

// Function to create a new graph
struct Graph* create_graph(int V, int E) {
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
  graph->color = (int*)malloc(V * sizeof(int));
  for (int i = 0; i < V; i++) {
    graph->color[i] = -1;
  }
  graph->degree = (int*)malloc(V * sizeof(int));
  for (int i = 0; i < V; i++) {
    graph->degree[i] = 0;
  }
  return graph;
}

// Function to add an edge to the graph
void add_edge(struct Graph* graph, int u, int v) {
  graph->adj[u][v] = 1;
  graph->adj[v][u] = 1;
  graph->degree[u]++;
  graph->degree[v]++;
}

// Function to print the adjacency matrix of the graph
void print_adj_matrix(struct Graph* graph) {
  printf("Adjacency matrix:\n");
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      printf("%d ", graph->adj[i][j]);
    }
    printf("\n");
  }
}

// Function to print the color of each vertex in the graph
void print_vertex_colors(struct Graph* graph) {
  printf("Vertex colors:\n");
  for (int i = 0; i < graph->V; i++) {
    printf("%d ", graph->color[i]);
  }
  printf("\n");
}

// Function to check if the graph is properly colored
int is_properly_colored(struct Graph* graph) {
  for (int i = 0; i < graph->V; i++) {
    for (int j = i + 1; j < graph->V; j++) {
      if (graph->adj[i][j] == 1 && graph->color[i] == graph->color[j]) {
        return 0;
      }
    }
  }
  return 1;
}

// Function to find the minimum number of colors needed to color the graph
int find_min_colors(struct Graph* graph) {
  int max_degree = 0;
  for (int i = 0; i < graph->V; i++) {
    if (graph->degree[i] > max_degree) {
      max_degree = graph->degree[i];
    }
  }
  return max_degree + 1;
}

// Function to color the graph using greedy algorithm
void color_graph_greedy(struct Graph* graph) {
  int min_colors = find_min_colors(graph);
  for (int i = 0; i < min_colors; i++) {
    int max_degree_vertex = -1;
    for (int j = 0; j < graph->V; j++) {
      if (graph->color[j] == -1 && (max_degree_vertex == -1 || graph->degree[j] > graph->degree[max_degree_vertex])) {
        max_degree_vertex = j;
      }
    }
    graph->color[max_degree_vertex] = i;
    for (int j = 0; j < graph->V; j++) {
      if (graph->adj[max_degree_vertex][j] == 1) {
        graph->color[j] = -2;
      }
    }
  }
}

// Function to test the graph coloring algorithm
int main() {
  // Create a graph
  struct Graph* graph = create_graph(5, 6);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);

  // Print the adjacency matrix of the graph
  print_adj_matrix(graph);

  // Color the graph using greedy algorithm
  color_graph_greedy(graph);

  // Print the color of each vertex in the graph
  print_vertex_colors(graph);

  // Check if the graph is properly colored
  if (is_properly_colored(graph)) {
    printf("The graph is properly colored.\n");
  } else {
    printf("The graph is not properly colored.\n");
  }

  return 0;
}