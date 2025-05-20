//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

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
    int src_node;
    int dst_node;
} edge_t;

typedef struct {
    int num_nodes;
    int num_edges;
    node_t *nodes;
    edge_t *edges;
} circuit_t;

circuit_t *circuit_new() {
    circuit_t *circuit = malloc(sizeof(circuit_t));
    circuit->num_nodes = 0;
    circuit->num_edges = 0;
    circuit->nodes = malloc(MAX_NODES * sizeof(node_t));
    circuit->edges = malloc(MAX_EDGES * sizeof(edge_t));
    return circuit;
}

void circuit_free(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        free(circuit->nodes[i].name);
        free(circuit->nodes[i].inputs);
        free(circuit->nodes[i].outputs);
    }
    for (int i = 0; i < circuit->num_edges; i++) {
        free(circuit->edges[i].name);
    }
    free(circuit->nodes);
    free(circuit->edges);
    free(circuit);
}

node_t *circuit_add_node(circuit_t *circuit, char *name, int num_inputs, int num_outputs) {
    if (circuit->num_nodes == MAX_NODES) {
        fprintf(stderr, "Error: Too many nodes\n");
        return NULL;
    }
    node_t *node = &circuit->nodes[circuit->num_nodes++];
    node->id = circuit->num_nodes;
    node->name = strdup(name);
    node->num_inputs = num_inputs;
    node->num_outputs = num_outputs;
    node->inputs = malloc(num_inputs * sizeof(int));
    node->outputs = malloc(num_outputs * sizeof(int));
    return node;
}

edge_t *circuit_add_edge(circuit_t *circuit, char *name, int src_node, int dst_node) {
    if (circuit->num_edges == MAX_EDGES) {
        fprintf(stderr, "Error: Too many edges\n");
        return NULL;
    }
    edge_t *edge = &circuit->edges[circuit->num_edges++];
    edge->id = circuit->num_edges;
    edge->name = strdup(name);
    edge->src_node = src_node;
    edge->dst_node = dst_node;
    return edge;
}

void circuit_print(circuit_t *circuit) {
    printf("Circuit:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = &circuit->nodes[i];
        printf("Node %d: %s (%d inputs, %d outputs)\n", node->id, node->name, node->num_inputs, node->num_outputs);
        for (int j = 0; j < node->num_inputs; j++) {
            printf("    Input %d: %d\n", j, node->inputs[j]);
        }
        for (int j = 0; j < node->num_outputs; j++) {
            printf("    Output %d: %d\n", j, node->outputs[j]);
        }
    }
    for (int i = 0; i < circuit->num_edges; i++) {
        edge_t *edge = &circuit->edges[i];
        printf("Edge %d: %s (%d -> %d)\n", edge->id, edge->name, edge->src_node, edge->dst_node);
    }
}

int main() {
    circuit_t *circuit = circuit_new();

    node_t *node1 = circuit_add_node(circuit, "Input A", 0, 1);
    node_t *node2 = circuit_add_node(circuit, "Input B", 0, 1);
    node_t *node3 = circuit_add_node(circuit, "AND", 2, 1);
    node_t *node4 = circuit_add_node(circuit, "Output", 1, 0);

    circuit_add_edge(circuit, "Edge 1", node1->id, node3->id);
    circuit_add_edge(circuit, "Edge 2", node2->id, node3->id);
    circuit_add_edge(circuit, "Edge 3", node3->id, node4->id);

    circuit_print(circuit);

    circuit_free(circuit);

    return 0;
}