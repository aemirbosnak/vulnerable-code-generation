//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the network topology information
typedef struct {
    int numNodes;
    int numLinks;
    int* nodes;
    int* links;
} NetworkTopology;

// Function to create a new network topology
NetworkTopology* createNetworkTopology(int numNodes, int numLinks) {
    NetworkTopology* topology = (NetworkTopology*)malloc(sizeof(NetworkTopology));
    topology->numNodes = numNodes;
    topology->numLinks = numLinks;
    topology->nodes = (int*)malloc(numNodes * sizeof(int));
    topology->links = (int*)malloc(numLinks * sizeof(int));
    return topology;
}

// Function to print the network topology
void printNetworkTopology(NetworkTopology* topology) {
    printf("Network Topology:\n");
    printf("Number of nodes: %d\n", topology->numNodes);
    printf("Number of links: %d\n", topology->numLinks);
    for (int i = 0; i < topology->numNodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < topology->numLinks; j++) {
            printf("%d ", topology->links[i * topology->numLinks + j]);
        }
        printf("\n");
    }
}

// Function to add a link between two nodes
void addLink(NetworkTopology* topology, int node1, int node2) {
    topology->links[node1 * topology->numLinks + node2] = 1;
}

// Function to remove a link between two nodes
void removeLink(NetworkTopology* topology, int node1, int node2) {
    topology->links[node1 * topology->numLinks + node2] = 0;
}

// Function to check if a link exists between two nodes
int linkExists(NetworkTopology* topology, int node1, int node2) {
    return topology->links[node1 * topology->numLinks + node2];
}

int main() {
    int numNodes = 4;
    int numLinks = 6;
    NetworkTopology* topology = createNetworkTopology(numNodes, numLinks);

    addLink(topology, 0, 1);
    addLink(topology, 1, 2);
    addLink(topology, 1, 3);
    addLink(topology, 2, 3);
    addLink(topology, 2, 4);
    addLink(topology, 3, 4);

    printNetworkTopology(topology);

    removeLink(topology, 1, 2);
    removeLink(topology, 3, 4);

    printNetworkTopology(topology);

    free(topology->nodes);
    free(topology->links);
    free(topology);

    return 0;
}