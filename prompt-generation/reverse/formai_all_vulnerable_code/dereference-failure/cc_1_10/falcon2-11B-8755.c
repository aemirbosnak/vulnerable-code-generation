//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_NODES 1000
#define MAX_EDGES 5000

typedef struct node_t {
    int data;
    struct node_t* next;
} node_t;

typedef struct edge_t {
    node_t* start;
    node_t* end;
} edge_t;

typedef struct graph_t {
    node_t* head;
    node_t* tail;
    int num_nodes;
    int num_edges;
} graph_t;

graph_t* create_graph(void) {
    graph_t* g = malloc(sizeof(graph_t));
    g->head = NULL;
    g->tail = NULL;
    g->num_nodes = 0;
    g->num_edges = 0;
    return g;
}

void add_node(graph_t* g, int data) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (g->head == NULL) {
        g->head = new_node;
        g->tail = new_node;
    } else {
        g->tail->next = new_node;
        g->tail = new_node;
    }
    g->num_nodes++;
}

void add_edge(graph_t* g, node_t* start, node_t* end) {
    edge_t* new_edge = malloc(sizeof(edge_t));
    new_edge->start = start;
    new_edge->end = end;
    g->num_edges++;
}

int main() {
    graph_t* g = create_graph();
    add_node(g, 1);
    add_node(g, 2);
    add_node(g, 3);
    add_edge(g, g->head, g->tail);
    add_edge(g, g->head->next, g->tail->next);
    add_edge(g, g->head->next->next, g->tail->next->next);
    printf("Number of nodes: %d\n", g->num_nodes);
    printf("Number of edges: %d\n", g->num_edges);
    return 0;
}