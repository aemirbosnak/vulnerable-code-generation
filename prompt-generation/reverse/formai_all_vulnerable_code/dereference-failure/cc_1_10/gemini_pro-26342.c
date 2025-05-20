//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct circuit {
    node *inputs;
    node *outputs;
    int num_inputs;
    int num_outputs;
} circuit;

circuit *create_circuit(int num_inputs, int num_outputs) {
    circuit *c = malloc(sizeof(circuit));
    c->inputs = malloc(sizeof(node) * num_inputs);
    c->outputs = malloc(sizeof(node) * num_outputs);
    c->num_inputs = num_inputs;
    c->num_outputs = num_outputs;
    return c;
}

void free_circuit(circuit *c) {
    free(c->inputs);
    free(c->outputs);
    free(c);
}

void connect_nodes(node *n1, node *n2) {
    n1->next = n2;
}

void set_input(circuit *c, int input, int value) {
    c->inputs[input].value = value;
}

int get_output(circuit *c, int output) {
    return c->outputs[output].value;
}

void simulate_circuit(circuit *c) {
    for (int i = 0; i < c->num_inputs; i++) {
        node *n = c->inputs[i].next;
        while (n != NULL) {
            n->value = c->inputs[i].value;
            n = n->next;
        }
    }

    for (int i = 0; i < c->num_outputs; i++) {
        node *n = c->outputs[i].next;
        int value = 0;
        while (n != NULL) {
            value += n->value;
            n = n->next;
        }
        c->outputs[i].value = value % 2;
    }
}

int main() {
    circuit *c = create_circuit(2, 1);

    connect_nodes(&c->inputs[0], &c->outputs[0]);
    connect_nodes(&c->inputs[1], &c->outputs[0]);

    set_input(c, 0, 1);
    set_input(c, 1, 1);

    simulate_circuit(c);

    printf("Output: %d\n", get_output(c, 0));

    free_circuit(c);

    return 0;
}