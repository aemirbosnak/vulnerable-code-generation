//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_VALUE 1e9

// Structure to store circuit node information
typedef struct Node {
    int node_index; // Node Index
    char node_name[20]; // Node Name
    double value; // Node Value
} Node;

// Structure to store circuit
typedef struct Circuit {
    char name[20];
    Node nodes[MAX_NODES];
    int num_nodes;
} Circuit;

// Function to read circuit details from input file
Circuit* read_circuit(FILE* fp) {
    Circuit* circuit = malloc(sizeof(Circuit));
    
    // Initialize circuit details
    fscanf(fp, "%s", circuit->name);
    fscanf(fp, "%d", &circuit->num_nodes);
    for(int i=0; i<circuit->num_nodes; i++) {
        Node node;
        fscanf(fp, "%d %s %lf", &node.node_index, node.node_name, &node.value);
        circuit->nodes[i] = node;
    }
    return circuit;
}

// Function to print circuit details
void print_circuit(Circuit* circuit) {
    printf("Circuit Name: %s\n", circuit->name);
    printf("Number of Nodes: %d\n", circuit->num_nodes);
    printf("Nodes:\n");
    for(int i=0; i<circuit->num_nodes; i++) {
        Node node = circuit->nodes[i];
        printf("Node Index: %d, Node Name: %s, Node Value: %lf\n", node.node_index, node.node_name, node.value);
    }
}

// Function to simulate circuit
void simulate_circuit(Circuit* circuit) {
    double total_value = 0.0;
    for(int i=0; i<circuit->num_nodes; i++) {
        Node node = circuit->nodes[i];
        total_value += node.value;
    }
    printf("Total Circuit Value: %lf\n", total_value);
}

int main() {
    FILE* fp = fopen("circuit.txt", "r"); // Input file containing circuit details
    if(!fp) {
        printf("Error Opening File!\n");
        return 1;
    }
    Circuit* circuit = read_circuit(fp);
    fclose(fp);
    
    printf("Circuit Details:\n");
    print_circuit(circuit);
    
    printf("\nSimulating Circuit:\n");
    simulate_circuit(circuit);
    
    free(circuit);
    return 0;
}