//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 4

typedef struct {
  int vertices[MAX_VERTICES];
  int colors[MAX_VERTICES];
} Graph;

int main() {
  Graph g;
  int i, j, k;
  int num_vertices, num_edges;
  int color;

  // Initialize random seed
  srand(time(NULL));

  // Generate a random graph
  num_vertices = rand() % (MAX_VERTICES - 1) + 1;
  num_edges = rand() % (num_vertices * (num_vertices - 1)) + 1;
  for (i = 0; i < num_vertices; i++) {
    g.vertices[i] = i;
    g.colors[i] = 0;
  }
  for (i = 0; i < num_edges; i++) {
    do {
      j = rand() % num_vertices;
      k = rand() % num_vertices;
    } while (j == k);
    g.vertices[j] = k;
  }

  // Perform graph coloring
  for (i = 0; i < num_vertices; i++) {
    color = 1;
    for (j = 0; j < i; j++) {
      if (g.vertices[i] == g.vertices[j]) {
        color++;
      }
    }
    if (color > MAX_COLORS) {
      printf("Graph is not colorable with %d colors\n", MAX_COLORS);
      return 1;
    }
    g.colors[i] = color;
  }

  // Print the coloring
  for (i = 0; i < num_vertices; i++) {
    printf("Vertex %d has color %d\n", g.vertices[i], g.colors[i]);
  }

  return 0;
}