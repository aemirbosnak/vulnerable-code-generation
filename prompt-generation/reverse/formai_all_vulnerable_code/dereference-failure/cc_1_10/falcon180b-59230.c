//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int id;
    int degree;
    struct node* neighbors[MAX_EDGES];
} Node;

typedef struct graph {
    int num_nodes;
    Node* nodes[MAX_NODES];
} Graph;

void create_node(Graph* g, int id) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->id = id;
    n->degree = 0;
    for (int i = 0; i < MAX_EDGES; i++) {
        n->neighbors[i] = NULL;
    }
    g->nodes[g->num_nodes++] = n;
}

void add_edge(Graph* g, int src_id, int dest_id) {
    Node* src = g->nodes[src_id];
    Node* dest = g->nodes[dest_id];
    src->degree++;
    dest->degree++;
    src->neighbors[src->degree - 1] = dest;
    dest->neighbors[dest->degree - 1] = src;
}

void print_graph(Graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        Node* n = g->nodes[i];
        printf("Node %d has degree %d and neighbors ", n->id, n->degree);
        for (int j = 0; j < n->degree; j++) {
            if (n->neighbors[j]!= NULL) {
                printf("%d ", n->neighbors[j]->id);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }
}

void destroy_graph(Graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        Node* n = g->nodes[i];
        for (int j = 0; j < n->degree; j++) {
            if (n->neighbors[j]!= NULL) {
                destroy_graph(n->neighbors[j]);
            }
        }
        free(n);
    }
    free(g);
}

int main() {
    srand(time(NULL));
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->num_nodes = 0;
    create_node(g, 0);
    create_node(g, 1);
    create_node(g, 2);
    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    print_graph(g);
    destroy_graph(g);
    return 0;
}