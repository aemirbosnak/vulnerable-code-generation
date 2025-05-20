//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct Edge {
    int dest;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int V;
    int E;
    Edge** adj;
} Graph;

Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = 0;
    graph->adj = (Edge**) calloc(V, sizeof(Edge*));
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Edge* newEdge = (Edge*) malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->next = graph->adj[src];
    graph->adj[src] = newEdge;
    graph->E++;
}

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->V; ++v) {
        printf("\nVertex %d: ", v);
        Edge* edge = graph->adj[v];
        while (edge != NULL) {
            printf(" -> %d", edge->dest);
            edge = edge->next;
        }
    }
}

void freeGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->V; ++v) {
        Edge* current = graph->adj[v];
        while (current != NULL) {
            Edge* temp = current;
            current = current->next;
            free(temp);
        }
        free(graph->adj[v]);
    }
    free(graph->adj);
    free(graph);
}

int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 1);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);

    printf("Graph representation:\n");
    printGraph(graph);

    freeGraph(graph);

    return 0;
}