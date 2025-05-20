//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 50

typedef struct Node {
    char name[MAX_NAME_LEN];
    int id;
    struct Node* connections[MAX_NODES];
    int connection_count;
} Node;

typedef struct Topology {
    Node* nodes[MAX_NODES];
    int total_nodes;
} Topology;

Topology* create_topology() {
    Topology* topology = (Topology*)malloc(sizeof(Topology));
    topology->total_nodes = 0;
    return topology;
}

Node* add_node(Topology* topology, const char* name) {
    if (topology->total_nodes >= MAX_NODES) {
        printf("Maximum node limit reached!\n");
        return NULL;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LEN);
    new_node->id = topology->total_nodes;
    new_node->connection_count = 0;

    topology->nodes[topology->total_nodes++] = new_node;
    return new_node;
}

void connect_nodes(Node* node1, Node* node2) {
    if (node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1;
    } else {
        printf("Connection limit reached for nodes %s or %s\n", node1->name, node2->name);
    }
}

void display_topology(Topology* topology) {
    printf("Network Topology:\n");
    for (int i = 0; i < topology->total_nodes; ++i) {
        Node* node = topology->nodes[i];
        printf("Node %s (ID: %d) is connected to: ", node->name, node->id);
        for (int j = 0; j < node->connection_count; ++j) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

void free_topology(Topology* topology) {
    for (int i = 0; i < topology->total_nodes; ++i) {
        free(topology->nodes[i]);
    }
    free(topology);
}

int main() {
    Topology* topology = create_topology();

    Node* nodeA = add_node(topology, "Router");
    Node* nodeB = add_node(topology, "Switch");
    Node* nodeC = add_node(topology, "Server");
    Node* nodeD = add_node(topology, "Firewall");
    Node* nodeE = add_node(topology, "PC1");
    Node* nodeF = add_node(topology, "PC2");

    connect_nodes(nodeA, nodeB);
    connect_nodes(nodeB, nodeC);
    connect_nodes(nodeB, nodeD);
    connect_nodes(nodeC, nodeF);
    connect_nodes(nodeD, nodeE);

    display_topology(topology);

    free_topology(topology);
    return 0;
}