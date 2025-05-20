//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NODES 100 // Maximum number of nodes in the network
#define MAX_NEIGHBORS 10 // Maximum number of neighboring nodes for each node

int nodes[MAX_NODES][MAX_NEIGHBORS]; // 2D array to store the network topology
int numNodes = 0; // Global variable to keep track of number of nodes in the network

void addNode(int nodeId, int numNeighbors, int *neighbors){
    int i;

    if(nodeId < 0 || nodeId >= MAX_NODES){
        printf("Invalid node id!\n");
        return;
    }

    if(numNeighbors < 0 || numNeighbors > MAX_NEIGHBORS){
        printf("Invalid number of neighbors!\n");
        return;
    }

    for(i = 0; i < numNeighbors; i++){
        if(neighbors[i] < 0 || neighbors[i] >= MAX_NODES || neighbors[i] == nodeId){
            printf("Invalid neighbor id!\n");
            return;
        }
    }

    memcpy(nodes[nodeId], neighbors, numNeighbors * sizeof(int)); // Copy the neighbors array to the nodes 2D array
    nodes[nodeId][numNeighbors] = -1; // Mark the end of neighbors array
    numNodes++; // Increment the number of nodes in the network
}

void printTopology(){
    int i, j;

    printf("\nNetwork Topology:\n");
    for(i = 0; i < numNodes; i++){
        printf("Node %d neighbors: ", i);
        for(j = 0; nodes[i][j] != -1; j++){
            printf("%d ", nodes[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int nodeId, numNeighbors, *neighbors, i, j;

    nodeId = 0;
    numNeighbors = 2;
    neighbors = (int *) malloc(numNeighbors * sizeof(int));
    neighbors[0] = 1;
    neighbors[1] = 2;
    addNode(nodeId, numNeighbors, neighbors);

    nodeId = 1;
    numNeighbors = 1;
    neighbors = (int *) malloc(numNeighbors * sizeof(int));
    neighbors[0] = 0;
    addNode(nodeId, numNeighbors, neighbors);

    nodeId = 2;
    numNeighbors = 2;
    neighbors = (int *) malloc(numNeighbors * sizeof(int));
    neighbors[0] = 0;
    neighbors[1] = 3;
    addNode(nodeId, numNeighbors, neighbors);

    nodeId = 3;
    numNeighbors = 1;
    neighbors = (int *) malloc(numNeighbors * sizeof(int));
    neighbors[0] = 2;
    addNode(nodeId, numNeighbors, neighbors);

    printTopology();

    return 0;
}