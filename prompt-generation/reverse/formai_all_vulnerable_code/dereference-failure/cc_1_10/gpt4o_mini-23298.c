//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Cheerful Node structure
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Cheerful Graph structure
typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void displayGraph(Graph* graph);
void dfs(Graph* graph, int startVertex, int* visited);

// Main function - The Happy Starting Point!
int main() {
    int vertices, src, dest;

    // A warm welcome to our graph creation
    printf("🎉 Welcome to the Cheerful Graph Creator! 🎉\n");
    printf("How many vertices do you want in your graph (max %d)? ", MAX_VERTICES);
    scanf("%d", &vertices);

    // Create the graph if the input is valid
    if (vertices > 0 && vertices <= MAX_VERTICES) {
        Graph* graph = createGraph(vertices);

        // Time to add edges! 😊
        printf("Let's add some edges! 💖\n");
        printf("Enter edges as pairs of vertices (e.g., 0 1 for an edge from 0 to 1). Type -1 -1 to stop.\n");

        while (1) {
            scanf("%d %d", &src, &dest);
            if (src == -1 && dest == -1) {
                break;
            }
            if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
                addEdge(graph, src, dest);
                printf("Edge added between %d and %d! 🎈\n", src, dest);
            } else {
                printf("😢 Oops! Please enter valid vertex numbers between 0 and %d.\n", vertices - 1);
            }
        }

        // Display the cheerful graph
        printf("\n🎆 Here is your cheerful graph! 🎆\n");
        displayGraph(graph);

        // Perform DFS
        int visited[MAX_VERTICES] = {0}; // Initialize the visited array
        printf("Let's do a Depth First Search starting from vertex 0! 🚀\n");
        dfs(graph, 0, visited);

        // Free allocated memory
        free(graph);
    } else {
        printf("😢 Oops! The number of vertices should be between 1 and %d!\n", MAX_VERTICES);
    }
    
    return 0;
}

// Create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    
    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Create a new node for the destination
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src also!
    newNode = malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Display the graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjList[i];
        printf("🗺️ Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf(" 🌟\n");
    }
}

// Perform DFS
void dfs(Graph* graph, int startVertex, int* visited) {
    // Mark the current node as visited
    visited[startVertex] = 1;
    printf("Visited vertex %d 🎡\n", startVertex);

    // Recur for all the vertices adjacent to this vertex
    Node* adjList = graph->adjList[startVertex];
    while (adjList) {
        int connectedVertex = adjList->vertex;
        if (!visited[connectedVertex]) {
            dfs(graph, connectedVertex, visited);
        }
        adjList = adjList->next;
    }
}