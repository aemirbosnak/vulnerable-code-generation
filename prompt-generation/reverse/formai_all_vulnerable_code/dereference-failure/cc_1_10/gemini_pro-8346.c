//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <stdbool.h>

#define MAX_IP_ADDR_LEN 16

typedef struct {
    char ip_addr[MAX_IP_ADDR_LEN];
    int num_hops;
    bool visited;
} node;

typedef struct {
    node* nodes;
    int num_nodes;
} network;

network* new_network() {
    network* n = malloc(sizeof(network));
    n->nodes = NULL;
    n->num_nodes = 0;
    return n;
}

void free_network(network* n) {
    for (int i = 0; i < n->num_nodes; i++) {
        free(n->nodes[i].ip_addr);
    }
    free(n->nodes);
    free(n);
}

node* new_node(char* ip_addr, int num_hops) {
    node* n = malloc(sizeof(node));
    strcpy(n->ip_addr, ip_addr);
    n->num_hops = num_hops;
    n->visited = false;
    return n;
}

void free_node(node* n) {
    free(n->ip_addr);
    free(n);
}

void add_node(network* n, node* new_node) {
    n->nodes = realloc(n->nodes, (n->num_nodes + 1) * sizeof(node));
    n->nodes[n->num_nodes++] = *new_node;
}

node* find_node_by_ip_addr(network* n, char* ip_addr) {
    for (int i = 0; i < n->num_nodes; i++) {
        if (strcmp(n->nodes[i].ip_addr, ip_addr) == 0) {
            return &n->nodes[i];
        }
    }
    return NULL;
}

void print_network(network* n) {
    for (int i = 0; i < n->num_nodes; i++) {
        printf("%s %d\n", n->nodes[i].ip_addr, n->nodes[i].num_hops);
    }
}

int main() {
    network* n = new_network();

    // Add some nodes to the network.
    add_node(n, new_node("192.168.1.1", 1));
    add_node(n, new_node("192.168.1.2", 2));
    add_node(n, new_node("192.168.1.3", 3));

    // Print the network.
    print_network(n);

    // Free the network.
    free_network(n);

    return 0;
}