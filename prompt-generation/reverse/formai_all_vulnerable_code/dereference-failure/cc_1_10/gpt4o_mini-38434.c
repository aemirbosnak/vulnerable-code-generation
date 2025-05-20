//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    char name[10];
    float resistance;
    struct Resistor *next;
} Resistor;

typedef struct Circuit {
    Resistor *head;
} Circuit;

Circuit* createCircuit() {
    Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
    circuit->head = NULL;
    return circuit;
}

void addResistor(Circuit *circuit, char *name, float resistance) {
    Resistor *newResistor = (Resistor *)malloc(sizeof(Resistor));
    snprintf(newResistor->name, sizeof(newResistor->name), "%s", name);
    newResistor->resistance = resistance;
    newResistor->next = circuit->head;
    circuit->head = newResistor;
}

float calculateEquivalentResistance(Circuit *circuit) {
    float totalResistance = 0.0;
    Resistor *current = circuit->head;

    while (current != NULL) {
        totalResistance += current->resistance;
        current = current->next;
    }
    return totalResistance;
}

void displayCircuit(Circuit *circuit) {
    Resistor *current = circuit->head;
    printf("Circuit configuration:\n");
    while (current != NULL) {
        printf("Resistor %s: %.2f Ohms\n", current->name, current->resistance);
        current = current->next;
    }
}

void freeCircuit(Circuit *circuit) {
    Resistor *current = circuit->head;
    Resistor *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(circuit);
}

int main() {
    Circuit *myCircuit = createCircuit();
    char resistorName[10];
    float resistorValue;
    char continueInput;

    do {
        printf("Do you want to add a resistor to the circuit? (y/n): ");
        scanf(" %c", &continueInput);

        if (continueInput == 'y' || continueInput == 'Y') {
            printf("What is the name of the resistor? ");
            scanf("%s", resistorName);
            printf("What is the resistance value of %s in Ohms? ", resistorName);
            scanf("%f", &resistorValue);
            addResistor(myCircuit, resistorName, resistorValue);
        }

    } while (continueInput == 'y' || continueInput == 'Y');

    displayCircuit(myCircuit);

    float equivalentResistance = calculateEquivalentResistance(myCircuit);
    printf("Equivalent Resistance of the Circuit: %.2f Ohms\n", equivalentResistance);

    freeCircuit(myCircuit);
    return 0;
}