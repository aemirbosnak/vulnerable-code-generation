//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a graph node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define the structure for the graph
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
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to perform DFS in the graph
void DFS(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    // Recursively visit all adjacent vertices
    Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;
        if (visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex, visited);
        }
        adjList = adjList->next;
    }
}

// Function to initiate DFS
void DFSInit(Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));
    
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    DFS(graph, startVertex, visited);
    free(visited);
}

// Main function
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Displaying the graph
    printf("Graph adjacency list representation:\n");
    displayGraph(graph);

    // Performing DFS
    printf("\nDFS starting from vertex 0:\n");
    DFSInit(graph, 0);

    // Freeing the allocated graph resources
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}