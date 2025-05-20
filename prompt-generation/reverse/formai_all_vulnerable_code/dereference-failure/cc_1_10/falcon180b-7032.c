//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Node {
    double value;
    struct Node *next;
};

struct Circuit {
    struct Node *head;
    struct Node *tail;
};

struct Circuit *create_circuit() {
    struct Circuit *circuit = (struct Circuit *) malloc(sizeof(struct Circuit));
    circuit->head = NULL;
    circuit->tail = NULL;
    return circuit;
}

void add_node(struct Circuit *circuit, double value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
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

void print_circuit(struct Circuit *circuit) {
    struct Node *node = circuit->head;
    while (node!= NULL) {
        printf("%.2f ", node->value);
        node = node->next;
    }
    printf("\n");
}

void calculate_circuit(struct Circuit *circuit) {
    struct Node *node = circuit->head;
    while (node!= NULL) {
        if (node->next == NULL) {
            node->value = 0;
        } else {
            node->value = node->next->value - node->value;
        }
        node = node->next;
    }
}

int main() {
    struct Circuit *circuit = create_circuit();
    add_node(circuit, 5);
    add_node(circuit, 10);
    add_node(circuit, 15);
    add_node(circuit, 20);
    print_circuit(circuit);
    calculate_circuit(circuit);
    print_circuit(circuit);
    return 0;
}