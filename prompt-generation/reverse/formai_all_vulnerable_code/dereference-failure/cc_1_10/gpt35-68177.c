//FormAI DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct graph {
    int vertices;
    int edges;
    int **adj_matrix;
} Graph;

Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* newGraph = malloc(sizeof(Graph));
    newGraph->vertices = vertices;
    newGraph->edges = 0;
    newGraph->adj_matrix = malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        newGraph->adj_matrix[i] = calloc(vertices, sizeof(int));
    }
    return newGraph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->adj_matrix[dest][src] = 1;
    graph->edges++;
}

void printGraph(Graph* graph) {
    printf("Number of vertices: %d\n", graph->vertices);
    printf("Number of edges: %d\n", graph->edges);
    printf("Adjacency matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    
    printGraph(graph);
    return 0;
}