//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Edge {
    Node* src;
    Node* dest;
} Edge;

typedef struct Graph {
    int numVertices;
    Node** vertices;
    Edge** edges;
} Graph;

void addEdge(Graph* graph, int src, int dest) {
    Edge* newEdge = (Edge*) malloc(sizeof(Edge));
    newEdge->src = &graph->vertices[src];
    newEdge->dest = &graph->vertices[dest];
    graph->edges = realloc(graph->edges, sizeof(Edge) * (graph->numVertices + 1));
    graph->edges[graph->numVertices++] = newEdge;
}

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->vertices = (Node**) calloc(numVertices, sizeof(Node*));
    for (int i = 0; i < numVertices; ++i) {
        graph->vertices[i] = (Node*) malloc(sizeof(Node));
        graph->vertices[i]->data = i;
        graph->vertices[i]->next = NULL;
    }
    graph->edges = (Edge*) calloc(numVertices, sizeof(Edge));
    return graph;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("Vertex %d: ", i);
        for (Node* current = graph->vertices[i]; current != NULL; current = current->next) {
            printf("-> %d", current->data);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printGraph(graph);

    return 0;
}