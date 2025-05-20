//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    char name[20];
    int id;
    int degree;
    int *neighbors;
} Node;

typedef struct {
    int src;
    int dest;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

int num_nodes = 0;
int num_edges = 0;

void add_node(char *name) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            printf("Node %s already exists.\n", name);
            return;
        }
    }
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].id = num_nodes;
    nodes[num_nodes].degree = 0;
    nodes[num_nodes].neighbors = NULL;
    num_nodes++;
}

void add_edge(int src, int dest) {
    Edge *e = &edges[num_edges];
    e->src = src;
    e->dest = dest;
    num_edges++;
}

void connect_nodes(int src, int dest) {
    nodes[src].degree++;
    nodes[dest].degree++;
    Node **neighbors = realloc(nodes[src].neighbors, sizeof(Node *) * nodes[src].degree);
    if (neighbors == NULL) {
        printf("Out of memory.\n");
        exit(1);
    }
    nodes[src].neighbors = neighbors;
    neighbors[nodes[src].degree - 1] = &nodes[dest];
}

void print_node(Node *n) {
    printf("%s (%d)\n", n->name, n->id);
}

void print_nodes() {
    int i;
    for (i = 0; i < num_nodes; i++) {
        print_node(&nodes[i]);
    }
}

void print_edge(Edge *e) {
    printf("(%d, %d)\n", e->src, e->dest);
}

void print_edges() {
    int i;
    for (i = 0; i < num_edges; i++) {
        print_edge(&edges[i]);
    }
}

int main() {
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    connect_nodes(0, 1);
    connect_nodes(0, 2);
    connect_nodes(1, 2);
    connect_nodes(2, 0);
    connect_nodes(2, 3);
    print_nodes();
    print_edges();
    return 0;
}