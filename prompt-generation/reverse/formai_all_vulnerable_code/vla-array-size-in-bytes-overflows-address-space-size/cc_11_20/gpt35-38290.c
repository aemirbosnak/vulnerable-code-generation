//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
  int numVertices;
  int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

int main() {

  // User input for number of vertices
  printf("Enter the number of vertices: \n");
  int numVertices;
  scanf("%d", &numVertices);

  // Initialize empty graph
  struct Graph g;
  g.numVertices = numVertices;
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      g.adjacencyMatrix[i][j] = 0;
    }
  }

  // User input for graph edges
  printf("Enter the edges of the graph in the form 'u v' (separated by spaces): \n");
  for (int i = 0; i < numVertices * (numVertices - 1) / 2; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u == -1 && v == -1) {
      break;
    }
    g.adjacencyMatrix[u][v] = 1;
    g.adjacencyMatrix[v][u] = 1;
  }

  // Initialize array to store vertex colors
  int color[numVertices];
  for (int i = 0; i < numVertices; i++) {
    color[i] = -1;
  }

  // Color first vertex with first color
  color[0] = 0;

  // Greedy algorithm for coloring remaining vertices
  for (int i = 1; i < numVertices; i++) {
    bool available[numVertices];
    for (int j = 0; j < numVertices; j++) {
      available[j] = true;
    }
    for (int j = 0; j < numVertices; j++) {
      if (g.adjacencyMatrix[i][j] && color[j] != -1) {
        available[color[j]] = false;
      }
    }
    int j;
    for (j = 0; j < numVertices; j++) {
      if (available[j]) {
        break;
      }
    }
    color[i] = j;
  }

  // Print the colors of each vertex
  printf("Vertex Color\n");
  for (int i = 0; i < numVertices; i++) {
    printf("%d      %d\n", i, color[i]);
  }

  return 0;
}