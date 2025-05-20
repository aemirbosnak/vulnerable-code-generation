//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct graph {
    int V;
    Node *nodes[100];
} Graph;

void add_node(Graph *g, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    g->nodes[g->V] = new_node;
    g->V++;
}

void add_edge(Graph *g, int src, int dest) {
    if (src >= g->V || dest >= g->V) {
        printf("Invalid node index\n");
        return;
    }
    g->nodes[src]->left = g->nodes[dest];
    g->nodes[dest]->right = g->nodes[src];
}

void print_graph(Graph *g) {
    printf("Graph has %d nodes\n", g->V);
    for (int i = 0; i < g->V; i++) {
        printf("Node %d: %d -> ", i, g->nodes[i]->data);
        if (g->nodes[i]->left!= NULL) {
            printf("Left: %d\n", g->nodes[i]->left->data);
        } else {
            printf("No left child\n");
        }
        if (g->nodes[i]->right!= NULL) {
            printf("Right: %d\n", g->nodes[i]->right->data);
        } else {
            printf("No right child\n");
        }
    }
}

int main() {
    int V;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &V);
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->V = 0;
    for (int i = 0; i < V; i++) {
        add_node(g, i);
    }
    for (int i = 0; i < V; i++) {
        printf("Enter the edge between node %d and node %d: ", i, i + 1);
        scanf("%d", &g->nodes[i]->left->data);
        printf("Enter the edge between node %d and node %d: ", i + 1, i);
        scanf("%d", &g->nodes[i + 1]->right->data);
        add_edge(g, i, i + 1);
    }
    printf("The graph is:\n");
    print_graph(g);
    return 0;
}