//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

struct node {
    char name[255];
    int num_links;
    struct link *links[MAX_LINKS];
};

struct link {
    struct node *node1;
    struct node *node2;
    int weight;
};

struct graph {
    int num_nodes;
    int num_links;
    struct node *nodes[MAX_NODES];
    struct link *links[MAX_LINKS];
};

struct graph *create_graph() {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->num_nodes = 0;
    graph->num_links = 0;
    return graph;
}

void add_node(struct graph *graph, char *name) {
    struct node *node = malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->num_links = 0;
    graph->nodes[graph->num_nodes++] = node;
}

void add_link(struct graph *graph, struct node *node1, struct node *node2, int weight) {
    struct link *link = malloc(sizeof(struct link));
    link->node1 = node1;
    link->node2 = node2;
    link->weight = weight;
    graph->links[graph->num_links++] = link;
    node1->links[node1->num_links++] = link;
    node2->links[node2->num_links++] = link;
}

void print_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        struct node *node = graph->nodes[i];
        printf("%s\n", node->name);
        for (int j = 0; j < node->num_links; j++) {
            struct link *link = node->links[j];
            printf("  %s %d\n", link->node2->name, link->weight);
        }
    }
}

void *thread_func(void *arg) {
    struct graph *graph = (struct graph *)arg;
    // Do something with the graph
    return NULL;
}

int main() {
    struct graph *graph = create_graph();

    // Add some nodes and links to the graph
    add_node(graph, "node1");
    add_node(graph, "node2");
    add_node(graph, "node3");
    add_link(graph, graph->nodes[0], graph->nodes[1], 1);
    add_link(graph, graph->nodes[1], graph->nodes[2], 2);
    add_link(graph, graph->nodes[2], graph->nodes[0], 3);

    // Print the graph
    print_graph(graph);

    // Create a thread to do something with the graph
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, graph);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}