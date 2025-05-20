//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

#define MAX_NODES 100
#define MAX_LINKS 500
#define MAX_LINK_LABEL_LEN 80

typedef struct {
    char label[MAX_LINK_LABEL_LEN];
    int node1;
    int node2;
    int weight;
} Link;

typedef struct {
    int num_nodes;
    int num_links;
    int *node_labels;
    Link *links;
} Network;

void init_network(Network *net) {
    net->num_nodes = 0;
    net->num_links = 0;
    net->node_labels = NULL;
    net->links = NULL;
}

void destroy_network(Network *net) {
    free(net->node_labels);
    free(net->links);
    net->num_nodes = 0;
    net->num_links = 0;
}

void add_node(Network *net, char *label) {
    net->num_nodes++;
    net->node_labels = realloc(net->node_labels, net->num_nodes * sizeof(char*));
    net->node_labels[net->num_nodes-1] = strdup(label);
}

void add_link(Network *net, int node1, int node2, char *label, int weight) {
    net->num_links++;
    net->links = realloc(net->links, net->num_links * sizeof(Link));
    net->links[net->num_links-1].node1 = node1;
    net->links[net->num_links-1].node2 = node2;
    net->links[net->num_links-1].weight = weight;
    strncpy(net->links[net->num_links-1].label, label, MAX_LINK_LABEL_LEN-1);
}

void print_node_labels(Network *net) {
    int i;
    for (i = 0; i < net->num_nodes; i++) {
        printf("%s\n", net->node_labels[i]);
    }
}

void print_links(Network *net) {
    int i;
    for (i = 0; i < net->num_links; i++) {
        printf("Node %d -> Node %d (%d)\n", net->links[i].node1, net->links[i].node2, net->links[i].weight);
    }
}

int main() {
    Network net;
    init_network(&net);

    add_node(&net, "Node 1");
    add_node(&net, "Node 2");
    add_node(&net, "Node 3");
    add_node(&net, "Node 4");
    add_node(&net, "Node 5");

    add_link(&net, 1, 2, "Link 1", 10);
    add_link(&net, 1, 3, "Link 2", 20);
    add_link(&net, 1, 4, "Link 3", 30);
    add_link(&net, 2, 3, "Link 4", 40);
    add_link(&net, 2, 4, "Link 5", 50);
    add_link(&net, 3, 4, "Link 6", 60);
    add_link(&net, 4, 5, "Link 7", 70);

    print_node_labels(&net);
    print_links(&net);

    destroy_network(&net);

    return 0;
}