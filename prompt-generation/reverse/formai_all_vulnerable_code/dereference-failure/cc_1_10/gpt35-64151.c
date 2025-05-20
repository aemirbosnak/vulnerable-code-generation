//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct graph {
    int V;
    Node **adj_list;
} Graph;

Graph *create_graph(int V) {
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->V = V;
    g->adj_list = (Node **) malloc(sizeof(Node *) * V);

    for (int i = 0; i < V; i++) {
        g->adj_list[i] = NULL;
    }

    return g;
}

void add_edge(Graph *g, int src, int dest) {
    // Adding edge from src to dest
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = dest;
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;

    // Adding edge from dest to src
    new_node = (Node *) malloc(sizeof(Node));
    new_node->data = src;
    new_node->next = g->adj_list[dest];
    g->adj_list[dest] = new_node;
}

void print_graph(Graph *g) {
    for (int i = 0; i < g->V; i++) {
        Node *temp = g->adj_list[i];
        printf("Adjacency list of vertex %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V = 5;
    Graph *g = create_graph(V);

    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    printf("Graph representation using adjacency list:\n");
    print_graph(g);

    return 0;
}