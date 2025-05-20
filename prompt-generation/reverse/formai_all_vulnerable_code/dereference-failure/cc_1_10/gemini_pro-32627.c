//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool value;
} Node;

typedef struct {
    Node *inputs[2];
    Node *output;
    bool (*operation)(bool, bool);
} Gate;

bool and(bool a, bool b) {
    return a && b;
}

bool or(bool a, bool b) {
    return a || b;
}

bool not(bool a) {
    return !a;
}

Gate* create_gate(bool (*operation)(bool, bool)) {
    Gate *gate = malloc(sizeof(Gate));
    gate->inputs[0] = malloc(sizeof(Node));
    gate->inputs[1] = malloc(sizeof(Node));
    gate->output = malloc(sizeof(Node));
    gate->operation = operation;
    return gate;
}

void connect_gates(Gate *gate1, Gate *gate2, int input1, int input2) {
    gate1->inputs[input1] = gate2->output;
    gate2->inputs[input2] = gate1->output;
}

void simulate_circuit(Gate *gate) {
    gate->output->value = gate->operation(gate->inputs[0]->value, gate->inputs[1]->value);
}

int main() {
    // Create the gates
    Gate *and_gate1 = create_gate(and);
    Gate *and_gate2 = create_gate(and);
    Gate *or_gate = create_gate(or);
    Gate *not_gate = create_gate(not);

    // Connect the gates
    connect_gates(and_gate1, and_gate2, 0, 0);
    connect_gates(and_gate1, or_gate, 1, 0);
    connect_gates(and_gate2, or_gate, 1, 1);
    connect_gates(not_gate, and_gate2, 0, 1);

    // Set the input values
    and_gate1->inputs[0]->value = true;
    and_gate1->inputs[1]->value = true;
    and_gate2->inputs[0]->value = true;
    not_gate->inputs[0]->value = false;

    // Simulate the circuit
    simulate_circuit(and_gate1);
    simulate_circuit(and_gate2);
    simulate_circuit(or_gate);
    simulate_circuit(not_gate);

    // Print the output value
    printf("The output value is: %d\n", or_gate->output->value);

    return 0;
}