//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: scalable
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

Circuit* CreateCircuit(char* name, double resistance, double capacitance, double inductance, double voltage) {
  Circuit* newCircuit = malloc(sizeof(Circuit));
  strcpy(newCircuit->name, name);
  newCircuit->resistance = resistance;
  newCircuit->capacitance = capacitance;
  newCircuit->inductance = inductance;
  newCircuit->voltage = voltage;
  newCircuit->current = 0.0;
  newCircuit->next = NULL;
  return newCircuit;
}

void SimulateCircuit(Circuit* circuit) {
  double time = 0.0;
  double timeStep = 0.01;
  double voltageSource = circuit->voltage;
  double currentSource = circuit->current;

  while (time < 1.0) {
    // Calculate voltage across the circuit
    double voltage = voltageSource - (circuit->resistance * currentSource);

    // Calculate current flowing through the circuit
    double current = currentSource * exp(-time * circuit->inductance) / circuit->capacitance;

    // Update circuit values
    circuit->voltage = voltage;
    circuit->current = current;

    // Increment time
    time += timeStep;
  }
}

int main() {
  // Create a list of circuits
  Circuit* head = CreateCircuit("Series Circuit", 10.0, 2.0, 0.1, 12.0);
  Circuit* second = CreateCircuit("Parallel Circuit", 2.0, 4.0, 0.2, 12.0);

  // Simulate each circuit
  SimulateCircuit(head);
  SimulateCircuit(second);

  // Print circuit values
  printf("Circuit Name: %s\n", head->name);
  printf("Voltage: %.2f V\n", head->voltage);
  printf("Current: %.2f A\n", head->current);

  printf("Circuit Name: %s\n", second->name);
  printf("Voltage: %.2f V\n", second->voltage);
  printf("Current: %.2f A\n", second->current);

  return 0;
}