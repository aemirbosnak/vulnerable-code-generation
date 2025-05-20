//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct node {
  int data;
  struct node *next;
};

// A graph is an array of linked lists.
// Each linked list represents a vertex and contains
// the vertices that are adjacent to it.
struct graph {
  int num_vertices;
  struct node **adj_lists;
};

// Create a new graph with num_vertices vertices.
struct graph *create_graph(int num_vertices) {
  struct graph *graph = malloc(sizeof(struct graph));
  graph->num_vertices = num_vertices;

  // Create an array of linked lists to represent the
  // adjacency lists.
  graph->adj_lists = malloc(num_vertices * sizeof(struct node *));

  // Initialize each linked list to be empty.
  for (int i = 0; i < num_vertices; i++) {
    graph->adj_lists[i] = NULL;
  }

  return graph;
}

// Add an edge to the graph between vertices u and v.
void add_edge(struct graph *graph, int u, int v) {
  // Create a new node to represent the edge.
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = v;
  new_node->next = NULL;

  // Add the new node to the beginning of the adjacency
  // list for vertex u.
  new_node->next = graph->adj_lists[u];
  graph->adj_lists[u] = new_node;
}

// Print the graph.
void print_graph(struct graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    struct node *current_node = graph->adj_lists[i];
    printf("Vertex %d: ", i);
    while (current_node != NULL) {
      printf("%d ", current_node->data);
      current_node = current_node->next;
    }
    printf("\n");
  }
}

// Free the graph.
void free_graph(struct graph *graph) {
  // Free each adjacency list.
  for (int i = 0; i < graph->num_vertices; i++) {
    struct node *current_node = graph->adj_lists[i];
    while (current_node != NULL) {
      struct node *next_node = current_node->next;
      free(current_node);
      current_node = next_node;
    }
  }

  // Free the array of adjacency lists.
  free(graph->adj_lists);

  // Free the graph itself.
  free(graph);
}

int main() {
  // Create a new graph with 5 vertices.
  struct graph *graph = create_graph(5);

  // Add edges to the graph.
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 4);

  // Print the graph.
  print_graph(graph);

  // Free the graph.
  free_graph(graph);

  return 0;
}