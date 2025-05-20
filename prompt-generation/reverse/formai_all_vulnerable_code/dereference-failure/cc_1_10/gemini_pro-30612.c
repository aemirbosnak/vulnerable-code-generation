//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *wires;
  int n_wires;
} circuit;

circuit *create_circuit(int n_wires) {
  circuit *c = malloc(sizeof(circuit));
  c->wires = malloc(sizeof(int) * n_wires);
  c->n_wires = n_wires;
  return c;
}

void destroy_circuit(circuit *c) {
  free(c->wires);
  free(c);
}

void connect_wires(circuit *c, int wire1, int wire2) {
  if (wire1 < 0 || wire1 >= c->n_wires ||
      wire2 < 0 || wire2 >= c->n_wires) {
    printf("Error: Invalid wire indices.\n");
    return;
  }
  c->wires[wire1] = wire2;
  c->wires[wire2] = wire1;
}

void simulate_circuit(circuit *c) {
  int i;
  for (i = 0; i < c->n_wires; i++) {
    if (c->wires[i] != -1) {
      c->wires[i] = c->wires[c->wires[i]];
    }
  }
}

void print_circuit(circuit *c) {
  int i;
  for (i = 0; i < c->n_wires; i++) {
    printf("%d: %d\n", i, c->wires[i]);
  }
}

int main() {
  circuit *c = create_circuit(6);

  connect_wires(c, 0, 1);
  connect_wires(c, 1, 2);
  connect_wires(c, 2, 3);
  connect_wires(c, 3, 0);

  connect_wires(c, 4, 5);

  simulate_circuit(c);

  print_circuit(c);

  destroy_circuit(c);

  return 0;
}