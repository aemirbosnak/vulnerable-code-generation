//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: configurable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_COMPONENTS 1000
#define MAX_NODES 10000
#define MAX_EDGES 100000

typedef struct node {
    int num;
    double voltage;
    int *edges;
    int num_edges;
} Node;

typedef struct edge {
    int start_node;
    int end_node;
    double resistance;
} Edge;

Node *nodes;
Edge *edges;
int num_nodes;
int num_edges;

void init() {
    num_nodes = 0;
    num_edges = 0;
    nodes = (Node *)malloc(MAX_NODES * sizeof(Node));
    edges = (Edge *)malloc(MAX_EDGES * sizeof(Edge));
}

void add_node() {
    num_nodes++;
}

void add_edge(int start_node, int end_node, double resistance) {
    num_edges++;
    edges[num_edges - 1].start_node = start_node;
    edges[num_edges - 1].end_node = end_node;
    edges[num_edges - 1].resistance = resistance;
}

void solve() {
    int i, j;
    double current;

    for (i = 0; i < num_nodes; i++) {
        nodes[i].voltage = 0.0;
    }

    for (i = 0; i < num_edges; i++) {
        current = (nodes[edges[i].end_node].voltage - nodes[edges[i].start_node].voltage) / edges[i].resistance;
        nodes[edges[i].start_node].voltage -= current * edges[i].resistance;
        nodes[edges[i].end_node].voltage += current * edges[i].resistance;
    }
}

void print_solution(int node_num) {
    printf("Node %d voltage: %lf\n", node_num, nodes[node_num].voltage);
}

int main() {
    init();

    add_node();
    add_node();
    add_node();

    add_edge(0, 1, 100.0);
    add_edge(1, 2, 200.0);

    solve();

    print_solution(0);
    print_solution(1);
    print_solution(2);

    return 0;
}