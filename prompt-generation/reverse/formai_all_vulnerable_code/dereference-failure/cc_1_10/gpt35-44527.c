//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 50

int num_nodes = 0;
int num_resistors = 0;

typedef struct _circuit Circuit;
typedef struct _resistor Resistor;

struct _circuit {
    double adjacency_matrix[MAX_NODES][MAX_NODES];
    double voltage[MAX_NODES];
    double current[MAX_NODES];
};

struct _resistor {
    int node1;
    int node2;
    double resistance;
};

bool add_resistor_to_circuit(Circuit* circuit, Resistor resistor) {
    if (num_resistors >= MAX_NODES) {
        printf("Error: circuit full.\n");
        return false;
    }
    circuit->adjacency_matrix[resistor.node1][resistor.node2] = -1.0 / resistor.resistance;
    circuit->adjacency_matrix[resistor.node2][resistor.node1] = -1.0 / resistor.resistance;
    ++num_resistors;
    return true;
}

Circuit* create_circuit(int num_nodes) {
    Circuit* circuit = (Circuit*) malloc(sizeof(Circuit));
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            circuit->adjacency_matrix[i][j] = 0.0;
        }
    }
    return circuit;
}

void print_circuit(Circuit* circuit) {
    printf("Adjacency matrix:\n");
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            printf("%f ", circuit->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    printf("Voltage:\n");
    for (int i = 0; i < num_nodes; ++i) {
        printf("%f ", circuit->voltage[i]);
    }
    printf("\n");
    printf("Current:\n");
    for (int i = 0; i < num_nodes; ++i) {
        printf("%f ", circuit->current[i]);
    }
    printf("\n");
}

int main() {
    Circuit* circuit = create_circuit(3);
    Resistor r1 = {0, 1, 1.0};
    Resistor r2 = {1, 2, 2.0};
    add_resistor_to_circuit(circuit, r1);
    add_resistor_to_circuit(circuit, r2);
    print_circuit(circuit);
    return 0;
}