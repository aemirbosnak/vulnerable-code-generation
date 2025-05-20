//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with numVertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjLists = malloc(numVertices * sizeof(struct Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Add edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // As it's an undirected graph, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Recursive DFS function
void dfsRecursive(struct Graph* graph, int vertex, int* visited) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            dfsRecursive(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal from a given start vertex
void dfs(struct Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));

    // Initialize visited array
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    // Call the recursive DFS function
    dfsRecursive(graph, startVertex, visited);

    free(visited);
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("\n Adjacency list of vertex %d:\n head ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to demonstrate graph implementation
int main() {
    // Create the graph
    struct Graph* graph = createGraph(5);

    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency list representation of the graph
    printGraph(graph);

    // Perform DFS traversal
    printf("\nDepth First Traversal (starting from vertex 0): ");
    dfs(graph, 0);
    printf("\n");

    // Free allocated memory (not fully implemented for brevity)
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