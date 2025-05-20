//GEMINI-pro DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of nodes in the graph
#define MAX_NODES 100

// Define the maximum number of edges in the graph
#define MAX_EDGES 1000

// Define the maximum length of a node name
#define MAX_NAME_LENGTH 32

// Define the maximum number of connections for each node
#define MAX_CONNECTIONS 10

// Define the type of a node
typedef struct node {
    char name[MAX_NAME_LENGTH];
    int num_connections;
    int connections[MAX_CONNECTIONS];
} node;

// Define the type of a graph
typedef struct graph {
    int num_nodes;
    int num_edges;
    node nodes[MAX_NODES];
} graph;

// Create a new graph
graph* create_graph() {
    graph* g = (graph*)malloc(sizeof(graph));
    g->num_nodes = 0;
    g->num_edges = 0;
    return g;
}

// Add a node to the graph
void add_node(graph* g, char* name) {
    if (g->num_nodes >= MAX_NODES) {
        printf("Error: cannot add more nodes to the graph\n");
        return;
    }
    strcpy(g->nodes[g->num_nodes].name, name);
    g->nodes[g->num_nodes].num_connections = 0;
    g->num_nodes++;
}

// Add an edge to the graph
void add_edge(graph* g, char* node1, char* node2) {
    if (g->num_edges >= MAX_EDGES) {
        printf("Error: cannot add more edges to the graph\n");
        return;
    }
    int node1_index = -1;
    int node2_index = -1;
    for (int i = 0; i < g->num_nodes; i++) {
        if (strcmp(g->nodes[i].name, node1) == 0) {
            node1_index = i;
        } else if (strcmp(g->nodes[i].name, node2) == 0) {
            node2_index = i;
        }
    }
    if (node1_index == -1 || node2_index == -1) {
        printf("Error: cannot find nodes %s and %s in the graph\n", node1, node2);
        return;
    }
    g->nodes[node1_index].connections[g->nodes[node1_index].num_connections] = node2_index;
    g->nodes[node1_index].num_connections++;
    g->nodes[node2_index].connections[g->nodes[node2_index].num_connections] = node1_index;
    g->nodes[node2_index].num_connections++;
    g->num_edges++;
}

// Print the graph
void print_graph(graph* g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("%s: ", g->nodes[i].name);
        for (int j = 0; j < g->nodes[i].num_connections; j++) {
            printf("%s, ", g->nodes[g->nodes[i].connections[j]].name);
        }
        printf("\n");
    }
}

// Free the graph
void free_graph(graph* g) {
    free(g);
}

// Main function
int main() {
    // Create a new graph
    graph* g = create_graph();

    // Add some nodes to the graph
    add_node(g, "Alice");
    add_node(g, "Bob");
    add_node(g, "Carol");
    add_node(g, "Dave");
    add_node(g, "Eve");

    // Add some edges to the graph
    add_edge(g, "Alice", "Bob");
    add_edge(g, "Alice", "Carol");
    add_edge(g, "Bob", "Carol");
    add_edge(g, "Bob", "Dave");
    add_edge(g, "Carol", "Dave");
    add_edge(g, "Carol", "Eve");
    add_edge(g, "Dave", "Eve");

    // Print the graph
    print_graph(g);

    // Free the graph
    free_graph(g);

    return 0;
}