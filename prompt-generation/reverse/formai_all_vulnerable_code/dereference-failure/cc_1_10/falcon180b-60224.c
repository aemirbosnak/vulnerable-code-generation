//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

// Graph node structure
typedef struct {
    int id;
    char name[20];
} GraphNode;

// Graph edge structure
typedef struct {
    int v;
    int w;
} GraphEdge;

// Graph representation using adjacency list
typedef struct {
    GraphNode nodes[MAX_NODES];
    GraphEdge edges[MAX_EDGES];
    int n;
    int m;
} Graph;

// Function to create a new graph
Graph* create_graph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = 0;
    g->m = 0;
    return g;
}

// Function to add a node to the graph
void add_node(Graph* g, int id, char* name) {
    if (g->n >= MAX_NODES) {
        printf("Error: maximum number of nodes reached.\n");
        return;
    }
    g->nodes[g->n].id = id;
    strcpy(g->nodes[g->n].name, name);
    g->n++;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int v, int w) {
    if (g->m >= MAX_EDGES) {
        printf("Error: maximum number of edges reached.\n");
        return;
    }
    g->edges[g->m].v = v;
    g->edges[g->m].w = w;
    g->m++;
}

// Function to print the graph
void print_graph(Graph* g) {
    printf("Graph:\n");
    for (int i = 0; i < g->n; i++) {
        printf("Node %d: %s\n", g->nodes[i].id, g->nodes[i].name);
    }
    printf("Edges:\n");
    for (int i = 0; i < g->m; i++) {
        printf("%d -> %d\n", g->edges[i].v, g->edges[i].w);
    }
}

int main() {
    Graph* g = create_graph();
    add_node(g, 1, "A");
    add_node(g, 2, "B");
    add_node(g, 3, "C");
    add_node(g, 4, "D");
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    print_graph(g);
    return 0;
}