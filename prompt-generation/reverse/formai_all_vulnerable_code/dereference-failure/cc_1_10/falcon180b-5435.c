//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MAX_COMPONENTS 1000
#define MAX_NODES 10000
#define MAX_EDGES 20000

typedef struct {
    int type;
    int value;
    int node1;
    int node2;
} Component;

typedef struct {
    int node;
    int next;
} Edge;

Component components[MAX_COMPONENTS];
Edge edges[MAX_EDGES];
int num_components;
int num_nodes;
int num_edges;
int *nodes;

void add_component(int type, int value, int node1, int node2) {
    components[num_components].type = type;
    components[num_components].value = value;
    components[num_components].node1 = node1;
    components[num_components].node2 = node2;
    num_components++;
}

void add_edge(int node1, int node2) {
    Edge edge;
    edge.node = node1;
    edge.next = nodes[node1];
    nodes[node1] = num_edges;
    edge.next = nodes[node2];
    nodes[node2] = num_edges;
    edges[num_edges++] = edge;
}

void create_graph() {
    int i, j, k;
    srand(time(NULL));
    num_components = 0;
    num_nodes = 0;
    num_edges = 0;
    nodes = malloc(MAX_NODES * sizeof(int));
    for (i = 0; i < MAX_NODES; i++) {
        nodes[i] = -1;
    }
    for (i = 0; i < 10; i++) {
        add_component(1, rand() % 1000, num_nodes, num_nodes + 1);
        num_nodes += 2;
    }
    for (i = 0; i < 20; i++) {
        j = rand() % num_nodes;
        k = rand() % num_nodes;
        while (k == j) {
            k = rand() % num_nodes;
        }
        add_edge(j, k);
    }
}

void simulate() {
    int i, j;
    for (i = 0; i < num_components; i++) {
        if (components[i].type == 1) {
            j = components[i].node1;
            while (j!= -1) {
                printf("%d ", j);
                j = nodes[j];
            }
            printf("\n");
        }
    }
}

int main() {
    create_graph();
    simulate();
    return 0;
}