//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    double resistance;
    int is_connected;
    struct node *next;
} Node;

typedef struct circuit {
    Node *start;
    Node *end;
    int is_closed;
} Circuit;

void create_node(Node **head, double resistance) {
    Node *node = malloc(sizeof(Node));
    node->resistance = resistance;
    node->is_connected = 0;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        Node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void connect_nodes(Node *node1, Node *node2) {
    node1->is_connected = 1;
    node2->is_connected = 1;
    node1->next = node2;
    node2->next = node1;
}

void print_circuit(Circuit *circuit) {
    Node *node = circuit->start;
    printf("Circuit:\n");
    while (node!= NULL) {
        printf("Resistance: %.2lf\n", node->resistance);
        printf("Is connected: %d\n", node->is_connected);
        printf("Next node: ");
        if (node->next!= NULL) {
            printf("%p\n", node->next);
        } else {
            printf("NULL\n");
        }
        node = node->next;
    }
}

double calculate_resistance(Circuit *circuit) {
    double total_resistance = 0.0;
    Node *node = circuit->start;
    while (node!= NULL) {
        total_resistance += node->resistance;
        node = node->next;
    }
    return total_resistance;
}

int main() {
    Node *node1 = NULL;
    Node *node2 = NULL;
    Node *node3 = NULL;
    create_node(&node1, 100.0);
    create_node(&node2, 200.0);
    create_node(&node3, 300.0);
    connect_nodes(node1, node2);
    connect_nodes(node2, node3);
    Circuit circuit;
    circuit.start = node1;
    circuit.end = node3;
    circuit.is_closed = 1;
    print_circuit(&circuit);
    double resistance = calculate_resistance(&circuit);
    printf("Total resistance: %.2lf\n", resistance);
    return 0;
}