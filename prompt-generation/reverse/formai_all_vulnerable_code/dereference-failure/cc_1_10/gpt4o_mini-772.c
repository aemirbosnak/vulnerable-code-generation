//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Graph structure
struct Graph {
    int vertices;
    struct Node** adjList;
};

// Create a new adjacent node
struct Node* createNode(int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with 'v' vertices
struct Graph* createGraph(int v) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->vertices = v;

    // Create an array of adjacency lists
    graph->adjList = malloc(v * sizeof(struct Node*));

    for (int i = 0; i < v; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // For undirected graph, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Depth First Search
void DFSUtil(int v, int visited[], struct Graph* graph) {
    visited[v] = 1;
    printf("Visiting vertex: %d\n", v);

    struct Node* temp = graph->adjList[v];

    while (temp) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex, visited, graph);
        }
        temp = temp->next;
    }
}

// Function to perform DFS
void DFS(struct Graph* graph, int startVertex) {
    int* visited = malloc(graph->vertices * sizeof(int));

    for (int i = 0; i < graph->vertices; i++)
        visited[i] = 0;

    DFSUtil(startVertex, visited, graph);
    free(visited);
}

// Print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->vertices; v++) {
        struct Node* temp = graph->adjList[v];
        printf("\n Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Free the graph
void freeGraph(struct Graph* graph) {
    for (int v = 0; v < graph->vertices; v++) {
        struct Node* temp = graph->adjList[v];
        while (temp) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjList);
    free(graph);
}

int main() {
    printf("Welcome, traveler, to the world of Graphs!\n");
    printf("Let the edges entwine...\n");

    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("The graph constructed:\n");
    printGraph(graph);

    printf("Embarking on a Depth First Search from vertex 0:\n");
    DFS(graph, 0);

    printf("Alas! Cleaning up the remnants...\n");
    freeGraph(graph);
    printf("The journey concludes with a whisper in the void...\n");

    return 0;
}