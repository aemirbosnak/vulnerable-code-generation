//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

typedef struct {
    char name[20];
    int value;
    int type;
} Component;

typedef struct {
    int num_components;
    Component components[100];
    int num_connections;
    int connections[500];
} Circuit;

void add_component(Circuit *circuit, char *name, int type, int value) {
    Component component;
    strcpy(component.name, name);
    component.value = value;
    component.type = type;
    circuit->components[circuit->num_components++] = component;
}

void add_connection(Circuit *circuit, int component1, int component2) {
    circuit->connections[circuit->num_connections++] = component1;
    circuit->connections[circuit->num_connections++] = component2;
}

void simulate(Circuit *circuit, double time) {
    for (int i = 0; i < circuit->num_components; i++) {
        Component component = circuit->components[i];
        double voltage = 0;
        if (component.type == 1) { // resistor
            voltage = (component.value / 100) * time;
        } else if (component.type == 2) { // capacitor
            voltage = (component.value / 100) * time * time;
        } else if (component.type == 3) { // inductor
            voltage = (component.value / 100) * time * time * time;
        }
        printf("Component %s has voltage %.3f\n", component.name, voltage);
    }
}

int main() {
    Circuit circuit;
    add_component(&circuit, "Resistor", 1, 100);
    add_component(&circuit, "Capacitor", 2, 50);
    add_component(&circuit, "Inductor", 3, 25);
    add_connection(&circuit, 0, 1);
    add_connection(&circuit, 1, 2);
    simulate(&circuit, 0.1);
    return 0;
}