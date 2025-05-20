//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define the structure for the Graph
typedef struct Graph {
    int numVertices;
    Node** adjLists; // Pointer to an array of pointers
} Graph;

// Function to create a node
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists, initialized to NULL
    graph->adjLists = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since this is an undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph (for visual excitement!)
void printGraph(Graph* graph) {
    printf("Graph adjacency list representation:\n");
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

// Perform a Depth First Search (DFS) on the graph
void DFSUtil(int vertex, int* visited, Graph* graph) {
    visited[vertex] = 1; // Mark the current node as visited
    printf("Visited %d\n", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex, visited, graph);
        }
        temp = temp->next;
    }
}

// Function to start DFS traversal
void DFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }
    DFSUtil(startVertex, visited, graph);
    free(visited); // Don't forget to free the allocated memory
}

// Clean up memory used by the graph
void freeGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    // Get bowled over by an exciting graph setup
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    // Throw in some edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Whoa! Let's visualize the graph!
    printGraph(graph);

    // Awaken the DFS adventure from vertex 0!
    printf("\nDepth First Search starting from vertex 0:\n");
    DFS(graph, 0);

    // Time to free the memory and bid farewell!
    freeGraph(graph);
    return 0;
}