//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_WIRES 1000

typedef struct node {
    int id;
    char *name;
    int type;
    int value;
    int num_inputs;
    int num_outputs;
    struct node **inputs;
    struct node **outputs;
} node;

typedef struct wire {
    int id;
    char *name;
    int value;
    struct node *source;
    struct node *destination;
} wire;

int num_nodes = 0;
int num_wires = 0;
node *nodes[MAX_NODES];
wire *wires[MAX_WIRES];

void add_node(int id, char *name, int type) {
    if (num_nodes >= MAX_NODES) {
        fprintf(stderr, "Error: Maximum number of nodes reached.\n");
        exit(1);
    }

    node *n = malloc(sizeof(node));
    n->id = id;
    n->name = strdup(name);
    n->type = type;
    n->value = 0;
    n->num_inputs = 0;
    n->num_outputs = 0;
    n->inputs = NULL;
    n->outputs = NULL;

    nodes[num_nodes++] = n;
}

void add_wire(int id, char *name, node *source, node *destination) {
    if (num_wires >= MAX_WIRES) {
        fprintf(stderr, "Error: Maximum number of wires reached.\n");
        exit(1);
    }

    wire *w = malloc(sizeof(wire));
    w->id = id;
    w->name = strdup(name);
    w->value = 0;
    w->source = source;
    w->destination = destination;

    wires[num_wires++] = w;
}

void connect_nodes(node *n1, node *n2) {
    if (n1->num_outputs >= MAX_WIRES) {
        fprintf(stderr, "Error: Maximum number of outputs for node %s reached.\n", n1->name);
        exit(1);
    }

    if (n2->num_inputs >= MAX_WIRES) {
        fprintf(stderr, "Error: Maximum number of inputs for node %s reached.\n", n2->name);
        exit(1);
    }

    wire *w = malloc(sizeof(wire));
    w->id = num_wires++;
    w->name = NULL;
    w->value = 0;
    w->source = n1;
    w->destination = n2;

    n1->outputs[n1->num_outputs++] = w;
    n2->inputs[n2->num_inputs++] = w;
}

void print_circuit() {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        node *n = nodes[i];
        printf("  %d: %s (%d inputs, %d outputs)\n", n->id, n->name, n->num_inputs, n->num_outputs);
    }

    printf("Wires:\n");
    for (int i = 0; i < num_wires; i++) {
        wire *w = wires[i];
        printf("  %d: %s (%s -> %s)\n", w->id, w->name, w->source->name, w->destination->name);
    }
}

void simulate_circuit() {
    // TODO: Implement circuit simulation here.
}

int main() {
    // Add nodes to the circuit.
    add_node(1, "input1", 1);
    add_node(2, "input2", 1);
    add_node(3, "gate1", 2);
    add_node(4, "gate2", 2);
    add_node(5, "output", 3);

    // Connect the nodes with wires.
    connect_nodes(nodes[0], nodes[2]);
    connect_nodes(nodes[1], nodes[2]);
    connect_nodes(nodes[2], nodes[3]);
    connect_nodes(nodes[3], nodes[4]);
    connect_nodes(nodes[4], nodes[5]);

    // Print the circuit.
    print_circuit();

    // Simulate the circuit.
    simulate_circuit();

    return 0;
}