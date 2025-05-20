//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_CONNECTIONS 10000

typedef struct {
    int num_nodes;
    int num_connections;
    int *nodes;
    int *connections;
} circuit;

circuit *create_circuit(int num_nodes, int num_connections) {
    circuit *c = malloc(sizeof(circuit));
    c->num_nodes = num_nodes;
    c->num_connections = num_connections;
    c->nodes = malloc(sizeof(int) * num_nodes);
    c->connections = malloc(sizeof(int) * num_connections);
    return c;
}

void destroy_circuit(circuit *c) {
    free(c->nodes);
    free(c->connections);
    free(c);
}

void connect_nodes(circuit *c, int node1, int node2) {
    c->connections[c->num_connections++] = node1;
    c->connections[c->num_connections++] = node2;
}

void print_circuit(circuit *c) {
    for (int i = 0; i < c->num_connections; i += 2) {
        printf("(%d, %d)\n", c->connections[i], c->connections[i + 1]);
    }
}

void simulate_circuit(circuit *c) {
    srand(time(NULL));

    for (int i = 0; i < c->num_nodes; i++) {
        c->nodes[i] = rand() % 2;
    }

    int num_iterations = 100;

    for (int i = 0; i < num_iterations; i++) {
        for (int j = 0; j < c->num_connections; j += 2) {
            int node1 = c->connections[j];
            int node2 = c->connections[j + 1];

            if (c->nodes[node1] == c->nodes[node2]) {
                c->nodes[node1] = 0;
                c->nodes[node2] = 0;
            } else {
                c->nodes[node1] = 1;
                c->nodes[node2] = 1;
            }
        }
    }

    for (int i = 0; i < c->num_nodes; i++) {
        printf("%d ", c->nodes[i]);
    }
    printf("\n");
}

int main() {
    circuit *c = create_circuit(100, 1000);

    for (int i = 0; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            connect_nodes(c, i, j);
        }
    }

    print_circuit(c);

    simulate_circuit(c);

    destroy_circuit(c);

    return 0;
}