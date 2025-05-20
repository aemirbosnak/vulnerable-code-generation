//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Graph structure using linked lists
struct Graph {
    int num_vertices;
    struct Node **adjacency_list;
};

// Node structure using linked lists
struct Node {
    int label;
    struct Node *next, *prev;
};

// Function to create a new graph
struct Graph *new_graph(int num_vertices) {
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = (struct Node **)malloc(num_vertices * sizeof(struct Node *));
    for (int i = 0; i < num_vertices; i++) {
        g->adjacency_list[i] = NULL;
    }
    return g;
}

// Function to add a new vertex to the graph
void add_vertex(struct Graph *g, int label) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->label = label;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (g->num_vertices == 0) {
        g->adjacency_list[0] = new_node;
    } else {
        g->adjacency_list[g->num_vertices - 1] = new_node;
    }
    g->num_vertices++;
}

// Function to add an edge to the graph
void add_edge(struct Graph *g, int src, int dest) {
    struct Node *src_node = g->adjacency_list[src];
    struct Node *dest_node = g->adjacency_list[dest];
    if (src_node->next == NULL) {
        src_node->next = dest_node;
    } else {
        src_node->next->prev = dest_node;
    }
    dest_node->prev = src_node;
    src_node->next = dest_node;
    dest_node->next = NULL;
}

// Function to print the graph
void print_graph(struct Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        struct Node *curr = g->adjacency_list[i];
        printf("%d -> ", curr->label);
        while (curr->next != NULL) {
            printf("%d, ", curr->next->label);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph *g = new_graph(5);
    add_vertex(g, 1);
    add_vertex(g, 2);
    add_vertex(g, 3);
    add_vertex(g, 4);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    print_graph(g);
    return 0;
}