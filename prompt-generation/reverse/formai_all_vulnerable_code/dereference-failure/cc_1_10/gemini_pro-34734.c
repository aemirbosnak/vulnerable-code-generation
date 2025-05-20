//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int n;
  int m;
  int **adj;
} Graph;

typedef struct {
  int s;
  int v;
} Edge;

Graph *createGraph(int n, int m) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->n = n;
  g->m = m;
  g->adj = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    g->adj[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      g->adj[i][j] = 0;
    }
  }
  return g;
}

void destroyGraph(Graph *g) {
  for (int i = 0; i < g->n; i++) {
    free(g->adj[i]);
  }
  free(g->adj);
  free(g);
}

int **cloneGraph(Graph *g) {
  int **clone = (int **)malloc(g->n * sizeof(int *));
  for (int i = 0; i < g->n; i++) {
    clone[i] = (int *)malloc(g->n * sizeof(int));
    for (int j = 0; j < g->n; j++) {
      clone[i][j] = g->adj[i][j];
    }
  }
  return clone;
}

void addEdge(Graph *g, int s, int v) {
  g->adj[s][v] = 1;
  g->adj[v][s] = 1;
  g->m++;
}

void removeEdge(Graph *g, int s, int v) {
  g->adj[s][v] = 0;
  g->adj[v][s] = 0;
  g->m--;
}

int isAdjacent(Graph *g, int s, int v) {
  return g->adj[s][v];
}

int degree(Graph *g, int v) {
  int deg = 0;
  for (int i = 0; i < g->n; i++) {
    deg += g->adj[v][i];
  }
  return deg;
}

int **getNeighbors(Graph *g, int v) {
  int **neighbors = (int **)malloc(degree(g, v) * sizeof(int *));
  int j = 0;
  for (int i = 0; i < g->n; i++) {
    if (g->adj[v][i]) {
      neighbors[j++] = &g->adj[v][i];
    }
  }
  return neighbors;
}

int **getEdges(Graph *g) {
  int **edges = (int **)malloc(g->m * sizeof(int *));
  int j = 0;
  for (int i = 0; i < g->n; i++) {
    for (int k = i + 1; k < g->n; k++) {
      if (g->adj[i][k]) {
        edges[j++] = &g->adj[i][k];
      }
    }
  }
  return edges;
}

void printGraph(Graph *g) {
  for (int i = 0; i < g->n; i++) {
    for (int j = 0; j < g->n; j++) {
      printf("%d ", g->adj[i][j]);
    }
    printf("\n");
  }
}

int main() {
  Graph *g = createGraph(5, 0);
  addEdge(g, 0, 1);
  addEdge(g, 0, 2);
  addEdge(g, 1, 2);
  addEdge(g, 1, 3);
  addEdge(g, 2, 3);
  addEdge(g, 2, 4);
  addEdge(g, 3, 4);

  printGraph(g);

  printf("Degree of vertex 0: %d\n", degree(g, 0));
  printf("Degree of vertex 2: %d\n", degree(g, 2));

  int **neighbors = getNeighbors(g, 2);
  printf("Neighbors of vertex 2: ");
  for (int i = 0; i < degree(g, 2); i++) {
    printf("%d ", *neighbors[i]);
  }
  printf("\n");

  int **edges = getEdges(g);
  printf("Edges of the graph: ");
  for (int i = 0; i < g->m; i++) {
    printf("(%d, %d) ", *edges[i], *(edges[i] + 1));
  }
  printf("\n");

  destroyGraph(g);

  return 0;
}