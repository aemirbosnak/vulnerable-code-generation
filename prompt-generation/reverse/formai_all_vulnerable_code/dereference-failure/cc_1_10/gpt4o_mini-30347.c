//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a circuit component
typedef struct {
    char type[10];  // Type of component (Resistor, Capacitor, Inductor)
    float value;    // Value of the component (Ohms, Farads, Henrys)
} Component;

// Define a structure for a circuit
typedef struct {
    Component *components;  // Pointer to array of components
    int componentCount;     // Number of components
} Circuit;

// Function to create a new component
Component createComponent(const char *type, float value) {
    Component comp;
    strcpy(comp.type, type);
    comp.value = value;
    return comp;
}

// Function to add a component to the circuit
void addComponent(Circuit *circuit, Component component) {
    circuit->components = realloc(circuit->components, sizeof(Component) * (circuit->componentCount + 1));
    circuit->components[circuit->componentCount] = component;
    circuit->componentCount++;
}

// Function to simulate the circuit (Basic example for resistors in series)
float simulateCircuit(Circuit *circuit) {
    float totalResistance = 0.0;
    for(int i = 0; i < circuit->componentCount; i++) {
        if (strcmp(circuit->components[i].type, "Resistor") == 0) {
            totalResistance += circuit->components[i].value;
        }
    }
    return totalResistance; // Returning total resistance for resistors in series
}

// Function to print the circuit components
void printCircuit(Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->componentCount; i++) {
        printf("Type: %s, Value: %.2f\n", circuit->components[i].type, circuit->components[i].value);
    }
}

int main() {
    Circuit circuit = {NULL, 0};  // Initialize circuit

    // Adding some components to the circuit
    addComponent(&circuit, createComponent("Resistor", 100.0));
    addComponent(&circuit, createComponent("Resistor", 200.0));
    addComponent(&circuit, createComponent("Capacitor", 0.001));
    addComponent(&circuit, createComponent("Inductor", 0.005));

    // Print circuit components
    printCircuit(&circuit);

    // Simulate the circuit and compute total resistance
    float totalResistance = simulateCircuit(&circuit);
    printf("Total Resistance: %.2f Ohms\n", totalResistance);

    // Clean up dynamically allocated memory
    free(circuit.components);
    
    return 0;
}