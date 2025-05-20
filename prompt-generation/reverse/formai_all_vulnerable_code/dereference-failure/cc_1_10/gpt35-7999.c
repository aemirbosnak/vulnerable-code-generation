//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50
#define MAX_RESISTORS 100

// Define the node struct
typedef struct Node {
    int id;
    double voltage;
} Node;

// Define the resistor struct
typedef struct Resistor {
    int id;
    double resistance;
    int n1, n2;
} Resistor;

// Define the circuit struct
typedef struct Circuit {
    int num_nodes;
    int num_resistors;
    Node nodes[MAX_NODES];
    Resistor resistors[MAX_RESISTORS];
} Circuit;

// Function to add a node to the circuit
void add_node(Circuit *circuit, int id) {
    circuit->nodes[circuit->num_nodes].id = id;
    circuit->nodes[circuit->num_nodes].voltage = 0.0;
    circuit->num_nodes++;
}

// Function to add a resistor to the circuit
void add_resistor(Circuit *circuit, int id, double resistance, int n1, int n2) {
    circuit->resistors[circuit->num_resistors].id = id;
    circuit->resistors[circuit->num_resistors].resistance = resistance;
    circuit->resistors[circuit->num_resistors].n1 = n1;
    circuit->resistors[circuit->num_resistors].n2 = n2;
    circuit->num_resistors++;
}

// Function to simulate the circuit and calculate the voltages on all nodes
void simulate_circuit(Circuit *circuit) {
    int i, j, k;
    double conductance_matrix[MAX_NODES][MAX_NODES];
    for (i = 0; i < circuit->num_nodes; i++) {
        for (j = 0; j < circuit->num_nodes; j++) {
            conductance_matrix[i][j] = 0.0;
        }
    }
    for (i = 0; i < circuit->num_resistors; i++) {
        int n1 = circuit->resistors[i].n1;
        int n2 = circuit->resistors[i].n2;
        double r = circuit->resistors[i].resistance;
        conductance_matrix[n1][n1] += 1.0 / r;
        conductance_matrix[n1][n2] += -1.0 / r;
        conductance_matrix[n2][n1] += -1.0 / r;
        conductance_matrix[n2][n2] += 1.0 / r;
    }
    for (k = 0; k < circuit->num_nodes - 1; k++) {
        for (i = k + 1; i < circuit->num_nodes; i++) {
            double coeff = conductance_matrix[i][k] / conductance_matrix[k][k];
            for (j = k; j < circuit->num_nodes; j++) {
                conductance_matrix[i][j] -= coeff * conductance_matrix[k][j];
            }
            circuit->nodes[i].voltage -= coeff * circuit->nodes[k].voltage;
        }
    }
    for (i = circuit->num_nodes - 1; i >= 0; i--) {
        double sum = 0.0;
        for (j = i + 1; j < circuit->num_nodes; j++) {
            sum += conductance_matrix[i][j] * circuit->nodes[j].voltage;
        }
        circuit->nodes[i].voltage = (circuit->nodes[i].voltage - sum) / conductance_matrix[i][i];
    }
}

// Main function
int main() {
    Circuit circuit;
    circuit.num_nodes = 0;
    circuit.num_resistors = 0;
    add_node(&circuit, 0);
    add_node(&circuit, 1);
    add_node(&circuit, 2);
    add_resistor(&circuit, 0, 1.0, 0, 1);
    add_resistor(&circuit, 1, 2.0, 1, 2);
    add_resistor(&circuit, 2, 3.0, 0, 2);
    simulate_circuit(&circuit);
    printf("Voltage on node 0: %f\n", circuit.nodes[0].voltage);
    printf("Voltage on node 1: %f\n", circuit.nodes[1].voltage);
    printf("Voltage on node 2: %f\n", circuit.nodes[2].voltage);
    return 0;
}