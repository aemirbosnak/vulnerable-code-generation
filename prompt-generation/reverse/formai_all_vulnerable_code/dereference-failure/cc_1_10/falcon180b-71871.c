//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
    double v;
    double i;
} Node;

typedef struct {
    Node *nodes;
    int num_nodes;
    double dt;
    double t;
    double vcc;
} Circuit;

void create_circuit(Circuit *circuit, int num_nodes) {
    circuit->num_nodes = num_nodes;
    circuit->nodes = malloc(sizeof(Node) * num_nodes);
    circuit->dt = 1e-6;
    circuit->t = 0;
    circuit->vcc = 5;
}

void destroy_circuit(Circuit *circuit) {
    free(circuit->nodes);
}

void set_node_voltage(Circuit *circuit, int node_idx, double v) {
    circuit->nodes[node_idx].v = v;
}

void set_node_current(Circuit *circuit, int node_idx, double i) {
    circuit->nodes[node_idx].i = i;
}

double get_node_voltage(Circuit *circuit, int node_idx) {
    return circuit->nodes[node_idx].v;
}

double get_node_current(Circuit *circuit, int node_idx) {
    return circuit->nodes[node_idx].i;
}

void step_circuit(Circuit *circuit) {
    int i;
    double total_current = 0;

    for (i = 0; i < circuit->num_nodes; i++) {
        total_current += circuit->nodes[i].i;
    }

    circuit->t += circuit->dt;

    if (circuit->t >= 1e-4) {
        circuit->t -= 1e-4;
        printf("Total Current: %f\n", total_current);
    }
}

int main() {
    Circuit circuit;
    create_circuit(&circuit, 3);

    set_node_voltage(&circuit, 0, 10);
    set_node_voltage(&circuit, 1, 0);
    set_node_voltage(&circuit, 2, 0);

    set_node_current(&circuit, 0, 0);
    set_node_current(&circuit, 1, 1);
    set_node_current(&circuit, 2, 0);

    while (1) {
        step_circuit(&circuit);
    }

    destroy_circuit(&circuit);
    return 0;
}