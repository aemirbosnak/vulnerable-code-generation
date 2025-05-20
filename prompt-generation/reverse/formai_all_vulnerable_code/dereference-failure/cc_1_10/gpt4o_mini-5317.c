//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists; // Array of adjacency lists
} Graph;

// Function to create a new node
Node* createNode(int vertex, int weight) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists
    graph->adjLists = malloc(vertices * sizeof(Node*));
    
    // Initialize each adjacency list as NULL
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (for undirected graph)
    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf(" -> %d (weight: %d)", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to perform DFS
void DFS(Graph* graph, int vertex, int* visited) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjacentVertex = temp->vertex;
        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to start DFS traversal
void startDFS(Graph* graph, int startVertex) {
    // Array to keep track of visited vertices
    int* visited = malloc(graph->numVertices * sizeof(int));
    
    // Initialize visited array
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    // Call DFS
    printf("DFS starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex, visited);
    printf("\n");

    // Free the visited array
    free(visited);
}

// Main function 
int main() {
    // Create a graph given in the above diagram
    Graph* graph = createGraph(5);

    // Add edges
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 8);
    addEdge(graph, 3, 4, 7);

    // Display the graph
    displayGraph(graph);

    // Perform DFS Traversal starting from vertex 0
    startDFS(graph, 0);

    // Free the graph memory
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}