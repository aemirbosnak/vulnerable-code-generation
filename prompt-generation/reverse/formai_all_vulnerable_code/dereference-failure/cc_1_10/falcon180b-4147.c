//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    char name[20];
    double value;
    int type;
} Component;

typedef struct {
    int num;
    int type;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Component *components;
    Edge *edges;
} Circuit;

Circuit *create_circuit() {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->num_nodes = 0;
    circuit->num_edges = 0;
    circuit->components = NULL;
    circuit->edges = NULL;
    return circuit;
}

void add_component(Circuit *circuit, char *name, double value, int type) {
    Component *component = malloc(sizeof(Component));
    strcpy(component->name, name);
    component->value = value;
    component->type = type;
    circuit->components = realloc(circuit->components, sizeof(Component) * ++circuit->num_nodes);
    circuit->components[circuit->num_nodes - 1] = *component;
}

void add_edge(Circuit *circuit, int node1, int node2, int type) {
    Edge *edge = malloc(sizeof(Edge));
    edge->num = ++circuit->num_edges;
    edge->type = type;
    circuit->edges = realloc(circuit->edges, sizeof(Edge) * circuit->num_edges);
    circuit->edges[circuit->num_edges - 1] = *edge;
}

void simulate_circuit(Circuit *circuit) {
    double voltage[MAX_NODES];
    memset(voltage, 0, sizeof(double) * circuit->num_nodes);

    for (int i = 0; i < circuit->num_nodes; i++) {
        Component *component = &circuit->components[i];
        if (component->type == 1) {
            voltage[i] = component->value;
        } else if (component->type == 2) {
            int edge_num = component->value;
            Edge *edge = &circuit->edges[edge_num];
            voltage[i] = voltage[edge->num] * edge->type;
        }
    }

    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("Node %d: %.2fV\n", i, voltage[i]);
    }
}

int main() {
    Circuit *circuit = create_circuit();

    add_component(circuit, "Resistor", 100.0, 1);
    add_component(circuit, "Capacitor", 1e-6, 2);

    add_edge(circuit, 0, 1, 1);
    add_edge(circuit, 1, 2, 2);

    simulate_circuit(circuit);

    free(circuit->components);
    free(circuit->edges);
    free(circuit);

    return 0;
}