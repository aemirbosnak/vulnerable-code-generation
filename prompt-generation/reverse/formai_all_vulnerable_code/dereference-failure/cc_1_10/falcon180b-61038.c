//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    double voltage;
    double current;
    struct Node* next;
} Node;

typedef struct Circuit {
    Node* head;
    int size;
} Circuit;

Circuit* createCircuit(int size) {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->head = NULL;
    circuit->size = size;
    return circuit;
}

void addNode(Circuit* circuit, double voltage, double current) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->voltage = voltage;
    node->current = current;
    node->next = NULL;
    if (circuit->head == NULL) {
        circuit->head = node;
    } else {
        Node* temp = circuit->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void calculateCircuit(Circuit* circuit) {
    Node* temp = circuit->head;
    while (temp!= NULL) {
        double resistance = 1 / (temp->current);
        double voltageDrop = resistance * temp->current;
        temp->voltage -= voltageDrop;
        temp = temp->next;
    }
}

void printCircuit(Circuit* circuit) {
    Node* temp = circuit->head;
    printf("Voltage | Current\n");
    while (temp!= NULL) {
        printf("%f | %f\n", temp->voltage, temp->current);
        temp = temp->next;
    }
}

int main() {
    Circuit* circuit = createCircuit(3);
    addNode(circuit, 5.0, 1.0);
    addNode(circuit, 10.0, 2.0);
    addNode(circuit, 15.0, 3.0);
    calculateCircuit(circuit);
    printCircuit(circuit);
    return 0;
}