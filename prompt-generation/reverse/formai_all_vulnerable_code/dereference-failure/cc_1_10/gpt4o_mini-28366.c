//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INIT_CAPACITY 2

// A structure to represent a node in the adjacency list
typedef struct Node {
    int destination;
    struct Node* next;
} Node;

// A structure to represent an adjacency list
typedef struct AdjList {
    Node* head; // Pointer to head node of list
} AdjList;

// A structure to represent a graph
typedef struct Graph {
    int numVertices; // Number of vertices
    AdjList* array;  // Array of adjacency lists
} Graph;

// Function to create a new node in the adjacency list
Node* createNode(int destination) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->destination = destination;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->array = (AdjList*)malloc(vertices * sizeof(AdjList));
    
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination) {
    Node* newNode = createNode(destination);
    newNode->next = graph->array[source].head;
    graph->array[source].head = newNode;

    // Since this is an undirected graph, add an edge from destination to source as well
    newNode = createNode(source);
    newNode->next = graph->array[destination].head;
    graph->array[destination].head = newNode;
}

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->array[v].head;
        printf("\n Adjacency list of vertex %d:\n head ", v);
        while (temp) {
            printf("-> %d ", temp->destination);
            temp = temp->next;
        }
        printf("\n");
    }
}

// A simple function to traverse the graph starting from a given node
void depthFirstSearch(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    Node* adjList = graph->array[vertex].head;
    while (adjList) {
        int adjacentVertex = adjList->destination;
        if (!visited[adjacentVertex]) {
            depthFirstSearch(graph, adjacentVertex, visited);
        }
        adjList = adjList->next;
    }
}

int main() {
    printf("=== A Marvelous Graph Representation ===\n");
    
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    printf("Adding edges to the graph...\n");
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Displaying the graph:\n");
    displayGraph(graph);

    bool visited[MAX_VERTICES] = {false};
    printf("Depth First Traversal starting from vertex 0:\n");
    depthFirstSearch(graph, 0, visited);
    
    // Free memory (cleaning up)
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->array[i].head;
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
    
    printf("\n\nProgram has successfully finished execution with no errors!\n");
    return 0;
}