//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

// Defining the node structure
typedef struct node {
    int value;
    struct node *next;
} Node;

// Defining the circuit structure
typedef struct circuit {
    Node *head;
    Node *tail;
} Circuit;

// Function to create a node
Node *create_node(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to create a circuit
Circuit *create_circuit() {
    Circuit *new_circuit = (Circuit *)malloc(sizeof(Circuit));
    new_circuit->head = NULL;
    new_circuit->tail = NULL;
    return new_circuit;
}

// Function to add a node to the circuit
void add_node(Circuit *circuit, int value) {
    Node *new_node = create_node(value);
    if(circuit->head == NULL) {
        circuit->head = new_node;
        circuit->tail = new_node;
    }
    else {
        circuit->tail->next = new_node;
        circuit->tail = new_node;
    }
}

// Function to print the circuit
void print_circuit(Circuit *circuit) {
    Node *temp = circuit->head;
    printf("Circuit: ");
    while(temp!= NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Function to simulate the circuit
void simulate_circuit(Circuit *circuit) {
    Node *temp = circuit->head;
    while(temp!= NULL) {
        printf("Node %d: ", temp->value);
        if(temp->next!= NULL) {
            printf("Connected to node %d\n", temp->next->value);
        }
        else {
            printf("Not connected\n");
        }
        temp = temp->next;
    }
}

int main() {
    Circuit *circuit = create_circuit();
    add_node(circuit, 1);
    add_node(circuit, 2);
    add_node(circuit, 3);
    add_node(circuit, 4);
    print_circuit(circuit);
    simulate_circuit(circuit);
    return 0;
}