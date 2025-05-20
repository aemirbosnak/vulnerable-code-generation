//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int id;
    char *name;
    int num_inputs;
    int num_outputs;
    int *inputs;
    int *outputs;
} node_t;

typedef struct {
    int id;
    char *name;
    int num_nodes;
    node_t *nodes;
} circuit_t;

circuit_t *create_circuit(char *name) {
    circuit_t *circuit = malloc(sizeof(circuit_t));
    circuit->id = 0;
    circuit->name = strdup(name);
    circuit->num_nodes = 0;
    circuit->nodes = malloc(sizeof(node_t) * MAX_NODES);
    return circuit;
}

void destroy_circuit(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        free(circuit->nodes[i].name);
        free(circuit->nodes[i].inputs);
        free(circuit->nodes[i].outputs);
    }
    free(circuit->nodes);
    free(circuit->name);
    free(circuit);
}

node_t *create_node(circuit_t *circuit, char *name, int num_inputs, int num_outputs) {
    node_t *node = &circuit->nodes[circuit->num_nodes++];
    node->id = circuit->num_nodes;
    node->name = strdup(name);
    node->num_inputs = num_inputs;
    node->num_outputs = num_outputs;
    node->inputs = malloc(sizeof(int) * num_inputs);
    node->outputs = malloc(sizeof(int) * num_outputs);
    return node;
}

void destroy_node(node_t *node) {
    free(node->name);
    free(node->inputs);
    free(node->outputs);
}

void connect_nodes(node_t *node1, node_t *node2, int input, int output) {
    node1->outputs[output] = node2->id;
    node2->inputs[input] = node1->id;
}

void print_circuit(circuit_t *circuit) {
    printf("Circuit: %s\n", circuit->name);
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = &circuit->nodes[i];
        printf("Node: %s\n", node->name);
        printf("  Inputs: ");
        for (int j = 0; j < node->num_inputs; j++) {
            printf("%d ", node->inputs[j]);
        }
        printf("\n");
        printf("  Outputs: ");
        for (int j = 0; j < node->num_outputs; j++) {
            printf("%d ", node->outputs[j]);
        }
        printf("\n");
    }
}

int main() {
    circuit_t *circuit = create_circuit("My Circuit");

    node_t *node1 = create_node(circuit, "Input 1", 0, 1);
    node_t *node2 = create_node(circuit, "Input 2", 0, 1);
    node_t *node3 = create_node(circuit, "AND Gate", 2, 1);
    node_t *node4 = create_node(circuit, "Output", 1, 0);

    connect_nodes(node1, node3, 0, 0);
    connect_nodes(node2, node3, 1, 0);
    connect_nodes(node3, node4, 0, 0);

    print_circuit(circuit);

    destroy_circuit(circuit);

    return 0;
}