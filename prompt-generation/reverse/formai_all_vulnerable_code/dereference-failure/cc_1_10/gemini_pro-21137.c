//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
  int num_nodes;
  int num_edges;
  int edges[MAX_EDGES][2];
  int potentials[MAX_NODES];
} Circuit;

Circuit* create_circuit(int num_nodes, int num_edges) {
  Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
  circuit->num_nodes = num_nodes;
  circuit->num_edges = num_edges;
  for (int i = 0; i < num_edges; i++) {
    scanf("%d %d", &circuit->edges[i][0], &circuit->edges[i][1]);
  }
  for (int i = 0; i < num_nodes; i++) {
    circuit->potentials[i] = 0;
  }
  return circuit;
}

void destroy_circuit(Circuit* circuit) {
  free(circuit);
}

void simulate_circuit(Circuit* circuit) {
  int changed = 1;
  while (changed) {
    changed = 0;
    for (int i = 0; i < circuit->num_nodes; i++) {
      int new_potential = 0;
      for (int j = 0; j < circuit->num_edges; j++) {
        if (circuit->edges[j][1] == i) {
          new_potential += circuit->potentials[circuit->edges[j][0]];
        }
      }
      if (circuit->potentials[i] != new_potential) {
        circuit->potentials[i] = new_potential;
        changed = 1;
      }
    }
  }
}

void print_circuit(Circuit* circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    printf("Node %d: potential = %d\n", i, circuit->potentials[i]);
  }
}

int main() {
  int num_nodes, num_edges;
  scanf("%d %d", &num_nodes, &num_edges);
  Circuit* circuit = create_circuit(num_nodes, num_edges);
  simulate_circuit(circuit);
  print_circuit(circuit);
  destroy_circuit(circuit);
  return 0;
}