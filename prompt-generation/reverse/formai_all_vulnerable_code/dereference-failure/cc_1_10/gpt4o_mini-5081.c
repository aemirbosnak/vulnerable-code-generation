//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent an adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent an adjacency list
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a graph with a specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d:", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to check if a color can be assigned to a vertex
bool canColor(Graph* graph, int vertex, int color, int* colors) {
    Node* temp = graph->adjLists[vertex];
    while (temp) {
        if (colors[temp->vertex] == color) {
            return false; // Adjacent vertex has the same color
        }
        temp = temp->next;
    }
    return true;
}

// Function to color the graph using greedy algorithm
void greedyGraphColoring(Graph* graph) {
    int* colors = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        colors[i] = -1; // Initialize all colors as -1
    }
    
    colors[0] = 0; // Assign the first color to the first vertex

    for (int u = 1; u < graph->numVertices; u++) {
        bool available[MAX_VERTICES];
        for (int i = 0; i < MAX_VERTICES; i++) {
            available[i] = true; // Mark all colors as available
        }

        // Check colors of adjacent vertices and mark them as unavailable
        Node* temp = graph->adjLists[u];
        while (temp) {
            if (colors[temp->vertex] != -1) {
                available[colors[temp->vertex]] = false;
            }
            temp = temp->next;
        }

        // Find the first available color
        for (int color = 0; color < MAX_VERTICES; color++) {
            if (available[color]) {
                colors[u] = color;
                break;
            }
        }
    }

    // Print colors assigned to each vertex
    printf("Vertex Colors:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d => Color %d\n", i, colors[i]);
    }

    // Free memory
    free(colors);
}

// Main function to demonstrate the graph coloring
int main() {
    Graph* graph = createGraph(6); // Create a graph with 6 vertices

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    // Print the graph
    printGraph(graph);

    // Perform graph coloring
    greedyGraphColoring(graph);

    // Free memory allocated for the graph
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

    return 0;
}