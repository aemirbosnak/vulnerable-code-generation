//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Define a structure for a circuit element
typedef struct CircuitElement {
    char name[10];
    char type; // 'R' for resistor, 'C' for capacitor, 'L' for inductor, 'V' for voltage source
    double value; // value in ohms for resistors, farads for capacitors, henries for inductors, volts for voltage sources
    struct CircuitElement* next;
} CircuitElement;

// Function to create a new circuit element
CircuitElement* createElement(const char* name, char type, double value) {
    CircuitElement* newElement = (CircuitElement*)malloc(sizeof(CircuitElement));
    if (newElement == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newElement->name, name, sizeof(newElement->name) - 1);
    newElement->name[sizeof(newElement->name) - 1] = '\0';
    newElement->type = type;
    newElement->value = value;
    newElement->next = NULL;
    return newElement;
}

// Function to free the circuit elements
void freeCircuit(CircuitElement* head) {
    CircuitElement* current = head;
    CircuitElement* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Function to calculate total resistance in a series circuit
double calculateSeriesResistance(CircuitElement* head) {
    double totalResistance = 0.0;
    CircuitElement* current = head;
    while (current != NULL) {
        if (current->type == 'R') {
            totalResistance += current->value;
        }
        current = current->next;
    }
    return totalResistance;
}

// Function to calculate total capacitance in a series circuit
double calculateSeriesCapacitance(CircuitElement* head) {
    double totalCapacitanceInverse = 0.0;
    CircuitElement* current = head;
    while (current != NULL) {
        if (current->type == 'C') {
            totalCapacitanceInverse += 1.0 / current->value;
        }
        current = current->next;
    }
    return (totalCapacitanceInverse == 0) ? 0 : (1.0 / totalCapacitanceInverse);
}

// Function to display circuit elements
void displayCircuit(CircuitElement* head) {
    CircuitElement* current = head;
    printf("Circuit Elements:\n");
    while (current != NULL) {
        printf("Name: %s, Type: %c, Value: %.2f\n", current->name, current->type, current->value);
        current = current->next;
    }
}

// Main function
int main() {
    CircuitElement* circuit = NULL;
    CircuitElement* lastElement = NULL;

    // Manually creating a simple circuit for demonstration
    circuit = createElement("R1", 'R', 100.0);
    lastElement = circuit;
    lastElement->next = createElement("R2", 'R', 200.0);
    lastElement = lastElement->next;
    lastElement->next = createElement("C1", 'C', 0.001);
    lastElement = lastElement->next;
    lastElement->next = createElement("V1", 'V', 5.0);

    // Display the circuit
    displayCircuit(circuit);

    // Perform calculations
    double totalResistance = calculateSeriesResistance(circuit);
    double totalCapacitance = calculateSeriesCapacitance(circuit);

    printf("Total Series Resistance: %.2f Ohms\n", totalResistance);
    printf("Total Series Capacitance: %.6f Farads\n", totalCapacitance);

    // Free allocated memory
    freeCircuit(circuit);
    
    return 0;
}