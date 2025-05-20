//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of nodes in the network
#define NUM_NODES 5

// Define the adjacency list for the network
typedef struct Node {
    struct Node* next;
    int node_id;
} Node;

// Create a network topology mapper
void map_topology(Node** graph) {
    int i, j;
    for (i = 0; i < NUM_NODES; i++) {
        for (j = 0; j < NUM_NODES; j++) {
            if (i != j && graph[i] && graph[j]) {
                printf("%d - %d\n", graph[i]->node_id, graph[j]->node_id);
            }
        }
    }
}

int main() {
    // Create an adjacency list for the network
    Node** graph = (Node**)malloc(NUM_NODES * sizeof(Node*));
    for (int i = 0; i < NUM_NODES; i++) {
        graph[i] = NULL;
    }

    // Add nodes to the adjacency list
    graph[0] = (Node*)malloc(sizeof(Node));
    graph[0]->node_id = 0;
    graph[0]->next = graph[1];

    graph[1] = (Node*)malloc(sizeof(Node));
    graph[1]->node_id = 1;
    graph[1]->next = graph[2];

    graph[2] = (Node*)malloc(sizeof(Node));
    graph[2]->node_id = 2;
    graph[2]->next = graph[3];

    graph[3] = (Node*)malloc(sizeof(Node));
    graph[3]->node_id = 3;
    graph[3]->next = graph[4];

    graph[4] = (Node*)malloc(sizeof(Node));
    graph[4]->node_id = 4;

    // Map the network topology
    map_topology(graph);

    return 0;
}