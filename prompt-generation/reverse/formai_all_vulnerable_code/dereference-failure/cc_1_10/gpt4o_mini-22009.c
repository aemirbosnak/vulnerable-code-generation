//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Node structure for an adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V; // Number of vertices
    struct Node** adjLists; // Array of adjacency lists
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists
    graph->adjLists = malloc(V * sizeof(struct Node*));

    // Initialize each adjacency list
    for (int i = 0; i < V; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to create a new adjacency list node
struct Node* createNode(int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the graph
void displayGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("\n Vertex %d:\n head", v);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf(" -> NULL");
    }
}

// Function for Depth First Search
void DFS(struct Graph* graph, int vertex, int* visited) {
    // Mark the current node as visited and print it
    visited[vertex] = 1;
    printf(" %d", vertex);

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal from a given start vertex
void performDFS(struct Graph* graph, int startVertex) {
    int* visited = malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0; // Initialize the visited array
    }

    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex, visited);
    free(visited);
}

// Main function to execute the program
int main() {
    int numVertices = 5; // Let's have 5 vertices
    struct Graph* graph = createGraph(numVertices); // Create the graph

    // Add edges to our amazing graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Display the graph
    printf("Graph representation:\n");
    displayGraph(graph);

    // Perform DFS
    performDFS(graph, 0);

    // Free allocated memory
    for (int i = 0; i < numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* deleteNode = temp;
            temp = temp->next;
            free(deleteNode);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}