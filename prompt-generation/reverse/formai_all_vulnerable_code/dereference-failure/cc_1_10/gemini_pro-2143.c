//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

#define PORT 5555
#define MAX_NODES 1024
#define MAX_LINKS 1024

struct node {
    int id;
    char *name;
    int num_links;
    struct link *links;
};

struct link {
    int id;
    int src_node_id;
    int dst_node_id;
    int cost;
};

struct graph {
    int num_nodes;
    int num_links;
    struct node *nodes;
    struct link *links;
};

struct graph *create_graph(int num_nodes, int num_links) {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->num_nodes = num_nodes;
    graph->num_links = num_links;
    graph->nodes = malloc(sizeof(struct node) * num_nodes);
    graph->links = malloc(sizeof(struct link) * num_links);
    return graph;
}

void add_node(struct graph *graph, int id, char *name) {
    struct node *node = &graph->nodes[id];
    node->id = id;
    node->name = strdup(name);
    node->num_links = 0;
    node->links = NULL;
}

void add_link(struct graph *graph, int id, int src_node_id, int dst_node_id, int cost) {
    struct link *link = &graph->links[id];
    link->id = id;
    link->src_node_id = src_node_id;
    link->dst_node_id = dst_node_id;
    link->cost = cost;
}

void print_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        struct node *node = &graph->nodes[i];
        printf("Node %d (%s)\n", node->id, node->name);
        printf("Links:\n");
        for (int j = 0; j < node->num_links; j++) {
            struct link *link = &node->links[j];
            printf("  - %d -> %d (cost %d)\n", link->src_node_id, link->dst_node_id, link->cost);
        }
    }
}

void free_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        struct node *node = &graph->nodes[i];
        free(node->name);
        free(node->links);
    }
    free(graph->nodes);
    free(graph->links);
    free(graph);
}

int main() {
    struct graph *graph = create_graph(MAX_NODES, MAX_LINKS);

    // Add the nodes
    char *node_names[] = {"Alice", "Bob", "Charlie", "Dave", "Eve", "Frank", "George", "Helen", "Ian", "Jacob"};
    for (int i = 0; i < MAX_NODES; i++) {
        add_node(graph, i, node_names[i]);
    }

    // Add the links
    int link_costs[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < MAX_LINKS; i++) {
        add_link(graph, i, rand() % MAX_NODES, rand() % MAX_NODES, link_costs[i]);
    }

    // Print the graph
    print_graph(graph);

    // Free the graph
    free_graph(graph);

    return 0;
}