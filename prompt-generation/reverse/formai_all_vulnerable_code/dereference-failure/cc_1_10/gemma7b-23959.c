//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

typedef struct Circuit {
  double r;
  double l;
  double c;
  double v;
  double i;
  struct Circuit *next;
} Circuit;

Circuit *circuit_new() {
  Circuit *circuit = malloc(sizeof(Circuit));
  circuit->r = 0.0;
  circuit->l = 0.0;
  circuit->c = 0.0;
  circuit->v = 0.0;
  circuit->i = 0.0;
  circuit->next = NULL;
  return circuit;
}

void circuit_add(Circuit *circuit, double r, double l, double c) {
  Circuit *new_circuit = circuit_new();
  new_circuit->r = r;
  new_circuit->l = l;
  new_circuit->c = c;
  new_circuit->next = circuit->next;
  circuit->next = new_circuit;
}

void circuit_simulate(Circuit *circuit) {
  double t = 0.0;
  double dt = 0.01;
  double v_out = 0.0;
  double i_out = 0.0;

  while (t < 1.0) {
    double v_in = sin(2 * PI * 50 * t);
    double v_acc = (v_in - circuit->v) / circuit->c;
    circuit->v += v_acc * dt;
    i_out = circuit->v / circuit->r;
    v_out = circuit->v;
    t += dt;
  }

  printf("Vout: %.2f\n", v_out);
  printf("Iout: %.2f\n", i_out);
}

int main() {
  Circuit *circuit = circuit_new();
  circuit_add(circuit, 10.0, 1.0, 0.1);
  circuit_add(circuit, 2.0, 0.5, 0.2);
  circuit_simulate(circuit);

  return 0;
}