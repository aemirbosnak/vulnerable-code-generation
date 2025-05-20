//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_EDGES 100

struct node {
    int id;
    struct node *next;
};

struct edge {
    int src;
    int dest;
};

struct graph {
    int num_nodes;
    int num_edges;
    struct node *adj_list[MAX_NODES];
    struct edge edge_list[MAX_EDGES];
};

// Function to create a new node
struct node* create_node(int id) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->id = id;
    new_node->next = NULL;
    return new_node;
}

// Function to add an edge to the graph
void add_edge(struct graph *G, int src, int dest) {
    struct node *new_node = create_node(dest);
    new_node->next = G->adj_list[src];
    G->adj_list[src] = new_node;
    G->edge_list[G->num_edges].src = src;
    G->edge_list[G->num_edges].dest = dest;
    G->num_edges++;
}

// Function to print the topology of the network
void print_topology(struct graph G) {
    printf("Topology of the network:\n");
    for (int i = 0; i < G.num_nodes; i++) {
        printf("Node %d:", i);
        struct node *curr = G.adj_list[i];
        while (curr != NULL) {
            printf(" %d", curr->id);
            curr = curr->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct graph G;
    G.num_nodes = 4;
    G.num_edges = 0;
    for (int i = 0; i < G.num_nodes; i++) {
        G.adj_list[i] = NULL;
    }
    add_edge(&G, 0, 1);
    add_edge(&G, 0, 2);
    add_edge(&G, 1, 2);
    add_edge(&G, 2, 3);
    print_topology(G);
    return 0;
}