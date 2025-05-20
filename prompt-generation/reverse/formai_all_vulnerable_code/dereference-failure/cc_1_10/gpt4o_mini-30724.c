//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_NODES 10
#define BUFFER_SIZE 256

typedef struct Node {
    char name[50];
    char ip[16];
    struct Node* connections[MAX_NODES];
    int connection_count;
} Node;

Node* create_node(const char* name, const char* ip) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->ip, ip);
    new_node->connection_count = 0;
    return new_node;
}

void connect_nodes(Node* node1, Node* node2) {
    if(node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1; // bidirectional connection
    } else {
        fprintf(stderr, "Connection limit reached for %s or %s\n", node1->name, node2->name);
    }
}

void print_network(Node* nodes[], int count) {
    printf("== Network Topology Map ==\n");
    for(int i = 0; i < count; i++) {
        printf("Node: %s (IP: %s)\n", nodes[i]->name, nodes[i]->ip);
        printf("Connected to: ");
        for(int j = 0; j < nodes[i]->connection_count; j++) {
            printf("%s ", nodes[i]->connections[j]->name);
        }
        printf("\n");
    }
}

void free_network(Node* nodes[], int count) {
    for(int i = 0; i < count; i++) {
        free(nodes[i]);
    }
}

int main() {
    Node* nodes[MAX_NODES];
    int node_count = 0;

    printf("Welcome to the Awake and Alive Network Topology Mapper!\n");

    nodes[node_count++] = create_node("Router1", "192.168.1.1");
    nodes[node_count++] = create_node("Switch1", "192.168.1.2");
    nodes[node_count++] = create_node("Server1", "192.168.1.3");
    nodes[node_count++] = create_node("PC1", "192.168.1.4");
    nodes[node_count++] = create_node("Laptop1", "192.168.1.5");

    connect_nodes(nodes[0], nodes[1]); // Router1 <-> Switch1
    connect_nodes(nodes[1], nodes[2]); // Switch1 <-> Server1
    connect_nodes(nodes[1], nodes[3]); // Switch1 <-> PC1
    connect_nodes(nodes[1], nodes[4]); // Switch1 <-> Laptop1

    print_network(nodes, node_count);

    // Simulate a shocking connection
    printf("\nSHOCKING LINK ESTABLISHED!!! Anomaly detected...\n");
    connect_nodes(nodes[2], nodes[4]); // Server1 <-> Laptop1

    printf("\n=== Updated Network Topology After SHOCK ===\n");
    print_network(nodes, node_count);

    free_network(nodes, node_count);
    printf("All nodes cleaned up! Fear not, network troubles have been dissolved!\n");
    return 0;
}