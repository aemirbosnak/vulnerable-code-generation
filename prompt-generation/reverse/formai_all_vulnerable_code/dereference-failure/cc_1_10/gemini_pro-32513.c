//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// A graph is a set of vertices and a set of edges.
// A vertex is a point in the graph.
// An edge is a connection between two vertices.
// A graph can be represented as a two-dimensional array, where the rows and
// columns represent the vertices and the values in the cells represent the edges.

// A graph coloring problem is a problem where you have to assign colors to the
// vertices of a graph so that no two adjacent vertices have the same color.
// The number of colors that you can use is limited.

// This program solves the graph coloring problem using a backtracking algorithm.
// The backtracking algorithm starts with an empty coloring and tries to assign
// colors to the vertices one by one.
// If the algorithm finds a solution, it prints the solution and exits.
// If the algorithm does not find a solution, it backtracks and tries a different
// coloring.

// The following function checks if a given coloring is valid.
// A coloring is valid if no two adjacent vertices have the same color.
int is_valid_coloring(int *coloring, int num_vertices, int **graph) {
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      if (graph[i][j] == 1 && coloring[i] == coloring[j]) {
        return 0;
      }
    }
  }
  return 1;
}

// The following function finds a solution to the graph coloring problem using a
// backtracking algorithm.
// The backtracking algorithm starts with an empty coloring and tries to assign
// colors to the vertices one by one.
// If the algorithm finds a solution, it prints the solution and exits.
// If the algorithm does not find a solution, it backtracks and tries a different
// coloring.
void graph_coloring(int *coloring, int num_vertices, int **graph) {
  // If all vertices have been colored, then the solution is valid.
  if (num_vertices == 0) {
    // Print the solution.
    for (int i = 0; i < num_vertices; i++) {
      printf("%d ", coloring[i]);
    }
    printf("\n");
    exit(0);
  }

  // Try all possible colors for the next vertex.
  for (int color = 1; color <= num_vertices; color++) {
    // Check if the current coloring is valid.
    coloring[num_vertices] = color;
    if (is_valid_coloring(coloring, num_vertices + 1, graph)) {
      // Recursively solve the problem for the remaining vertices.
      graph_coloring(coloring, num_vertices + 1, graph);
    }
  }

  // If no valid coloring was found, then backtrack.
  coloring[num_vertices] = 0;
}

int main() {
  // The number of vertices in the graph.
  int num_vertices = 4;

  // The graph is represented as a two-dimensional array.
  int **graph = malloc(num_vertices * sizeof(int *));
  for (int i = 0; i < num_vertices; i++) {
    graph[i] = malloc(num_vertices * sizeof(int));
  }

  // The initial coloring is empty.
  int *coloring = malloc(num_vertices * sizeof(int));
  for (int i = 0; i < num_vertices; i++) {
    coloring[i] = 0;
  }

  // Solve the graph coloring problem.
  graph_coloring(coloring, 0, graph);

  return 0;
}