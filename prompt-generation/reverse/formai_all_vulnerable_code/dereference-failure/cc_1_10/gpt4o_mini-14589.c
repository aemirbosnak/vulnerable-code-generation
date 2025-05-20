//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since it's undirected, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to free the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}

// Function to perform Depth-First Search (DFS)
void DFSUtil(int v, int visited[], Graph* graph) {
    visited[v] = 1;
    printf("Visited %d\n", v);
    
    Node* temp = graph->adjLists[v];
    while (temp) {
        int adjacentVertex = temp->vertex;
        if (!visited[adjacentVertex]) {
            DFSUtil(adjacentVertex, visited, graph);
        }
        temp = temp->next;
    }
}

// Function to initiate DFS
void DFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    DFSUtil(startVertex, visited, graph);
    free(visited);
}

// Main function to demonstrate the graph and DFS
int main() {
    Graph* graph = createGraph(5);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printf("Graph representation:\n");
    printGraph(graph);

    printf("\nPerforming DFS starting from vertex 0:\n");
    DFS(graph, 0);
    
    freeGraph(graph);
    return 0;
}