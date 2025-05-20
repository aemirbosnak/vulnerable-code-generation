//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_LABEL_LENGTH 100

typedef struct node {
    char label[MAX_LABEL_LENGTH];
    int num_edges;
    struct node *edges[MAX_EDGES];
} Node;

typedef struct edge {
    Node *src;
    Node *dest;
} Edge;

void add_edge(Node *src, Node *dest) {
    src->edges[src->num_edges++] = dest;
    dest->edges[dest->num_edges++] = src;
}

void print_graph(Node *graph) {
    for (int i = 0; i < graph->num_edges; i++) {
        printf("%s -> %s\n", graph->label, graph->edges[i]->label);
    }
}

int main() {
    Node *graph = (Node *) malloc(sizeof(Node));
    strcpy(graph->label, "Main");
    graph->num_edges = 0;

    Node *node1 = (Node *) malloc(sizeof(Node));
    strcpy(node1->label, "Node 1");
    node1->num_edges = 0;

    Node *node2 = (Node *) malloc(sizeof(Node));
    strcpy(node2->label, "Node 2");
    node2->num_edges = 0;

    add_edge(graph, node1);
    add_edge(graph, node2);
    add_edge(node1, node2);

    print_graph(graph);

    return 0;
}