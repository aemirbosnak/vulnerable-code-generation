//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct node {
    char *ip;
    int port;
    struct node *next;
};

struct graph {
    struct node *nodes;
    int num_nodes;
};

struct graph *create_graph() {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->nodes = NULL;
    graph->num_nodes = 0;
    return graph;
}

void add_node(struct graph *graph, char *ip, int port) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->ip = strdup(ip);
    new_node->port = port;
    new_node->next = graph->nodes;
    graph->nodes = new_node;
    graph->num_nodes++;
}

void print_graph(struct graph *graph) {
    struct node *node = graph->nodes;
    while (node != NULL) {
        printf("%s:%d\n", node->ip, node->port);
        node = node->next;
    }
}

void free_graph(struct graph *graph) {
    struct node *node = graph->nodes;
    while (node != NULL) {
        struct node *next_node = node->next;
        free(node->ip);
        free(node);
        node = next_node;
    }
    free(graph);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    struct graph *graph = create_graph();
    add_node(graph, argv[1], atoi(argv[2]));

    // TODO: Discover other nodes in the network

    print_graph(graph);
    free_graph(graph);

    return 0;
}