//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTS 100
#define MAX_NODES 200

typedef struct {
    double value;
    int index;
} Element;

typedef struct {
    int num_nodes;
    Element *elements;
} Circuit;

void create_circuit(Circuit *circuit, int num_nodes) {
    circuit->num_nodes = num_nodes;
    circuit->elements = malloc(MAX_ELEMENTS * sizeof(Element));
}

void add_element(Circuit *circuit, int node1, int node2, double value) {
    Element *element = circuit->elements;
    int count = 0;

    while (count < circuit->num_nodes && element->index!= -1) {
        element++;
        count++;
    }

    if (count == circuit->num_nodes) {
        printf("Error: Circuit is full.\n");
        exit(1);
    }

    element->index = node1;
    element->value = value;
    element->index = node2;
    element++;
}

void simulate_circuit(Circuit *circuit) {
    Element *element = circuit->elements;
    double voltage[MAX_NODES];

    for (int i = 0; i < circuit->num_nodes; i++) {
        voltage[i] = 0.0;
    }

    while (element->index!= -1) {
        int node1 = element->index;
        int node2 = element->index;

        element++;

        voltage[node1] += element->value * voltage[node2];
        voltage[node2] += element->value * voltage[node1];
    }

    printf("Voltages:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("%d: %lf\n", i, voltage[i]);
    }
}

int main() {
    Circuit circuit;
    create_circuit(&circuit, 3);

    add_element(&circuit, 0, 1, 10.0);
    add_element(&circuit, 1, 2, 20.0);

    simulate_circuit(&circuit);

    return 0;
}