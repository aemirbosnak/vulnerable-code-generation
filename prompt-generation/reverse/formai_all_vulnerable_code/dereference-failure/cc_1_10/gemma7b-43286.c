//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CIRcuits 10
#define MAX_COMPONENTS 20

typedef struct Circuit {
    char name[20];
    int numComponents;
    struct Component **components;
} Circuit;

typedef struct Component {
    char name[20];
    double resistance;
    double capacitance;
    double inductance;
} Component;

void createCircuit(Circuit **circuit) {
    *circuit = malloc(sizeof(Circuit));
    (*circuit)->numComponents = 0;
    (*circuit)->components = NULL;
    strcpy((*circuit)->name, "New Circuit");
}

void addComponent(Circuit *circuit, Component *component) {
    circuit->components = realloc(circuit->components, (circuit->numComponents + 1) * sizeof(Component *));
    circuit->components[circuit->numComponents++] = component;
}

int main() {
    Circuit *circuit;
    Component *component1, *component2;

    createCircuit(&circuit);

    component1 = malloc(sizeof(Component));
    strcpy(component1->name, "Component 1");
    component1->resistance = 10.0;
    component1->capacitance = 2.0;
    addComponent(circuit, component1);

    component2 = malloc(sizeof(Component));
    strcpy(component2->name, "Component 2");
    component2->resistance = 20.0;
    component2->capacitance = 4.0;
    addComponent(circuit, component2);

    printf("Circuit Name: %s\n", circuit->name);
    printf("Number of Components: %d\n", circuit->numComponents);
    for (int i = 0; i < circuit->numComponents; i++) {
        printf("Component Name: %s\n", circuit->components[i]->name);
        printf("Resistance: %.2lf\n", circuit->components[i]->resistance);
        printf("Capacitance: %.2lf\n", circuit->components[i]->capacitance);
    }

    return 0;
}