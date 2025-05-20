//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 1024
#define MAX_EDGES 2048

typedef uint32_t node_id_t;
typedef uint32_t edge_id_t;

typedef struct {
    node_id_t id;
    char *name;
    bool is_input;
    bool is_output;
    uint32_t num_inputs;
    uint32_t num_outputs;
    node_id_t *inputs;
    node_id_t *outputs;
} node_t;

typedef struct {
    edge_id_t id;
    node_id_t src_id;
    node_id_t dst_id;
    bool is_directed;
    uint32_t weight;
} edge_t;

typedef struct {
    uint32_t num_nodes;
    node_t *nodes;
    
    uint32_t num_edges;
    edge_t *edges;
} circuit_t;

void circuit_init(circuit_t *circuit) {
    circuit->num_nodes = 0;
    circuit->nodes = malloc(sizeof(node_t) * MAX_NODES);
    
    circuit->num_edges = 0;
    circuit->edges = malloc(sizeof(edge_t) * MAX_EDGES);
}

void circuit_free(circuit_t *circuit) {
    for (int i = 0; i < circuit->num_nodes; i++) {
        free(circuit->nodes[i].name);
    }
    free(circuit->nodes);
    
    free(circuit->edges);
}

node_id_t circuit_add_node(circuit_t *circuit, char *name, bool is_input, bool is_output) {
    node_t *node = &circuit->nodes[circuit->num_nodes++];
    node->id = circuit->num_nodes - 1;
    node->name = strdup(name);
    node->is_input = is_input;
    node->is_output = is_output;
    node->num_inputs = 0;
    node->num_outputs = 0;
    node->inputs = NULL;
    node->outputs = NULL;
    return node->id;
}

edge_id_t circuit_add_edge(circuit_t *circuit, node_id_t src_id, node_id_t dst_id, bool is_directed, uint32_t weight) {
    edge_t *edge = &circuit->edges[circuit->num_edges++];
    edge->id = circuit->num_edges - 1;
    edge->src_id = src_id;
    edge->dst_id = dst_id;
    edge->is_directed = is_directed;
    edge->weight = weight;
    return edge->id;
}

void circuit_print(circuit_t *circuit) {
    printf("Circuit has %d nodes and %d edges:\n", circuit->num_nodes, circuit->num_edges);
    for (int i = 0; i < circuit->num_nodes; i++) {
        node_t *node = &circuit->nodes[i];
        printf("Node %d: %s (", node->id, node->name);
        if (node->is_input) {
            printf("input");
        }
        if (node->is_output) {
            printf("output");
        }
        printf(")\n");
        for (int j = 0; j < node->num_inputs; j++) {
            printf("  Input %d: %s\n", j, circuit->nodes[node->inputs[j]].name);
        }
        for (int j = 0; j < node->num_outputs; j++) {
            printf("  Output %d: %s\n", j, circuit->nodes[node->outputs[j]].name);
        }
    }
    for (int i = 0; i < circuit->num_edges; i++) {
        edge_t *edge = &circuit->edges[i];
        printf("Edge %d: %s -> %s (", edge->id, circuit->nodes[edge->src_id].name, circuit->nodes[edge->dst_id].name);
        if (edge->is_directed) {
            printf("directed");
        }
        printf(")\n");
    }
}

int main() {
    circuit_t circuit;
    circuit_init(&circuit);
    
    node_id_t input_a_id = circuit_add_node(&circuit, "Input A", true, false);
    node_id_t input_b_id = circuit_add_node(&circuit, "Input B", true, false);
    node_id_t output_id = circuit_add_node(&circuit, "Output", false, true);
    
    edge_id_t edge_a_to_output_id = circuit_add_edge(&circuit, input_a_id, output_id, true, 1);
    edge_id_t edge_b_to_output_id = circuit_add_edge(&circuit, input_b_id, output_id, true, 1);
    
    circuit_print(&circuit);
    
    circuit_free(&circuit);
    
    return 0;
}