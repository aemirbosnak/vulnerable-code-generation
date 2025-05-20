//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the circuit elements
typedef struct {
  double resistance;
  double capacitance;
  double inductance;
} CircuitElement;

// Define the circuit
typedef struct {
  int numElements;
  CircuitElement *elements;
} Circuit;

// Create a new circuit
Circuit *createCircuit(int numElements) {
  Circuit *circuit = malloc(sizeof(Circuit));
  circuit->numElements = numElements;
  circuit->elements = malloc(numElements * sizeof(CircuitElement));
  return circuit;
}

// Free the memory allocated for a circuit
void freeCircuit(Circuit *circuit) {
  free(circuit->elements);
  free(circuit);
}

// Set the resistance of a circuit element
void setResistance(Circuit *circuit, int elementIndex, double resistance) {
  circuit->elements[elementIndex].resistance = resistance;
}

// Set the capacitance of a circuit element
void setCapacitance(Circuit *circuit, int elementIndex, double capacitance) {
  circuit->elements[elementIndex].capacitance = capacitance;
}

// Set the inductance of a circuit element
void setInductance(Circuit *circuit, int elementIndex, double inductance) {
  circuit->elements[elementIndex].inductance = inductance;
}

// Calculate the impedance of a circuit element
double calculateImpedance(CircuitElement *element) {
  return sqrt(element->resistance * element->resistance + element->capacitance * element->capacitance * element->inductance * element->inductance);
}

// Calculate the total impedance of a circuit
double calculateTotalImpedance(Circuit *circuit) {
  double totalImpedance = 0;
  for (int i = 0; i < circuit->numElements; i++) {
    totalImpedance += calculateImpedance(&circuit->elements[i]);
  }
  return totalImpedance;
}

// Print the circuit elements
void printCircuit(Circuit *circuit) {
  for (int i = 0; i < circuit->numElements; i++) {
    printf("Element %d: resistance = %f, capacitance = %f, inductance = %f\n", i, circuit->elements[i].resistance, circuit->elements[i].capacitance, circuit->elements[i].inductance);
  }
}

// Main function
int main() {
  // Create a new circuit with 3 elements
  Circuit *circuit = createCircuit(3);

  // Set the circuit element values
  setResistance(circuit, 0, 10);
  setCapacitance(circuit, 0, 1e-6);
  setInductance(circuit, 0, 1e-3);

  setResistance(circuit, 1, 20);
  setCapacitance(circuit, 1, 2e-6);
  setInductance(circuit, 1, 2e-3);

  setResistance(circuit, 2, 30);
  setCapacitance(circuit, 2, 3e-6);
  setInductance(circuit, 2, 3e-3);

  // Print the circuit elements
  printCircuit(circuit);

  // Calculate the total impedance of the circuit
  double totalImpedance = calculateTotalImpedance(circuit);

  // Print the total impedance
  printf("Total impedance: %f\n", totalImpedance);

  // Free the memory allocated for the circuit
  freeCircuit(circuit);

  return 0;
}