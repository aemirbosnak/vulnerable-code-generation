//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int source, int destination);
void displayGraph(Graph* graph);
void depthFirstSearch(Graph* graph, int vertex, int* visited);
void dfsTraversal(Graph* graph, int startVertex);
void freeGraph(Graph* graph);

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Graph Adjacency Matrix:\n");
    displayGraph(graph);

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    dfsTraversal(graph, startVertex);

    freeGraph(graph);
    return 0;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph* graph, int source, int destination) {
    if (source >= graph->numVertices || destination >= graph->numVertices || source < 0 || destination < 0) {
        printf("Invalid edge!\n");
        return;
    }

    graph->adjMatrix[source][destination] = 1;
    graph->adjMatrix[destination][source] = 1;  // For undirected graph
}

void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void depthFirstSearch(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            depthFirstSearch(graph, i, visited);
        }
    }
}

void dfsTraversal(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    depthFirstSearch(graph, startVertex, visited);
    printf("\n");
}

void freeGraph(Graph* graph) {
    free(graph);
}