//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 100

typedef struct CircuitNode {
    unsigned int id;
    double value;
    bool isSource;
    struct CircuitNode* next;
} CircuitNode;

typedef struct Circuit {
    CircuitNode* head;
    unsigned int size;
} Circuit;

Circuit* circuit;
double dt;

void addNode(double value, bool isSource) {
    CircuitNode* newNode = malloc(sizeof(CircuitNode));
    newNode->id = circuit->size++;
    newNode->value = value;
    newNode->isSource = isSource;
    newNode->next = circuit->head;
    circuit->head = newNode;
}

double eulerUpdate(CircuitNode* node, double input, double output) {
    if (node->isSource) {
        return input;
    } else {
        return node->value + (1 / node->value) * (input - output) * dt;
    }
}

void simulate(int iterations) {
    double input, output, tempOutput, error, delta, tolerance = 0.001;
    CircuitNode* node;
    for (int i = 0; i < iterations; i++) {
        printf("Iteration %d:\n", i + 1);
        printf("------------\n");

        input = 20 * sin(2 * M_PI * 1 * i / iterations);
        node = circuit->head;
        tempOutput = node->value;
        do {
            output = tempOutput;
            tempOutput = eulerUpdate(node, input, output);
            node = node->next;
        } while (node != NULL);

        error = fabs(output - tempOutput);
        for (int j = 0; j < 10 && error > tolerance; j++) {
            delta = (tempOutput - output) / (1 / tempOutput + 1 / output);
            output += delta;
            tempOutput -= delta;
            error = fabs(output - tempOutput);
        }

        printf("Input voltage: %fV\n", input);
        node = circuit->head;
        do {
            printf("Node %d voltage: %fV\n", node->id, node->value);
            node->value = eulerUpdate(node, input, output);
            node = node->next;
        } while (node != NULL);

        printf("Output voltage: %fV\n", output);
        printf("\n");
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    double value;
    circuit = malloc(sizeof(Circuit));
    circuit->head = NULL;
    circuit->size = 0;
    printf("Enter circuit nodes (press q to quit):\n");
    do {
        printf("Node %d value: ", circuit->size);
        fgets(input, MAX_INPUT_SIZE, stdin);
        if (*input == 'q') {
            break;
        }
        value = atof(input);
        addNode(value, false);
    } while (true);

    dt = 0.1;
    simulate(10);

    while (circuit->head != NULL) {
        CircuitNode* temp = circuit->head;
        circuit->head = circuit->head->next;
        free(temp);
    }
    free(circuit);

    return 0;
}