//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the circuit elements
typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR
} element_type;

typedef struct {
    element_type type;
    double value;
} element;

// Define the circuit
typedef struct {
    int num_elements;
    element *elements;
} circuit;

// Create a new circuit
circuit *create_circuit(int num_elements) {
    circuit *c = malloc(sizeof(circuit));
    c->num_elements = num_elements;
    c->elements = malloc(num_elements * sizeof(element));
    return c;
}

// Add an element to the circuit
void add_element(circuit *c, element_type type, double value) {
    element *e = &c->elements[c->num_elements++];
    e->type = type;
    e->value = value;
}

// Print the circuit
void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_elements; i++) {
        element *e = &c->elements[i];
        switch (e->type) {
            case RESISTOR:
                printf("Resistor: %f ohms\n", e->value);
                break;
            case CAPACITOR:
                printf("Capacitor: %f farads\n", e->value);
                break;
            case INDUCTOR:
                printf("Inductor: %f henrys\n", e->value);
                break;
        }
    }
}

// Free the circuit
void free_circuit(circuit *c) {
    free(c->elements);
    free(c);
}

// Main function
int main() {
    // Create a new circuit
    circuit *c = create_circuit(3);

    // Add elements to the circuit
    add_element(c, RESISTOR, 100);
    add_element(c, CAPACITOR, 1e-6);
    add_element(c, INDUCTOR, 1e-3);

    // Print the circuit
    print_circuit(c);

    // Free the circuit
    free_circuit(c);

    return 0;
}