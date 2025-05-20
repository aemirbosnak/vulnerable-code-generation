//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure representing a graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function prototypes
struct Graph* createGraph(int vertices);
struct Node* createNode(int vertex);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void DFS(struct Graph* graph, int startVertex, int* visited);
void freeGraph(struct Graph* graph);

int main() {
    int vertices = 5;
    
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(vertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printf("Graph adjacency list:\n");
    printGraph(graph);

    // Perform DFS traversal
    int* visited = (int*) malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    printf("DFS traversal starting from vertex 0:\n");
    DFS(graph, 0, visited);

    // Free allocated memory
    free(visited);
    freeGraph(graph);

    return 0;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Allocate memory for adjacency lists
    graph->adjLists = (struct Node**) malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to create a new adjacency list node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from source to destination
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from destination to source
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("\nVertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
    }
}

// Function to perform DFS traversal of the graph
void DFS(struct Graph* graph, int startVertex, int* visited) {
    // Mark the current vertex as visited
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->adjLists[startVertex];
    while (temp) {
        int adjacentVertex = temp->vertex;
        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}