//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define a structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Create a node
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists
    graph->adjLists = malloc(vertices * sizeof(Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d:\n head", v);
        while (temp != NULL) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf(" -> NULL\n");
    }
}

// Helper function for DFS
void DFSUtil(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        if (!visited[temp->vertex])
            DFSUtil(graph, temp->vertex, visited);
        temp = temp->next;
    }
}

// Perform DFS on the graph
void DFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    DFSUtil(graph, startVertex, visited);
    free(visited);
}

// Perform BFS on the graph
void BFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    int* queue = malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}

int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printf("Graph adjacency list representation:\n");
    printGraph(graph);

    printf("\nDepth-First Search (starting from vertex 0):\n");
    DFS(graph, 0);
    
    printf("\n\nBreadth-First Search (starting from vertex 0):\n");
    BFS(graph, 0);

    // Free the graph memory
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}