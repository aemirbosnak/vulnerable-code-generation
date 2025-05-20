//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: complex
// Network Topology Mapper in C

#include <stdio.h>
#define MAX_NODES 100

typedef struct node {
    int id;
    char *name;
    struct node *next;
} node;

typedef struct graph {
    node *nodes[MAX_NODES];
    int num_nodes;
} graph;

// Create a new graph
graph *create_graph() {
    graph *g = (graph *)malloc(sizeof(graph));

    // Initialize the graph
    for (int i = 0; i < MAX_NODES; i++) {
        g->nodes[i] = NULL;
    }

    g->num_nodes = 0;

    return g;
}

// Add a node to the graph
void add_node(graph *g, int id, char *name) {
    if (g->num_nodes >= MAX_NODES) {
        printf("Error: Graph is full!\n");
        return;
    }

    // Create a new node
    node *new_node = (node *)malloc(sizeof(node));
    new_node->id = id;
    new_node->name = name;
    new_node->next = NULL;

    // Add the node to the graph
    g->nodes[g->num_nodes++] = new_node;
}

// Add an edge between two nodes
void add_edge(graph *g, int src, int dest) {
    if (src < 0 || src >= g->num_nodes || dest < 0 || dest >= g->num_nodes) {
        printf("Error: Invalid node IDs!\n");
        return;
    }

    // Add the edge to the source node
    node *curr = g->nodes[src];
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = g->nodes[dest];

    // Add the edge to the destination node
    curr = g->nodes[dest];
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = g->nodes[src];
}

// Print the graph
void print_graph(graph *g) {
    printf("Graph:\n");
    for (int i = 0; i < g->num_nodes; i++) {
        node *curr = g->nodes[i];
        printf("Node %d (%s): ", curr->id, curr->name);
        while (curr->next != NULL) {
            printf("%d ", curr->next->id);
            curr = curr->next;
        }
        printf("\n");
    }
}

// Free the graph
void free_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        node *curr = g->nodes[i];
        while (curr != NULL) {
            node *next = curr->next;
            free(curr);
            curr = next;
        }
    }

    free(g);
}

// Main function
int main() {
    // Create a new graph
    graph *g = create_graph();

    // Add some nodes to the graph
    add_node(g, 0, "Node 0");
    add_node(g, 1, "Node 1");
    add_node(g, 2, "Node 2");
    add_node(g, 3, "Node 3");
    add_node(g, 4, "Node 4");

    // Add some edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    // Print the graph
    print_graph(g);

    // Free the graph
    free_graph(g);

    return 0;
}