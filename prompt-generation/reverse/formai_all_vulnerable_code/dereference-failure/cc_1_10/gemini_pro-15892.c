//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the types of gates
typedef enum {
  GATE_AND,
  GATE_OR,
  GATE_NOT,
  GATE_XOR,
  GATE_NAND,
  GATE_NOR,
  GATE_XNOR
} gate_type;

// Define the structure of a gate
typedef struct {
  gate_type type;
  int num_inputs;
  int *inputs;
  int output;
} gate;

// Create a new gate
gate *create_gate(gate_type type, int num_inputs) {
  gate *g = (gate *)malloc(sizeof(gate));
  g->type = type;
  g->num_inputs = num_inputs;
  g->inputs = (int *)malloc(sizeof(int) * num_inputs);
  g->output = 0;
  return g;
}

// Destroy a gate
void destroy_gate(gate *g) {
  free(g->inputs);
  free(g);
}

// Set the inputs of a gate
void set_gate_inputs(gate *g, int *inputs) {
  memcpy(g->inputs, inputs, sizeof(int) * g->num_inputs);
}

// Compute the output of a gate
void compute_gate_output(gate *g) {
  int output = 0;
  switch (g->type) {
    case GATE_AND:
      for (int i = 0; i < g->num_inputs; i++) {
        output &= g->inputs[i];
      }
      break;
    case GATE_OR:
      for (int i = 0; i < g->num_inputs; i++) {
        output |= g->inputs[i];
      }
      break;
    case GATE_NOT:
      output = !g->inputs[0];
      break;
    case GATE_XOR:
      output = g->inputs[0] ^ g->inputs[1];
      break;
    case GATE_NAND:
      output = !(g->inputs[0] & g->inputs[1]);
      break;
    case GATE_NOR:
      output = !(g->inputs[0] | g->inputs[1]);
      break;
    case GATE_XNOR:
      output = !(g->inputs[0] ^ g->inputs[1]);
      break;
    default:
      break;
  }
  g->output = output;
}

// Print the truth table of a gate
void print_gate_truth_table(gate *g) {
  int num_inputs = g->num_inputs;
  int num_combinations = 1 << num_inputs;
  int *inputs = (int *)malloc(sizeof(int) * num_inputs);
  for (int i = 0; i < num_combinations; i++) {
    for (int j = 0; j < num_inputs; j++) {
      inputs[j] = (i >> j) & 1;
    }
    set_gate_inputs(g, inputs);
    compute_gate_output(g);
    printf("%d", g->output);
  }
  printf("\n");
  free(inputs);
}

// Main function
int main() {
  // Create some gates
  gate *g1 = create_gate(GATE_AND, 2);
  gate *g2 = create_gate(GATE_OR, 2);
  gate *g3 = create_gate(GATE_NOT, 1);
  gate *g4 = create_gate(GATE_XOR, 2);
  gate *g5 = create_gate(GATE_NAND, 2);
  gate *g6 = create_gate(GATE_NOR, 2);
  gate *g7 = create_gate(GATE_XNOR, 2);

  // Print the truth tables of the gates
  printf("AND gate truth table:\n");
  print_gate_truth_table(g1);
  printf("\nOR gate truth table:\n");
  print_gate_truth_table(g2);
  printf("\nNOT gate truth table:\n");
  print_gate_truth_table(g3);
  printf("\nXOR gate truth table:\n");
  print_gate_truth_table(g4);
  printf("\nNAND gate truth table:\n");
  print_gate_truth_table(g5);
  printf("\nNOR gate truth table:\n");
  print_gate_truth_table(g6);
  printf("\nXNOR gate truth table:\n");
  print_gate_truth_table(g7);

  // Destroy the gates
  destroy_gate(g1);
  destroy_gate(g2);
  destroy_gate(g3);
  destroy_gate(g4);
  destroy_gate(g5);
  destroy_gate(g6);
  destroy_gate(g7);

  return 0;
}