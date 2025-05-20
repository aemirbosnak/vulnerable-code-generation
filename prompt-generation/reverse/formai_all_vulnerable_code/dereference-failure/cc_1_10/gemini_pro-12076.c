//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int value;
} wire;

typedef struct {
  char *name;
  int num_inputs;
  int *inputs;
  int output;
} gate;

typedef struct {
  int num_wires;
  wire *wires;
  int num_gates;
  gate *gates;
} circuit;

circuit *create_circuit(int num_wires, int num_gates) {
  circuit *c = malloc(sizeof(circuit));
  c->num_wires = num_wires;
  c->wires = malloc(sizeof(wire) * num_wires);
  c->num_gates = num_gates;
  c->gates = malloc(sizeof(gate) * num_gates);
  return c;
}

void destroy_circuit(circuit *c) {
  int i;
  for (i = 0; i < c->num_wires; i++) {
    free(c->wires[i].name);
  }
  for (i = 0; i < c->num_gates; i++) {
    free(c->gates[i].name);
    free(c->gates[i].inputs);
  }
  free(c->wires);
  free(c->gates);
  free(c);
}

wire *get_wire(circuit *c, char *name) {
  int i;
  for (i = 0; i < c->num_wires; i++) {
    if (strcmp(c->wires[i].name, name) == 0) {
      return &c->wires[i];
    }
  }
  return NULL;
}

gate *get_gate(circuit *c, char *name) {
  int i;
  for (i = 0; i < c->num_gates; i++) {
    if (strcmp(c->gates[i].name, name) == 0) {
      return &c->gates[i];
    }
  }
  return NULL;
}

void add_wire(circuit *c, char *name) {
  c->wires[c->num_wires].name = malloc(strlen(name) + 1);
  strcpy(c->wires[c->num_wires].name, name);
  c->wires[c->num_wires].value = 0;
  c->num_wires++;
}

void add_gate(circuit *c, char *name, int num_inputs, int *inputs, int output) {
  int i;
  c->gates[c->num_gates].name = malloc(strlen(name) + 1);
  strcpy(c->gates[c->num_gates].name, name);
  c->gates[c->num_gates].num_inputs = num_inputs;
  c->gates[c->num_gates].inputs = malloc(sizeof(int) * num_inputs);
  for (i = 0; i < num_inputs; i++) {
    c->gates[c->num_gates].inputs[i] = inputs[i];
  }
  c->gates[c->num_gates].output = output;
  c->num_gates++;
}

void simulate_circuit(circuit *c) {
  int i, j;
  for (i = 0; i < c->num_gates; i++) {
    int output = 0;
    for (j = 0; j < c->gates[i].num_inputs; j++) {
      output |= c->wires[c->gates[i].inputs[j]].value;
    }
    c->wires[c->gates[i].output].value = output;
  }
}

void print_circuit(circuit *c) {
  int i;
  for (i = 0; i < c->num_wires; i++) {
    printf("%s = %d\n", c->wires[i].name, c->wires[i].value);
  }
}

int main() {
  circuit *c = create_circuit(4, 3);

  add_wire(c, "a");
  add_wire(c, "b");
  add_wire(c, "c");
  add_wire(c, "d");

  add_gate(c, "and1", 2, (int[]){0, 1}, 2);
  add_gate(c, "and2", 2, (int[]){0, 2}, 3);
  add_gate(c, "or", 2, (int[]){2, 3}, 4);

  c->wires[0].value = 1;
  c->wires[1].value = 1;
  c->wires[2].value = 0;

  simulate_circuit(c);

  print_circuit(c);

  destroy_circuit(c);

  return 0;
}