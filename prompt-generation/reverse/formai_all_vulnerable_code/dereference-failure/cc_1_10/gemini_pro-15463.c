//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the circuit elements
typedef struct {
    int value;
    int next;
} Element;

// Define the circuit
typedef struct {
    int numElements;
    Element *elements;
} Circuit;

// Create a new circuit
Circuit *createCircuit(int numElements) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->numElements = numElements;
    circuit->elements = malloc(sizeof(Element) * numElements);
    return circuit;
}

// Destroy a circuit
void destroyCircuit(Circuit *circuit) {
    free(circuit->elements);
    free(circuit);
}

// Add an element to a circuit
void addElement(Circuit *circuit, int value, int next) {
    circuit->elements[circuit->numElements].value = value;
    circuit->elements[circuit->numElements].next = next;
    circuit->numElements++;
}

// Simulate a circuit
void simulateCircuit(Circuit *circuit) {
    int i;
    for (i = 0; i < circuit->numElements; i++) {
        printf("%d ", circuit->elements[i].value);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new circuit
    Circuit *circuit = createCircuit(5);

    // Add elements to the circuit
    addElement(circuit, 1, 2);
    addElement(circuit, 2, 3);
    addElement(circuit, 3, 4);
    addElement(circuit, 4, 5);
    addElement(circuit, 5, 1);

    // Simulate the circuit
    simulateCircuit(circuit);

    // Destroy the circuit
    destroyCircuit(circuit);

    return 0;
}