//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_ELEMENTS 10000

typedef struct {
    int index;
    double value;
} node_t;

typedef struct {
    int index;
    double value;
    int n1;
    int n2;
} element_t;

node_t *nodes;
element_t *elements;
int num_nodes, num_elements;

void init() {
    nodes = (node_t *) malloc(MAX_NODES * sizeof(node_t));
    elements = (element_t *) malloc(MAX_ELEMENTS * sizeof(element_t));
    num_nodes = 0;
    num_elements = 0;
}

void add_node(int index, double value) {
    nodes[num_nodes].index = index;
    nodes[num_nodes].value = value;
    num_nodes++;
}

void add_element(int index, double value, int n1, int n2) {
    elements[num_elements].index = index;
    elements[num_elements].value = value;
    elements[num_elements].n1 = n1;
    elements[num_elements].n2 = n2;
    num_elements++;
}

void connect_nodes(int n1, int n2) {
    add_element(num_elements, 1.0, n1, n2);
    add_element(num_elements, 1.0, n2, n1);
}

void simulate() {
    for (int i = 0; i < num_elements; i++) {
        int n1 = elements[i].n1;
        int n2 = elements[i].n2;
        double value = elements[i].value;
        double v1 = nodes[n1].value;
        double v2 = nodes[n2].value;
        nodes[n1].value += value * (v2 - v1);
        nodes[n2].value += value * (v1 - v2);
    }
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: %lf\n", i, nodes[i].value);
    }
}

int main() {
    init();
    add_node(0, 5.0);
    add_node(1, 0.0);
    connect_nodes(0, 1);
    simulate();
    print_nodes();
    return 0;
}