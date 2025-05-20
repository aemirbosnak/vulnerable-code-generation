//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_NAME_LENGTH 20

// Structure to represent a Node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a Graph
typedef struct Graph {
    int numVertices;
    char vertexNames[MAX_VERTICES][MAX_NAME_LENGTH];
    Node* adjacencyLists[MAX_VERTICES];
} Graph;

// Function to create a new node in the adjacency list
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyLists[i] = NULL;
    }
    return graph;
}

// Function to add a vertex name to the graph
void addVertexName(Graph* graph, int index, const char* name) {
    strcpy(graph->vertexNames[index], name);
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* node = createNode(dest);
    node->next = graph->adjacencyLists[src];
    graph->adjacencyLists[src] = node;

    // Add edge from dest to src (for undirected graph)
    node = createNode(src);
    node->next = graph->adjacencyLists[dest];
    graph->adjacencyLists[dest] = node;
}

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%s -> ", graph->vertexNames[i]);
        Node* temp = graph->adjacencyLists[i];
        while (temp) {
            printf("%s ", graph->vertexNames[temp->vertex]);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Recursive function for DFS
void DFS(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%s ", graph->vertexNames[vertex]);

    Node* temp = graph->adjacencyLists[vertex];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS on the graph
void performDFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    printf("DFS starting from vertex %s:\n", graph->vertexNames[startVertex]);
    DFS(graph, startVertex, visited);
    printf("\n");
}

// Main function to demonstrate the graph functionality
int main() {
    int numVertices = 5; // Number of vertices
    Graph* graph = createGraph(numVertices);

    // Adding vertex names
    addVertexName(graph, 0, "A");
    addVertexName(graph, 1, "B");
    addVertexName(graph, 2, "C");
    addVertexName(graph, 3, "D");
    addVertexName(graph, 4, "E");

    // Adding edges
    addEdge(graph, 0, 1); // A <-> B
    addEdge(graph, 0, 4); // A <-> E
    addEdge(graph, 1, 2); // B <-> C
    addEdge(graph, 1, 3); // B <-> D
    addEdge(graph, 1, 4); // B <-> E
    addEdge(graph, 2, 3); // C <-> D
    addEdge(graph, 3, 4); // D <-> E

    // Display the graph
    displayGraph(graph);

    // Perform DFS
    performDFS(graph, 0);

    // Free allocated memory (not implemented for brevity)

    return 0;
}