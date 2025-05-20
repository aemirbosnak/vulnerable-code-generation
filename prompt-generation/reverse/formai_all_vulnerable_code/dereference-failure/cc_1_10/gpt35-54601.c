//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct vertex {
    int data;
    struct vertex* next;
};

struct Graph {
    int V;
    int E;
    struct vertex** adjList;
};

// create a new vertex with given data
struct vertex* newVertex(int data) {
    struct vertex* newV = (struct vertex*) malloc(sizeof(struct vertex));
    newV->data = data;
    newV->next = NULL;
    return newV;
}

// create a new graph with given number of vertices
struct Graph* createGraph(int V) {
    struct Graph* G = (struct Graph*) malloc(sizeof(struct Graph));
    G->V = V;
    G->E = 0;
    G->adjList = (struct vertex**) malloc(sizeof(struct vertex*) * V);
    for(int i = 0; i < V; i++) {
        G->adjList[i] = NULL;
    }
    return G;
}

// add an edge between two vertices
void addEdge(struct Graph* G, int src, int dest) {
    struct vertex* newV = newVertex(dest);
    newV->next = G->adjList[src];
    G->adjList[src] = newV;

    newV = newVertex(src);
    newV->next = G->adjList[dest];
    G->adjList[dest] = newV;

    G->E++;
}

// print the graph in adjacency list format
void printGraph(struct Graph* G) {
    printf("Adjacency List of Graph:\n");
    for(int i = 0; i < G->V; i++) {
        printf("Vertex %d:", i);
        struct vertex* temp = G->adjList[i];
        while(temp) {
            printf("-> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    struct Graph* G = createGraph(V);
    addEdge(G, 0, 1);
    addEdge(G, 0, 4);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 3);
    addEdge(G, 3, 4);
    printGraph(G);
    return 0;
}