//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the structure for an adjacency list node
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Define the structure for the adjacency list
typedef struct Graph {
    int vertices;
    Node** adjLists;
} Graph;

// Function to create a new adjacency list node
Node* createNode(int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Allocate memory for adjacency lists
    graph->adjLists = malloc(vertices * sizeof(Node*));

    // Initialize each adjacency list to NULL
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->vertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\n Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to perform Depth First Search
void DFSUtil(Graph* graph, int v, int* visited) {
    // Mark the current node as visited
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    Node* temp = graph->adjLists[v];
    while (temp) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS on the graph
void DFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    // Call the recursive helper function to perform DFS
    DFSUtil(graph, startVertex, visited);
    free(visited); // Free allocated memory
}

// Function for Breadth First Search
void BFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    int* queue = malloc(graph->vertices * sizeof(int));
    int front = 0, rear = 0;

    // Mark the start node as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    // Loop till the queue is empty
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    free(queue); // Free allocated memory
    free(visited); // Free allocated memory
}

// Main function to demonstrate graph implementation
int main() {
    // Create a graph with a specified number of vertices
    int vertices = 5; 
    Graph* graph = createGraph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency list representation of the graph
    printGraph(graph);

    printf("\nDFS starting from vertex 0:\n");
    DFS(graph, 0);

    printf("\n\nBFS starting from vertex 0:\n");
    BFS(graph, 0);

    // Free memory allocated for the graph
    for (int v = 0; v < vertices; v++) {
        Node* temp = graph->adjLists[v];
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