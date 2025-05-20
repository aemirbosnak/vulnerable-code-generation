//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure using linked lists
struct Graph {
    int num_vertices;
    struct Node **adjacency_list;
};

// Node structure for graph vertices
struct Node {
    int vertex;
    struct Node *next;
};

// Function to create a new graph with the given number of vertices
struct Graph* create_graph(int num_vertices) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = malloc(num_vertices * sizeof(struct Node*));
    for (int i = 0; i < num_vertices; i++) {
        g->adjacency_list[i] = NULL;
    }
    return g;
}

// Function to add an edge to the graph
void add_edge(struct Graph* g, int u, int v) {
    struct Node* node_u = g->adjacency_list[u];
    struct Node* node_v = g->adjacency_list[v];
    if (node_u == NULL) {
        node_u = malloc(sizeof(struct Node));
        node_u->vertex = u;
        node_u->next = g->adjacency_list[u];
        g->adjacency_list[u] = node_u;
    }
    if (node_v == NULL) {
        node_v = malloc(sizeof(struct Node));
        node_v->vertex = v;
        node_v->next = g->adjacency_list[v];
        g->adjacency_list[v] = node_v;
    }
    node_u->next = node_v;
}

// Function to traverse the graph
void traverse(struct Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        struct Node* current = g->adjacency_list[i];
        printf("%d -> ", current->vertex);
        while (current != NULL) {
            printf("%d ", current->next->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    traverse(g);
    return 0;
}