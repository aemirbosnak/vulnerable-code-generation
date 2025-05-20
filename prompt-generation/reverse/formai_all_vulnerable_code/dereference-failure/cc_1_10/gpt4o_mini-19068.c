//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    float resistance; // Ohms
    struct Resistor* next;
} Resistor;

typedef struct Circuit {
    Resistor* head;
    float voltage; // Volts
} Circuit;

void initCircuit(Circuit* circuit, float voltage) {
    circuit->head = NULL;
    circuit->voltage = voltage;
}

void addResistor(Circuit* circuit, float resistance) {
    Resistor* newResistor = (Resistor*)malloc(sizeof(Resistor));
    newResistor->resistance = resistance;
    newResistor->next = circuit->head;
    circuit->head = newResistor;
}

float calculateTotalResistance(Circuit* circuit) {
    float totalResistance = 0.0;
    Resistor* current = circuit->head;

    while (current) {
        totalResistance += current->resistance;
        current = current->next;
    }

    return totalResistance;
}

float calculateCurrent(Circuit* circuit) {
    float totalResistance = calculateTotalResistance(circuit);
    if (totalResistance == 0) {
        fprintf(stderr, "Error: Total resistance is zero. Cannot calculate current.\n");
        exit(EXIT_FAILURE);
    }
    
    return circuit->voltage / totalResistance;
}

void freeCircuit(Circuit* circuit) {
    Resistor* current = circuit->head;
    Resistor* nextResistor = NULL;

    while (current) {
        nextResistor = current->next;
        free(current);
        current = nextResistor;
    }
    circuit->head = NULL;
}

void printCircuit(Circuit* circuit) {
    Resistor* current = circuit->head;
    printf("Circuit Voltage: %.2f V\n", circuit->voltage);
    printf("Resistors in series:\n");

    while (current) {
        printf("%.2f Ohms\n", current->resistance);
        current = current->next;
    }

    float totalResistance = calculateTotalResistance(circuit);
    printf("Total Resistance: %.2f Ohms\n", totalResistance);
    printf("Current: %.2f A\n", calculateCurrent(circuit));
}

int main() {
    Circuit circuit;
    initCircuit(&circuit, 12.0); // Set circuit voltage to 12V

    addResistor(&circuit, 4.0); // Add 4 Ohm resistor
    addResistor(&circuit, 6.0); // Add 6 Ohm resistor
    addResistor(&circuit, 2.0); // Add 2 Ohm resistor

    printCircuit(&circuit);

    freeCircuit(&circuit);
    return 0;
}