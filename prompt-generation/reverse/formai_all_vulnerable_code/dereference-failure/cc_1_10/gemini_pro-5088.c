//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// A linked list node to store a vertex
typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

// A graph is an array of linked lists.
// Size of the array will be V (number of vertices in the graph)
typedef struct Graph {
    int V;
    Node **edges;
} Graph;

// Create a new graph with V vertices
Graph* createGraph(int V) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    // Create an array of linked lists.
    // Size of the array will be V
    graph->edges = (Node**)malloc(V * sizeof(Node*));

    // Initialize all linked lists as empty
    for (int i = 0; i < V; i++) {
        graph->edges[i] = NULL;
    }

    return graph;
}

// Add an edge to the graph
void addEdge(Graph *graph, int source, int destination) {
    // Create a new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = destination;

    // Add the node to the end of the linked list
    newNode->next = graph->edges[source];
    graph->edges[source] = newNode;
}

// Print the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        Node *temp = graph->edges[i];
        printf("%d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth First Search (DFS)
void DFS(Graph *graph, int source) {
    // Create a stack
    int stack[graph->V];
    int top = -1;

    // Initialize all vertices as unvisited
    int visited[graph->V];
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    // Push the source vertex onto the stack
    stack[++top] = source;

    // While the stack is not empty, pop the top vertex and visit it
    while (top != -1) {
        int vertex = stack[top--];

        // If the vertex has not been visited, visit it and push all its adjacent vertices onto the stack
        if (!visited[vertex]) {
            visited[vertex] = 1;
            printf("%d ", vertex);

            Node *temp = graph->edges[vertex];
            while (temp) {
                if (!visited[temp->vertex]) {
                    stack[++top] = temp->vertex;
                }
                temp = temp->next;
            }
        }
    }
}

// Breadth First Search (BFS)
void BFS(Graph *graph, int source) {
    // Create a queue
    int queue[graph->V];
    int front = -1;
    int rear = -1;

    // Initialize all vertices as unvisited
    int visited[graph->V];
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    // Enqueue the source vertex
    queue[++rear] = source;

    // While the queue is not empty, dequeue the front vertex and visit it
    while (front != rear) {
        int vertex = queue[++front];

        // If the vertex has not been visited, visit it and enqueue all its adjacent vertices
        if (!visited[vertex]) {
            visited[vertex] = 1;
            printf("%d ", vertex);

            Node *temp = graph->edges[vertex];
            while (temp) {
                if (!visited[temp->vertex]) {
                    queue[++rear] = temp->vertex;
                }
                temp = temp->next;
            }
        }
    }
}

int main() {
    // Create a graph with 5 vertices
    Graph *graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Print the graph
    printGraph(graph);

    // Perform DFS on the graph
    printf("DFS: ");
    DFS(graph, 0);
    printf("\n");

    // Perform BFS on the graph
    printf("BFS: ");
    BFS(graph, 0);
    printf("\n");

    return 0;
}