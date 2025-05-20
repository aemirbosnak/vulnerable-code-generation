//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 50

// Structure to represent a node in the graph
typedef struct {
    char name[50];  // Name of the node
    int weight;     // Weight of the node (used for layout)
    int edges[MAX_EDGES];  // Edges connecting to other nodes
} Node;

// Structure to represent an edge in the graph
typedef struct {
    int src;  // Source node index
    int dest;  // Destination node index
    int weight;  // Weight of the edge
} Edge;

// Function to generate a random graph
void generate_graph(Node *nodes, int num_nodes, Edge *edges, int num_edges) {
    int i, j, k;
    for (i = 0; i < num_nodes; i++) {
        // Generate a random name for the node
        snprintf(nodes[i].name, sizeof(nodes[i].name), "Node %d", i);
        // Generate a random weight for the node
        nodes[i].weight = (int) (rand() % 100) + 1;
        // Generate random edges for the node
        for (j = 0; j < MAX_EDGES; j++) {
            Edge e;
            e.src = i;
            e.dest = (int) (rand() % num_nodes);
            e.weight = (int) (rand() % 100) + 1;
            edges[num_edges++] = e;
        }
    }
}

// Function to print the graph
void print_graph(Node *nodes, int num_nodes, Edge *edges, int num_edges) {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        printf("%s (%d) ", nodes[i].name, nodes[i].weight);
        for (j = 0; j < num_edges; j++) {
            if (edges[j].src == i) {
                printf(" -> %s (%d) ", edges[j].dest, edges[j].weight);
            }
        }
        printf("\n");
    }
}

int main() {
    int i, num_nodes, num_edges;
    Node *nodes;
    Edge *edges;

    // Generate a random graph with 50 nodes and 100 edges
    num_nodes = 50;
    num_edges = 100;
    nodes = calloc(num_nodes, sizeof(Node));
    edges = calloc(num_edges, sizeof(Edge));
    generate_graph(nodes, num_nodes, edges, num_edges);

    // Print the graph
    print_graph(nodes, num_nodes, edges, num_edges);

    // Free memory
    free(nodes);
    free(edges);

    return 0;
}