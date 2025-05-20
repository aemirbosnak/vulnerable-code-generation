//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_GATES 50
#define MAX_LINES 1000

typedef struct Gate {
    char* type; //AND, OR, XOR, NOT
    int inputs[2]; //input gates
    unsigned short output; //output signal
} Gate;

void simulate(Gate* gates, int* signals, int numGates, int numSignals) {
    int i;
    for (i = 0; i < numGates; i++) {
        if (strcmp(gates[i].type, "AND") == 0) {
            int input1 = signals[gates[i].inputs[0]];
            int input2 = signals[gates[i].inputs[1]];
            gates[i].output = input1 && input2;
        } else if (strcmp(gates[i].type, "OR") == 0) {
            int input1 = signals[gates[i].inputs[0]];
            int input2 = signals[gates[i].inputs[1]];
            gates[i].output = input1 || input2;
        } else if (strcmp(gates[i].type, "XOR") == 0) {
            int input1 = signals[gates[i].inputs[0]];
            int input2 = signals[gates[i].inputs[1]];
            gates[i].output = input1 ^ input2;
        } else if (strcmp(gates[i].type, "NOT") == 0) {
            int input = signals[gates[i].inputs[0]];
            gates[i].output = !input;
        } else {
            printf("Error: unsupported gate type %s\n", gates[i].type);
            exit(1);
        }
    }
}

int main() {
    char* fileName = "input.txt";
    FILE* f = fopen(fileName, "r");
    if (!f) {
        printf("Error: failed to open file %s\n", fileName);
        exit(1);
    }

    Gate* gates = malloc(MAX_GATES * sizeof(Gate));
    int numGates = 0;

    int numSignals, i, j;
    fscanf(f, "%d", &numSignals);

    int* signals = malloc(numSignals * sizeof(int));
    for (i = 0; i < numSignals; i++) {
        int signalValue;
        fscanf(f, "%d", &signalValue);
        signals[i] = signalValue;
    }

    int numLines = 0;
    while (!feof(f)) {
        char line[MAX_LINES];
        fgets(line, MAX_LINES, f);

        //remove new line character if it exists
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        //split line into tokens
        char* token;
        int gateInputs[2];
        int numGateInputs = 0;

        token = strtok(line, " ");
        char* gateType = token;

        while (token != NULL) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                gateInputs[numGateInputs] = atoi(token);
                numGateInputs++;
            }
        }

        //create new gate and add to gates array
        Gate newGate;
        newGate.type = gateType;
        newGate.inputs[0] = gateInputs[0];
        newGate.inputs[1] = gateInputs[1];
        newGate.output = 0;

        gates[numGates] = newGate;
        numGates++;
        numLines++;
    }

    //simulate circuit
    simulate(gates, signals, numGates, numSignals);

    //print results
    for (i = 0; i < numGates; i++) {
        printf("%s ", gates[i].type);

        for (j = 0; j < 2; j++) {
            printf("%d ", gates[i].inputs[j]);
        }

        printf("%hu\n", gates[i].output);
    }

    return 0;
}