//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

struct node {
    int id;
    char *name;
    int num_links;
    struct link *links;
};

struct link {
    int id;
    struct node *node1;
    struct node *node2;
    int weight;
};

struct graph {
    int num_nodes;
    struct node *nodes;
    int num_links;
    struct link *links;
};

struct graph *create_graph() {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->num_nodes = 0;
    graph->nodes = NULL;
    graph->num_links = 0;
    graph->links = NULL;
    return graph;
}

void destroy_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->nodes[i].name);
        free(graph->nodes[i].links);
    }
    free(graph->nodes);
    free(graph->links);
    free(graph);
}

struct node *create_node(int id, char *name) {
    struct node *node = malloc(sizeof(struct node));
    node->id = id;
    node->name = strdup(name);
    node->num_links = 0;
    node->links = NULL;
    return node;
}

void destroy_node(struct node *node) {
    free(node->name);
    free(node->links);
    free(node);
}

struct link *create_link(int id, struct node *node1, struct node *node2, int weight) {
    struct link *link = malloc(sizeof(struct link));
    link->id = id;
    link->node1 = node1;
    link->node2 = node2;
    link->weight = weight;
    return link;
}

void destroy_link(struct link *link) {
    free(link);
}

void add_node(struct graph *graph, struct node *node) {
    graph->nodes = realloc(graph->nodes, (graph->num_nodes + 1) * sizeof(struct node));
    graph->nodes[graph->num_nodes++] = *node;
}

void add_link(struct graph *graph, struct link *link) {
    graph->links = realloc(graph->links, (graph->num_links + 1) * sizeof(struct link));
    graph->links[graph->num_links++] = *link;
}

void print_graph(struct graph *graph) {
    printf("Nodes:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("  %d: %s\n", graph->nodes[i].id, graph->nodes[i].name);
    }
    printf("Links:\n");
    for (int i = 0; i < graph->num_links; i++) {
        printf("  %d: %d -> %d (weight %d)\n", graph->links[i].id, graph->links[i].node1->id, graph->links[i].node2->id, graph->links[i].weight);
    }
}

int main() {
    struct graph *graph = create_graph();

    struct node *node1 = create_node(1, "Node 1");
    struct node *node2 = create_node(2, "Node 2");
    struct node *node3 = create_node(3, "Node 3");
    struct node *node4 = create_node(4, "Node 4");
    struct node *node5 = create_node(5, "Node 5");

    add_node(graph, node1);
    add_node(graph, node2);
    add_node(graph, node3);
    add_node(graph, node4);
    add_node(graph, node5);

    struct link *link1 = create_link(1, node1, node2, 1);
    struct link *link2 = create_link(2, node1, node3, 2);
    struct link *link3 = create_link(3, node2, node4, 3);
    struct link *link4 = create_link(4, node2, node5, 4);
    struct link *link5 = create_link(5, node3, node4, 5);
    struct link *link6 = create_link(6, node3, node5, 6);
    struct link *link7 = create_link(7, node4, node5, 7);

    add_link(graph, link1);
    add_link(graph, link2);
    add_link(graph, link3);
    add_link(graph, link4);
    add_link(graph, link5);
    add_link(graph, link6);
    add_link(graph, link7);

    print_graph(graph);

    destroy_graph(graph);

    return 0;
}