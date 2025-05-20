//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

// Structure to represent a Node in the network
typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
    struct Node* connections[MAX_NODES];
    int conn_count;
} Node;

// Structure to represent the Network
typedef struct Network {
    Node* nodes[MAX_NODES];
    int node_count;
} Network;

// Function to create a new node
Node* create_node(const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    new_node->next = NULL;
    new_node->conn_count = 0;
    return new_node;
}

// Function to add a node to the network
void add_node(Network* network, const char* name) {
    if (network->node_count < MAX_NODES) {
        Node* node = create_node(name);
        network->nodes[network->node_count++] = node;
        printf("Node '%s' added to the network!\n", name);
    } else {
        printf("Max nodes limit reached!\n");
    }
}

// Function to connect two nodes
void connect_nodes(Network* network, const char* name1, const char* name2) {
    Node* node1 = NULL;
    Node* node2 = NULL;
    
    for(int i = 0; i < network->node_count; i++) {
        if (strcmp(network->nodes[i]->name, name1) == 0) {
            node1 = network->nodes[i];
        }
        if (strcmp(network->nodes[i]->name, name2) == 0) {
            node2 = network->nodes[i];
        }
    }

    if (node1 && node2) {
        node1->connections[node1->conn_count++] = node2;
        node2->connections[node2->conn_count++] = node1;
        printf("Connection established between '%s' and '%s'!\n", name1, name2);
    } else {
        printf("One or both nodes not found!\n");
    }
}

// Function to display the network topology
void display_topology(const Network* network) {
    printf("\n--- Network Topology ---\n");
    for (int i = 0; i < network->node_count; i++) {
        Node* current = network->nodes[i];
        printf("Node '%s' is connected to: ", current->name);
        for (int j = 0; j < current->conn_count; j++) {
            printf("'%s' ", current->connections[j]->name);
        }
        printf("\n");
    }
}

// Function to free the allocated memory
void free_network(Network* network) {
    for (int i = 0; i < network->node_count; i++) {
        free(network->nodes[i]);
    }
    free(network);
}

int main() {
    // Create the network
    Network* network = (Network*)malloc(sizeof(Network));
    network->node_count = 0;

    // Welcome message
    printf("Welcome to the Marvelous Network Topology Mapper!\n");

    // Adding nodes
    add_node(network, "Switch_A");
    add_node(network, "Router_B");
    add_node(network, "Server_C");
    add_node(network, "PC_D");
    add_node(network, "Printer_E");

    // Creating connections
    connect_nodes(network, "Switch_A", "Router_B");
    connect_nodes(network, "Router_B", "Server_C");
    connect_nodes(network, "PC_D", "Switch_A");
    connect_nodes(network, "Printer_E", "Router_B");

    // Displaying the network topology
    display_topology(network);

    // Clean up
    free_network(network);
    printf("Thank you for using the Network Topology Mapper!\n");

    return 0;
}