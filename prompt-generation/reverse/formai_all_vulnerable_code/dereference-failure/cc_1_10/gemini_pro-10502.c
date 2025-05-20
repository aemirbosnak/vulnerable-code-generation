//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct _node {
    int id;
    int type;
    int num_inputs;
    int *inputs;
    int output;
} node;

typedef struct _circuit {
    int num_nodes;
    node *nodes;
} circuit;

circuit *create_circuit(int num_nodes) {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->nodes = malloc(sizeof(node) * num_nodes);
    return c;
}

void destroy_circuit(circuit *c) {
    free(c->nodes);
    free(c);
}

void add_node(circuit *c, int id, int type, int num_inputs, int *inputs) {
    node *n = &c->nodes[id];
    n->id = id;
    n->type = type;
    n->num_inputs = num_inputs;
    n->inputs = malloc(sizeof(int) * num_inputs);
    memcpy(n->inputs, inputs, sizeof(int) * num_inputs);
    n->output = 0;
}

void evaluate_circuit(circuit *c) {
    for (int i = 0; i < c->num_nodes; i++) {
        node *n = &c->nodes[i];
        switch (n->type) {
            case 0: // AND
                n->output = 1;
                for (int j = 0; j < n->num_inputs; j++) {
                    n->output &= c->nodes[n->inputs[j]].output;
                }
                break;
            case 1: // OR
                n->output = 0;
                for (int j = 0; j < n->num_inputs; j++) {
                    n->output |= c->nodes[n->inputs[j]].output;
                }
                break;
            case 2: // NOT
                n->output = !c->nodes[n->inputs[0]].output;
                break;
            case 3: // INPUT
                break;
            case 4: // OUTPUT
                printf("Output of node %d: %d\n", n->id, n->output);
                break;
        }
    }
}

int main() {
    circuit *c = create_circuit(5);

    // Add nodes
    add_node(c, 0, 3, 0, NULL);  // Input 1
    add_node(c, 1, 3, 0, NULL);  // Input 2
    add_node(c, 2, 0, 2, (int[]){0, 1});  // AND
    add_node(c, 3, 4, 1, (int[]){2});  // Output
    add_node(c, 4, 3, 0, NULL);  // Input 3

    // Evaluate circuit
    evaluate_circuit(c);

    // Destroy circuit
    destroy_circuit(c);

    return 0;
}