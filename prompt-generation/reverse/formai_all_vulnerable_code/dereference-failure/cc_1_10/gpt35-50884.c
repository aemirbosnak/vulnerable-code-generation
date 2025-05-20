//FormAI DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Type representing a graph node
typedef struct GraphNode {
    int vertex;             // Node identifier
    struct GraphNode *next; // Pointer to next node in linked list
} GraphNode;

// Type representing a graph
typedef struct Graph {
    GraphNode *adjList[MAX_VERTICES]; // Array of linked lists
    int numVertices;                  // Number of vertices in graph
} Graph;

// Function to create a new node with given vertex identifier
GraphNode *newNode(int v) {
    GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->next = NULL;
    return node;
}

// Function to create a new graph with given number of vertices
Graph *newGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    GraphNode *node = newNode(dest);
    node->next = graph->adjList[src];
    graph->adjList[src] = node;
}

// Function to print the graph in adjacency list representation
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        GraphNode *node = graph->adjList[i];
        printf("Adjacency list of vertex %d\nhead ", i);
        while (node != NULL) {
            printf("-> %d ", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

// Function to free memory allocated to the graph
void destroyGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        GraphNode *node = graph->adjList[i];
        while (node != NULL) {
            GraphNode *temp = node;
            node = node->next;
            free(temp);
        }
        graph->adjList[i] = NULL;
    }
    free(graph);
}

// Recursive function to perform DFS from a given vertex
void DFS(Graph *graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    GraphNode *adjNode = graph->adjList[vertex];
    while (adjNode != NULL) {
        int adjVertex = adjNode->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        adjNode = adjNode->next;
    }
}

// Driver function to test the graph implementation
int main() {
    Graph *graph = newGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);
    addEdge(graph, 1, 4);
    addEdge(graph, 4, 2);
    printGraph(graph);
    int visited[MAX_VERTICES] = {0};
    printf("DFS traversal starting from vertex 0: ");
    DFS(graph, 0, visited);
    printf("\n");
    destroyGraph(graph);
    return 0;
}