//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
  int id;
  int num_edges;
  int *edges;
  int value;
} node_t;

typedef struct graph {
  int num_nodes;
  int num_edges;
  node_t *nodes;
} graph_t;

graph_t *create_graph(int num_nodes, int num_edges) {
  graph_t *graph = malloc(sizeof(graph_t));
  graph->num_nodes = num_nodes;
  graph->num_edges = num_edges;
  graph->nodes = malloc(sizeof(node_t) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    graph->nodes[i].id = i;
    graph->nodes[i].num_edges = 0;
    graph->nodes[i].edges = NULL;
    graph->nodes[i].value = 0;
  }
  return graph;
}

void destroy_graph(graph_t *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    free(graph->nodes[i].edges);
  }
  free(graph->nodes);
  free(graph);
}

void add_edge(graph_t *graph, int node1, int node2) {
  graph->nodes[node1].edges = realloc(graph->nodes[node1].edges, sizeof(int) * (graph->nodes[node1].num_edges + 1));
  graph->nodes[node1].edges[graph->nodes[node1].num_edges++] = node2;
  graph->nodes[node2].edges = realloc(graph->nodes[node2].edges, sizeof(int) * (graph->nodes[node2].num_edges + 1));
  graph->nodes[node2].edges[graph->nodes[node2].num_edges++] = node1;
}

void print_graph(graph_t *graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    printf("Node %d: ", i);
    for (int j = 0; j < graph->nodes[i].num_edges; j++) {
      printf("%d ", graph->nodes[i].edges[j]);
    }
    printf("\n");
  }
}

void simulate_circuit(graph_t *graph) {
  // Initialize the queue with the input nodes
  int queue[MAX_NODES];
  int head = 0;
  int tail = 0;
  for (int i = 0; i < graph->num_nodes; i++) {
    if (graph->nodes[i].num_edges == 0) {
      queue[tail++] = i;
    }
  }

  // While the queue is not empty
  while (head != tail) {
    // Dequeue the next node
    int node = queue[head++];

    // Calculate the new value of the node
    int value = 0;
    for (int i = 0; i < graph->nodes[node].num_edges; i++) {
      value += graph->nodes[graph->nodes[node].edges[i]].value;
    }
    value %= 2;

    // Update the value of the node
    graph->nodes[node].value = value;

    // Enqueue the next nodes
    for (int i = 0; i < graph->nodes[node].num_edges; i++) {
      graph->nodes[graph->nodes[node].edges[i]].num_edges--;
      if (graph->nodes[graph->nodes[node].edges[i]].num_edges == 0) {
        queue[tail++] = graph->nodes[node].edges[i];
      }
    }
  }
}

int main() {
  // Create a graph
  graph_t *graph = create_graph(5, 6);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);
  add_edge(graph, 4, 0);

  // Print the graph
  print_graph(graph);

  // Simulate the circuit
  simulate_circuit(graph);

  // Print the results
  for (int i = 0; i < graph->num_nodes; i++) {
    printf("Node %d: %d\n", i, graph->nodes[i].value);
  }

  // Destroy the graph
  destroy_graph(graph);

  return 0;
}