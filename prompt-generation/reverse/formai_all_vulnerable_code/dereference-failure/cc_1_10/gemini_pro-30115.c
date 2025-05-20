//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Circuit elements
typedef enum {
    RESISTOR,
    CAPACITOR,
    INDUCTOR
} ElementType;

typedef struct {
    ElementType type;
    double value;
} Element;

// Circuit nodes
typedef struct {
    int id;
    double voltage;
} Node;

// Circuit
typedef struct {
    int num_elements;
    Element *elements;
    int num_nodes;
    Node *nodes;
} Circuit;

// Initializes a circuit
Circuit* init_circuit(int num_elements, int num_nodes) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->num_elements = num_elements;
    circuit->elements = malloc(sizeof(Element) * num_elements);
    circuit->num_nodes = num_nodes;
    circuit->nodes = malloc(sizeof(Node) * num_nodes);
    return circuit;
}

// Frees a circuit
void free_circuit(Circuit *circuit) {
    free(circuit->elements);
    free(circuit->nodes);
    free(circuit);
}

// Adds an element to a circuit
void add_element(Circuit *circuit, ElementType type, double value, int node1, int node2) {
    Element element = {type, value};
    circuit->elements[circuit->num_elements++] = element;
    circuit->nodes[node1].id = node1;
    circuit->nodes[node2].id = node2;
}

// Solves a circuit using nodal analysis
void solve_circuit(Circuit *circuit) {
    // Create the system of equations
    int num_equations = circuit->num_nodes;
    double A[num_equations][num_equations];
    double b[num_equations];
    for (int i = 0; i < num_equations; i++) {
        for (int j = 0; j < num_equations; j++) {
            A[i][j] = 0;
        }
        b[i] = 0;
    }

    // Populate the system of equations
    for (int i = 0; i < circuit->num_elements; i++) {
        Element element = circuit->elements[i];
        int node1 = circuit->nodes[i].id;
        int node2 = circuit->nodes[i + 1].id;
        switch (element.type) {
            case RESISTOR:
                A[node1][node1] += 1 / element.value;
                A[node1][node2] -= 1 / element.value;
                A[node2][node1] -= 1 / element.value;
                A[node2][node2] += 1 / element.value;
                break;
            case CAPACITOR:
                A[node1][node1] += 1 / (element.value * circuit->nodes[i].voltage);
                A[node1][node2] -= 1 / (element.value * circuit->nodes[i].voltage);
                A[node2][node1] -= 1 / (element.value * circuit->nodes[i].voltage);
                A[node2][node2] += 1 / (element.value * circuit->nodes[i].voltage);
                break;
            case INDUCTOR:
                A[node1][node1] += element.value * circuit->nodes[i].voltage;
                A[node1][node2] -= element.value * circuit->nodes[i].voltage;
                A[node2][node1] -= element.value * circuit->nodes[i].voltage;
                A[node2][node2] += element.value * circuit->nodes[i].voltage;
                break;
        }
    }

    // Solve the system of equations
    double x[num_equations];
    for (int i = 0; i < num_equations; i++) {
        x[i] = 0;
        for (int j = 0; j < num_equations; j++) {
            x[i] += A[i][j] * circuit->nodes[j].voltage;
        }
        x[i] -= b[i];
    }

    // Update the node voltages
    for (int i = 0; i < num_equations; i++) {
        circuit->nodes[i].voltage = x[i];
    }
}

// Prints the circuit solution
void print_solution(Circuit *circuit) {
    printf("Node voltages:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("Node %d: %f\n", circuit->nodes[i].id, circuit->nodes[i].voltage);
    }
}

// Example circuit
int main() {
    Circuit *circuit = init_circuit(4, 3);

    add_element(circuit, RESISTOR, 10, 0, 1);
    add_element(circuit, CAPACITOR, 1e-6, 1, 2);
    add_element(circuit, INDUCTOR, 1e-3, 2, 0);

    solve_circuit(circuit);
    print_solution(circuit);

    free_circuit(circuit);
    return 0;
}