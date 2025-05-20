//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char type[10];  // Type of the component: "Resistor", "Capacitor", "Inductor"
    double value;   // The value of the component (Ohm for Resistor, Farad for Capacitor, Henry for Inductor)
    double voltage; // Voltage across the component
    double current; // Current through the component
} Component;

typedef struct {
    Component* components;
    int size;
    int capacity;
} Circuit;

// Function prototypes
Circuit* createCircuit(int initialCapacity);
void addComponent(Circuit* circuit, const char* type, double value);
void simulate(Circuit* circuit);
void cleanupCircuit(Circuit* circuit);

// Main execution function
int main() {
    Circuit* myCircuit = createCircuit(5); // Create a circuit with an initial capacity for 5 components

    addComponent(myCircuit, "Resistor", 250.0);
    addComponent(myCircuit, "Capacitor", 0.001);
    addComponent(myCircuit, "Inductor", 0.5);
    
    printf("Simulating Circuit...\n");
    simulate(myCircuit);
    
    cleanupCircuit(myCircuit);
    return 0;
}

// Function to create a new circuit
Circuit* createCircuit(int initialCapacity) {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    if (!circuit) {
        perror("Failed to create circuit");
        exit(EXIT_FAILURE);
    }

    circuit->components = (Component*)malloc(initialCapacity * sizeof(Component));
    if (!circuit->components) {
        perror("Failed to allocate components");
        exit(EXIT_FAILURE);
    }

    circuit->size = 0;
    circuit->capacity = initialCapacity;
    return circuit;
}

// Function to add a component to the circuit
void addComponent(Circuit* circuit, const char* type, double value) {
    if (circuit->size >= circuit->capacity) {
        circuit->capacity *= 2;
        circuit->components = (Component*)realloc(circuit->components, circuit->capacity * sizeof(Component));
        if (!circuit->components) {
            perror("Failed to resize components");
            exit(EXIT_FAILURE);
        }
    }

    strcpy(circuit->components[circuit->size].type, type);
    circuit->components[circuit->size].value = value;
    circuit->components[circuit->size].voltage = 0.0;
    circuit->components[circuit->size].current = 0.0;
    circuit->size++;
}

// Simple function to simulate the circuit
void simulate(Circuit* circuit) {
    double totalResistance = 0.0;
    double totalCapacitance = 0.0;
    double totalInductance = 0.0;
    
    for (int i = 0; i < circuit->size; i++) {
        Component* comp = &circuit->components[i];
        if (strcmp(comp->type, "Resistor") == 0) {
            totalResistance += comp->value; // Add resistance
            comp->voltage = comp->current * comp->value; // Ohm's law
        } else if (strcmp(comp->type, "Capacitor") == 0) {
            totalCapacitance += comp->value; // Add capacitance
            comp->voltage = 5.0; // Assume a constant voltage source for example
            comp->current = comp->voltage / comp->value; // C = Q/V; Q = C * V
        } else if (strcmp(comp->type, "Inductor") == 0) {
            totalInductance += comp->value; // Add inductance
            comp->current = 3.0; // Assume a constant current for example
            comp->voltage = comp->value * (comp->current); // Faraday's law
        }
    }

    printf("Total Resistance: %.2f Ohms\n", totalResistance);
    printf("Total Capacitance: %.2f Farads\n", totalCapacitance);
    printf("Total Inductance: %.2f Henries\n", totalInductance);
    
    for (int i = 0; i < circuit->size; i++) {
        Component* comp = &circuit->components[i];
        printf("%s - Voltage: %.2f V, Current: %.2f A\n", comp->type, comp->voltage, comp->current);
    }
}

// Function to cleanup and free allocated memory
void cleanupCircuit(Circuit* circuit) {
    free(circuit->components);
    free(circuit);
}