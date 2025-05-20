//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 20

typedef struct Node {
    char name[MAX_NAME_LEN];
    struct Node* neighbors[MAX_NODES];
    int neighbor_count;
} Node;

typedef struct Network {
    Node* nodes[MAX_NODES];
    int node_count;
} Network;

// Function prototypes
Network* create_network();
Node* add_node(Network* network, const char* name);
void connect_nodes(Node* n1, Node* n2);
void print_network(Network* network);
void free_network(Network* network);

int main() {
    Network* network = create_network();

    Node* nodeA = add_node(network, "NodeA");
    Node* nodeB = add_node(network, "NodeB");
    Node* nodeC = add_node(network, "NodeC");
    Node* nodeD = add_node(network, "NodeD");
    
    connect_nodes(nodeA, nodeB);
    connect_nodes(nodeA, nodeC);
    connect_nodes(nodeB, nodeC);
    connect_nodes(nodeC, nodeD);
    
    print_network(network);
    
    free_network(network);
    return 0;
}

Network* create_network() {
    Network* network = (Network*)malloc(sizeof(Network));
    network->node_count = 0;
    return network;
}

Node* add_node(Network* network, const char* name) {
    if (network->node_count >= MAX_NODES) {
        printf("Network node limit reached!\n");
        return NULL;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LEN);
    new_node->neighbor_count = 0;
    
    network->nodes[network->node_count++] = new_node;
    return new_node;
}

void connect_nodes(Node* n1, Node* n2) {
    if (n1->neighbor_count >= MAX_NODES || n2->neighbor_count >= MAX_NODES) {
        printf("Node neighbor limit reached!\n");
        return;
    }
    
    n1->neighbors[n1->neighbor_count++] = n2;
    n2->neighbors[n2->neighbor_count++] = n1; // Bi-directional connection
}

void print_network(Network* network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->node_count; i++) {
        Node* node = network->nodes[i];
        printf("%s is connected to: ", node->name);
        for (int j = 0; j < node->neighbor_count; j++) {
            printf("%s ", node->neighbors[j]->name);
        }
        printf("\n");
    }
}

void free_network(Network* network) {
    for (int i = 0; i < network->node_count; i++) {
        free(network->nodes[i]);
    }
    free(network);
}