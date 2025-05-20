//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
    int value;
    struct node *next;
} node;

// Circuit structure
typedef struct circuit {
    int num_nodes;
    int num_inputs;
    int num_outputs;
    node **inputs;
    node **outputs;
    node **nodes;
} circuit;

// Create a new circuit
circuit *create_circuit(int num_nodes, int num_inputs, int num_outputs) {
    circuit *c = (circuit *)malloc(sizeof(circuit));
    if (c == NULL) {
        return NULL;
    }

    c->num_nodes = num_nodes;
    c->num_inputs = num_inputs;
    c->num_outputs = num_outputs;

    c->inputs = (node **)malloc(sizeof(node *) * num_inputs);
    if (c->inputs == NULL) {
        free(c);
        return NULL;
    }

    c->outputs = (node **)malloc(sizeof(node *) * num_outputs);
    if (c->outputs == NULL) {
        free(c->inputs);
        free(c);
        return NULL;
    }

    c->nodes = (node **)malloc(sizeof(node *) * num_nodes);
    if (c->nodes == NULL) {
        free(c->outputs);
        free(c->inputs);
        free(c);
        return NULL;
    }

    for (int i = 0; i < num_nodes; i++) {
        c->nodes[i] = NULL;
    }

    return c;
}

// Free a circuit
void free_circuit(circuit *c) {
    if (c == NULL) {
        return;
    }

    for (int i = 0; i < c->num_nodes; i++) {
        node *n = c->nodes[i];
        while (n != NULL) {
            node *temp = n;
            n = n->next;
            free(temp);
        }
    }

    free(c->nodes);
    free(c->outputs);
    free(c->inputs);
    free(c);
}

// Add a new node to a circuit
node *add_node(circuit *c, int value) {
    if (c == NULL) {
        return NULL;
    }

    node *n = (node *)malloc(sizeof(node));
    if (n == NULL) {
        return NULL;
    }

    n->value = value;
    n->next = NULL;

    c->nodes[c->num_nodes++] = n;

    return n;
}

// Add an edge between two nodes
void add_edge(circuit *c, node *n1, node *n2) {
    if (c == NULL || n1 == NULL || n2 == NULL) {
        return;
    }

    node *new_edge = (node *)malloc(sizeof(node));
    if (new_edge == NULL) {
        return;
    }

    new_edge->value = 1;
    new_edge->next = n1->next;

    n1->next = new_edge;
}

// Evaluate a circuit
int evaluate_circuit(circuit *c) {
    if (c == NULL) {
        return -1;
    }

    for (int i = 0; i < c->num_inputs; i++) {
        node *n = c->inputs[i];
        while (n != NULL) {
            n->value = 1;
            n = n->next;
        }
    }

    for (int i = 0; i < c->num_nodes; i++) {
        node *n = c->nodes[i];
        while (n != NULL) {
            int sum = 0;
            node *prev = n;
            while (prev != NULL) {
                sum += prev->value;
                prev = prev->next;
            }
            n->value = sum % 2;
            n = n->next;
        }
    }

    int output = 0;
    for (int i = 0; i < c->num_outputs; i++) {
        node *n = c->outputs[i];
        while (n != NULL) {
            output += n->value;
            n = n->next;
        }
    }

    return output;
}

// Print a circuit
void print_circuit(circuit *c) {
    if (c == NULL) {
        return;
    }

    printf("Circuit:\n");
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = c->nodes[i];
        printf("Node %d: ", i);
        while (n != NULL) {
            printf("%d ", n->value);
            n = n->next;
        }
        printf("\n");
    }

    printf("Inputs:\n");
    for (int i = 0; i < c->num_inputs; i++) {
        node *n = c->inputs[i];
        printf("Input %d: ", i);
        while (n != NULL) {
            printf("%d ", n->value);
            n = n->next;
        }
        printf("\n");
    }

    printf("Outputs:\n");
    for (int i = 0; i < c->num_outputs; i++) {
        node *n = c->outputs[i];
        printf("Output %d: ", i);
        while (n != NULL) {
            printf("%d ", n->value);
            n = n->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new circuit
    circuit *c = create_circuit(4, 2, 1);

    // Add nodes to the circuit
    node *n1 = add_node(c, 0);
    node *n2 = add_node(c, 0);
    node *n3 = add_node(c, 0);
    node *n4 = add_node(c, 0);

    // Add edges to the circuit
    add_edge(c, n1, n2);
    add_edge(c, n1, n3);
    add_edge(c, n2, n4);
    add_edge(c, n3, n4);

    // Set the inputs to the circuit
    c->inputs[0] = n1;
    c->inputs[1] = n2;

    // Set the outputs to the circuit
    c->outputs[0] = n4;

    // Print the circuit
    print_circuit(c);

    // Evaluate the circuit
    int output = evaluate_circuit(c);

    // Print the output
    printf("Output: %d\n", output);

    // Free the circuit
    free_circuit(c);

    return 0;
}