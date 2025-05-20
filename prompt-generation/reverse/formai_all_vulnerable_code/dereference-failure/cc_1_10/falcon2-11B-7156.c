//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

struct Node {
    double resistance;
    double voltage;
    struct Node* next;
};

struct Node* createNode(double resistance, double voltage) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->resistance = resistance;
    newNode->voltage = voltage;
    newNode->next = NULL;
    return newNode;
}

struct Node* createCircuit(double resistance1, double voltage1, double resistance2, double voltage2) {
    struct Node* node1 = createNode(resistance1, voltage1);
    struct Node* node2 = createNode(resistance2, voltage2);
    node1->next = node2;
    return node1;
}

double computeCurrent(struct Node* node) {
    double voltage = node->voltage;
    double current = voltage / node->resistance;
    return current;
}

double computePower(struct Node* node) {
    double current = computeCurrent(node);
    double power = (current * current) * node->resistance;
    return power;
}

int main() {
    struct Node* circuit = createCircuit(2.0, 3.0, 4.0, 5.0);
    struct Node* currentNode = circuit;
    double current = computeCurrent(currentNode);
    printf("Current: %f\n", current);
    double power = computePower(currentNode);
    printf("Power: %f\n", power);
    while (currentNode->next!= NULL) {
        currentNode = currentNode->next;
        current = computeCurrent(currentNode);
        printf("Current: %f\n", current);
        power = computePower(currentNode);
        printf("Power: %f\n", power);
    }
    return 0;
}