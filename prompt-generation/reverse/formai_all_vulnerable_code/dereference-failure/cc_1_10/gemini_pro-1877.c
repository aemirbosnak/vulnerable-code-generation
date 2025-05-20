//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool value;
} Wire;

typedef struct {
    Wire *input1;
    Wire *input2;
    Wire *output;
} Gate;

void create_wire(Wire *wire) {
    wire->value = false;
}

void create_gate_and(Gate *gate) {
    gate->input1 = malloc(sizeof(Wire));
    create_wire(gate->input1);
    gate->input2 = malloc(sizeof(Wire));
    create_wire(gate->input2);
    gate->output = malloc(sizeof(Wire));
    create_wire(gate->output);
}

void create_gate_or(Gate *gate) {
    gate->input1 = malloc(sizeof(Wire));
    create_wire(gate->input1);
    gate->input2 = malloc(sizeof(Wire));
    create_wire(gate->input2);
    gate->output = malloc(sizeof(Wire));
    create_wire(gate->output);
}

void create_gate_not(Gate *gate) {
    gate->input1 = malloc(sizeof(Wire));
    create_wire(gate->input1);
    gate->output = malloc(sizeof(Wire));
    create_wire(gate->output);
}

void connect_wire(Wire *wire1, Wire *wire2) {
    wire1->value = wire2->value;
}

void connect_gate_and(Gate *gate, Wire *input1, Wire *input2, Wire *output) {
    gate->input1 = input1;
    gate->input2 = input2;
    gate->output = output;
}

void connect_gate_or(Gate *gate, Wire *input1, Wire *input2, Wire *output) {
    gate->input1 = input1;
    gate->input2 = input2;
    gate->output = output;
}

void connect_gate_not(Gate *gate, Wire *input1, Wire *output) {
    gate->input1 = input1;
    gate->output = output;
}

void simulate(Gate *gate) {
    if (gate->input1->value && gate->input2->value) {
        gate->output->value = true;
    } else {
        gate->output->value = false;
    }
}

int main() {
    // Create the circuit

    Wire *input1 = malloc(sizeof(Wire));
    create_wire(input1);
    Wire *input2 = malloc(sizeof(Wire));
    create_wire(input2);
    Gate *gate1 = malloc(sizeof(Gate));
    create_gate_and(gate1);
    connect_gate_and(gate1, input1, input2, gate1->output);

    Wire *input3 = malloc(sizeof(Wire));
    create_wire(input3);
    Gate *gate2 = malloc(sizeof(Gate));
    create_gate_or(gate2);
    connect_gate_or(gate2, input3, gate1->output, gate2->output);

    Gate *gate3 = malloc(sizeof(Gate));
    create_gate_not(gate3);
    connect_gate_not(gate3, gate2->output, gate3->output);

    // Set the inputs

    input1->value = true;
    input2->value = false;
    input3->value = true;

    // Simulate the circuit

    simulate(gate1);
    simulate(gate2);
    simulate(gate3);

    // Print the outputs

    printf("gate1 output: %d\n", gate1->output->value);
    printf("gate2 output: %d\n", gate2->output->value);
    printf("gate3 output: %d\n", gate3->output->value);

    return 0;
}