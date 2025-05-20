//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_EDGES 45

typedef struct Edge {
    int src;
    int dest;
} Edge;

typedef struct Graph {
    int V;
    int E;
    Edge* edges[MAX_EDGES];
} Graph;

void init_graph(Graph* G, int V) {
    G->V = V;
    G->E = 0;
    for(int i = 0; i < MAX_EDGES; i++) {
        G->edges[i] = NULL;
    }
}

void add_edge(Graph* G, int src, int dest) {
    if(G->E == MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        return;
    }
    
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    
    G->edges[G->E] = edge;
    G->E++;
}

void print_graph(Graph* G) {
    for(int i = 0; i < G->E; i++) {
        Edge* edge = G->edges[i];
        printf("(%d,%d)\n", edge->src, edge->dest);
    }
}

int main() {
    Graph* G = (Graph*)malloc(sizeof(Graph));
    int V = 5;
    init_graph(G, V);
    
    add_edge(G, 0, 1);
    add_edge(G, 0, 4);
    add_edge(G, 1, 2);
    add_edge(G, 1, 3);
    add_edge(G, 1, 4);
    add_edge(G, 2, 3);
    add_edge(G, 3, 4);
    
    printf("Edges in the network topology:\n");
    print_graph(G);
    
    return 0;
}