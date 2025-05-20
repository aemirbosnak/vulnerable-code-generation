//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

typedef struct Node {
    int type;
    double value;
    struct Node* next;
} Node;

typedef struct Circuit {
    Node* head;
    Node* tail;
    double voltage;
} Circuit;

Circuit* createCircuit(double voltage) {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->head = NULL;
    circuit->tail = NULL;
    circuit->voltage = voltage;
    return circuit;
}

void addNode(Circuit* circuit, int type, double value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->value = value;
    node->next = NULL;

    if (circuit->head == NULL) {
        circuit->head = node;
        circuit->tail = node;
    } else {
        circuit->tail->next = node;
        circuit->tail = node;
    }
}

void simulate(Circuit* circuit) {
    double current = 0.0;
    double resistance = 0.0;
    double voltageDrop = 0.0;

    for (Node* node = circuit->head; node; node = node->next) {
        switch (node->type) {
            case 1:
                current = circuit->voltage / node->value;
                voltageDrop = current * node->value;
                break;
            case 2:
                resistance = node->value;
                voltageDrop = circuit->voltage * resistance;
                break;
            case 3:
                voltageDrop = circuit->voltage * (node->value / 100.0);
                break;
        }

        printf("%f A flowing through a %d ohm resistor, causing a voltage drop of %f V.\n", current, resistance, voltageDrop);
    }

    printf("Total voltage drop: %f V\n", voltageDrop);
}

int main() {
    Circuit* circuit = createCircuit(12.0);
    addNode(circuit, 1, 2.0);
    addNode(circuit, 2, 4.0);
    addNode(circuit, 3, 10.0);

    simulate(circuit);

    return 0;
}