//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct CircuitElement {
    char type;
    double value; // resistance (Ohms) or capacitance (Farads)
    struct CircuitElement* next;
} CircuitElement;

typedef struct Circuit {
    CircuitElement* head;
} Circuit;

Circuit* createCircuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->head = NULL;
    return circuit;
}

void addElement(Circuit* circuit, char type, double value) {
    CircuitElement* newElement = (CircuitElement*)malloc(sizeof(CircuitElement));
    newElement->type = type;
    newElement->value = value;
    newElement->next = circuit->head;
    circuit->head = newElement;
}

void displayCircuit(Circuit* circuit) {
    CircuitElement* current = circuit->head;
    printf("Circuit Elements:\n");
    while (current != NULL) {
        printf("Type: %c, Value: %.2f\n", current->type, current->value);
        current = current->next;
    }
}

double totalResistance(Circuit* circuit) {
    double totalRes = 0;
    CircuitElement* current = circuit->head;
    while (current != NULL) {
        if (current->type == 'R') {
            totalRes += current->value;
        }
        current = current->next;
    }
    return totalRes;
}

double totalCapacitance(Circuit* circuit) {
    double totalCap = 0;
    CircuitElement* current = circuit->head;
    double reciprocal = 0;
    while (current != NULL) {
        if (current->type == 'C') {
            reciprocal += 1 / current->value;
        }
        current = current->next;
    }
    if (reciprocal != 0) {
        totalCap = 1 / reciprocal;
    }
    return totalCap;
}

void freeCircuit(Circuit* circuit) {
    CircuitElement* current = circuit->head;
    CircuitElement* next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(circuit);
}

void panicMode() {
    printf("*** SYSTEM IN PANIC MODE! CHECK CIRCUIT STATE IMMEDIATELY! ***\n");
}

void checkForErrors(Circuit* circuit) {
    CircuitElement* current = circuit->head;
    while (current != NULL) {
        if (current->type != 'R' && current->type != 'C') {
            printf("Error: Unknown circuit element type '%c' detected!\n", current->type);
            panicMode();
            return;
        }
        current = current->next;
    }
}

int main() {
    Circuit* myCircuit = createCircuit();

    addElement(myCircuit, 'R', 100.0);
    addElement(myCircuit, 'C', 0.001);
    addElement(myCircuit, 'R', 150.0);
    addElement(myCircuit, 'X', 50.0); // Unknown type for testing error detection

    displayCircuit(myCircuit);

    checkForErrors(myCircuit);
    
    double totalRes = totalResistance(myCircuit);
    printf("Total Resistance: %.2f Ohms\n", totalRes);

    double totalCap = totalCapacitance(myCircuit);
    if (totalCap > 0) {
        printf("Total Capacitance: %.6f Farads\n", totalCap);
    } else {
        printf("No valid capacitance calculation possible.\n");
    }

    // Free resources
    freeCircuit(myCircuit);
    return 0;
}