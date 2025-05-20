//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Edge {
  int dest;
  int weight;
  struct Edge *next;
} Edge;

typedef struct Vertex {
  int val;
  Edge *edges;
} Vertex;

typedef struct Graph {
  int vertices;
  int edges;
  Vertex *vertices_list;
} Graph;

Graph *create_graph(int vertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->vertices = vertices;
  graph->vertices_list = (Vertex *)calloc(vertices, sizeof(Vertex));
  graph->edges = 0;
  return graph;
}

void add_edge(Graph *graph, int src, int dest, int weight) {
  Edge *new_edge = (Edge *)malloc(sizeof(Edge));
  new_edge->dest = dest;
  new_edge->weight = weight;
  new_edge->next = graph->vertices_list[src].edges;
  graph->vertices_list[src].edges = new_edge;
  graph->edges++;
}

void print_graph(Graph *graph) {
  for (int i = 0; i < graph->vertices; i++) {
    Vertex vertex = graph->vertices_list[i];
    printf("Vertex %d: ", i);
    Edge *edge = vertex.edges;
    while (edge) {
      printf("(%d, %d) ", edge->dest, edge->weight);
      edge = edge->next;
    }
    printf("\n");
  }
}

void free_graph(Graph *graph) {
  for (int i = 0; i < graph->vertices; i++) {
    Edge *edge = graph->vertices_list[i].edges;
    while (edge) {
      Edge *next = edge->next;
      free(edge);
      edge = next;
    }
  }
  free(graph->vertices_list);
  free(graph);
}

int main() {
  Graph *graph = create_graph(5);
  add_edge(graph, 0, 1, 10);
  add_edge(graph, 0, 2, 20);
  add_edge(graph, 1, 2, 30);
  add_edge(graph, 1, 3, 40);
  add_edge(graph, 2, 3, 50);
  add_edge(graph, 3, 4, 60);
  add_edge(graph, 4, 0, 70);
  print_graph(graph);
  free_graph(graph);
  return 0;
}