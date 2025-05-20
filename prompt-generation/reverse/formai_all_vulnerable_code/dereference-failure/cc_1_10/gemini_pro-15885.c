//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <err.h>
#include <errno.h>

#define MAX_HOPS 32
#define MAX_NODES 1024
#define MAX_LINK_LENGTH 1024

typedef struct node {
    char *name;
    int num_links;
    struct link *links;
} node_t;

typedef struct link {
    char *name;
    node_t *node1;
    node_t *node2;
    int weight;
} link_t;

typedef struct topology {
    int num_nodes;
    node_t *nodes;
    int num_links;
    link_t *links;
} topology_t;

topology_t *topology_new() {
    topology_t *topology = malloc(sizeof(topology_t));
    if (topology == NULL) {
        err(1, "malloc");
    }
    topology->num_nodes = 0;
    topology->nodes = NULL;
    topology->num_links = 0;
    topology->links = NULL;
    return topology;
}

void topology_free(topology_t *topology) {
    for (int i = 0; i < topology->num_nodes; i++) {
        free(topology->nodes[i].name);
        for (int j = 0; j < topology->nodes[i].num_links; j++) {
            free(topology->nodes[i].links[j].name);
        }
        free(topology->nodes[i].links);
    }
    free(topology->nodes);
    for (int i = 0; i < topology->num_links; i++) {
        free(topology->links[i].name);
    }
    free(topology->links);
    free(topology);
}

node_t *topology_add_node(topology_t *topology, char *name) {
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) {
        err(1, "malloc");
    }
    node->name = strdup(name);
    node->num_links = 0;
    node->links = NULL;
    topology->nodes = realloc(topology->nodes, (topology->num_nodes + 1) * sizeof(node_t));
    if (topology->nodes == NULL) {
        err(1, "realloc");
    }
    topology->nodes[topology->num_nodes++] = *node;
    return node;
}

link_t *topology_add_link(topology_t *topology, node_t *node1, node_t *node2, char *name, int weight) {
    link_t *link = malloc(sizeof(link_t));
    if (link == NULL) {
        err(1, "malloc");
    }
    link->name = strdup(name);
    link->node1 = node1;
    link->node2 = node2;
    link->weight = weight;
    topology->links = realloc(topology->links, (topology->num_links + 1) * sizeof(link_t));
    if (topology->links == NULL) {
        err(1, "realloc");
    }
    topology->links[topology->num_links++] = *link;
    return link;
}

void topology_print(topology_t *topology) {
    for (int i = 0; i < topology->num_nodes; i++) {
        printf("%s\n", topology->nodes[i].name);
        for (int j = 0; j < topology->nodes[i].num_links; j++) {
            printf("  %s %s %d\n",
                topology->nodes[i].links[j].name,
                topology->nodes[i].links[j].node1->name,
                topology->nodes[i].links[j].node2->name,
                topology->nodes[i].links[j].weight);
        }
    }
}

int main(int argc, char **argv) {
    topology_t *topology = topology_new();
    node_t *node1 = topology_add_node(topology, "node1");
    node_t *node2 = topology_add_node(topology, "node2");
    node_t *node3 = topology_add_node(topology, "node3");
    topology_add_link(topology, node1, node2, "link1", 1);
    topology_add_link(topology, node2, node3, "link2", 1);
    topology_print(topology);
    topology_free(topology);
    return 0;
}