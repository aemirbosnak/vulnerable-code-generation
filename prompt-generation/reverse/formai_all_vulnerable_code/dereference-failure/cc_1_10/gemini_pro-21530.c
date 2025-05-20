//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef unsigned int UINT;

typedef struct _GATE {
    UINT type;
    UINT num_inputs;
    UINT *inputs;
    UINT output;
} GATE;

typedef struct _CIRCUIT {
    UINT num_gates;
    GATE *gates;
} CIRCUIT;

CIRCUIT *create_circuit(UINT num_gates) {
    CIRCUIT *circuit = (CIRCUIT *) malloc(sizeof(CIRCUIT));
    circuit->num_gates = num_gates;
    circuit->gates = (GATE *) malloc(num_gates * sizeof(GATE));
    return circuit;
}

void destroy_circuit(CIRCUIT *circuit) {
    free(circuit->gates);
    free(circuit);
}

GATE *create_gate(UINT type, UINT num_inputs) {
    GATE *gate = (GATE *) malloc(sizeof(GATE));
    gate->type = type;
    gate->num_inputs = num_inputs;
    gate->inputs = (UINT *) malloc(num_inputs * sizeof(UINT));
    gate->output = 0;
    return gate;
}

void destroy_gate(GATE *gate) {
    free(gate->inputs);
    free(gate);
}

void connect_gates(CIRCUIT *circuit, UINT gate1, UINT gate2, UINT input) {
    circuit->gates[gate1].inputs[input] = gate2;
}

void simulate_circuit(CIRCUIT *circuit) {
    for (UINT i = 0; i < circuit->num_gates; i++) {
        GATE *gate = &circuit->gates[i];
        switch (gate->type) {
            case 0: // AND gate
                gate->output = TRUE;
                for (UINT j = 0; j < gate->num_inputs; j++) {
                    gate->output &= circuit->gates[gate->inputs[j]].output;
                }
                break;
            case 1: // OR gate
                gate->output = FALSE;
                for (UINT j = 0; j < gate->num_inputs; j++) {
                    gate->output |= circuit->gates[gate->inputs[j]].output;
                }
                break;
            case 2: // NOT gate
                gate->output = !circuit->gates[gate->inputs[0]].output;
                break;
        }
    }
}

void print_circuit(CIRCUIT *circuit) {
    for (UINT i = 0; i < circuit->num_gates; i++) {
        GATE *gate = &circuit->gates[i];
        printf("Gate %d: type %d, num_inputs %d, inputs ", i, gate->type, gate->num_inputs);
        for (UINT j = 0; j < gate->num_inputs; j++) {
            printf("%d ", gate->inputs[j]);
        }
        printf(", output %d\n", gate->output);
    }
}

int main() {
    srand(time(NULL));

    CIRCUIT *circuit = create_circuit(10);

    for (UINT i = 0; i < circuit->num_gates; i++) {
        GATE *gate = create_gate(rand() % 3, rand() % 3);
        for (UINT j = 0; j < gate->num_inputs; j++) {
            gate->inputs[j] = rand() % circuit->num_gates;
        }
        circuit->gates[i] = *gate;
    }

    simulate_circuit(circuit);

    print_circuit(circuit);

    destroy_circuit(circuit);

    return 0;
}