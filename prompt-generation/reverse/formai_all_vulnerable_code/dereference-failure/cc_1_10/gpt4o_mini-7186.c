//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function prototypes
Graph* createGraph(int vertices);
Node* createNode(int v);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void DFS(Graph* graph, int startVertex, bool* visited);

int main() {
    int numVertices, choice, src, dest;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);
    
    do {
        printf("\nGraph Operations Menu:\n");
        printf("1. Add Edge\n");
        printf("2. Print Graph\n");
        printf("3. Perform DFS\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter source vertex and destination vertex: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printGraph(graph);
                break;
            case 3:
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &src);
                bool* visited = (bool*)malloc(numVertices * sizeof(bool));
                for (int i = 0; i < numVertices; i++) {
                    visited[i] = false;
                }
                printf("DFS traversal starting from vertex %d: ", src);
                DFS(graph, src, visited);
                printf("\n");
                free(visited);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    // Free graph memory
    for (int i = 0; i < numVertices; i++) {
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

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

// Function to create a node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add an edge in the other direction also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth-first search utility
void DFS(Graph* graph, int startVertex, bool* visited) {
    visited[startVertex] = true;
    printf("%d ", startVertex);
    
    Node* adjList = graph->adjLists[startVertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;
        if (!visited[connectedVertex]) {
            DFS(graph, connectedVertex, visited);
        }
        adjList = adjList->next;
    }
}