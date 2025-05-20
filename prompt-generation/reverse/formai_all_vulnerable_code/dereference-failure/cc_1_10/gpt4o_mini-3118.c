//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node {
    char name[50];
    struct Node* connections[MAX_NODES];
    int connection_count;
} Node;

Node* create_node(const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->connection_count = 0;
    return new_node;
}

void connect_nodes(Node* node1, Node* node2) {
    if (node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1; // Bidirectional connection
    } else {
        printf("Connection limit reached for nodes %s or %s\n", node1->name, node2->name);
    }
}

void display_connections(Node* node) {
    printf("Node %s is connected to:\n", node->name);
    for (int i = 0; i < node->connection_count; i++) {
        printf(" - %s\n", node->connections[i]->name);
    }
}

void free_nodes(Node* nodes[], int count) {
    for (int i = 0; i < count; i++) {
        free(nodes[i]);
    }
}

int main() {
    Node* nodes[MAX_NODES];
    int node_count = 0;

    printf("Welcome to the C Network Topology Mapper.\n");
    printf("Creating network topology...\n");

    // Create some nodes
    nodes[node_count++] = create_node("Router1");
    nodes[node_count++] = create_node("Switch1");
    nodes[node_count++] = create_node("Server1");
    nodes[node_count++] = create_node("PC1");
    nodes[node_count++] = create_node("PC2");

    // Connect nodes
    connect_nodes(nodes[0], nodes[1]); // Router1 <-> Switch1
    connect_nodes(nodes[1], nodes[2]); // Switch1 <-> Server1
    connect_nodes(nodes[1], nodes[3]); // Switch1 <-> PC1
    connect_nodes(nodes[1], nodes[4]); // Switch1 <-> PC2

    // Display the connections
    for (int i = 0; i < node_count; i++) {
        display_connections(nodes[i]);
    }

    // Free allocated memory
    free_nodes(nodes, node_count);
    
    printf("Network topology mapping complete. Exiting...\n");
    return 0;
}