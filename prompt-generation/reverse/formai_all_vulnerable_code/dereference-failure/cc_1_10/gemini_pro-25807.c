//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 4
#define NUM_VERTICES 10

typedef struct {
  int vertex;
  int weight;
  struct edge *next;
} edge;

typedef struct {
  int num_vertices;
  edge **adj_list;
} graph;

graph *create_graph(int num_vertices) {
  graph *g = malloc(sizeof(graph));
  g->num_vertices = num_vertices;
  g->adj_list = malloc(sizeof(edge *) * num_vertices);
  for (int i = 0; i < num_vertices; i++) {
    g->adj_list[i] = NULL;
  }
  return g;
}

void add_edge(graph *g, int v1, int v2, int weight) {
  edge *new_edge = malloc(sizeof(edge));
  new_edge->vertex = v2;
  new_edge->weight = weight;
  new_edge->next = g->adj_list[v1];
  g->adj_list[v1] = new_edge;
}

void print_graph(graph *g) {
  for (int i = 0; i < g->num_vertices; i++) {
    printf("Vertex %d: ", i);
    edge *curr = g->adj_list[i];
    while (curr != NULL) {
      printf("%d(%d) -> ", curr->vertex, curr->weight);
      curr = curr->next;
    }
    printf("\n");
  }
}

void *thread_function(void *arg) {
  int *vertex = (int *)arg;
  // Do something with the vertex
  printf("Thread %d processing vertex %d\n", pthread_self(), *vertex);
  return NULL;
}

int main() {
  // Create a graph
  graph *g = create_graph(NUM_VERTICES);

  // Add some edges to the graph
  add_edge(g, 0, 1, 1);
  add_edge(g, 0, 2, 2);
  add_edge(g, 1, 2, 3);
  add_edge(g, 1, 3, 4);
  add_edge(g, 2, 3, 5);
  add_edge(g, 3, 4, 6);
  add_edge(g, 4, 5, 7);
  add_edge(g, 5, 6, 8);
  add_edge(g, 6, 7, 9);
  add_edge(g, 7, 8, 10);

  // Print the graph
  print_graph(g);

  // Create a thread for each vertex
  pthread_t threads[NUM_VERTICES];
  for (int i = 0; i < NUM_VERTICES; i++) {
    pthread_create(&threads[i], NULL, thread_function, &i);
  }

  // Join all the threads
  for (int i = 0; i < NUM_VERTICES; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}