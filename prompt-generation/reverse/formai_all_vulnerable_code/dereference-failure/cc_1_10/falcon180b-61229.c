//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000
#define MAX_EDGES 10000
#define PI 3.14159265358979323846

typedef struct {
    double value;
    int type;
} Component;

typedef struct {
    int node1;
    int node2;
    double resistance;
} Edge;

int num_components;
int num_nodes;
int num_edges;

Component *components;
Edge *edges;

void init() {
    srand(time(NULL));
    num_components = rand() % MAX_COMPONENTS + 1;
    num_nodes = rand() % MAX_NODES + 1;
    num_edges = rand() % MAX_EDGES + 1;

    components = (Component *) malloc(num_components * sizeof(Component));
    edges = (Edge *) malloc(num_edges * sizeof(Edge));

    for (int i = 0; i < num_components; i++) {
        components[i].value = rand() % 1000;
        components[i].type = rand() % 2;
    }

    for (int i = 0; i < num_edges; i++) {
        edges[i].node1 = rand() % num_nodes;
        edges[i].node2 = rand() % num_nodes;
        edges[i].resistance = rand() % 1000;
    }
}

void simulate() {
    for (int i = 0; i < num_edges; i++) {
        int node1 = edges[i].node1;
        int node2 = edges[i].node2;
        double resistance = edges[i].resistance;

        double voltage1 = 0;
        double voltage2 = 0;

        for (int j = 0; j < num_components; j++) {
            if (components[j].type == 0) {
                voltage1 += components[j].value;
            } else {
                voltage2 += components[j].value;
            }
        }

        double current = (voltage2 - voltage1) / resistance;

        printf("%d %d %f %f\n", node1, node2, voltage1, current);
    }
}

int main() {
    init();
    simulate();

    return 0;
}