//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    int degree; // number of edges connected to this node
    int *neighbors; // array of neighbor nodes
    int *edgeWeights; // array of edge weights
} Node;

typedef struct {
    int node1;
    int node2;
    int weight;
} Edge;

void initGraph(Node *nodes, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        nodes[i].id = i;
        nodes[i].degree = 0;
        nodes[i].neighbors = NULL;
        nodes[i].edgeWeights = NULL;
    }
}

void addEdge(Node *nodes, int numNodes, int node1, int node2, int weight) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->node1 = node1;
    edge->node2 = node2;
    edge->weight = weight;
    nodes[node1].neighbors = (int *) realloc(nodes[node1].neighbors, (nodes[node1].degree + 1) * sizeof(int));
    nodes[node1].neighbors[nodes[node1].degree] = node2;
    nodes[node1].degree++;
    nodes[node2].neighbors = (int *) realloc(nodes[node2].neighbors, (nodes[node2].degree + 1) * sizeof(int));
    nodes[node2].neighbors[nodes[node2].degree] = node1;
    nodes[node2].degree++;
}

void printGraph(Node *nodes, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d:\n", i);
        printf("Neighbors: ");
        for (int j = 0; j < nodes[i].degree; j++) {
            printf("%d ", nodes[i].neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    Node nodes[MAX_NODES];
    int numNodes = 5;
    initGraph(nodes, numNodes);
    
    addEdge(nodes, numNodes, 0, 1, 10);
    addEdge(nodes, numNodes, 1, 2, 5);
    addEdge(nodes, numNodes, 2, 3, 15);
    addEdge(nodes, numNodes, 3, 4, 20);
    
    printGraph(nodes, numNodes);
    
    return 0;
}