//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the adjacency list node
struct Node {
    int dest;
    struct Node* next;
};

// Define a structure for the adjacency list
struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function to create a new node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    
    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function for Depth First Search
void DFSUtil(struct Graph* graph, int v, int visited[]) {
    // Mark the current node as visited
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->adjList[v];
    while (temp) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Wrapper function for DFS
void DFS(struct Graph* graph, int start) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    
    // Initialize visited array
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    // Call DFS utility function
    printf("Depth First Search starting from vertex %d:\n", start);
    DFSUtil(graph, start, visited);
    printf("\n");
    free(visited);
}

// Function for Breadth First Search
void BFS(struct Graph* graph, int start) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    // Initialize visited array
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue[rear++] = start;

    printf("Breadth First Search starting from vertex %d:\n", start);
    
    while (front < rear) {
        int currVertex = queue[front++];
        printf("%d ", currVertex);

        struct Node* temp = graph->adjList[currVertex];
        while (temp) {
            int adjVertex = temp->dest;

            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}

// Main function
int main() {
    int vertices = 5;

    struct Graph* graph = createGraph(vertices);

    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Perform DFS and BFS
    DFS(graph, 0);
    BFS(graph, 0);

    // Free graph memory
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}