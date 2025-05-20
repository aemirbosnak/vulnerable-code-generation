//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256
#define MAX_CIRCUIT 25
#define MAX_NODES 10

typedef struct node {
    int id; // node id
    int gnd; // ground flag
    double voltage; //n node voltage
    double current; // node current
} Node;

typedef struct circuit {
    int num_nodes; // number of nodes in the circuit
    Node nodes[MAX_NODES]; // list of nodes in the circuit
} Circuit;

void init_node(Node *node, int id, int gnd) {
    node->id = id;
    node->gnd = gnd;
    node->voltage = 0.0;
    node->current = 0.0;
}

Circuit *parse_circuit(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE];
    /* read number of nodes, initialize circuit */
    fgets(line, MAX_LINE, fp);
    int num_nodes = atoi(line);
    if (num_nodes > MAX_NODES) {
        printf("Error: too many nodes in circuit.\n");
        exit(EXIT_FAILURE);
    }
    Circuit *circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->num_nodes = num_nodes;

    /* parse node data from file */
    for (int i = 0; i < num_nodes; i++) {
        fgets(line, MAX_LINE, fp);
        char *token = strtok(line, " ");
        int id = atoi(token);
        token = strtok(NULL, " ");
        int gnd = atoi(token);
        init_node(&circuit->nodes[i], id, gnd);
    }
    fclose(fp);
    return circuit;
}

void print_circuit(Circuit *circuit) {
    printf("Circuit with %d nodes:\n", circuit->num_nodes);
    for (int i = 0; i < circuit->num_nodes; i++) {
        Node *node = &circuit->nodes[i];
        printf("Node %d (", node->id);
        if (node->gnd) {
            printf("ground");
        } else {
            printf("voltage=%.1f, current=%.3f", node->voltage, node->current);
        }
        printf(")\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Circuit *circuit = parse_circuit(argv[1]);

    print_circuit(circuit);

    free(circuit);
    return 0;
}