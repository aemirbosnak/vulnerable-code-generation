//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a node structure
typedef struct {
    int id;
    int degree;
    int* neighbors;
} node_t;

// Define a graph structure
typedef struct {
    int num_nodes;
    int num_edges;
    node_t* nodes;
} graph_t;

// Helper functions
void add_neighbor(node_t* node, int neighbor) {
    node->degree++;
    node->neighbors = realloc(node->neighbors, node->degree * sizeof(int));
    node->neighbors[node->degree - 1] = neighbor;
}

void add_edge(graph_t* graph, int node1, int node2) {
    node_t* node1_ptr = &graph->nodes[node1];
    node_t* node2_ptr = &graph->nodes[node2];
    add_neighbor(node1_ptr, node2);
    add_neighbor(node2_ptr, node1);
}

// Main function
int main() {
    // Define the graph
    graph_t graph = {
       .num_nodes = 6,
       .num_edges = 7,
       .nodes = malloc(graph.num_nodes * sizeof(node_t))
    };

    // Initialize the nodes
    for (int i = 0; i < graph.num_nodes; i++) {
        graph.nodes[i].id = i;
        graph.nodes[i].degree = 0;
        graph.nodes[i].neighbors = NULL;
    }

    // Add edges to the graph
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 4, 5);

    // Print the graph
    for (int i = 0; i < graph.num_nodes; i++) {
        printf("Node %d (degree: %d): ", i, graph.nodes[i].degree);
        for (int j = 0; j < graph.nodes[i].degree; j++) {
            printf("%d ", graph.nodes[i].neighbors[j]);
        }
        printf("\n");
    }

    return 0;
}