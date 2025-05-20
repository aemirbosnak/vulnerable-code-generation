//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int id;
    int degree;
    char name[10];
    struct node *edges[MAX_EDGES];
} Node;

typedef struct graph {
    int nnodes;
    Node *nodes[MAX_NODES];
} Graph;

Graph *create_graph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->nnodes = 0;
    return graph;
}

Node *create_node(int id, char name[10]) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->degree = 0;
    strcpy(node->name, name);
    node->edges[0] = NULL;
    return node;
}

void add_node(Graph *graph, Node *node) {
    graph->nodes[graph->nnodes++] = node;
}

void add_edge(Node *node1, Node *node2) {
    node1->degree++;
    node2->degree++;
    node1->edges[node1->degree - 1] = node2;
    node2->edges[node2->degree - 1] = node1;
}

void print_graph(Graph *graph) {
    int i, j;
    for (i = 0; i < graph->nnodes; i++) {
        printf("Node %d (%s)\n", graph->nodes[i]->id, graph->nodes[i]->name);
        for (j = 0; j < graph->nodes[i]->degree; j++) {
            printf(" -> Node %d (%s)\n", graph->nodes[i]->edges[j]->id, graph->nodes[i]->edges[j]->name);
        }
    }
}

int main() {
    Graph *graph = create_graph();
    add_node(graph, create_node(1, "A"));
    add_node(graph, create_node(2, "B"));
    add_node(graph, create_node(3, "C"));
    add_node(graph, create_node(4, "D"));
    add_edge(graph->nodes[0], graph->nodes[1]);
    add_edge(graph->nodes[0], graph->nodes[2]);
    add_edge(graph->nodes[1], graph->nodes[3]);
    add_edge(graph->nodes[2], graph->nodes[3]);
    add_edge(graph->nodes[2], graph->nodes[4]);
    print_graph(graph);
    return 0;
}