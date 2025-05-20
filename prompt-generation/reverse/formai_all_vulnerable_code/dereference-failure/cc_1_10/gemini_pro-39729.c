//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
  int id;
  int num_edges;
  int *edges;
} node_t;

typedef struct circuit {
  int num_nodes;
  int num_edges;
  node_t *nodes;
} circuit_t;

circuit_t *create_circuit(int num_nodes, int num_edges) {
  circuit_t *circuit = malloc(sizeof(circuit_t));
  circuit->num_nodes = num_nodes;
  circuit->num_edges = num_edges;
  circuit->nodes = malloc(sizeof(node_t) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    circuit->nodes[i].id = i;
    circuit->nodes[i].num_edges = 0;
    circuit->nodes[i].edges = NULL;
  }
  return circuit;
}

void add_edge(circuit_t *circuit, int node1, int node2) {
  if (node1 < 0 || node1 >= circuit->num_nodes || node2 < 0 || node2 >= circuit->num_nodes) {
    printf("Invalid node IDs\n");
    return;
  }
  circuit->nodes[node1].edges = realloc(circuit->nodes[node1].edges, sizeof(int) * (circuit->nodes[node1].num_edges + 1));
  circuit->nodes[node1].edges[circuit->nodes[node1].num_edges++] = node2;
  circuit->nodes[node2].edges = realloc(circuit->nodes[node2].edges, sizeof(int) * (circuit->nodes[node2].num_edges + 1));
  circuit->nodes[node2].edges[circuit->nodes[node2].num_edges++] = node1;
}

void print_circuit(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    printf("Node %d: ", circuit->nodes[i].id);
    for (int j = 0; j < circuit->nodes[i].num_edges; j++) {
      printf("%d ", circuit->nodes[i].edges[j]);
    }
    printf("\n");
  }
}

void free_circuit(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    free(circuit->nodes[i].edges);
  }
  free(circuit->nodes);
  free(circuit);
}

int main() {
  circuit_t *circuit = create_circuit(5, 6);
  add_edge(circuit, 0, 1);
  add_edge(circuit, 0, 2);
  add_edge(circuit, 1, 2);
  add_edge(circuit, 1, 3);
  add_edge(circuit, 2, 3);
  add_edge(circuit, 3, 4);
  print_circuit(circuit);
  free_circuit(circuit);
  return 0;
}