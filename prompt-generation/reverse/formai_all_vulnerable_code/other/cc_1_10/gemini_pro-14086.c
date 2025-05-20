//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 5

// Cyberpunk-themed graph data structure
typedef struct Node {
    int id;
    char *label;
    struct Node *next;
} Node;

typedef struct Graph {
    int num_nodes;
    Node *nodes;
} Graph;

// Create a new graph with n nodes
Graph *create_graph(int n) {
    Graph *g = malloc(sizeof(Graph));
    assert(g);
    g->num_nodes = n;
    g->nodes = malloc(n * sizeof(Node));
    assert(g->nodes);
    for (int i = 0; i < n; i++) {
        g->nodes[i].id = i;
        g->nodes[i].label = NULL;
        g->nodes[i].next = NULL;
    }
    return g;
}

// Add an edge between two nodes in the graph
void add_edge(Graph *g, int node1, int node2) {
    assert(node1 >= 0 && node1 < g->num_nodes);
    assert(node2 >= 0 && node2 < g->num_nodes);
    Node *new_node = malloc(sizeof(Node));
    assert(new_node);
    new_node->id = node2;
    new_node->label = NULL;
    new_node->next = g->nodes[node1].next;
    g->nodes[node1].next = new_node;
}

// Free the memory allocated for the graph
void free_graph(Graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        Node *node = g->nodes[i].next;
        while (node) {
            Node *next = node->next;
            free(node);
            node = next;
        }
    }
    free(g->nodes);
    free(g);
}

// Cyberpunk-themed graph coloring function
void color_graph(Graph *g) {
    int colors[N] = {0}; // Initialize all colors to black
    for (int i = 0; i < g->num_nodes; i++) {
        Node *node = g->nodes[i].next;
        while (node) {
            if (colors[node->id] == colors[i]) {
                // Cyberpunk-themed error message
                printf("Error: Nodes %d and %d cannot be the same color!\n", i, node->id);
                exit(1);
            }
            node = node->next;
        }
        // Cyberpunk-themed color assignment
        colors[i] = rand() % 3 + 1; // Assign a random color (1-3) to the node
        printf("Node %d colored %d\n", i, colors[i]);
    }
}

int main() {
    // Cyberpunk-themed graph creation
    Graph *g = create_graph(N);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    // Cyberpunk-themed graph coloring
    color_graph(g);

    // Cyberpunk-themed graph cleanup
    free_graph(g);

    return 0;
}