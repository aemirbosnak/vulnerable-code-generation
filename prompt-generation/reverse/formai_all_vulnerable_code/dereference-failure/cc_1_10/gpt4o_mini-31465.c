//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_CONNECTIONS 10

typedef struct Node {
    char name[20];
    struct Node* connections[MAX_CONNECTIONS];
    int connection_count;
} Node;

typedef struct Graph {
    Node* nodes[MAX_NODES];
    int node_count;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->node_count = 0;
    return graph;
}

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->connection_count = 0;
    return newNode;
}

void addNode(Graph* graph, const char* name) {
    if (graph->node_count < MAX_NODES) {
        Node* newNode = createNode(name);
        graph->nodes[graph->node_count++] = newNode;
        printf("Gratefully added node: %s\n", name);
    } else {
        printf("Node limit reached! Can't add: %s\n", name);
    }
}

void addConnection(Graph* graph, const char* from, const char* to) {
    Node* fromNode = NULL;
    Node* toNode = NULL;

    for (int i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i]->name, from) == 0) {
            fromNode = graph->nodes[i];
        }
        if (strcmp(graph->nodes[i]->name, to) == 0) {
            toNode = graph->nodes[i];
        }
    }

    if (fromNode && toNode) {
        if (fromNode->connection_count < MAX_CONNECTIONS) {
            fromNode->connections[fromNode->connection_count++] = toNode;
            printf("Gratefully connected %s to %s\n", from, to);
        } else {
            printf("Connection limit reached for node: %s\n", from);
        }
    } else {
        printf("One or both nodes not found for connection: %s -> %s\n", from, to);
    }
}

void displayNetwork(Graph* graph) {
    printf("\nCurrent Network Topology:\n");
    for (int i = 0; i < graph->node_count; i++) {
        Node* node = graph->nodes[i];
        printf("Node %s is connected to: ", node->name);
        for (int j = 0; j < node->connection_count; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->node_count; i++) {
        free(graph->nodes[i]);
    }
    free(graph);
    printf("Gratefully cleaned up the network resources!\n");
}

int main() {
    Graph* network = createGraph();
    addNode(network, "Router1");
    addNode(network, "Switch1");
    addNode(network, "Router2");
    addNode(network, "PC1");
    addNode(network, "PC2");
    
    addConnection(network, "Router1", "Switch1");
    addConnection(network, "Switch1", "PC1");
    addConnection(network, "Switch1", "PC2");
    addConnection(network, "Router1", "Router2");

    displayNetwork(network);

    freeGraph(network);
    return 0;
}