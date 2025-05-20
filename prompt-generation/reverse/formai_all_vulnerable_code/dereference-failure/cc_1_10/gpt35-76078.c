//FormAI DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

// Structure of a graph node
struct Node {
    int vertex;
    struct Node* next;  // Pointer to the next node
};

struct Graph {
    int vertices;  // Number of vertices in the graph
    struct Node** adjList;  // Array of adjacency lists
};

// Function to create a graph with n vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = n;

    graph->adjList = (struct Node**)malloc(n * sizeof(struct Node*));

    int i;
    for (i = 0; i < n; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = dest;
    node->next = graph->adjList[src];
    graph->adjList[src] = node;

    node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = src;
    node->next = graph->adjList[dest];
    graph->adjList[dest] = node;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->vertices; v++) {
        struct Node* temp = graph->adjList[v];
        printf("\nAdjacency list of vertex %d\n", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n = 5;
    struct Graph* graph = createGraph(n);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);

    return 0;
}