//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 100

// Maximum number of colors
#define MAX_COLORS 10

// Data structure to represent a graph
typedef struct Graph {
  int num_vertices;
  int num_edges;
  int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Data structure to represent a solution to the graph coloring problem
typedef struct Solution {
  int colors[MAX_VERTICES];
} Solution;

// Function to create a new graph
Graph* create_graph(int num_vertices, int num_edges) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->num_vertices = num_vertices;
  graph->num_edges = num_edges;

  // Initialize the adjacency matrix to 0
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      graph->adj_matrix[i][j] = 0;
    }
  }

  // Add the edges to the graph
  for (int i = 0; i < num_edges; i++) {
    int vertex1, vertex2;
    scanf("%d %d", &vertex1, &vertex2);
    graph->adj_matrix[vertex1][vertex2] = 1;
    graph->adj_matrix[vertex2][vertex1] = 1;
  }

  return graph;
}

// Function to free the memory allocated for a graph
void free_graph(Graph* graph) {
  free(graph);
}

// Function to create a new solution
Solution* create_solution(int num_vertices) {
  Solution* solution = (Solution*)malloc(sizeof(Solution));

  // Initialize the colors to 0
  for (int i = 0; i < num_vertices; i++) {
    solution->colors[i] = 0;
  }

  return solution;
}

// Function to free the memory allocated for a solution
void free_solution(Solution* solution) {
  free(solution);
}

// Function to check if a solution is valid
int is_valid_solution(Graph* graph, Solution* solution) {
  // Check if any two adjacent vertices have the same color
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      if (graph->adj_matrix[i][j] == 1 && solution->colors[i] == solution->colors[j]) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to print a solution
void print_solution(Graph* graph, Solution* solution) {
  printf("Solution:\n");
  for (int i = 0; i < graph->num_vertices; i++) {
    printf("Vertex %d: Color %d\n", i, solution->colors[i]);
  }
}

// Function to find all solutions to the graph coloring problem
void find_all_solutions(Graph* graph, Solution* solution, int vertex) {
  // If we have colored all vertices, then we have found a solution
  if (vertex == graph->num_vertices) {
    if (is_valid_solution(graph, solution)) {
      print_solution(graph, solution);
    }
    return;
  }

  // Try all possible colors for the current vertex
  for (int color = 1; color <= MAX_COLORS; color++) {
    solution->colors[vertex] = color;
    find_all_solutions(graph, solution, vertex + 1);
  }
}

// Main function
int main() {
  //srand(time(NULL));

  // Get the number of vertices and edges in the graph
  int num_vertices, num_edges;
  scanf("%d %d", &num_vertices, &num_edges);

  // Create the graph
  Graph* graph = create_graph(num_vertices, num_edges);

  // Create the solution
  Solution* solution = create_solution(num_vertices);

  // Find all solutions to the graph coloring problem
  find_all_solutions(graph, solution, 0);

  // Free the memory allocated for the graph and the solution
  free_graph(graph);
  free_solution(solution);

  return 0;
}