//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    char name[20];
    int degree;
    int *neighbors;
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes = 0;
int num_edges = 0;

void add_node(int id, char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached\n");
        exit(1);
    }
    nodes[num_nodes].id = id;
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].degree = 0;
    nodes[num_nodes].neighbors = (int *)malloc(MAX_EDGES * sizeof(int));
    num_nodes++;
}

void add_edge(int src, int dest, int weight) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached\n");
        exit(1);
    }
    edges[num_edges].src = src;
    edges[num_edges].dest = dest;
    edges[num_edges].weight = weight;
    nodes[src].degree++;
    nodes[dest].degree++;
    num_edges++;
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s (%d neighbors)\n", nodes[i].id, nodes[i].name, nodes[i].degree);
    }
}

void print_edges() {
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d (%d)\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

int main() {
    add_node(1, "Node 1");
    add_node(2, "Node 2");
    add_node(3, "Node 3");
    add_node(4, "Node 4");
    add_edge(1, 2, 10);
    add_edge(1, 3, 5);
    add_edge(2, 3, 15);
    add_edge(2, 4, 20);
    add_edge(3, 4, 25);
    print_nodes();
    print_edges();
    return 0;
}