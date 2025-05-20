//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int num_nodes;
    int num_edges;
    int** edges;
    int** node_values;
    bool* connected;
} Circuit;

void initialize_circuit(Circuit* circuit, int num_nodes, int num_edges) {
    circuit->num_nodes = num_nodes;
    circuit->num_edges = num_edges;
    circuit->edges = malloc(num_nodes * sizeof(int*));
    circuit->node_values = malloc(num_nodes * sizeof(int*));
    circuit->connected = malloc(num_nodes * sizeof(bool));

    for (int i = 0; i < num_nodes; i++) {
        circuit->edges[i] = malloc(num_edges * sizeof(int));
        circuit->node_values[i] = malloc(num_edges * sizeof(int));
        circuit->connected[i] = false;
    }
}

void add_edge(Circuit* circuit, int node1, int node2, int weight) {
    circuit->edges[node1][circuit->num_edges] = node2;
    circuit->edges[node2][circuit->num_edges] = node1;
    circuit->node_values[node1][circuit->num_edges] = weight;
    circuit->node_values[node2][circuit->num_edges] = weight;
    circuit->num_edges++;
}

void set_node_value(Circuit* circuit, int node, int value) {
    circuit->node_values[node][circuit->num_edges] = value;
}

int get_node_value(Circuit* circuit, int node) {
    return circuit->node_values[node][circuit->num_edges];
}

void set_connected(Circuit* circuit, int node1, int node2) {
    circuit->connected[node1] = true;
    circuit->connected[node2] = true;
}

bool is_connected(Circuit* circuit, int node1, int node2) {
    return circuit->connected[node1] && circuit->connected[node2];
}

void print_circuit(Circuit* circuit) {
    printf("Circuit with %d nodes and %d edges:\n", circuit->num_nodes, circuit->num_edges);
    printf("Node values:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("Node %d: %d\n", i, get_node_value(circuit, i));
    }
    printf("Edges:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < circuit->num_edges; j++) {
            printf("%d ", circuit->edges[i][j]);
        }
        printf("\n");
    }
    printf("Connected nodes:\n");
    for (int i = 0; i < circuit->num_nodes; i++) {
        if (circuit->connected[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num_nodes = 4;
    int num_edges = 5;

    Circuit circuit;
    initialize_circuit(&circuit, num_nodes, num_edges);

    add_edge(&circuit, 0, 1, 5);
    add_edge(&circuit, 0, 2, 3);
    add_edge(&circuit, 1, 2, 7);
    add_edge(&circuit, 1, 3, 2);
    add_edge(&circuit, 2, 3, 1);
    add_edge(&circuit, 3, 0, 4);
    set_node_value(&circuit, 0, 9);
    set_node_value(&circuit, 1, 1);
    set_node_value(&circuit, 2, 0);
    set_node_value(&circuit, 3, 2);

    print_circuit(&circuit);

    return 0;
}