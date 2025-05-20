//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char *name;
} node_t;

typedef struct {
    int from;
    int to;
    int weight;
} edge_t;

node_t *nodes = NULL;
int num_nodes = 0;

edge_t *edges = NULL;
int num_edges = 0;

void add_node(char *name) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->id = num_nodes;
    new_node->name = strdup(name);
    nodes = realloc(nodes, sizeof(node_t) * ++num_nodes);
    nodes[num_nodes - 1] = *new_node;
    free(new_node);
}

void add_edge(int from, int to, int weight) {
    edge_t *new_edge = malloc(sizeof(edge_t));
    new_edge->from = from;
    new_edge->to = to;
    new_edge->weight = weight;
    edges = realloc(edges, sizeof(edge_t) * ++num_edges);
    edges[num_edges - 1] = *new_edge;
    free(new_edge);
}

void print_graph() {
    printf("Graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: %s\n", i, nodes[i].name);
    }
    printf("\nEdges:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d (%d)\n", edges[i].from, edges[i].to, edges[i].weight);
    }
}

int main() {
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    add_node("E");

    add_edge(0, 1, 2);
    add_edge(0, 2, 1);
    add_edge(1, 2, 3);
    add_edge(2, 3, 1);
    add_edge(2, 4, 2);

    print_graph();

    return 0;
}