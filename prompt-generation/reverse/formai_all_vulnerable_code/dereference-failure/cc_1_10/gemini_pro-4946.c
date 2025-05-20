//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_INPUTS 100
#define MAX_OUTPUTS 100

typedef struct {
  char name[100];
  int num_inputs;
  int num_outputs;
  int inputs[MAX_INPUTS];
  int outputs[MAX_OUTPUTS];
  int value;
} node_t;

typedef struct {
  int num_nodes;
  node_t nodes[MAX_NODES];
} circuit_t;

circuit_t* create_circuit() {
  circuit_t* circuit = malloc(sizeof(circuit_t));
  circuit->num_nodes = 0;
  return circuit;
}

void destroy_circuit(circuit_t* circuit) {
  free(circuit);
}

node_t* create_node(char* name, int num_inputs, int num_outputs) {
  node_t* node = malloc(sizeof(node_t));
  strcpy(node->name, name);
  node->num_inputs = num_inputs;
  node->num_outputs = num_outputs;
  for (int i = 0; i < num_inputs; i++) {
    node->inputs[i] = -1;
  }
  for (int i = 0; i < num_outputs; i++) {
    node->outputs[i] = -1;
  }
  node->value = 0;
  return node;
}

void destroy_node(node_t* node) {
  free(node);
}

void add_node(circuit_t* circuit, node_t* node) {
  circuit->nodes[circuit->num_nodes] = *node;
  circuit->num_nodes++;
}

void connect_nodes(circuit_t* circuit, char* from_name, int from_output, char* to_name, int to_input) {
  node_t* from_node = NULL;
  node_t* to_node = NULL;
  for (int i = 0; i < circuit->num_nodes; i++) {
    if (strcmp(circuit->nodes[i].name, from_name) == 0) {
      from_node = &circuit->nodes[i];
    }
    if (strcmp(circuit->nodes[i].name, to_name) == 0) {
      to_node = &circuit->nodes[i];
    }
  }
  if (from_node == NULL || to_node == NULL) {
    return;
  }
  from_node->outputs[from_output] = to_node - circuit->nodes;
  to_node->inputs[to_input] = from_node - circuit->nodes;
}

void simulate_circuit(circuit_t* circuit) {
  int changed = 1;
  while (changed) {
    changed = 0;
    for (int i = 0; i < circuit->num_nodes; i++) {
      node_t* node = &circuit->nodes[i];
      int new_value = 0;
      for (int j = 0; j < node->num_inputs; j++) {
        if (node->inputs[j] != -1) {
          new_value |= circuit->nodes[node->inputs[j]].value;
        }
      }
      if (new_value != node->value) {
        node->value = new_value;
        changed = 1;
        for (int j = 0; j < node->num_outputs; j++) {
          if (node->outputs[j] != -1) {
            simulate_circuit(circuit);
          }
        }
      }
    }
  }
}

void print_circuit(circuit_t* circuit) {
  for (int i = 0; i < circuit->num_nodes; i++) {
    node_t* node = &circuit->nodes[i];
    printf("%s: %d", node->name, node->value);
    if (node->num_inputs > 0) {
      printf(" (");
      for (int j = 0; j < node->num_inputs; j++) {
        if (node->inputs[j] != -1) {
          printf("%s", circuit->nodes[node->inputs[j]].name);
          if (j < node->num_inputs - 1) {
            printf(", ");
          }
        }
      }
      printf(")");
    }
    if (node->num_outputs > 0) {
      printf(" -> ");
      for (int j = 0; j < node->num_outputs; j++) {
        if (node->outputs[j] != -1) {
          printf("%s", circuit->nodes[node->outputs[j]].name);
          if (j < node->num_outputs - 1) {
            printf(", ");
          }
        }
      }
    }
    printf("\n");
  }
}

int main() {
  circuit_t* circuit = create_circuit();

  node_t* input_a = create_node("input_a", 0, 1);
  node_t* input_b = create_node("input_b", 0, 1);
  node_t* and_gate = create_node("and_gate", 2, 1);
  node_t* output = create_node("output", 1, 0);

  add_node(circuit, input_a);
  add_node(circuit, input_b);
  add_node(circuit, and_gate);
  add_node(circuit, output);

  connect_nodes(circuit, "input_a", 0, "and_gate", 0);
  connect_nodes(circuit, "input_b", 0, "and_gate", 1);
  connect_nodes(circuit, "and_gate", 0, "output", 0);

  simulate_circuit(circuit);

  print_circuit(circuit);

  destroy_circuit(circuit);

  return 0;
}