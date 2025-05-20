//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char type[10]; // "resistor", "capacitor", "inductor", "voltage_source", "current_source"
    float value;
} Component;

typedef struct {
    Component *components;
    int count;
} Circuit;

void initializeCircuit(Circuit *circuit) {
    circuit->components = NULL;
    circuit->count = 0;
}

void addComponent(Circuit *circuit, const char *name, const char *type, float value) {
    circuit->count++;
    circuit->components = realloc(circuit->components, circuit->count * sizeof(Component));
    if (circuit->components == NULL) {
        perror("Failed to allocate memory for components");
        exit(EXIT_FAILURE);
    }
    strcpy(circuit->components[circuit->count - 1].name, name);
    strcpy(circuit->components[circuit->count - 1].type, type);
    circuit->components[circuit->count - 1].value = value;
}

void displayCircuit(const Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("%s: %s (%.2f)\n", circuit->components[i].name, circuit->components[i].type, circuit->components[i].value);
    }
}

float calculateTotalResistance(const Circuit *circuit) {
    float totalResistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].type, "resistor") == 0) {
            totalResistance += circuit->components[i].value;
        }
    }
    return totalResistance;
}

void freeCircuit(Circuit *circuit) {
    free(circuit->components);
    circuit->components = NULL;
    circuit->count = 0;
}

int main() {
    Circuit myCircuit;
    initializeCircuit(&myCircuit);

    addComponent(&myCircuit, "R1", "resistor", 100.0);
    addComponent(&myCircuit, "R2", "resistor", 200.0);
    addComponent(&myCircuit, "C1", "capacitor", 10e-6);
    addComponent(&myCircuit, "L1", "inductor", 0.001);
    addComponent(&myCircuit, "V1", "voltage_source", 5.0);
    
    displayCircuit(&myCircuit);

    float totalResistance = calculateTotalResistance(&myCircuit);
    printf("Total Resistance in the Circuit: %.2f ohms\n", totalResistance);

    freeCircuit(&myCircuit);

    return 0;
}