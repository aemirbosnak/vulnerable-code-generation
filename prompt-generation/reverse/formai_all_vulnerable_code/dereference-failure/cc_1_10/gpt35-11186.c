//FormAI DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6

typedef struct node {
    int edge_index;
    struct node* next;
} Node;

typedef struct graph {
    Node* edges[MAX_VERTICES];
} Graph;

Graph* create_graph() {
    Graph* G = (Graph*) malloc(sizeof(Graph));
    for (int i = 0; i < MAX_VERTICES; i++) {
        G->edges[i] = NULL;
    }
    return G;
}

void add_edge(Graph* G, int u, int v) {
    Node* new_edge = (Node*) malloc(sizeof(Node));
    new_edge->edge_index = v;
    new_edge->next = G->edges[u];
    G->edges[u] = new_edge;
}

void print_graph(Graph* G) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%d -> ", i);
        Node* edge = G->edges[i];
        while (edge) {
            printf("%d -> ", edge->edge_index);
            edge = edge->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Graph* G = create_graph();
    
    add_edge(G, 0, 1);
    add_edge(G, 0, 2);
    add_edge(G, 1, 2);
    add_edge(G, 2, 3);
    add_edge(G, 2, 4);
    add_edge(G, 3, 4);
    add_edge(G, 3, 5);
    add_edge(G, 4, 5);
    
    print_graph(G);
    
    return 0;
}