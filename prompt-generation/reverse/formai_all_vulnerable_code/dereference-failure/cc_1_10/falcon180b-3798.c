//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000
#define MAX_EDGES 2000
#define PI 3.14159265358979323846

typedef struct {
    double value;
    int node1;
    int node2;
} Edge;

typedef struct {
    double value;
    int node;
} Node;

void add_edge(Edge* edges, int num_edges, int node1, int node2, double value) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        exit(1);
    }
    edges[num_edges].value = value;
    edges[num_edges].node1 = node1;
    edges[num_edges].node2 = node2;
    num_edges++;
}

void add_node(Node* nodes, int num_nodes, double value, int node) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }
    nodes[num_nodes].value = value;
    nodes[num_nodes].node = node;
    num_nodes++;
}

void simulate_circuit(Edge* edges, int num_edges, Node* nodes, int num_nodes) {
    double* voltages = malloc(num_nodes * sizeof(double));
    memset(voltages, 0, num_nodes * sizeof(double));

    for (int i = 0; i < num_edges; i++) {
        int node1 = edges[i].node1;
        int node2 = edges[i].node2;
        double resistance = edges[i].value;

        double current = (voltages[node1] - voltages[node2]) / resistance;
        voltages[node1] -= current;
        voltages[node2] += current;
    }

    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %.2f V\n", i, voltages[i]);
    }

    free(voltages);
}

int main() {
    Edge edges[MAX_EDGES];
    Node nodes[MAX_NODES];
    int num_edges = 0;
    int num_nodes = 0;

    add_node(nodes, num_nodes, 5.0, 0);
    add_node(nodes, num_nodes, 0.0, 1);
    add_edge(edges, num_edges, 0, 1, 100.0);

    simulate_circuit(edges, num_edges, nodes, num_nodes);

    return 0;
}