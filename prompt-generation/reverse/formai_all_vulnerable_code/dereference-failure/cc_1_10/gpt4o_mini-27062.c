//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_NAME_LENGTH 20

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node *connections[MAX_NODES];
    int connection_count;
} Node;

Node* create_node(const char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->connection_count = 0;
    return new_node;
}

void add_connection(Node *node1, Node *node2) {
    if (node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1; // Bi-directional
    } else {
        printf("Connection limit reached for one of the nodes.\n");
    }
}

void print_topology(Node *nodes[], int node_count) {
    printf("Network Topology: \n");
    for (int i = 0; i < node_count; i++) {
        Node *node = nodes[i];
        printf("Node %s is connected to: ", node->name);
        for (int j = 0; j < node->connection_count; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void free_nodes(Node *nodes[], int node_count) {
    for (int i = 0; i < node_count; i++) {
        free(nodes[i]);
    }
}

int main() {
    Node *network[MAX_NODES];
    int node_count = 0;

    // Creating nodes
    network[node_count++] = create_node("Router");
    network[node_count++] = create_node("Switch1");
    network[node_count++] = create_node("Switch2");
    network[node_count++] = create_node("PC1");
    network[node_count++] = create_node("PC2");
    network[node_count++] = create_node("Server");

    // Establishing connections
    add_connection(network[0], network[1]); // Router <-> Switch1
    add_connection(network[0], network[2]); // Router <-> Switch2
    add_connection(network[1], network[3]); // Switch1 <-> PC1
    add_connection(network[1], network[4]); // Switch1 <-> PC2
    add_connection(network[2], network[5]); // Switch2 <-> Server

    // Print the network topology
    print_topology(network, node_count);

    // Free allocated memory
    free_nodes(network, node_count);
    
    return 0;
}