//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
// C Classical Circuit Simulation

#include <stdio.h>
#include <stdlib.h>

// Circuit component types
enum component_type {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
};

// Circuit component structure
struct circuit_component {
    enum component_type type;
    double value;
};

// Circuit node structure
struct circuit_node {
    double voltage;
    double current;
};

// Circuit structure
struct circuit {
    int num_components;
    int num_nodes;
    struct circuit_component *components;
    struct circuit_node *nodes;
};

// Create a new circuit
struct circuit *create_circuit(int num_components, int num_nodes) {
    struct circuit *circuit = malloc(sizeof(struct circuit));
    circuit->num_components = num_components;
    circuit->num_nodes = num_nodes;
    circuit->components = malloc(num_components * sizeof(struct circuit_component));
    circuit->nodes = malloc(num_nodes * sizeof(struct circuit_node));
    return circuit;
}

// Add a component to a circuit
void add_component(struct circuit *circuit, enum component_type type, double value) {
    circuit->components[circuit->num_components].type = type;
    circuit->components[circuit->num_components].value = value;
    circuit->num_components++;
}

// Add a node to a circuit
void add_node(struct circuit *circuit, double voltage, double current) {
    circuit->nodes[circuit->num_nodes].voltage = voltage;
    circuit->nodes[circuit->num_nodes].current = current;
    circuit->num_nodes++;
}

// Solve a circuit
void solve_circuit(struct circuit *circuit) {
    // Loop through each component and calculate the current through it
    for (int i = 0; i < circuit->num_components; i++) {
        switch (circuit->components[i].type) {
            case RESISTOR:
                circuit->nodes[i].current = circuit->nodes[i].voltage / circuit->components[i].value;
                break;
            case CAPACITOR:
                circuit->nodes[i].current = circuit->components[i].value * circuit->nodes[i].voltage;
                break;
            case INDUCTOR:
                circuit->nodes[i].current = circuit->nodes[i].voltage / circuit->components[i].value;
                break;
            case VOLTAGE_SOURCE:
                circuit->nodes[i].voltage = circuit->components[i].value;
                break;
            case CURRENT_SOURCE:
                circuit->nodes[i].current = circuit->components[i].value;
                break;
        }
    }

    // Loop through each node and calculate the voltage at it
    for (int i = 0; i < circuit->num_nodes; i++) {
        double voltage = 0;
        for (int j = 0; j < circuit->num_components; j++) {
            if (circuit->components[j].type == RESISTOR) {
                voltage += circuit->nodes[j].current * circuit->components[j].value;
            } else if (circuit->components[j].type == CAPACITOR) {
                voltage += circuit->nodes[j].current / circuit->components[j].value;
            } else if (circuit->components[j].type == INDUCTOR) {
                voltage += circuit->nodes[j].current * circuit->components[j].value;
            }
        }
        circuit->nodes[i].voltage = voltage;
    }
}

// Print the circuit
void print_circuit(struct circuit *circuit) {
    printf("Circuit:\n");
    for (int i = 0; i < circuit->num_components; i++) {
        printf("Component %d:\n", i);
        printf("  Type: %d\n", circuit->components[i].type);
        printf("  Value: %f\n", circuit->components[i].value);
    }
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("Node %d:\n", i);
        printf("  Voltage: %f\n", circuit->nodes[i].voltage);
        printf("  Current: %f\n", circuit->nodes[i].current);
    }
}

// Free the memory allocated for a circuit
void free_circuit(struct circuit *circuit) {
    free(circuit->components);
    free(circuit->nodes);
    free(circuit);
}

// Main function
int main() {
    // Create a new circuit
    struct circuit *circuit = create_circuit(5, 4);

    // Add components to the circuit
    add_component(circuit, RESISTOR, 10);
    add_component(circuit, CAPACITOR, 1e-6);
    add_component(circuit, INDUCTOR, 1e-3);
    add_component(circuit, VOLTAGE_SOURCE, 12);
    add_component(circuit, CURRENT_SOURCE, 1e-3);

    // Add nodes to the circuit
    add_node(circuit, 0, 0);
    add_node(circuit, 0, 0);
    add_node(circuit, 0, 0);
    add_node(circuit, 0, 0);

    // Solve the circuit
    solve_circuit(circuit);

    // Print the circuit
    print_circuit(circuit);

    // Free the memory allocated for the circuit
    free_circuit(circuit);

    return 0;
}