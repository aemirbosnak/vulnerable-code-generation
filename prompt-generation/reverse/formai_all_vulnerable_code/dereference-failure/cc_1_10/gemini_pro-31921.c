//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define MAX_ITERATIONS 1000

typedef struct {
  int num_nodes;
  int num_edges;
  int nodes[MAX_NODES];
  int edges[MAX_EDGES][2];
  double probabilities[MAX_EDGES];
} circuit;

circuit* create_circuit(int num_nodes, int num_edges) {
  circuit* c = malloc(sizeof(circuit));
  c->num_nodes = num_nodes;
  c->num_edges = num_edges;
  for (int i = 0; i < num_nodes; i++) {
    c->nodes[i] = i;
  }
  for (int i = 0; i < num_edges; i++) {
    c->edges[i][0] = rand() % num_nodes;
    c->edges[i][1] = rand() % num_nodes;
    c->probabilities[i] = (double)rand() / RAND_MAX;
  }
  return c;
}

void free_circuit(circuit* c) {
  free(c);
}

double simulate_circuit(circuit* c, int num_iterations) {
  double output = 0.0;
  for (int i = 0; i < num_iterations; i++) {
    int current_node = 0;
    while (current_node != c->num_nodes - 1) {
      double r = (double)rand() / RAND_MAX;
      for (int j = 0; j < c->num_edges; j++) {
        if (c->edges[j][0] == current_node && r < c->probabilities[j]) {
          current_node = c->edges[j][1];
          break;
        }
      }
    }
    output += 1.0;
  }
  return output / num_iterations;
}

int main() {
  srand(time(NULL));

  int num_nodes = 10;
  int num_edges = 20;
  int num_iterations = 1000;

  circuit* c = create_circuit(num_nodes, num_edges);

  double output = simulate_circuit(c, num_iterations);

  printf("Output: %f\n", output);

  free_circuit(c);

  return 0;
}