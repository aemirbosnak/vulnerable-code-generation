//MISTRAL-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define INPUT 0
#define OUTPUT 1
#define NAND_GATE 0
#define NUM_GATES 10
#define NUM_INPUTS 2
#define NUM_OUTPUTS 1

typedef struct {
    int gateType;
    int numPins;
    int *pins;
    int *output;
} gate;

gate gates[NUM_GATES];
int inputs[NUM_INPUTS];
int outputs[NUM_OUTPUTS];
int clock = 0;

void nandGate(int pinA, int pinB, int pinOut) {
    gate *gatePtr;
    gatePtr = &gates[pinOut];
    gatePtr->gateType = NAND_GATE;
    gatePtr->numPins = NUM_INPUTS;
    gatePtr->pins = malloc(gatePtr->numPins * sizeof(int));
    gatePtr->output = malloc(sizeof(int));
    gatePtr->pins[0] = pinA;
    gatePtr->pins[1] = pinB;
}

void processInputs() {
    int i;
    for (i = 0; i < NUM_INPUTS; i++) {
        gates[inputs[i]].output[0] = inputs[i];
    }
}

void propagateSignals() {
    gate *gatePtr;
    int i, j;
    for (i = 0; i < NUM_GATES; i++) {
        gatePtr = &gates[i];
        if (gatePtr->gateType == NAND_GATE) {
            gatePtr->output[0] = (gatePtr->pins[0] & gatePtr->pins[1]);
        }
    }
}

void assignOutputs() {
    gate *gatePtr;
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        gatePtr = &gates[outputs[i]];
        outputs[i] = gatePtr->output[0];
    }
}

void printOutputs() {
    int i;
    for (i = 0; i < NUM_OUTPUTS; i++) {
        printf("Output %d: %d\n", i, outputs[i]);
    }
}

int main() {
    int inputA, inputB, output;

    nandGate(INPUT, INPUT, 0);
    nandGate(INPUT, INPUT, 1);

    inputA = 1;
    inputB = 0;

    inputs[0] = 0;
    inputs[1] = 1;

    outputs[0] = 1;

    while (clock < 2) {
        processInputs();
        propagateSignals();
        assignOutputs();

        clock++;
        printf("\nClock %d:\n", clock);
        printOutputs();

        inputA = !inputA;
        inputB = !inputB;
    }

    return 0;
}