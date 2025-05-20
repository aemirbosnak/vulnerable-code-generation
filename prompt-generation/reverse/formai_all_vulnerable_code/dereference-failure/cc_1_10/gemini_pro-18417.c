//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int value;
    struct node *next;
} NODE;

// Circuit structure
typedef struct circuit {
    int num_nodes;
    NODE *head;
} CIRCUIT;

// Create a new node
NODE *create_node(int value) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (new_node == NULL) {
        fprintf(stderr, "Error: could not allocate memory for new node\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Create a new circuit
CIRCUIT *create_circuit(int num_nodes) {
    CIRCUIT *new_circuit = (CIRCUIT *)malloc(sizeof(CIRCUIT));
    if (new_circuit == NULL) {
        fprintf(stderr, "Error: could not allocate memory for new circuit\n");
        exit(1);
    }
    new_circuit->num_nodes = num_nodes;
    new_circuit->head = NULL;
    return new_circuit;
}

// Add a node to the circuit
void add_node(CIRCUIT *circuit, int value) {
    NODE *new_node = create_node(value);
    if (circuit->head == NULL) {
        circuit->head = new_node;
    } else {
        NODE *current_node = circuit->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Print the circuit
void print_circuit(CIRCUIT *circuit) {
    NODE *current_node = circuit->head;
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the circuit
void free_circuit(CIRCUIT *circuit) {
    NODE *current_node = circuit->head;
    while (current_node != NULL) {
        NODE *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(circuit);
}

int main() {
    // Create a new circuit
    CIRCUIT *circuit = create_circuit(5);

    // Add some nodes to the circuit
    add_node(circuit, 1);
    add_node(circuit, 2);
    add_node(circuit, 3);
    add_node(circuit, 4);
    add_node(circuit, 5);

    // Print the circuit
    print_circuit(circuit);

    // Free the circuit
    free_circuit(circuit);

    return 0;
}