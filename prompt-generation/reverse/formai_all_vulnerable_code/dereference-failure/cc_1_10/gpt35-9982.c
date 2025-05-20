//FormAI DATASET v1.0 Category: Graph representation ; Style: Alan Touring
// Alan Turing Style C Graph Representation Example Program

#include <stdio.h>
#include <stdlib.h>

struct Vertex {
    int value;
    struct Edge* edges;
};

struct Edge {
    struct Vertex* adj_vertex;
    struct Edge* next_edge;
};

struct Graph {
    struct Vertex* vertices;
};

// function to initialize graph with given number of vertices
struct Graph* create_graph(int n) {
    struct Graph* G = (struct Graph*) malloc(sizeof(struct Graph));
    G->vertices = (struct Vertex*) malloc(n * sizeof(struct Vertex));
    int i;
    for (i = 0; i < n; i++) {
        G->vertices[i].value = i;
        G->vertices[i].edges = NULL;
    }
    return G;
}

// function to add an edge to the graph
void add_edge(struct Graph* G, int v1, int v2) {
    struct Edge* new_edge = (struct Edge*) malloc(sizeof(struct Edge));
    new_edge->adj_vertex = &G->vertices[v2];
    new_edge->next_edge = G->vertices[v1].edges;
    G->vertices[v1].edges = new_edge;
}

// function to print the graph
void print_graph(struct Graph* G) {
    int i;
    for (i = 0; i < sizeof(G->vertices); i++) {
        struct Vertex current = G->vertices[i];
        printf("Vertex %d is adjacent to:\n", current.value);
        struct Edge* e = current.edges;
        while (e != NULL) {
            printf("%d ", e->adj_vertex->value);
            e = e->next_edge;
        }
        printf("\n");
    }
}

// main function to test the graph representation
int main() {
    struct Graph* G = create_graph(6);
    add_edge(G, 0, 1);
    add_edge(G, 0, 2);
    add_edge(G, 1, 2);
    add_edge(G, 2, 3);
    add_edge(G, 3, 4);
    add_edge(G, 3, 5);
    print_graph(G);
    return 0;
}