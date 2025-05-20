//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CIRcuits 10

typedef struct Circuit {
  char name[20];
  double resistance;
  double capacitance;
  double inductance;
  double voltage;
  double current;
  struct Circuit* next;
} Circuit;

Circuit* createCircuit(char* name, double resistance, double capacitance, double inductance, double voltage) {
  Circuit* circuit = malloc(sizeof(Circuit));
  strcpy(circuit->name, name);
  circuit->resistance = resistance;
  circuit->capacitance = capacitance;
  circuit->inductance = inductance;
  circuit->voltage = voltage;
  circuit->current = 0.0;
  circuit->next = NULL;
  return circuit;
}

void simulateCircuit(Circuit* circuit) {
  double time = 0.0;
  double dt = 0.01;
  double voltage_source = circuit->voltage;
  double current_source = circuit->current;

  while (time < 10) {
    double voltage_drop = circuit->resistance * current_source;
    double voltage_across_capacitor = voltage_source - voltage_drop;
    double charge = circuit->capacitance * voltage_across_capacitor;
    double current_through_inductor = circuit->inductance * (charge / circuit->inductance - current_source);

    circuit->current = current_through_inductor;

    time += dt;
  }

  printf("%s's current: %.2f A\n", circuit->name, circuit->current);
}

int main() {
  Circuit* circuits[MAX_CIRcuits];

   circuits[0] = createCircuit("Series Circuit", 2.0, 1.0, 0.2, 10.0);
  simulateCircuit(circuits[0]);

  circuits[1] = createCircuit("Parallel Circuit", 2.0, 2.0, 0.2, 10.0);
  simulateCircuit(circuits[1]);

  return 0;
}