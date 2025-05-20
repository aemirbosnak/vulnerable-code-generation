//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
// Alan Turing's Network Topology Mapper

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

struct node {
    int id;
    char *ip_address;
    int num_links;
    int *links;
};

struct link {
    int id;
    int node1;
    int node2;
};

struct network {
    int num_nodes;
    struct node *nodes;
    int num_links;
    struct link *links;
};

struct network *create_network() {
    struct network *network = malloc(sizeof(struct network));
    network->num_nodes = 0;
    network->nodes = NULL;
    network->num_links = 0;
    network->links = NULL;
    return network;
}

void free_network(struct network *network) {
    for (int i = 0; i < network->num_nodes; i++) {
        free(network->nodes[i].ip_address);
        free(network->nodes[i].links);
    }
    free(network->nodes);
    free(network->links);
    free(network);
}

void add_node(struct network *network, int id, char *ip_address) {
    struct node *node = malloc(sizeof(struct node));
    node->id = id;
    node->ip_address = strdup(ip_address);
    node->num_links = 0;
    node->links = NULL;
    network->nodes = realloc(network->nodes, (network->num_nodes + 1) * sizeof(struct node));
    network->nodes[network->num_nodes] = *node;
    network->num_nodes++;
}

void add_link(struct network *network, int id, int node1, int node2) {
    struct link *link = malloc(sizeof(struct link));
    link->id = id;
    link->node1 = node1;
    link->node2 = node2;
    network->links = realloc(network->links, (network->num_links + 1) * sizeof(struct link));
    network->links[network->num_links] = *link;
    network->num_links++;
    network->nodes[node1].num_links++;
    network->nodes[node2].num_links++;
    network->nodes[node1].links = realloc(network->nodes[node1].links, (network->nodes[node1].num_links) * sizeof(int));
    network->nodes[node1].links[network->nodes[node1].num_links - 1] = node2;
    network->nodes[node2].links = realloc(network->nodes[node2].links, (network->nodes[node2].num_links) * sizeof(int));
    network->nodes[node2].links[network->nodes[node2].num_links - 1] = node1;
}

void print_network(struct network *network) {
    printf("Network:\n");
    for (int i = 0; i < network->num_nodes; i++) {
        printf("Node %d:\n", network->nodes[i].id);
        printf("  IP address: %s\n", network->nodes[i].ip_address);
        printf("  Number of links: %d\n", network->nodes[i].num_links);
        printf("  Links: ");
        for (int j = 0; j < network->nodes[i].num_links; j++) {
            printf("%d ", network->nodes[i].links[j]);
        }
        printf("\n");
    }
    for (int i = 0; i < network->num_links; i++) {
        printf("Link %d:\n", network->links[i].id);
        printf("  Node 1: %d\n", network->links[i].node1);
        printf("  Node 2: %d\n", network->links[i].node2);
    }
}

int main() {
    struct network *network = create_network();

    add_node(network, 1, "192.168.1.1");
    add_node(network, 2, "192.168.1.2");
    add_node(network, 3, "192.168.1.3");

    add_link(network, 1, 1, 2);
    add_link(network, 2, 2, 3);
    add_link(network, 3, 1, 3);

    print_network(network);

    free_network(network);

    return 0;
}