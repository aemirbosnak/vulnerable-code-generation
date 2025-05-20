//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure representing a graph node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure representing the graph
typedef struct Graph {
    int numVertices;    
    Node** adjLists;    
} Graph;

// Create a node in the adjacency list
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create the graph with a maximum number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists
    graph->adjLists = malloc(vertices * sizeof(Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Add an edge between two vertices
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (because this is an undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth-First Search (DFS) algorithm
void DFS(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;  // Mark the current node as visited
    printf("%d ", vertex); // Print the visited vertex

    // Recur for all the vertices adjacent to this vertex
    Node* adjNode = graph->adjLists[vertex];
    while (adjNode != NULL) {
        int connectedVertex = adjNode->vertex;
        if (!visited[connectedVertex]) {
            DFS(graph, connectedVertex, visited);
        }
        adjNode = adjNode->next;
    }
}

// Breadth-First Search (BFS) algorithm
void BFS(Graph* graph, int startVertex) {
    int visited[MAX_NODES] = {0}; // Initialize all vertices as not visited
    Node* queue[MAX_NODES];       // Queue for BFS
    int front = -1, rear = -1;    // Front and rear indices

    visited[startVertex] = 1; // Mark the start vertex as visited
    queue[++rear] = createNode(startVertex); // Enqueue it
    printf("BFS starting from vertex %d: ", startVertex);

    while (front < rear) {
        Node* currentNode = queue[++front]; // Dequeue
        int currentVertex = currentNode->vertex;
        printf("%d ", currentVertex); // Print the visited vertex

        Node* adjNode = graph->adjLists[currentVertex];
        while (adjNode != NULL) {
            int adjVertex = adjNode->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1; // Mark it as visited
                queue[++rear] = createNode(adjVertex); // Enqueue
            }
            adjNode = adjNode->next;
        }
    }
}

// Function to delete the graph
void deleteGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* adjNode = graph->adjLists[i];
        while (adjNode != NULL) {
            Node* temp = adjNode;
            adjNode = adjNode->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph);
}

// Main function to demonstrate the graph operations
int main() {
    Graph* graph = createGraph(5);  // Create a graph with 5 vertices
    
    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Perform DFS
    int visited[MAX_NODES] = {0}; // Reset visited for DFS
    printf("Depth First Search: ");
    DFS(graph, 0, visited);
    printf("\n");

    // Perform BFS
    BFS(graph, 0);
    printf("\n");

    // Deleting the graph to free memory
    deleteGraph(graph);

    return 0;
}