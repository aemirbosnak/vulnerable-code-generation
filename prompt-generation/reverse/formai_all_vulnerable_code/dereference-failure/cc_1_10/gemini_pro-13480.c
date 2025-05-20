//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// A linked list node to represent a vertex
struct Node {
    int data;
    struct Node *next;
};

// A graph is represented as an array of adjacency lists
struct Graph {
    int V;
    struct Node **adjLists;
};

// Create a new graph with V vertices
struct Graph *createGraph(int V) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->adjLists = malloc(V * sizeof(struct Node *));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Add an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src
    newNode = malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print the adjacency list representation of the graph
void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node *temp = graph->adjLists[i];
        printf("%d", i);
        while (temp) {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth First Search (DFS)
void DFS(struct Graph *graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    struct Node *temp = graph->adjLists[v];
    while (temp) {
        if (!visited[temp->data]) {
            DFS(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

// Breadth First Search (BFS)
void BFS(struct Graph *graph, int v) {
    int *visited = calloc(graph->V, sizeof(int));

    // Create a queue for BFS
    struct Node *queue[graph->V];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[v] = 1;
    queue[rear++] = graph->adjLists[v];

    // 'i' will be used to get all adjacent vertices of a vertex
    while (front < rear) {
        struct Node *temp = queue[front++];

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it
        // visited and enqueue it
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = graph->adjLists[temp->data];
            }
            temp = temp->next;
        }
    }

    // Print the BFS traversal
    for (int i = 0; i < graph->V; i++) {
        if (visited[i]) {
            printf("%d ", i);
        }
    }
}

int main() {
    // Create a graph with 5 vertices
    struct Graph *graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Print the adjacency list representation of the graph
    printGraph(graph);

    // Perform DFS starting from vertex 0
    int visited[graph->V];
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }
    DFS(graph, 0, visited);
    printf("\n");

    // Perform BFS starting from vertex 0
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }
    BFS(graph, 0);
    printf("\n");

    return 0;
}