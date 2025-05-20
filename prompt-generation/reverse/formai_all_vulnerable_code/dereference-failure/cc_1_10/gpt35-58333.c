//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CIRCUITS 10
#define MAX_NODES 100

// Data structure to represent a circuit node
typedef struct Node {
    int id;
    int value;
} Node;

// Data structure to represent a circuit
typedef struct Circuit {
    int id;
    int numNodes;
    Node nodes[MAX_NODES];
    int numConnections;
    int connections[MAX_NODES][2];
} Circuit;

// Global variables
Circuit circuits[MAX_CIRCUITS];
int numCircuits = 0;

// Function to create a new node with given id and value
Node *newNode(int id, int value) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->id = id;
    node->value = value;
    return node;
}

// Function to create a new circuit with given id
Circuit *newCircuit(int id) {
    Circuit *circuit = (Circuit*) malloc(sizeof(Circuit));
    circuit->id = id;
    circuit->numNodes = 0;
    circuit->numConnections = 0;
    return circuit;
}

// Function to add a node to a circuit
void addNode(Circuit *circuit, Node *node) {
    circuit->nodes[circuit->numNodes++] = *node;
}

// Function to add a connection between two nodes
void addConnection(Circuit *circuit, int node1, int node2) {
    circuit->connections[circuit->numConnections][0] = node1;
    circuit->connections[circuit->numConnections][1] = node2;
    circuit->numConnections++;
}

// Function to simulate a circuit
void simulate(Circuit *circuit) {
    for (int i = 0; i < circuit->numNodes; i++) {
        Node *node = &circuit->nodes[i];
        for (int j = 0; j < circuit->numConnections; j++) {
            if (circuit->connections[j][0] == node->id) {
                int otherNodeId = circuit->connections[j][1];
                Node *otherNode = &circuit->nodes[otherNodeId];
                if (otherNode->value != node->value) {
                    printf("Circuit %d: Nodes %d and %d are in conflict!\n", circuit->id, node->id, otherNodeId);
                }
            }
        }
    }
}

// Main function to run the program
int main() {
    // Create two circuits
    Circuit *circuit1 = newCircuit(0);
    Circuit *circuit2 = newCircuit(1);

    // Add nodes to circuit 1
    addNode(circuit1, newNode(0, 1));
    addNode(circuit1, newNode(1, 0));
    addNode(circuit1, newNode(2, 1));
    addNode(circuit1, newNode(3, 0));

    // Add nodes to circuit 2
    addNode(circuit2, newNode(0, 1));
    addNode(circuit2, newNode(1, 0));
    addNode(circuit2, newNode(2, 0));
    addNode(circuit2, newNode(3, 1));

    // Add connections to circuit 1
    addConnection(circuit1, 0, 1);
    addConnection(circuit1, 0, 2);
    addConnection(circuit1, 1, 2);
    addConnection(circuit1, 2, 3);

    // Add connections to circuit 2
    addConnection(circuit2, 0, 1);
    addConnection(circuit2, 0, 2);
    addConnection(circuit2, 1, 2);
    addConnection(circuit2, 2, 3);

    // Add the circuits to the global array
    circuits[numCircuits++] = *circuit1;
    circuits[numCircuits++] = *circuit2;

    // Simulate the circuits
    for (int i = 0; i < numCircuits; i++) {
        simulate(&circuits[i]);
    }

    return 0;
}