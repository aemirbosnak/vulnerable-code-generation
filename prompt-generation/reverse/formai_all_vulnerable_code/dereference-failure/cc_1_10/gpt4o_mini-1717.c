//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node** adjLists;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
Node* createNode(int data);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void depthFirstSearch(Graph* graph, int start);
void depthFirstSearchUtil(Graph* graph, int vertex, int visited[]);
void freeGraph(Graph* graph);

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph adjacency list representation:\n");
    printGraph(graph);

    printf("\nDepth-First Search starting from vertex 0:\n");
    depthFirstSearch(graph, 0);

    freeGraph(graph);
    return 0;
}

// Create a graph with the given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Create a new node for the adjacency list
Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print the graph adjacency list
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->vertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\nVertex %d:", v);
        while (temp) {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth First Search algorithm util
void depthFirstSearchUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            depthFirstSearchUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Depth First Search
void depthFirstSearch(Graph* graph, int start) {
    int* visited = malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++)
        visited[i] = 0;

    depthFirstSearchUtil(graph, start, visited);
    free(visited);
}

// Free the graph's allocated memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}