//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int id;
    struct Node* connections[MAX_NODES];
    int connection_count;
} Node;

typedef struct Topology {
    Node* nodes[MAX_NODES];
    int node_count;
} Topology;

// Function prototypes
Topology* create_topology();
Node* create_node(const char* name, int id);
void add_node(Topology* topology, const char* name);
void connect_nodes(Topology* topology, int id1, int id2);
void display_topology(const Topology* topology);
void free_topology(Topology* topology);

int main() {
    Topology* topology = create_topology();
    
    add_node(topology, "Router1");
    add_node(topology, "Switch1");
    add_node(topology, "PC1");
    add_node(topology, "PC2");
    
    connect_nodes(topology, 0, 1); // Router1 to Switch1
    connect_nodes(topology, 1, 2); // Switch1 to PC1
    connect_nodes(topology, 1, 3); // Switch1 to PC2
    
    display_topology(topology);
    
    free_topology(topology);
    return 0;
}

Topology* create_topology() {
    Topology* topology = malloc(sizeof(Topology));
    topology->node_count = 0;
    return topology;
}

Node* create_node(const char* name, int id) {
    Node* node = malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->id = id;
    node->connection_count = 0;
    return node;
}

void add_node(Topology* topology, const char* name) {
    if (topology->node_count >= MAX_NODES) {
        printf("Cannot add more nodes. Maximum limit reached.\n");
        return;
    }
    Node* new_node = create_node(name, topology->node_count);
    topology->nodes[topology->node_count++] = new_node;
}

void connect_nodes(Topology* topology, int id1, int id2) {
    if (id1 >= topology->node_count || id2 >= topology->node_count) {
        printf("Invalid node IDs for connection.\n");
        return;
    }
    Node* node1 = topology->nodes[id1];
    Node* node2 = topology->nodes[id2];
    
    if (node1->connection_count >= MAX_NODES || node2->connection_count >= MAX_NODES) {
        printf("Maximum connections reached for one of the nodes.\n");
        return;
    }
    
    node1->connections[node1->connection_count++] = node2;
    node2->connections[node2->connection_count++] = node1;
    
    printf("Connected %s (ID %d) to %s (ID %d)\n", node1->name, id1, node2->name, id2);
}

void display_topology(const Topology* topology) {
    printf("Network Topology:\n");
    for (int i = 0; i < topology->node_count; i++) {
        Node* node = topology->nodes[i];
        printf("Node %d: %s\n", node->id, node->name);
        if (node->connection_count > 0) {
            printf("  Connections: ");
            for (int j = 0; j < node->connection_count; j++) {
                printf("%s (ID %d) ", node->connections[j]->name, node->connections[j]->id);
            }
            printf("\n");
        }
    }
}

void free_topology(Topology* topology) {
    for (int i = 0; i < topology->node_count; i++) {
        free(topology->nodes[i]);
    }
    free(topology);
}