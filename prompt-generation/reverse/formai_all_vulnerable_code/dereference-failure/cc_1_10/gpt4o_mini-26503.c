//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Structure to represent the adjacency list node
struct Node {
    int dest;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int V; // Number of vertices
    struct Node** adjLists; // Adjacency list
};

// Function to create a new adjacency list node
struct Node* createNode(int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjLists = malloc(V * sizeof(struct Node*));
    
    // Initialize adjacency lists
    for (int i = 0; i < V; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Adding from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Adding from dest to src (undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// A utility function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("\n Vertex %d:", v);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to color the graph
void graphColoring(struct Graph* graph) {
    int V = graph->V;
    int result[V];

    // Assign the first color to first vertex
    result[0] = 0;

    // Available colors
    for (int u = 1; u < V; u++) {
        result[u] = -1; // Initialize all vertices as uncolored
    }

    // A temporary array to store the available colors
    int available[V];
    for (int cr = 0; cr < V; cr++) {
        available[cr] = 1; // Initially, all colors are available
    }

    // Assign colors to the remaining vertices
    for (int u = 1; u < V; u++) {
        // Check colors of adjacent vertices
        struct Node* temp = graph->adjLists[u];
        while (temp) {
            if (result[temp->dest] != -1) {
                available[result[temp->dest]] = 0; // Color not available
            }
            temp = temp->next;
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (available[cr]) {
                break; // Found the color
            }
        }

        // Assign the found color to this vertex
        result[u] = cr;

        // Reset the available array for the next iteration
        for (temp = graph->adjLists[u]; temp; temp = temp->next) {
            if (result[temp->dest] != -1) {
                available[result[temp->dest]] = 1; // Reset to available
            }
        }
    }

    // Print the result
    printf("\nColors assigned to vertices:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i, result[i]);
    }
}

// Driver Code
int main() {
    // Create a graph given in the example
    int V = 5;
    struct Graph* graph = createGraph(V);

    // Add edges to the graph (undirected)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    // Print the graph
    printGraph(graph);

    // Perform graph coloring
    graphColoring(graph);

    // Free allocated memory
    for (int i = 0; i < V; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}