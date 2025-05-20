//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Adjacency list structure
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    int* color;
    struct Node** adjList;
};

// Function to create a new node in the adjacency list
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->color = malloc(V * sizeof(int));
    graph->adjList = malloc(V * sizeof(struct Node*));
    
    // Set color of all vertices as unassigned
    for (int i = 0; i < V; i++) {
        graph->color[i] = -1;
        graph->adjList[i] = NULL;
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to check if it is safe to color the vertex with a given color
bool isSafe(struct Graph* graph, int vertex, int color) {
    struct Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        if (graph->color[temp->vertex] == color) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

// Recursive function to assign colors to vertices
bool graphColoringUtil(struct Graph* graph, int vertex, int m) {
    // Base case: If all vertices are colored, return true
    if (vertex == graph->V) {
        return true;
    }
    
    // Try different colors for vertex until a valid color is found
    for (int i = 0; i < m; i++) {
        if (isSafe(graph, vertex, i)) {
            graph->color[vertex] = i;
            if (graphColoringUtil(graph, vertex + 1, m)) {
                return true;
            }
            graph->color[vertex] = -1;
        }
    }
    return false;
}

// Function to assign colors to vertices using graph coloring algorithm
void graphColoring(struct Graph* graph, int m) {
    if (graphColoringUtil(graph, 0, m)) {
        printf("Solution Exists:\n");
        for (int i = 0; i < graph->V; i++) {
            printf("Vertex %d is assigned color %d\n", i, graph->color[i]);
        }
    } else {
        printf("Solution does not exist.\n");
    }
}

// Main function
int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printf("Graph:\n");
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d: ", i);
        struct Node* temp = graph->adjList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    
    graphColoring(graph, 3);
    return 0;
}