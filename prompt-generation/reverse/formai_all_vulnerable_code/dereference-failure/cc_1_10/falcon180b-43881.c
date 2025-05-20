//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    char *name;
    float value;
} component;

typedef struct {
    int num_components;
    component *components;
} circuit;

void create_circuit(circuit *c) {
    c->num_components = 0;
    c->components = NULL;
}

void add_component(circuit *c, char *name, float value) {
    component *new_component = malloc(sizeof(component));
    new_component->name = name;
    new_component->value = value;
    c->components = realloc(c->components, sizeof(component) * ++c->num_components);
    c->components[c->num_components - 1] = *new_component;
}

void print_circuit(circuit *c) {
    printf("Circuit:\n");
    for (int i = 0; i < c->num_components; i++) {
        printf("%s: %.2f\n", c->components[i].name, c->components[i].value);
    }
}

void calculate_circuit(circuit *c) {
    for (int i = 0; i < c->num_components; i++) {
        char *name = c->components[i].name;
        float value = c->components[i].value;

        if (strcmp(name, "resistor") == 0) {
            printf("Resistor %.2f\n", value);
        } else if (strcmp(name, "capacitor") == 0) {
            printf("Capacitor %.2f\n", value);
        } else if (strcmp(name, "inductor") == 0) {
            printf("Inductor %.2f\n", value);
        } else {
            printf("Unknown component %s\n", name);
        }
    }
}

int main() {
    circuit c;
    create_circuit(&c);

    add_component(&c, "resistor", 1000.0);
    add_component(&c, "capacitor", 0.01);
    add_component(&c, "inductor", 0.001);

    print_circuit(&c);
    calculate_circuit(&c);

    return 0;
}