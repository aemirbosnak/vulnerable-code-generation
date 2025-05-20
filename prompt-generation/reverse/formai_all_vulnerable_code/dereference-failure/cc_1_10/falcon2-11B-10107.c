//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 5000

typedef struct node_s {
    int id;
    char name[50];
    int num_outgoing;
    struct node_s **outgoing;
} node_t;

typedef struct edge_s {
    int src;
    int dest;
} edge_t;

typedef struct graph_s {
    int num_nodes;
    node_t *nodes;
    int num_edges;
    edge_t *edges;
} graph_t;

void create_graph(graph_t *graph, int num_nodes, int num_edges) {
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->nodes = (node_t*) malloc(num_nodes * sizeof(node_t));
    graph->edges = (edge_t*) malloc(num_edges * sizeof(edge_t));
}

void add_node(graph_t *graph, int id, char name[]) {
    node_t *node = &(graph->nodes[id]);
    strcpy(node->name, name);
    node->num_outgoing = 0;
    node->outgoing = (struct node_s**) malloc(node->num_outgoing * sizeof(struct node_s*));
}

void add_edge(graph_t *graph, int src, int dest) {
    edge_t edge = {src, dest};
    graph->edges[graph->num_edges].src = src;
    graph->edges[graph->num_edges].dest = dest;
    graph->num_edges++;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%s -> ", graph->nodes[i].name);
    }
    printf("EOF\n");
}

int main() {
    graph_t graph;
    create_graph(&graph, 5, 10);

    add_node(&graph, 0, "Alice");
    add_node(&graph, 1, "Bob");
    add_node(&graph, 2, "Charlie");
    add_node(&graph, 3, "David");
    add_node(&graph, 4, "Eve");

    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 0);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 1);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 2);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 4, 3);
    add_edge(&graph, 4, 0);

    print_graph(&graph);

    return 0;
}