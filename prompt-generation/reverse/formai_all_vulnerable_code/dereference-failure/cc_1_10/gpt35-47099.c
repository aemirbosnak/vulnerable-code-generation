//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
// A minimalist implementation of Graph ADT using Adjacency Lists

#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int dest;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int V;
    Edge** adjList;
} Graph;

Graph* createGraph(int V) {
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->V = V;
    G->adjList = (Edge**)calloc(V, sizeof(Edge*));
    return G;
}

void addEdge(Graph* G, int src, int dest) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->dest = dest;
    e->next = G->adjList[src];
    G->adjList[src] = e;
}

void printGraph(Graph* G) {
    printf("Graph Details:\n");
    printf("Vertices: %d\n\n", G->V);
    for (int i = 0; i < G->V; i++) {
        printf("Vertex %d: ", i);
        Edge* e = G->adjList[i];
        while (e != NULL) {
            printf("%d -> ", e->dest);
            e = e->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Graph* G = createGraph(5);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 3);
    addEdge(G, 3, 4);
    printGraph(G);
    return 0;
}