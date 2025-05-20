//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct node {
  int id;
  bool value;
  int num_inputs;
  int *inputs;
  int num_outputs;
  int *outputs;
} node_t;

typedef struct circuit {
  int num_nodes;
  node_t *nodes;
} circuit_t;

circuit_t *create_circuit(int num_nodes) {
  circuit_t *circuit = malloc(sizeof(circuit_t));
  circuit->num_nodes = num_nodes;
  circuit->nodes = malloc(sizeof(node_t) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    circuit->nodes[i].id = i;
    circuit->nodes[i].value = false;
    circuit->nodes[i].num_inputs = 0;
    circuit->nodes[i].inputs = NULL;
    circuit->nodes[i].num_outputs = 0;
    circuit->nodes[i].outputs = NULL;
  }
  return circuit;
}

void destroy_circuit(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    free(circuit->nodes[i].inputs);
    free(circuit->nodes[i].outputs);
  }
  free(circuit->nodes);
  free(circuit);
}

void add_node(circuit_t *circuit, int id, bool value) {
  if (id < 0 || id >= circuit->num_nodes) {
    fprintf(stderr, "Invalid node ID: %d\n", id);
    return;
  }
  circuit->nodes[id].value = value;
}

void add_edge(circuit_t *circuit, int input_id, int output_id) {
  if (input_id < 0 || input_id >= circuit->num_nodes) {
    fprintf(stderr, "Invalid input node ID: %d\n", input_id);
    return;
  }
  if (output_id < 0 || output_id >= circuit->num_nodes) {
    fprintf(stderr, "Invalid output node ID: %d\n", output_id);
    return;
  }
  circuit->nodes[input_id].num_outputs++;
  circuit->nodes[input_id].outputs = realloc(circuit->nodes[input_id].outputs, sizeof(int) * circuit->nodes[input_id].num_outputs);
  circuit->nodes[input_id].outputs[circuit->nodes[input_id].num_outputs - 1] = output_id;
  circuit->nodes[output_id].num_inputs++;
  circuit->nodes[output_id].inputs = realloc(circuit->nodes[output_id].inputs, sizeof(int) * circuit->nodes[output_id].num_inputs);
  circuit->nodes[output_id].inputs[circuit->nodes[output_id].num_inputs - 1] = input_id;
}

void simulate_circuit(circuit_t *circuit) {
  bool changed = true;
  while (changed) {
    changed = false;
    for (int i = 0; i < circuit->num_nodes; i++) {
      bool new_value = false;
      for (int j = 0; j < circuit->nodes[i].num_inputs; j++) {
        new_value |= circuit->nodes[circuit->nodes[i].inputs[j]].value;
      }
      if (new_value != circuit->nodes[i].value) {
        circuit->nodes[i].value = new_value;
        changed = true;
      }
    }
  }
}

void print_circuit(circuit_t *circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    printf("Node %d: value = %d, inputs = [", i, circuit->nodes[i].value);
    for (int j = 0; j < circuit->nodes[i].num_inputs; j++) {
      printf("%d, ", circuit->nodes[i].inputs[j]);
    }
    printf("], outputs = [");
    for (int j = 0; j < circuit->nodes[i].num_outputs; j++) {
      printf("%d, ", circuit->nodes[i].outputs[j]);
    }
    printf("]\n");
  }
}

int main() {
  circuit_t *circuit = create_circuit(4);
  add_node(circuit, 0, false);
  add_node(circuit, 1, false);
  add_node(circuit, 2, false);
  add_node(circuit, 3, false);
  add_edge(circuit, 0, 1);
  add_edge(circuit, 1, 2);
  add_edge(circuit, 2, 3);
  simulate_circuit(circuit);
  print_circuit(circuit);
  destroy_circuit(circuit);
  return 0;
}