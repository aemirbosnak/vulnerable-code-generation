//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    int current;
    int voltage;
    float resistance;
    struct Node *next;
};

struct Circuit {
    struct Node *head;
    struct Node *tail;
};

void addNode(struct Circuit *circuit, int id, int current, int voltage, float resistance) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->id = id;
    node->current = current;
    node->voltage = voltage;
    node->resistance = resistance;
    node->next = NULL;

    if (circuit->tail == NULL) {
        circuit->head = circuit->tail = node;
    } else {
        circuit->tail->next = node;
        circuit->tail = node;
    }
}

void simulate(struct Circuit *circuit) {
    struct Node *node = circuit->head;

    while (node != NULL) {
        float voltage = node->voltage;
        float resistance = node->resistance;

        if (node->next != NULL) {
            float nextCurrent = (voltage * 1.0) / resistance;
            node->current = nextCurrent;
            node->next->voltage = -(nextCurrent * node->next->resistance);
        }

        node = node->next;
    }
}

void printCircuit(struct Circuit *circuit) {
    struct Node *node = circuit->head;

    printf("Node\tVoltage\tCurrent\tResistance\n");
    while (node != NULL) {
        printf("%d\t%d\t%.2f\t%.2f\n", node->id, node->voltage, node->current, node->resistance);
        node = node->next;
    }
}

int main() {
    struct Circuit circuit;

    addNode(&circuit, 1, 0, 10, 10);
    addNode(&circuit, 2, 0, 0, 20);
    addNode(&circuit, 3, 0, 0, 30);
    addNode(&circuit, 4, 0, 0, 40);
    addNode(&circuit, 5, 0, 0, 50);

    printCircuit(&circuit);
    simulate(&circuit);
    printCircuit(&circuit);

    return 0;
}