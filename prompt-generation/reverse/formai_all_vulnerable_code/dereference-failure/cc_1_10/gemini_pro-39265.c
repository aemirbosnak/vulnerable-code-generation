//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the circuit elements
typedef enum { RESISTOR, CAPACITOR, INDUCTOR } element_type;
struct element {
    element_type type;
    double value;
};

// Define the circuit
struct circuit {
    int num_elements;
    struct element *elements;
};

// Create a new circuit
struct circuit *create_circuit(int num_elements) {
    struct circuit *circuit = malloc(sizeof(struct circuit));
    circuit->num_elements = num_elements;
    circuit->elements = malloc(sizeof(struct element) * num_elements);
    return circuit;
}

// Add an element to the circuit
void add_element(struct circuit *circuit, element_type type, double value) {
    struct element element = { type, value };
    circuit->elements[circuit->num_elements++] = element;
}

// Simulate the circuit
void simulate_circuit(struct circuit *circuit) {
    // Calculate the current through each element
    for (int i = 0; i < circuit->num_elements; i++) {
        struct element element = circuit->elements[i];
        switch (element.type) {
            case RESISTOR:
                element.value = element.value * 1000;
                break;
            case CAPACITOR:
                element.value = element.value * 1000000;
                break;
            case INDUCTOR:
                element.value = element.value * 1000000;
                break;
        }
    }

    // Calculate the voltage across each element
    for (int i = 0; i < circuit->num_elements; i++) {
        struct element element = circuit->elements[i];
        switch (element.type) {
            case RESISTOR:
                element.value = element.value / 1000;
                break;
            case CAPACITOR:
                element.value = element.value / 1000000;
                break;
            case INDUCTOR:
                element.value = element.value / 1000000;
                break;
        }
    }

    // Print the results
    for (int i = 0; i < circuit->num_elements; i++) {
        struct element element = circuit->elements[i];
        printf("Element %d: type = %d, value = %f\n", i, element.type, element.value);
    }
}

// Free the memory allocated for the circuit
void free_circuit(struct circuit *circuit) {
    free(circuit->elements);
    free(circuit);
}

int main() {
    // Create a new circuit
    struct circuit *circuit = create_circuit(3);

    // Add elements to the circuit
    add_element(circuit, RESISTOR, 1000);
    add_element(circuit, CAPACITOR, 1000000);
    add_element(circuit, INDUCTOR, 1000000);

    // Simulate the circuit
    simulate_circuit(circuit);

    // Free the memory allocated for the circuit
    free_circuit(circuit);

    return 0;
}