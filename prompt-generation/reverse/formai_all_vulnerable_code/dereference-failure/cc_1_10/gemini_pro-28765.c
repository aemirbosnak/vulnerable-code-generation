//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
} component_type;

typedef struct {
    component_type type;
    char *name;
    double value;
    int node1;
    int node2;
} component;

typedef struct {
    int num_components;
    component *components;
} circuit;

circuit *create_circuit(int num_components) {
    circuit *c = malloc(sizeof(circuit));
    c->num_components = num_components;
    c->components = malloc(num_components * sizeof(component));
    return c;
}

void add_component(circuit *c, component_type type, char *name, double value, int node1, int node2) {
    component *comp = &c->components[c->num_components++];
    comp->type = type;
    comp->name = strdup(name);
    comp->value = value;
    comp->node1 = node1;
    comp->node2 = node2;
}

void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_components; i++) {
        component *comp = &c->components[i];
        printf("%s %s %f %d %d\n", comp->name,
               comp->type == RESISTOR ? "R" : comp->type == CAPACITOR ? "C" : comp->type == INDUCTOR ? "L" : comp->type == VOLTAGE_SOURCE ? "V" : "I",
               comp->value, comp->node1, comp->node2);
    }
}

void free_circuit(circuit *c) {
    for (int i = 0; i < c->num_components; i++) {
        free(c->components[i].name);
    }
    free(c->components);
    free(c);
}

int main() {
    circuit *c = create_circuit(5);
    add_component(c, RESISTOR, "R1", 100, 1, 2);
    add_component(c, CAPACITOR, "C1", 100e-6, 2, 3);
    add_component(c, INDUCTOR, "L1", 100e-3, 3, 4);
    add_component(c, VOLTAGE_SOURCE, "V1", 10, 1, 4);
    add_component(c, CURRENT_SOURCE, "I1", 1, 2, 3);
    print_circuit(c);
    free_circuit(c);
    return 0;
}