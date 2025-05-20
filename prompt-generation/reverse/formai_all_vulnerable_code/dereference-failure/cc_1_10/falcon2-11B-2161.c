//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for a node
typedef struct {
    int isFilled;
} Node;

// Function to print the state of the simulation
void printState(Node* nodes, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        printf("%d ", nodes[i].isFilled);
    }
    printf("\n");
}

// Function to fill a random node
void fillNode(Node* nodes, int numNodes) {
    int randIndex = rand() % numNodes;
    nodes[randIndex].isFilled = 1;
}

// Function to run the simulation
void runSimulation(Node* nodes, int numNodes, int maxIterations) {
    srand(time(NULL));
    int numFilledNodes = 0;
    int numIterations = 0;

    while (numFilledNodes < numNodes && numIterations < maxIterations) {
        fillNode(nodes, numNodes);
        numFilledNodes++;
        numIterations++;
    }

    printf("Simulation complete after %d iterations.\n", numIterations);
    printState(nodes, numNodes);
}

int main() {
    int numNodes = 100;
    int maxIterations = 1000;

    // Allocate memory for the nodes
    Node* nodes = (Node*) malloc(numNodes * sizeof(Node));

    // Run the simulation
    runSimulation(nodes, numNodes, maxIterations);

    // Free the allocated memory
    free(nodes);

    return 0;
}