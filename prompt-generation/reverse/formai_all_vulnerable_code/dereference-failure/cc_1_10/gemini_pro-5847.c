//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

struct node {
    int id;
    char *ip;
    int num_links;
    int links[MAX_LINKS];
};

struct link {
    int id;
    int node1;
    int node2;
    int weight;
};

struct network {
    int num_nodes;
    int num_links;
    struct node nodes[MAX_NODES];
    struct link links[MAX_LINKS];
};

struct network *create_network() {
    struct network *network = malloc(sizeof(struct network));
    network->num_nodes = 0;
    network->num_links = 0;
    return network;
}

void add_node(struct network *network, int id, char *ip) {
    network->nodes[network->num_nodes].id = id;
    network->nodes[network->num_nodes].ip = strdup(ip);
    network->nodes[network->num_nodes].num_links = 0;
    network->num_nodes++;
}

void add_link(struct network *network, int id, int node1, int node2, int weight) {
    network->links[network->num_links].id = id;
    network->links[network->num_links].node1 = node1;
    network->links[network->num_links].node2 = node2;
    network->links[network->num_links].weight = weight;
    network->num_links++;
    network->nodes[node1].links[network->nodes[node1].num_links++] = id;
    network->nodes[node2].links[network->nodes[node2].num_links++] = id;
}

void print_network(struct network *network) {
    printf("Network:\n");
    for (int i = 0; i < network->num_nodes; i++) {
        printf("Node %d: %s\n", network->nodes[i].id, network->nodes[i].ip);
        for (int j = 0; j < network->nodes[i].num_links; j++) {
            printf("  Link %d: %d -> %d (%d)\n", network->links[network->nodes[i].links[j]].id, network->nodes[i].id, network->links[network->nodes[i].links[j]].node2, network->links[network->nodes[i].links[j]].weight);
        }
    }
}

int main() {
    struct network *network = create_network();

    add_node(network, 1, "192.168.0.1");
    add_node(network, 2, "192.168.0.2");
    add_node(network, 3, "192.168.0.3");
    add_node(network, 4, "192.168.0.4");
    add_node(network, 5, "192.168.0.5");

    add_link(network, 1, 1, 2, 10);
    add_link(network, 2, 1, 3, 20);
    add_link(network, 3, 2, 4, 30);
    add_link(network, 4, 3, 5, 40);
    add_link(network, 5, 4, 1, 50);

    print_network(network);

    return 0;
}