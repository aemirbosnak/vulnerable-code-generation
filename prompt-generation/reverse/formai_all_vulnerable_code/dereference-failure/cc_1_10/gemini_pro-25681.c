//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
  int num_nodes;
  int num_edges;
  int nodes[MAX_NODES];
  int edges[MAX_EDGES][2];
} circuit;

circuit *create_circuit(int num_nodes, int num_edges) {
  circuit *c = malloc(sizeof(circuit));
  c->num_nodes = num_nodes;
  c->num_edges = num_edges;
  for (int i = 0; i < num_nodes; i++) {
    c->nodes[i] = 0;
  }
  for (int i = 0; i < num_edges; i++) {
    c->edges[i][0] = 0;
    c->edges[i][1] = 0;
  }
  return c;
}

void destroy_circuit(circuit *c) {
  free(c);
}

int simulate_circuit(circuit *c) {
  int output = 0;
  for (int i = 0; i < c->num_edges; i++) {
    int node1 = c->edges[i][0];
    int node2 = c->edges[i][1];
    if (c->nodes[node1] && c->nodes[node2]) {
      output |= 1;
    }
  }
  return output;
}

int main() {
  circuit *c = create_circuit(3, 3);
  c->nodes[0] = 1;
  c->nodes[1] = 0;
  c->nodes[2] = 0;
  c->edges[0][0] = 0;
  c->edges[0][1] = 1;
  c->edges[1][0] = 1;
  c->edges[1][1] = 2;
  c->edges[2][0] = 2;
  c->edges[2][1] = 0;
  int output = simulate_circuit(c);
  printf("Output: %d\n", output);
  destroy_circuit(c);
  return 0;
}