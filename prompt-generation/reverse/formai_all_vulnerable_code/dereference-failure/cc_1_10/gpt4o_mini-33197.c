//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A structure to represent a graph using an adjacency list representation
struct AdjListNode {
    int dest; // Destination vertex
    struct AdjListNode* next; // Pointer to the next node in the adjacency list
};

// An adjacency list is represented as an array of pointers
struct AdjList {
    struct AdjListNode* head; // Pointer to the head node of the list
};

// A structure to represent a graph
struct Graph {
    int vertices; // Number of vertices
    struct AdjList* array; // Array of adjacency lists
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Create an array of adjacency lists
    graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));

    // Initialize each adjacency list
    for (int i = 0; i < vertices; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to the undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head; // Point to the previous head
    graph->array[src].head = newNode; // Update head to new node

    // Since the graph is undirected, add an edge from dest to src
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->vertices; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Function to perform DFS starting from a given vertex
void DFSUtil(int v, bool visited[], struct Graph* graph) {
    visited[v] = true; // Mark the current vertex as visited
    printf("%d ", v); // Print the vertex

    struct AdjListNode* pCrawl = graph->array[v].head; // Get the adjacency list of v
    while (pCrawl) {
        if (!visited[pCrawl->dest]) { // If the vertex is not visited
            DFSUtil(pCrawl->dest, visited, graph); // Recur for the vertex
        }
        pCrawl = pCrawl->next;
    }
}

// Function to initiate the DFS traversal
void DFS(struct Graph* graph) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool)); // Create an array to track visited vertices
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false; // Initialize all vertices as not visited
    }

    // Call DFS for each vertex to cover all components
    for (int v = 0; v < graph->vertices; v++) {
        if (!visited[v]) {
            printf("\nDFS starting from vertex %d:\n", v);
            DFSUtil(v, visited, graph);
        }
    }
    free(visited); // Free dynamically allocated memory
}

// The main function to demonstrate the graph and its functionality
int main() {
    int vertices = 5; // Number of vertices in the graph
    struct Graph* graph = createGraph(vertices); // Create the graph

    // Creating edges in the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency list representation of the graph
    printGraph(graph);

    // Perform DFS traversal
    DFS(graph);

    // Free the graph memory (not shown for simplicity)
    // Ideally, we need to free each adjacency list too
    free(graph->array);
    free(graph);

    return 0;
}