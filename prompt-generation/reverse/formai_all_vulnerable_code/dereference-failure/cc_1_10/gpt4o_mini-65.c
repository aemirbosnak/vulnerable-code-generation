//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure for a graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array; // Array of adjacency lists
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists and initialize them
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Recursive function to perform DFS traversal
void DFSUtil(int v, int visited[], struct Graph* graph) {
    // Mark the current node as visited and print it
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    struct AdjListNode* adjListNode = graph->array[v].head;
    while (adjListNode != NULL) {
        int connectedVertex = adjListNode->dest;

        if (!visited[connectedVertex]) {
            DFSUtil(connectedVertex, visited, graph);
        }
        adjListNode = adjListNode->next;
    }
}

// Function to perform DFS on the graph
void DFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int));

    // Initialize all vertices as not visited
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    // Call the recursive DFS utility function
    DFSUtil(startVertex, visited, graph);

    free(visited);
}

// Function to free the graph's memory
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct AdjListNode* current = graph->array[i].head;
        while (current != NULL) {
            struct AdjListNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

// Main function to demonstrate the graph implementation
int main() {
    // Create a graph
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Add edges (friendships) between users
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency list representation of the graph
    printf("Adjacency list representation of the graph:\n");
    for (int i = 0; i < V; i++) {
        struct AdjListNode* current = graph->array[i].head;
        printf("User %d: ", i);
        while (current != NULL) {
            printf("-> %d ", current->dest);
            current = current->next;
        }
        printf("\n");
    }

    // Perform DFS starting from vertex 0
    printf("\nDepth First Traversal starting from user 0:\n");
    DFS(graph, 0);

    // Free the graph memory
    freeGraph(graph);

    return 0;
}