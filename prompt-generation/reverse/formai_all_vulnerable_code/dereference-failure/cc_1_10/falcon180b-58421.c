//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 200
#define MAX_EDGES 400

typedef struct {
    int type;
    int value;
    int node1;
    int node2;
} Component;

int num_components = 0;
Component components[MAX_COMPONENTS];

int num_nodes = 0;
int *nodes;

int num_edges = 0;
int *edges;

int add_node(int value) {
    nodes = (int *)realloc(nodes, sizeof(int) * ++num_nodes);
    nodes[num_nodes - 1] = value;
    return num_nodes - 1;
}

int add_edge(int node1, int node2) {
    edges = (int *)realloc(edges, sizeof(int) * ++num_edges);
    edges[num_edges - 1] = node1;
    edges[num_edges] = node2;
    return num_edges - 1;
}

int add_component(int type, int value, int node1, int node2) {
    components[num_components].type = type;
    components[num_components].value = value;
    components[num_components].node1 = node1;
    components[num_components].node2 = node2;
    return num_components++;
}

int main() {
    int i, j, k;

    // Add components
    add_component(1, 100, add_node(0), add_node(1));
    add_component(2, 100, add_node(1), add_node(2));
    add_component(3, 100, add_node(2), add_node(0));

    // Add edges
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 0);

    for (i = 0; i < num_components; i++) {
        for (j = 0; j < num_nodes; j++) {
            if (components[i].node1 == j) {
                k = add_node(components[i].value);
                add_edge(j, k);
                add_edge(k, components[i].node2);
            } else if (components[i].node2 == j) {
                k = add_node(components[i].value);
                add_edge(components[i].node1, k);
                add_edge(j, k);
            }
        }
    }

    for (i = 0; i < num_edges; i++) {
        printf("%d -> %d\n", edges[i], edges[i + 1]);
    }

    return 0;
}