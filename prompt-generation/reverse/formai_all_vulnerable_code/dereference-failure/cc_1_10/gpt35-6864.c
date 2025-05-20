//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node {
    int id;
    char *ip_address;
    int neighbors[MAX_NODES];
    int num_neighbors;
} Node;

typedef struct Connection {
    int node1;
    int node2;
} Connection;

Node network[MAX_NODES];
int num_nodes = 0;
Connection connections[MAX_NODES * MAX_NODES];
int num_connections = 0;

void add_node(char *ip_address) {
    Node new_node;
    new_node.id = num_nodes;
    new_node.ip_address = strdup(ip_address);
    new_node.num_neighbors = 0;

    network[num_nodes] = new_node;
    num_nodes++;
}

void add_connection(int node1, int node2) {
    Connection new_connection;
    new_connection.node1 = node1;
    new_connection.node2 = node2;

    connections[num_connections] = new_connection;
    num_connections++;
}

void map_topology() {
    for (int i = 0; i < num_nodes; i++) {
        Node current_node = network[i];
        printf("Node %d (%s) is connected to: ", current_node.id, current_node.ip_address);
        for (int j = 0; j < current_node.num_neighbors; j++) {
            Node neighbor = network[current_node.neighbors[j]];
            printf("%d (%s) ", neighbor.id, neighbor.ip_address);
        }
        printf("\n");
    }
}

int main() {
    // create some nodes
    add_node("192.168.1.1");
    add_node("192.168.1.2");
    add_node("192.168.1.3");
    add_node("192.168.1.4");

    // create some connections
    add_connection(0, 1);
    add_connection(0, 2);
    add_connection(1, 2);
    add_connection(2, 3);

    // map the topology
    map_topology();

    return 0;
}