//MISTRAL-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define NAND_FANIN 2
#define NAND_FANOUT 1

typedef struct NANDGate {
    bool inputs[NAND_FANIN];
    bool output;
} NANDGate;

void nand_compute(NANDGate* gate) {
    gate->output = !gate->inputs[0] || !gate->inputs[1];
}

void print_gate_state(NANDGate gate) {
    printf("NAND Gate State:\n");
    printf("Input 0: %s, Input 1: %s, Output: %s\n",
           (gate.inputs[0] ? "HIGH" : "LOW"),
           (gate.inputs[1] ? "HIGH" : "LOW"),
           (gate.output ? "HIGH" : "LOW"));
}

int main() {
    srand(time(NULL));
    int num_gates = 5;
    int num_simulations = 10;

    NANDGate* gates = malloc(num_gates * sizeof(NANDGate));

    for (int i = 0; i < num_gates; i++) {
        for (int j = 0; j < NAND_FANIN; j++) {
            gates[i].inputs[j] = rand() % 2;
        }
        gates[i].output = false;
    }

    for (int simulation = 0; simulation < num_simulations; simulation++) {
        printf("\nSimulation %d:\n", simulation + 1);

        for (int i = 0; i < num_gates; i++) {
            nand_compute(&gates[i]);
            print_gate_state(gates[i]);
        }

        printf("\n");
    }

    free(gates);

    return 0;
}