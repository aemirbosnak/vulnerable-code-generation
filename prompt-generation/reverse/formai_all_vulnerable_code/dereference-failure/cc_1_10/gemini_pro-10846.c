//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int num_inputs;
  int num_outputs;
  int *truth_table;
} gate;

gate *create_gate(int num_inputs, int num_outputs) {
  gate *g = malloc(sizeof(gate));
  g->num_inputs = num_inputs;
  g->num_outputs = num_outputs;
  g->truth_table = malloc(sizeof(int) << (num_inputs + num_outputs));
  return g;
}

void destroy_gate(gate *g) {
  free(g->truth_table);
  free(g);
}

void set_truth_table(gate *g, int *truth_table) {
  for (int i = 0; i < (1 << (g->num_inputs + g->num_outputs)); i++) {
    g->truth_table[i] = truth_table[i];
  }
}

int evaluate_gate(gate *g, int *inputs) {
  int output = 0;
  for (int i = 0; i < (1 << g->num_inputs); i++) {
    int mask = 1 << (g->num_inputs + g->num_outputs - 1);
    for (int j = 0; j < g->num_inputs; j++) {
      if ((inputs[j] & (1 << j)) != 0) {
        mask >>= 1;
      }
    }
    output |= (g->truth_table[i] & mask);
  }
  return output;
}

int main() {
  gate *g = create_gate(2, 1);
  int truth_table[] = {0, 0, 0, 1};
  set_truth_table(g, truth_table);
  int inputs[] = {0, 1};
  int output = evaluate_gate(g, inputs);
  printf("%d\n", output);  // prints 1
  destroy_gate(g);
  return 0;
}