//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_RESISTORS 200

struct resistor {
    int node1;
    int node2;
    double resistance;
    struct resistor *next;
};

int num_resistors;
struct resistor *resistor_list[MAX_RESISTORS];
double node_voltage[MAX_NODES];

void add_resistor(int node1, int node2, double resistance) {
    struct resistor *r = malloc(sizeof(struct resistor));
    r->node1 = node1;
    r->node2 = node2;
    r->resistance = resistance;
    r->next = resistor_list[num_resistors];
    resistor_list[num_resistors++] = r;
}

void calculate_node_voltage(int node) {
    double new_voltage = 0;
    struct resistor *r = resistor_list[node];
    while (r != NULL) {
        int other_node = (r->node1 == node) ? r->node2 : r->node1;
        new_voltage += node_voltage[other_node] / r->resistance;
        r = r->next;
    }
    node_voltage[node] = new_voltage;
}

int main() {
    int num_nodes = 4;
    node_voltage[0] = 10;
    node_voltage[1] = 5;
    add_resistor(0, 1, 2);
    add_resistor(0, 2, 4);
    add_resistor(1, 2, 3);
    add_resistor(1, 3, 1);
    add_resistor(2, 3, 2);
    for (int i = 0; i < num_nodes; i++) {
        calculate_node_voltage(i);
    }
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %f\n", i, node_voltage[i]);
    }
    return 0;
}