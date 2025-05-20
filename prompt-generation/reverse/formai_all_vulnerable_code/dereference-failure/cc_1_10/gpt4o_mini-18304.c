//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Node structure for the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the graph
void displayGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Recursive function for DFS traversal
void DFSUtil(int v, int visited[], struct Graph* graph) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adjLists[v];
    while (temp) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex])
            DFSUtil(connectedVertex, visited, graph);
        temp = temp->next;
    }
}

// Function to perform DFS
void DFS(struct Graph* graph) {
    int* visited = malloc(graph->numVertices * sizeof(int));

    // Mark all the vertices as not visited
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    // Call the recursive helper to print DFS traversal starting from vertex 0
    printf("Depth First Traversal starting from vertex 0:\n");
    DFSUtil(0, visited, graph);
    free(visited);
}

// Main function
int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    displayGraph(graph);
    DFS(graph);

    // Memory cleanup
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}