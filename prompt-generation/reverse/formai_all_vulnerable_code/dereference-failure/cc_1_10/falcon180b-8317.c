//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure
typedef struct node {
    int index;
    double voltage;
    struct node *next;
} Node;

// Circuit structure
typedef struct circuit {
    Node *head;
    int num_nodes;
} Circuit;

// Function prototypes
void create_circuit(Circuit *circuit, int num_nodes);
void add_node(Circuit *circuit, int index, double voltage);
void delete_circuit(Circuit *circuit);
void print_circuit(Circuit *circuit);

// Main function
int main() {
    Circuit circuit;
    create_circuit(&circuit, 5);
    add_node(&circuit, 0, 5.0);
    add_node(&circuit, 1, 10.0);
    add_node(&circuit, 2, 15.0);
    add_node(&circuit, 3, 20.0);
    add_node(&circuit, 4, 25.0);
    print_circuit(&circuit);
    delete_circuit(&circuit);
    return 0;
}

// Function definitions
void create_circuit(Circuit *circuit, int num_nodes) {
    circuit->head = NULL;
    circuit->num_nodes = num_nodes;
}

void add_node(Circuit *circuit, int index, double voltage) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->index = index;
    new_node->voltage = voltage;
    new_node->next = NULL;
    if (circuit->head == NULL) {
        circuit->head = new_node;
    } else {
        Node *curr_node = circuit->head;
        while (curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

void delete_circuit(Circuit *circuit) {
    Node *curr_node = circuit->head;
    while (curr_node!= NULL) {
        Node *next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    circuit->head = NULL;
}

void print_circuit(Circuit *circuit) {
    Node *curr_node = circuit->head;
    printf("Circuit:\n");
    while (curr_node!= NULL) {
        printf("Node %d: Voltage = %.2fV\n", curr_node->index, curr_node->voltage);
        curr_node = curr_node->next;
    }
}