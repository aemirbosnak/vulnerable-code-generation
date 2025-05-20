//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Graph structure using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int visited[MAX_VERTICES];
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Assuming it's an undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        Node* temp = graph->adjList[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth First Search (DFS) Algorithm
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjList[vertex];
    while (temp) {
        int adjacentVertex = temp->vertex;
        if (!graph->visited[adjacentVertex]) {
            DFS(graph, adjacentVertex);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal on the entire graph
void dfsTraversal(Graph* graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (!graph->visited[i]) {
            printf("DFS starting from vertex %d:\n", i);
            DFS(graph, i);
            printf("\n");
        }
    }
}

// Free memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

// Main function to demonstrate the graph operations
int main() {
    Graph* graph = createGraph();

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 5);

    // Display the graph
    printf("Graph representation:\n");
    displayGraph(graph);

    // Perform DFS traversal
    printf("\nPerforming DFS traversal:\n");
    dfsTraversal(graph);

    // Free allocated memory
    freeGraph(graph);
    
    return 0;
}