//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: excited
#include<stdio.h>
#include<stdlib.h>

#define MAX_GATES 10
#define MAX_INPUTS 2

/* Gate Type Enum */
typedef enum {
    AND, OR, NOT,
} GateType;

/* Circuit Gate Structure */
typedef struct {
    int id;
    int inputs[MAX_INPUTS];
    int output;
    GateType type;
} CircuitGate;

/* Circuit Structure */
typedef struct {
    int num_gates;
    CircuitGate gates[MAX_GATES];
} Circuit;

/* Function to initialize the circuit */
void init_circuit(Circuit *circuit) {
    circuit->num_gates = 0;
}

/* Function to add a gate to the circuit */
void add_gate(Circuit *circuit, int id, int input1, int input2, int output, GateType type) {
    CircuitGate gate = { id, { input1, input2 }, output, type };
    circuit->gates[circuit->num_gates] = gate;
    circuit->num_gates++;
}

/* Function to simulate a circuit */
void simulate_circuit(Circuit *circuit, int *inputs, int *outputs) {
    int i, j, output_val;
    CircuitGate gate;

    for (i = 0; i < circuit->num_gates; i++) {
        gate = circuit->gates[i];
        switch (gate.type) {
            case AND:
                output_val = 1;
                for (j = 0; j < MAX_INPUTS; j++) {
                    if (inputs[gate.inputs[j]] == 0) {
                        output_val = 0;
                        break;
                    }
                }
                outputs[gate.output] = output_val;
                break;
            case OR:
                output_val = 0;
                for (j = 0; j < MAX_INPUTS; j++) {
                    if (inputs[gate.inputs[j]] == 1) {
                        output_val = 1;
                        break;
                    }
                }
                outputs[gate.output] = output_val;
                break;
            case NOT:
                outputs[gate.output] = !inputs[gate.inputs[0]];
                break;
            default:
                printf("Invalid gate type!\n");
        }
    }
}

/* Main function */
int main() {
    /* Initialize the circuit */
    Circuit circuit;
    init_circuit(&circuit);

    /* Add the gates */
    add_gate(&circuit, 0, 0, 1, 2, OR);
    add_gate(&circuit, 1, 2, -1, 3, NOT);
    add_gate(&circuit, 2, 3, 4, 5, AND);

    /* Test the circuit */
    int inputs[MAX_INPUTS] = { 1, 0 };
    int outputs[MAX_GATES] = { 0 };
    simulate_circuit(&circuit, inputs, outputs);

    /* Print the outputs */
    int i;
    for (i = 0; i < circuit.num_gates; i++) {
        printf("Gate %d output: %d\n", circuit.gates[i].id, outputs[i]);
    }

    return 0;
}