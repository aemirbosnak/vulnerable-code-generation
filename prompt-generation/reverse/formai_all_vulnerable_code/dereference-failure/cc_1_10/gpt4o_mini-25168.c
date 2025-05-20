//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defined constants for maximum number of nodes and the size of the label
#define MAX_NODES 100
#define LABEL_SIZE 30

// Structure for a Graph node which contains vertex and next pointer
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for a graph which contains an array of adjacency lists
typedef struct Graph {
    int numVertices;
    Node* adjacencyLists[MAX_NODES];
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
Node* createNode(int vertex);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void depthFirstSearch(Graph* graph, int startVertex, int* visited);
void visualizeGraph(Graph* graph);

// Main function to test graph structure and its visualization
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

    printf("\nDepth First Search starting from vertex 0:\n");
    int visited[MAX_NODES] = {0}; // Track visited nodes
    depthFirstSearch(graph, 0, visited);

    printf("\nVisualizing graph:\n");
    visualizeGraph(graph);
    
    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph->adjacencyLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
    
    return 0;
}

// Function to create a graph with a specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyLists[i] = NULL;
    }
    
    return graph;
}

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyLists[src];
    graph->adjacencyLists[src] = newNode;

    // Add edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjacencyLists[dest];
    graph->adjacencyLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjacencyLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Recursive function for depth-first search
void depthFirstSearch(Graph* graph, int startVertex, int* visited) {
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    Node* temp = graph->adjacencyLists[startVertex];
    while (temp) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            depthFirstSearch(graph, connectedVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to visualize the graph in a simple textual representation
void visualizeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        Node* temp = graph->adjacencyLists[i];
        while (temp) {
            printf("-----> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}