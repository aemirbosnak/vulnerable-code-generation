//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Defining a structure for a Graph Node
struct Node {
    int vertex;
    struct Node* next;
};

// Defining a structure for a Graph
struct Graph {
    int numVertices;
    struct Node** adjLists; // Array of adjacency lists
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the Graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;

    printf("Hooray! Edge added between %d and %d!\n", src, dest);
}

// Utility function to print the graph
void printGraph(struct Graph* graph) {
    printf("\nLet’s explore the lovely graph:\n");
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d:", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Recursive function for DFS
void DFSUtil(int v, int visited[], struct Graph* graph) {
    // Mark the current node as visited
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->adjLists[v];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex, visited, graph);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal
void DFS(struct Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    printf("\nLet’s embark on a DFS adventure from vertex %d:\n", startVertex);
    DFSUtil(startVertex, visited, graph);
    printf("\nThe exploration is complete!\n");
    free(visited);
}

// Main function to run the graph example
int main() {
    struct Graph* myGraph = createGraph(5); // Let's create a graph with 5 vertices!

    // Adding edges to make it colorful
    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 4);
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 1, 3);
    addEdge(myGraph, 1, 4);
    addEdge(myGraph, 2, 3);
    addEdge(myGraph, 3, 4);

    // Print the graph to see how beautiful it is!
    printGraph(myGraph);

    // Let's explore with Depth First Search
    DFS(myGraph, 0); // Start the adventure from vertex 0!

    // Free the graph memory (clean up the cheerfulness!)
    for (int i = 0; i < myGraph->numVertices; i++) {
        struct Node* temp = myGraph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(myGraph->adjLists);
    free(myGraph);

    return 0;
}