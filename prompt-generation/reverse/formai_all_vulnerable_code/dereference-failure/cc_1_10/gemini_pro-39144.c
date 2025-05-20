//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// A graph is a data structure that represents relationships between objects.
// It can be used to represent social networks, road networks, or any other type of
// network where objects are connected to each other.

// A graph is typically represented as a collection of vertices (or nodes) and edges.
// Vertices are the objects in the graph, and edges are the connections between them.
// Edges can be directed or undirected, and they can have weights to represent the
// strength of the connection.

// In this example, we will create a simple graph and perform some basic operations
// on it.

// First, we need to define a data structure to represent our graph.
// We will use an adjacency list, which is a collection of lists of vertices.
// Each list represents the vertices that are connected to a particular vertex.

typedef struct graph {
  int num_vertices;
  int** adjacency_list;
} graph;

// Next, we need to create a function to initialize a graph.
// We will pass in the number of vertices in the graph, and the function will
// allocate memory for the graph and initialize the adjacency list.

graph* create_graph(int num_vertices) {
  graph* g = malloc(sizeof(graph));
  g->num_vertices = num_vertices;
  g->adjacency_list = malloc(sizeof(int*) * num_vertices);
  for (int i = 0; i < num_vertices; i++) {
    g->adjacency_list[i] = malloc(sizeof(int) * num_vertices);
    for (int j = 0; j < num_vertices; j++) {
      g->adjacency_list[i][j] = 0;
    }
  }
  return g;
}

// Now, we need to define a function to add an edge to the graph.
// We will pass in the graph, the source vertex, and the destination vertex.
// The function will add an edge between the source and destination vertices.
// We say that the edge is directed if it goes from the source to the destination alone.
// There is no path from destination to source in directed graphs.

void add_edge(graph* g, int source, int destination) {
  g->adjacency_list[source][destination] = 1;
}

// Finally, we need to define a function to print the graph.
// The function will print the adjacency list of the graph.

void print_graph(graph* g) {
  for (int i = 0; i < g->num_vertices; i++) {
    printf("Vertex %d: ", i);
    for (int j = 0; j < g->num_vertices; j++) {
      if (g->adjacency_list[i][j] == 1) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }
}

// Now, we can use the functions we have defined to create and manipulate a graph.

int main() {
  // First, we create a graph with 5 vertices.
  graph* g = create_graph(5);

  // Then, we add some edges to the graph.
  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 2);
  add_edge(g, 1, 3);
  add_edge(g, 2, 4);

  // Finally, we print the graph.
  print_graph(g);

  return 0;
}