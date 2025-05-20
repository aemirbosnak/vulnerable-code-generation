//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define circuit components
typedef struct {
    int type;
    float value;
} Component;

// Define nodes and their connecting components
typedef struct {
    int id;
    Component *component1;
    Component *component2;
} Node;

// Define circuit
typedef struct {
    Node *nodes[10];
    int num_nodes;
} Circuit;

// Function to simulate voltage divider circuit
float voltage_divider(float vin, float r1, float r2) {
    return vin * r2 / (r1 + r2);
}

int main() {
    // Create circuit components
    Component *r1 = (Component *) malloc(sizeof(Component));
    r1->type = 1;
    r1->value = 1000.0;
    Component *r2 = (Component *) malloc(sizeof(Component));
    r2->type = 1;
    r2->value = 2000.0;
    Component *vin = (Component *) malloc(sizeof(Component));
    vin->type = 2;
    vin->value = 5.0;

    // Create circuit nodes
    Node *node1 = (Node *) malloc(sizeof(Node));
    node1->id = 1;
    node1->component1 = vin;
    node1->component2 = r1;
    Node *node2 = (Node *) malloc(sizeof(Node));
    node2->id = 2;
    node2->component1 = r1;
    node2->component2 = r2;

    // Add nodes to circuit
    Circuit circuit;
    circuit.nodes[0] = node1;
    circuit.nodes[1] = node2;
    circuit.num_nodes = 2;

    // Simulate circuit
    float vout = voltage_divider(vin->value, r1->value, r2->value);

    // Output results
    printf("Vin: %.2fV\nR1: %.2f Ohm\nR2: %.2f Ohm\nVout: %.2fV", vin->value, r1->value, r2->value, vout);

    // Free memory
    free(r1);
    free(r2);
    free(vin);
    free(node1);
    free(node2);

    return 0;
}