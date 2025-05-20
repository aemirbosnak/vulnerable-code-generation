//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAXV 1000
#define MAXC 10 // Maximum number of colors

struct Graph {
  int V; // number of vertices
  int E; // number of edges
  int **adj; // adjacency matrix
};

struct Graph G;

int colors[MAXV]; // color of each vertex

bool isSafe(int v, int c) {
  for (int i = 0; i < G.V; i++) {
    if (G.adj[v][i] && colors[i] == c)
      return false;
  }
  return true;
}

void* compute_coloring(void* arg) {
  int start = *(int*)arg;
  for (int i = start; i < G.V; i += 2) {
    for (int c = 1; c <= MAXC; c++) {
      if (isSafe(i, c)) {
        colors[i] = c;
        break;
      }
    }
  }
  return NULL;
}

int main() {
  scanf("%d %d", &G.V, &G.E); // read input

  // allocate memory for adjacency matrix
  G.adj = (int**)malloc(G.V * sizeof(int*));
  for (int i = 0; i < G.V; i++) {
    G.adj[i] = (int*)calloc(G.V, sizeof(int));
  }

  // read edges
  for (int i = 0; i < G.E; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G.adj[u][v] = G.adj[v][u] = 1;
  }

  // initialize colors to 0
  for (int i = 0; i < G.V; i++) {
    colors[i] = 0;
  }

  // create threads
  pthread_t t1, t2;
  int start1 = 0, start2 = 1;
  pthread_create(&t1, NULL, compute_coloring, &start1);
  pthread_create(&t2, NULL, compute_coloring, &start2);

  // wait for threads to finish
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  // output colors
  for (int i = 0; i < G.V; i++) {
    printf("Vertex %d: Color %d\n", i, colors[i]);
  }

  // free memory
  for (int i = 0; i < G.V; i++) {
    free(G.adj[i]);
  }
  free(G.adj);

  return 0;
}