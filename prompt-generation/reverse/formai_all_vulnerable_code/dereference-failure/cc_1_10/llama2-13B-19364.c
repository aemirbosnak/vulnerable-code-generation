//LLAMA2-13B DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the minimum spanning tree of a graph
void mst(int* adjacency_matrix, int n) {
  int* parent = (int*)calloc(n, sizeof(int));
  int* dist = (int*)calloc(n, sizeof(int));
  int* prev = (int*)calloc(n, sizeof(int));

  // Initialize distances and parents
  for (int i = 0; i < n; i++) {
    dist[i] = INFINITY;
    parent[i] = -1;
    prev[i] = -1;
  }

  // Mark the source node as visited
  dist[0] = 0;
  parent[0] = -1;

  // Perform Dijkstra's algorithm
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist[j] > dist[i] + adjacency_matrix[i * n + j]) {
        dist[j] = dist[i] + adjacency_matrix[i * n + j];
        parent[j] = i;
        prev[j] = i;
      }
    }
  }

  // Print the minimum spanning tree
  for (int i = 0; i < n; i++) {
    if (parent[i] != -1) {
      printf("%d -> %d (dist = %d)\n", i, parent[i], dist[i]);
    }
  }

  free(parent);
  free(dist);
  free(prev);
}

int main() {
  int n = 5;
  int adjacency_matrix[] = {
   0, 1, 2, 3, 4,
   1, 0, 3, 4, 5,
   2, 3, 0, 4, 5,
   3, 4, 4, 0, 5,
   4, 5, 5, 5, 0
  };

  mst(adjacency_matrix, n);

  return 0;
}