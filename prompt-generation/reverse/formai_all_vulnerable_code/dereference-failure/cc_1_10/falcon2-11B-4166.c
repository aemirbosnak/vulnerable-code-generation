//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

// Define a struct to hold the graph data
typedef struct {
    int num_nodes;
    int num_edges;
    bool* visited;
    int** adjacency_list;
} Graph;

// Function to initialize the graph
void init_graph(Graph* graph, int num_nodes) {
    graph->num_nodes = num_nodes;
    graph->num_edges = 0;
    graph->visited = (bool*)malloc(sizeof(bool) * num_nodes);
    memset(graph->visited, 0, sizeof(bool) * num_nodes);
    graph->adjacency_list = (int**)malloc(sizeof(int*) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adjacency_list[i] = (int*)malloc(sizeof(int) * MAX_EDGES);
        memset(graph->adjacency_list[i], 0, sizeof(int) * MAX_EDGES);
    }
}

// Function to add an edge to the graph
void add_edge(Graph* graph, int node1, int node2, bool bidirectional) {
    if (graph->adjacency_list[node1][graph->num_edges] == 0) {
        graph->adjacency_list[node1][graph->num_edges++] = node2;
    }
    if (bidirectional) {
        add_edge(graph, node2, node1, true);
    }
}

// Function to check if two nodes are connected in the graph
bool connected(Graph* graph, int node1, int node2) {
    if (graph->adjacency_list[node1][graph->num_edges] == 0) {
        return false;
    }
    int* neighbors = graph->adjacency_list[node1];
    for (int i = 0; i < graph->num_edges; i++) {
        if (neighbors[i] == node2) {
            return true;
        }
    }
    return false;
}

// Function to print the graph representation
void print_graph(Graph* graph) {
    printf("Graph Representation:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d ", i);
        for (int j = 0; j < graph->num_edges; j++) {
            printf("%d ", graph->adjacency_list[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Graph graph;
    init_graph(&graph, 5);
    add_edge(&graph, 0, 1, false);
    add_edge(&graph, 1, 2, false);
    add_edge(&graph, 2, 3, false);
    add_edge(&graph, 3, 0, false);
    add_edge(&graph, 0, 3, false);
    print_graph(&graph);
    return 0;
}