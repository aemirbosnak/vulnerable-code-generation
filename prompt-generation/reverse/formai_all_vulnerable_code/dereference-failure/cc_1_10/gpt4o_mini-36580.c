//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Node* createNode(int);

// Function to create a graph of n vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Create a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\n Vertex %d:", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth First Search (DFS) algorithm
void dfs(Graph* graph, int vertex, int* visited) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (visited[connectedVertex] == 0) {
            dfs(graph, connectedVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to initiate DFS
void startDFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));
    
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    dfs(graph, startVertex, visited);
    
    free(visited);
}

// Main function to demonstrate graph
int main() {
    // Create a new graph
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Perform Depth First Search
    printf("\nDepth First Search Starting from vertex 0:\n");
    startDFS(graph, 0);
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            Node* toBeFreed = temp;
            temp = temp->next;
            free(toBeFreed);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}