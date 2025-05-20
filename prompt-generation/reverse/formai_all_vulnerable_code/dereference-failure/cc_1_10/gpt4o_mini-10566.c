//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Component {
    char name[20];
    double value; // Resistance in Ohms, Capacitance in Farads or Inductance in Henries.
    struct Component *next;
} Component;

typedef struct Circuit {
    Component *first;
    double sourceVoltage;
    double current; // in Amperes
} Circuit;

void addComponent(Circuit *circuit, const char *name, double value) {
    Component *newComp = (Component *) malloc(sizeof(Component));
    snprintf(newComp->name, sizeof(newComp->name), "%s", name);
    newComp->value = value;
    newComp->next = circuit->first;
    circuit->first = newComp;
}

double calculateTotalResistance(Circuit *circuit) {
    double totalResistance = 0.0;
    Component *currentComp = circuit->first;
    
    while (currentComp) {
        totalResistance += currentComp->value;
        currentComp = currentComp->next;
    }
    
    return totalResistance;
}

double calculateCurrent(Circuit *circuit) {
    double totalResistance = calculateTotalResistance(circuit);
    if (totalResistance == 0.0) return 0.0; // Avoid division by zero
    circuit->current = circuit->sourceVoltage / totalResistance; 
    return circuit->current;
}

void displayCircuit(Circuit *circuit) {
    printf("\nLovers in this Circuit:\n");
    Component *currentComp = circuit->first;
    while (currentComp) {
        printf("Component: %s, Value: %.2f\n", currentComp->name, currentComp->value);
        currentComp = currentComp->next;
    }
    printf("\nSource Voltage: %.2f V\n", circuit->sourceVoltage);
    printf("Calculated Current: %.2f A\n", calculateCurrent(circuit));
}

void releaseCircuit(Circuit *circuit) {
    Component *currentComp = circuit->first;
    while (currentComp) {
        Component *temp = currentComp;
        currentComp = currentComp->next;
        free(temp);
    }
    circuit->first = NULL;
}

int main() {
    Circuit myCircuit;
    myCircuit.first = NULL;
    myCircuit.sourceVoltage = 10.0;

    addComponent(&myCircuit, "Loving Resistor", 5.0);
    addComponent(&myCircuit, "Hope Inductor", 10.0);
    addComponent(&myCircuit, "Passion Capacitor", 15.0);

    displayCircuit(&myCircuit);
    
    releaseCircuit(&myCircuit);
    return 0;
}