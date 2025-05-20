//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
Node* createNode(int vertex);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void bfs(Graph* graph, int startVertex);
void freeGraph(Graph* graph);

// Main function demonstrating the graph implementation
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph Representation (Adjacency List):\n");
    printGraph(graph);

    printf("\nBreadth-First Search starting from vertex 0:\n");
    bfs(graph, 0);

    freeGraph(graph);
    return 0;
}

// Create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    
    return graph;
}

// Create a new adjacency list node
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Add an edge from source to destination
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print the adjacency list representation of the graph
void printGraph(Graph* graph) {
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

// Perform breadth-first search
void bfs(Graph* graph, int startVertex) {
    Node* queue[MAX_VERTICES];
    int front = 0, rear = 0;

    graph->visited[startVertex] = true;
    queue[rear++] = createNode(startVertex);

    while (front < rear) {
        int currentVertex = queue[front++]->vertex;
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                queue[rear++] = createNode(adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Free the allocated memory for the graph
void freeGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        while (temp) {
            Node* tempNext = temp->next;
            free(temp);
            temp = tempNext;
        }
    }
    free(graph);
}