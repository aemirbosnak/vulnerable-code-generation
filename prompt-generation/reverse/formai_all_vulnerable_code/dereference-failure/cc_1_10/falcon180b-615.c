//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure definition
struct Node {
    int node_num;
    double voltage;
    double current;
    struct Node *next;
};

// Function prototypes
void create_node(struct Node **head, int node_num);
void create_circuit(struct Node **head, int num_nodes);
void print_circuit(struct Node *head);
void simulate_circuit(struct Node *head);

int main() {
    struct Node *head = NULL;

    // Create circuit with 3 nodes
    create_circuit(&head, 3);

    // Print the circuit
    print_circuit(head);

    // Simulate the circuit
    simulate_circuit(head);

    return 0;
}

// Function to create a new node
void create_node(struct Node **head, int node_num) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->node_num = node_num;
    new_node->voltage = 0;
    new_node->current = 0;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to create a new circuit
void create_circuit(struct Node **head, int num_nodes) {
    int i;
    for (i = 1; i <= num_nodes; i++) {
        create_node(head, i);
    }
}

// Function to print the circuit
void print_circuit(struct Node *head) {
    struct Node *temp = head;
    while (temp!= NULL) {
        printf("Node %d: Voltage = %.2f, Current = %.2f\n", temp->node_num, temp->voltage, temp->current);
        temp = temp->next;
    }
}

// Function to simulate the circuit
void simulate_circuit(struct Node *head) {
    struct Node *temp = head;
    while (temp!= NULL) {
        temp->voltage = (temp->voltage + 5) / 2;
        temp->current = (temp->current + 10) / 2;
        temp = temp->next;
    }
}