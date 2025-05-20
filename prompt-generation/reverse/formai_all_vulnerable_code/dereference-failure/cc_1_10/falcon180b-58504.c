//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_COMPONENTS 100

typedef struct {
    char name[20];
    double value;
    int type;
    struct circuit_component *next;
} circuit_component;

typedef struct {
    circuit_component *components[MAX_COMPONENTS];
    int num_components;
} circuit;

void add_component(circuit *c, char *name, double value, int type) {
    circuit_component *new_component = malloc(sizeof(circuit_component));
    strcpy(new_component->name, name);
    new_component->value = value;
    new_component->type = type;
    new_component->next = NULL;

    if (c->num_components >= MAX_COMPONENTS) {
        printf("Error: Maximum number of components reached.\n");
        exit(1);
    }

    c->components[c->num_components++] = new_component;
}

void simulate_circuit(circuit *c) {
    circuit_component *current_component = c->components[0];

    while (current_component!= NULL) {
        switch (current_component->type) {
            case 0: // resistor
                printf("Resistor %s has resistance of %.2f ohms.\n", current_component->name, current_component->value);
                break;
            case 1: // capacitor
                printf("Capacitor %s has capacitance of %.2f farads.\n", current_component->name, current_component->value);
                break;
            case 2: // inductor
                printf("Inductor %s has inductance of %.2f henries.\n", current_component->name, current_component->value);
                break;
            default:
                printf("Unknown component type for %s.\n", current_component->name);
        }

        current_component = current_component->next;
    }
}

int main() {
    circuit c;
    c.num_components = 0;

    add_component(&c, "R1", 1000.0, 0);
    add_component(&c, "C1", 1.0, 1);
    add_component(&c, "L1", 0.1, 2);

    simulate_circuit(&c);

    return 0;
}