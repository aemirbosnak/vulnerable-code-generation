//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int node;
    int weight;
    int num_edges;
} Node;

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Node *nodes;
    Edge *edges;
} Graph;

int main() {
    Graph graph;
    int num_nodes = 4;
    int num_edges = 6;
    
    graph.num_nodes = num_nodes;
    graph.num_edges = num_edges;
    
    Node *nodes = (Node *)malloc(num_nodes * sizeof(Node));
    Edge *edges = (Edge *)malloc(num_edges * sizeof(Edge));
    
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].node = i;
        nodes[i].weight = 0;
        nodes[i].num_edges = 0;
    }
    
    for (int i = 0; i < num_edges; i++) {
        edges[i].source = i / 2;
        edges[i].destination = i % 2;
        edges[i].weight = 1;
    }
    
    graph.nodes = nodes;
    graph.edges = edges;
    
    printf("Graph representation:\n");
    printf("Nodes: ");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", nodes[i].node);
    }
    printf("\nEdges: ");
    for (int i = 0; i < num_edges; i++) {
        printf("%d (%d) -> (%d) (%d)\n", edges[i].source, edges[i].weight, edges[i].destination, edges[i].weight);
    }
    
    free(nodes);
    free(edges);
    
    return 0;
}