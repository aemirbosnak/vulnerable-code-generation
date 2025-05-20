//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define number of vertices in the graph
#define MAX_VERTICES 10

// Structure for an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the adjacency list
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for the array of adjacency lists
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest (directed)
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graphs, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("\n Vertex %d:\n head", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to perform Depth First Search
void DFSUtil(int v, int visited[], struct Graph* graph) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adjLists[v];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex, visited, graph);
        }
        temp = temp->next;
    }
}

// Function to perform DFS on the entire graph
void DFS(struct Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));

    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    for (int v = 0; v < graph->numVertices; v++) {
        if (!visited[v])
            DFSUtil(v, visited, graph);
    }
    
    free(visited);
}

// Function to free the graph
void freeGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    struct Graph* graph = createGraph(MAX_VERTICES);

    // Creating edges between vertices
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 4, 7);
    addEdge(graph, 4, 8);
    
    // Print graph adjacency list
    printf("Graph adjacency list:\n");
    printGraph(graph);
    
    // Perform DFS on the graph
    printf("\nDepth First Search starting from vertex 0:\n");
    DFS(graph);
    
    // Free the allocated memory for the graph
    freeGraph(graph);

    return 0;
}