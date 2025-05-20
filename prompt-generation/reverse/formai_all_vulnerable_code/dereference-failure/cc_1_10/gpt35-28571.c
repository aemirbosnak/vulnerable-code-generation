//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the graph
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// Define the graph structure
typedef struct graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with n vertices
Graph* createGraph(int n) {
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->numVertices = n;
    newGraph->adjLists = (Node**)malloc(n * sizeof(Node*));
    int i;
    for (i = 0; i < n; i++) {
        newGraph->adjLists[i] = NULL;
    }
    return newGraph;
}

// Function to add an edge to a graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to perform a depth-first search traversal of the graph
void DFS(Graph* graph, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = graph->adjLists[v];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform a breadth-first search traversal of the graph
void BFS(Graph* graph, int start, int* visited) {
    int queue[graph->numVertices];
    int size = 0, front = 0, rear = -1;

    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node* temp = graph->adjLists[current];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

// Main function for testing
int main() {
    // Create the graph
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    // Print the graph
    printf("Graph:\n");
    printGraph(graph);
    printf("\n");

    // Perform depth-first search
    printf("Depth-First Search:\n");
    int visited1[graph->numVertices];
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        visited1[i] = 0;
    }
    DFS(graph, 0, visited1);
    printf("\n\n");

    // Perform breadth-first search
    printf("Breadth-First Search:\n");
    int visited2[graph->numVertices];
    for (i = 0; i < graph->numVertices; i++) {
        visited2[i] = 0;
    }
    BFS(graph, 0, visited2);
    printf("\n");

    return 0;
}