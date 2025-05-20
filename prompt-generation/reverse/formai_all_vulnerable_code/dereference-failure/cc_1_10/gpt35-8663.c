//FormAI DATASET v1.0 Category: Graph representation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct graph {
  int vertices;
  int edges;
  int **adj_matrix; 
};

struct graph *create_graph(int vertex_count) {
  int i;
  struct graph *gra = malloc(sizeof(struct graph));
  gra->vertices = vertex_count;
  gra->edges = 0;
  gra->adj_matrix = malloc(sizeof(int *) * vertex_count);
  
  for (i = 0; i < vertex_count; i++) {
    gra->adj_matrix[i] = calloc(vertex_count, sizeof(int));
  }
  return gra;
}

void add_edge(struct graph *gra, int u, int v) {
  gra->adj_matrix[u][v] = 1;
  gra->adj_matrix[v][u] = 1;
  gra->edges++;
}

void print_graph(struct graph *gra) {
  int i, j;
  for (i = 0; i < gra->vertices; i++) {
    for (j = 0; j < gra->vertices; j++) {
      printf("%d ", gra->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

void destroy_graph(struct graph *gra) {
  int i;
  for (i = 0; i < gra->vertices; i++) {
    free(gra->adj_matrix[i]);
  }
  free(gra->adj_matrix);
  free(gra);
}

void add_edges(struct graph *gra, int count) {
  printf("Enter %d edges : \n", count);
  int i, u, v;
  for (i = 0; i < count; i++) {
    printf("Enter u and v : ");
    scanf("%d %d", &u, &v);
    add_edge(gra, u, v);
  }
}

int main() {
  struct graph *gra = create_graph(4);
  add_edges(gra, 2);
  print_graph(gra);
  destroy_graph(gra);
  return 0;
}