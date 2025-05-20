//FormAI DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

// Define a structure for the graph vertices
typedef struct vertex {
  int val;
  struct edge *next;
} vertex_t;

// Define a structure for the graph edges
typedef struct edge {
  struct vertex *dest;
  struct edge *next;
} edge_t;

// Define a function to add an edge between two vertices
void add_edge(vertex_t *v1, vertex_t *v2) {
  edge_t *e = malloc(sizeof(edge_t));
  e->dest = v2;
  e->next = v1->next;
  v1->next = e;
}

// Define a function to print the graph
void print_graph(vertex_t *v) {
  while (v != NULL) {
    printf("%d -> ", v->val);
    edge_t *e = v->next;
    while (e != NULL) {
      printf("%d ", e->dest->val);
      e = e->next;
    }
    printf("\n");
    v = v->next;
  }
}

int main() {

  // Create the vertices
  vertex_t *v1 = malloc(sizeof(vertex_t));
  v1->val = 1;
  v1->next = NULL;

  vertex_t *v2 = malloc(sizeof(vertex_t));
  v2->val = 2;
  v2->next = NULL;

  vertex_t *v3 = malloc(sizeof(vertex_t));
  v3->val = 3;
  v3->next = NULL;

  vertex_t *v4 = malloc(sizeof(vertex_t));
  v4->val = 4;
  v4->next = NULL;

  // Create the edges
  add_edge(v1, v2);
  add_edge(v1, v3);
  add_edge(v2, v3);
  add_edge(v3, v4);

  // Print the graph
  print_graph(v1);

  return 0;
}