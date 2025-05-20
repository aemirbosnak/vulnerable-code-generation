//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// A cheerful struct to hold cheerful nodes
struct cheerful_node {
  int data;
  struct cheerful_node *next;
};

// A cheerful struct to hold cheerful adjacency lists
struct cheerful_adjlist {
  struct cheerful_node *head;
};

// A cheerful struct to hold cheerful graphs
struct cheerful_graph {
  int num_vertices;
  struct cheerful_adjlist *adjlists;
};

// A cheerful function to create a cheerful graph
struct cheerful_graph *cheerful_create_graph(int num_vertices) {
  struct cheerful_graph *graph = malloc(sizeof(struct cheerful_graph));
  graph->num_vertices = num_vertices;
  graph->adjlists = malloc(num_vertices * sizeof(struct cheerful_adjlist));
  for (int i = 0; i < num_vertices; i++) {
    graph->adjlists[i].head = NULL;
  }
  return graph;
}

// A cheerful function to add a cheerful edge to a cheerful graph
void cheerful_add_edge(struct cheerful_graph *graph, int src, int dest) {
  struct cheerful_node *new_node = malloc(sizeof(struct cheerful_node));
  new_node->data = dest;
  new_node->next = graph->adjlists[src].head;
  graph->adjlists[src].head = new_node;
}

// A cheerful function to print a cheerful graph
void cheerful_print_graph(struct cheerful_graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    struct cheerful_node *curr = graph->adjlists[i].head;
    printf("Vertex %d: ", i);
    while (curr) {
      printf("%d -> ", curr->data);
      curr = curr->next;
    }
    printf("NULL\n");
  }
}

// A cheerful function to free a cheerful graph
void cheerful_free_graph(struct cheerful_graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    struct cheerful_node *curr = graph->adjlists[i].head;
    while (curr) {
      struct cheerful_node *next = curr->next;
      free(curr);
      curr = next;
    }
  }
  free(graph->adjlists);
  free(graph);
}

int main() {
  // Create a cheerful graph with 5 cheerful vertices
  struct cheerful_graph *graph = cheerful_create_graph(5);

  // Add some cheerful edges to the cheerful graph
  cheerful_add_edge(graph, 0, 1);
  cheerful_add_edge(graph, 0, 2);
  cheerful_add_edge(graph, 1, 2);
  cheerful_add_edge(graph, 1, 3);
  cheerful_add_edge(graph, 2, 3);
  cheerful_add_edge(graph, 2, 4);
  cheerful_add_edge(graph, 3, 4);

  // Print the cheerful graph
  cheerful_print_graph(graph);

  // Free the cheerful graph
  cheerful_free_graph(graph);

  return 0;
}