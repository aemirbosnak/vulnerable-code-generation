//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node **adj;
};

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int v, int w) {
    graph->adj[v] = (graph->adj[v])? graph->adj[v] : (graph->adj[v] = (struct Node*) malloc(sizeof(struct Node)));
    struct Node* last = (graph->adj[v])->next;
    (graph->adj[v])->next = (struct Node*) malloc(sizeof(struct Node));
    (graph->adj[v])->next->data = w;
    (graph->adj[v])->next->next = last;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < graph->V; i++) {
        struct Node* node = graph->adj[i];
        printf("Vertex %d is connected to: ", i);
        while (node!= NULL) {
            printf(" %d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

// Function to generate a random graph
void generateRandomGraph(struct Graph* graph, int V, int E) {
    int i, j;
    srand(time(NULL));
    graph->V = V;
    graph->adj = (struct Node**) malloc(V * sizeof(struct Node*));
    for (i = 0; i < V; i++)
        graph->adj[i] = NULL;

    int count = 0;
    while (count < E) {
        int v = rand() % V;
        int w = rand() % V;
        if (v!= w &&!graph->adj[v]) {
            addEdge(graph, v, w);
            count++;
        }
    }
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    generateRandomGraph(graph, V, E);
    printGraph(graph);

    return 0;
}