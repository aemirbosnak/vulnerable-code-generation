//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure for a vertex in the graph
typedef struct Vertex {
    int data;
    struct Vertex* next;
} Vertex;

// Function to add a vertex to the graph
void addVertex(Vertex** head, int data) {
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->data = data;
    newVertex->next = *head;
    *head = newVertex;
}

// Function to print the graph
void printGraph(Vertex* vertex) {
    while (vertex!= NULL) {
        printf("%d ", vertex->data);
        vertex = vertex->next;
    }
}

// Recursive function to traverse the graph in depth-first order
void depthFirstTraversal(Vertex* vertex) {
    printf("Depth-First Traversal: ");
    printGraph(vertex);
    printf("\n");
}

// Recursive function to traverse the graph in breadth-first order
void breadthFirstTraversal(Vertex* vertex) {
    printf("Breadth-First Traversal: ");
    printGraph(vertex);
    printf("\n");
}

// Recursive function to check if the graph is connected
int isConnected(Vertex* vertex) {
    if (vertex == NULL)
        return 0;
    if (vertex->next == NULL)
        return 1;
    return isConnected(vertex->next);
}

// Recursive function to check if the graph is a tree
int isTree(Vertex* vertex) {
    if (vertex == NULL)
        return 1;
    if (vertex->next == NULL)
        return 1;
    if (!isTree(vertex->next))
        return 0;
    return 1;
}

// Main function to test the graph functions
int main() {
    Vertex* graph = NULL;

    // Add vertices to the graph
    addVertex(&graph, 1);
    addVertex(&graph, 2);
    addVertex(&graph, 3);
    addVertex(&graph, 4);
    addVertex(&graph, 5);

    // Connect the vertices
    graph->next->next->next->next->next = graph->next->next;

    // Test depth-first traversal
    depthFirstTraversal(graph);

    // Test breadth-first traversal
    breadthFirstTraversal(graph);

    // Test if the graph is connected
    if (isConnected(graph))
        printf("The graph is connected.\n");
    else
        printf("The graph is not connected.\n");

    // Test if the graph is a tree
    if (isTree(graph))
        printf("The graph is a tree.\n");
    else
        printf("The graph is not a tree.\n");

    return 0;
}