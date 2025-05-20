//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph Coloring Problem using Backtracking

// A structure to represent a graph
typedef struct Graph {
  int V;           // Number of vertices
  int **adj;       // Adjacency matrix
  int *color;      // Color assigned to each vertex
} Graph;

// A utility function to create a new graph
Graph *createGraph(int V) {
  Graph *graph = malloc(sizeof(Graph));
  graph->V = V;
  graph->adj = malloc(sizeof(int *) * V);
  for (int i = 0; i < V; i++) {
    graph->adj[i] = malloc(sizeof(int) * V);
  }
  graph->color = malloc(sizeof(int) * V);
  return graph;
}

// A utility function to check if the current color assignment is valid
int isSafe(Graph *graph, int vertex, int color) {
  // Check if any adjacent vertex is already colored with the same color
  for (int i = 0; i < graph->V; i++) {
    if (graph->adj[vertex][i] == 1 && graph->color[i] == color) {
      return 0;
    }
  }
  return 1;
}

// A recursive function to solve the graph coloring problem
int graphColoring(Graph *graph, int vertex) {
  // Base case: If all vertices are colored, return true
  if (vertex == graph->V) {
    return 1;
  }

  // Try all possible colors for the current vertex
  for (int i = 1; i <= graph->V; i++) {
    // Check if the current color is safe for the current vertex
    if (isSafe(graph, vertex, i)) {
      // Assign the current color to the current vertex
      graph->color[vertex] = i;

      // Recursively call the function for the next vertex
      if (graphColoring(graph, vertex + 1)) {
        return 1;
      }

      // If the recursive call failed, reset the color of the current vertex
      graph->color[vertex] = 0;
    }
  }

  // If no color is safe for the current vertex, return false
  return 0;
}

// A utility function to print the solution
void printSolution(Graph *graph) {
  printf("The following is a valid coloring of the graph:\n");
  for (int i = 0; i < graph->V; i++) {
    printf("Vertex %d: Color %d\n", i + 1, graph->color[i]);
  }
}

// Driver program to test the above functions
int main() {
  // Create a graph given in the example
  Graph *graph = createGraph(4);
  graph->adj[0][1] = 1;
  graph->adj[0][2] = 1;
  graph->adj[1][2] = 1;
  graph->adj[1][3] = 1;
  graph->adj[2][3] = 1;

  // Color the graph using backtracking
  if (graphColoring(graph, 0)) {
    printSolution(graph);
  } else {
    printf("No valid coloring exists for the given graph.\n");
  }

  // Free the memory allocated for the graph
  for (int i = 0; i < graph->V; i++) {
    free(graph->adj[i]);
  }
  free(graph->adj);
  free(graph->color);
  free(graph);

  return 0;
}