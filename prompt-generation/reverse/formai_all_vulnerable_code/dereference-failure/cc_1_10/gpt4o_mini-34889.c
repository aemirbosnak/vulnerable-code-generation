//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// A function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// A function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// A function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // As the graph is undirected, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// A function to perform DFS on the graph
void DFSUtil(int vertex, int visited[], struct Graph* graph) {
    visited[vertex] = 1;      // Mark the current vertex as visited
    printf("%d ", vertex);    // Print the vertex

    // Visit all the adjacent vertices
    struct Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;

        if (!visited[connectedVertex]) {
            DFSUtil(connectedVertex, visited, graph);
        }
        adjList = adjList->next;
    }
}

// The function to call DFS
void DFS(struct Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    // Call the recursive DFS utility function
    DFSUtil(startVertex, visited, graph);
    free(visited);
}

// A function to clean up the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}

// The artistically designed main function where magic happens
int main() {
    // Declaring number of vertices
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    // Creating a masterpiece of edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Announcing the traversal
    printf("Depth-First Traversal starting from vertex 0:\n");
    DFS(graph, 0);

    // Allocating memory gracefully
    freeGraph(graph);
    return 0;
}