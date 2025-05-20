//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a graph node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define the structure for a graph
typedef struct Graph {
    int numVertices;
    Node** adjLists; 
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL; // Initialize each adjacency list as empty
    }
    return graph;
}

// Function to create a new graph node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest (directed graph)
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\n Vertex %d\n: ", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the graph's resources
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

// A demonstration of the graph in action
void graphDemo() {
    printf("Creating a graph with 5 vertices...\n");
    Graph* myGraph = createGraph(5);

    // Adding edges to the graph
    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 4);
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 1, 3);
    addEdge(myGraph, 1, 4);
    addEdge(myGraph, 2, 3);
    addEdge(myGraph, 3, 4);

    // Printing the graph
    printGraph(myGraph);

    // Free the graph
    freeGraph(myGraph);
}

// Main function to execute the program
int main() {
    printf("Welcome to the Graph Representation Program!\n");
    graphDemo();
    printf("Graph demonstration completed.\n");

    return 0;
}