//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Graph representation using an adjacency list
struct AdjListNode {
    int vertex;
    struct AdjListNode *next;
};

struct Graph {
    int numVertices;
    struct AdjListNode **adjLists; // Array of adjacency lists
};

// Create a new graph with n vertices
struct Graph *createGraph(int n) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = n;

    // Create an array of adjacency lists
    graph->adjLists = (struct AdjListNode **)malloc(n * sizeof(struct AdjListNode *));

    // Initialize all adjacency lists to NULL
    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    // Create a new adjacency list node
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->vertex = dest;
    newNode->next = NULL;

    // Add the new node to the adjacency list of the source vertex
    struct AdjListNode *temp = graph->adjLists[src];
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print the graph
void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct AdjListNode *temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Free the graph
void freeGraph(struct Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct AdjListNode *temp = graph->adjLists[i];
        while (temp != NULL) {
            struct AdjListNode *next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(graph->adjLists);
    free(graph);
}

int main() {
    // Create a graph with 5 vertices
    struct Graph *graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Print the graph
    printGraph(graph);

    // Free the graph
    freeGraph(graph);

    return 0;
}