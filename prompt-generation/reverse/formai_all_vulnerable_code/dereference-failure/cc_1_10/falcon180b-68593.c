//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_LINKS 100
#define MAX_LINK_LENGTH 20

typedef struct {
    int node1;
    int node2;
    int length;
} Link;

typedef struct {
    int num_nodes;
    int num_links;
    Link links[MAX_LINKS];
} Network;

Network* create_network() {
    Network* net = (Network*)malloc(sizeof(Network));
    net->num_nodes = 0;
    net->num_links = 0;
    return net;
}

void add_node(Network* net, int node_id) {
    net->num_nodes++;
}

void add_link(Network* net, int node1, int node2, int length) {
    net->num_links++;
    Link* link = &net->links[net->num_links - 1];
    link->node1 = node1;
    link->node2 = node2;
    link->length = length;
}

void print_network(Network* net) {
    printf("Network:\n");
    printf("Nodes: %d\n", net->num_nodes);
    printf("Links: %d\n", net->num_links);
    for (int i = 0; i < net->num_links; i++) {
        printf("[%d,%d,%d]\n", net->links[i].node1, net->links[i].node2, net->links[i].length);
    }
}

int main() {
    Network* net = create_network();
    add_node(net, 1);
    add_node(net, 2);
    add_node(net, 3);
    add_link(net, 1, 2, 5);
    add_link(net, 2, 3, 10);
    print_network(net);
    return 0;
}