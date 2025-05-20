//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Graph {
    int V;
    int E;
    struct Node **adj;
};

struct Node {
    int vertex;
    int distance;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (struct Node **)malloc(V * sizeof(struct Node *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->distance = w;
    graph->adj[u] = newNode;
    newNode->distance = w;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d %d\n", i, graph->adj[i]->distance);
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    struct Graph* graph = createGraph(V, E);
    printf("Enter vertices and their distance: ");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }
    printGraph(graph);
    return 0;
}