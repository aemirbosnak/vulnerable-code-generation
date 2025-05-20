//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
typedef struct Node {
    int destination;
    struct Node* next;
} Node;

// Structure for the graph
typedef struct Graph {
    int vertices;
    Node** adjacencyList;
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (Node**)malloc(vertices * sizeof(Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

// Function to create a new adjacency list node
Node* createNode(int destination) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->destination = destination;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination) {
    Node* newNode = createNode(destination);
    newNode->next = graph->adjacencyList[source];
    graph->adjacencyList[source] = newNode;
    
    // For undirected graph, add an edge from destination to source
    newNode = createNode(source);
    newNode->next = graph->adjacencyList[destination];
    graph->adjacencyList[destination] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjacencyList[i];
        printf("Vertex %d: ", i);
        
        while (temp) {
            printf("%d -> ", temp->destination);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Recursive function for DFS
void DFSUtil(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    Node* temp = graph->adjacencyList[vertex];
    while (temp) {
        if (!visited[temp->destination]) {
            DFSUtil(graph, temp->destination, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS
void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0;
    }
    
    DFSUtil(graph, startVertex, visited);
    free(visited);
}

// Function to perform BFS
void BFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0;
    }
    
    int* queue = (int*)malloc(graph->vertices * sizeof(int));
    int front = 0, rear = 0;
    
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        
        Node* temp = graph->adjacencyList[current];
        while (temp) {
            if (!visited[temp->destination]) {
                visited[temp->destination] = 1;
                queue[rear++] = temp->destination;
            }
            temp = temp->next;
        }
    }
    
    free(visited);
    free(queue);
}

// Main function to demonstrate graph operations
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

    printf("Graph structure:\n");
    printGraph(graph);
    
    printf("\nDFS starting from vertex 0:\n");
    DFS(graph, 0);
    
    printf("\n\nBFS starting from vertex 0:\n");
    BFS(graph, 0);
    
    // Free the allocated memory
    for (int i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjacencyList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjacencyList);
    free(graph);
    
    return 0;
}