//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 50

typedef struct Node {
    char name[MAX_NAME_LEN];
    struct Node *connections[MAX_NODES];
    int connection_count;
} Node;

typedef struct Network {
    Node *nodes[MAX_NODES];
    int node_count;
} Network;

Network* create_network() {
    Network *network = malloc(sizeof(Network));
    network->node_count = 0;
    return network;
}

Node* create_node(const char *name) {
    Node *node = malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LEN);
    node->connection_count = 0;
    return node;
}

void add_node(Network *network, const char *name) {
    if (network->node_count < MAX_NODES) {
        Node *node = create_node(name);
        network->nodes[network->node_count++] = node;
        printf("Node '%s' added to the network.\n", name);
    } else {
        printf("Network capacity reached. Unable to add node '%s'.\n", name);
    }
}

void connect_nodes(Network *network, const char *name1, const char *name2) {
    Node *node1 = NULL;
    Node *node2 = NULL;

    for (int i = 0; i < network->node_count; i++) {
        if (strcmp(network->nodes[i]->name, name1) == 0) {
            node1 = network->nodes[i];
        }
        if (strcmp(network->nodes[i]->name, name2) == 0) {
            node2 = network->nodes[i];
        }
    }

    if (node1 && node2) {
        if (node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
            node1->connections[node1->connection_count++] = node2;
            node2->connections[node2->connection_count++] = node1; // bidirectional
            printf("Connected '%s' with '%s'.\n", name1, name2);
        } else {
            printf("One of the nodes has reached connection limit.\n");
        }
    } else {
        printf("Unable to connect: One or both nodes not found.\n");
    }
}

void display_network(Network *network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node *node = network->nodes[i];
        printf("%s: ", node->name);
        for (int j = 0; j < node->connection_count; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void free_network(Network *network) {
    for (int i = 0; i < network->node_count; i++) {
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    Network *network = create_network();
    
    add_node(network, "Router");
    add_node(network, "Switch");
    add_node(network, "Server");
    add_node(network, "Client1");
    add_node(network, "Client2");

    connect_nodes(network, "Router", "Switch");
    connect_nodes(network, "Switch", "Server");
    connect_nodes(network, "Switch", "Client1");
    connect_nodes(network, "Switch", "Client2");

    display_network(network);
    
    free_network(network);
    return 0;
}