//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a graph using an adjacency list
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node** adjLists;
} Graph;

// Function to create a node
Node* createNode(int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with v vertices
Graph* createGraph(int v) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = v;

    graph->adjLists = malloc(v * sizeof(Node*));

    for (int i = 0; i < v; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->vertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d:\n", v);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function for Depth First Search
void DFSUtil(int v, int visited[], Graph* graph) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = graph->adjLists[v];
    while (temp) {
        if (!visited[temp->dest]) {
            DFSUtil(temp->dest, visited, graph);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal from a given vertex
void DFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0;
    }
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFSUtil(startVertex, visited, graph);
    free(visited);
}

// Function to free the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph);
}

// Main function
int main() {
    // Create a graph given in the above example
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Perform DFS traversal
    DFS(graph, 0);

    // Free memory allocated for the graph
    freeGraph(graph);

    return 0;
}