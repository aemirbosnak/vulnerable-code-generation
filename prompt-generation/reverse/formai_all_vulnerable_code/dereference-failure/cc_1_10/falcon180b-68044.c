//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    char name[10];
    int id;
    int degree;
    int* neighbors;
} Node;

typedef struct {
    int node1;
    int node2;
    int weight;
} Edge;

void initialize(Node* nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        nodes[i].degree = 0;
        nodes[i].neighbors = (int*) malloc(sizeof(int) * MAX_EDGES);
    }
}

void add_edge(Edge* edges, int num_edges, int node1, int node2, int weight) {
    for (int i = 0; i < num_edges; i++) {
        if (edges[i].node1 == node1 && edges[i].node2 == node2) {
            edges[i].weight = weight;
            return;
        }
    }
    edges[num_edges].node1 = node1;
    edges[num_edges].node2 = node2;
    edges[num_edges].weight = weight;
    num_edges++;
}

void print_nodes(Node* nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%s (%d)\n", nodes[i].name, nodes[i].id);
    }
}

void print_edges(Edge* edges, int num_edges) {
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d (%d)\n", edges[i].node1, edges[i].node2, edges[i].weight);
    }
}

int main() {
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];

    initialize(nodes, 5);
    add_edge(edges, 0, 0, 1, 5);
    add_edge(edges, 1, 1, 2, 3);
    add_edge(edges, 2, 2, 3, 1);
    add_edge(edges, 3, 3, 4, 2);
    add_edge(edges, 4, 4, 0, 4);

    print_nodes(nodes, 5);
    print_edges(edges, 5);

    return 0;
}