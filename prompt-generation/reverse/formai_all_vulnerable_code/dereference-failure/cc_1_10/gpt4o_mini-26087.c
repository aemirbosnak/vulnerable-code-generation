//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int vertices;
    Node** adjLists;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
Node* createNode(int dest);
void addEdge(Graph* graph, int src, int dest);
void displayGraph(Graph* graph);
void freeGraph(Graph* graph);

// Main function
int main() {
    int vertices = 5; // Number of vertices
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printf("Graph adjacency list:\n");
    displayGraph(graph);
    
    freeGraph(graph);
    return 0;
}

// Function to create a graph with given vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Function to create a new adjacency list node
Node* createNode(int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
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

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf(" \n");
    }
}

// Function to free the graph's memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
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