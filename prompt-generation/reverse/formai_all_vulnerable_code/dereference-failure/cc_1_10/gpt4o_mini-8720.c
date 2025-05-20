//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

// Structure to represent an adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph using an adjacency list
typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    for(int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(Graph* graph) {
    for(int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjList[v];
        printf("Vertex %d: ", v);
        while(temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth First Search (DFS) helper function
void DFSUtil(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjList[vertex];
    while(temp) {
        if(!visited[temp->vertex]) {
            DFSUtil(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal of the graph
void DFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    printf("DFS starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// Breadth First Search (BFS) function
void BFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, back = 0;

    visited[startVertex] = 1;
    queue[back++] = startVertex;

    printf("BFS starting from vertex %d:\n", startVertex);
    
    while(front < back) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = graph->adjList[currentVertex];
        while(temp) {
            if(!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[back++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Main function to demonstrate the graph representation and traversal methods
int main() {
    Graph* graph = createGraph(5); // Create a graph with 5 vertices

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph); // Print the graph

    DFS(graph, 0); // Perform DFS starting from vertex 0
    BFS(graph, 0); // Perform BFS starting from vertex 0

    // Free allocated memory (not shown here for brevity)
    // Normally, you'd want to free the graph and nodes

    return 0;
}