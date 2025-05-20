//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTICES 10

typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int startVertex, int endVertex) {
    graph->adjMatrix[startVertex][endVertex] = 1;
    graph->adjMatrix[endVertex][startVertex] = 1; // Uncomment for undirected graph
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                printf(" -> %d", j);
            }
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    free(graph);
}

void depthFirstSearch(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            depthFirstSearch(graph, i, visited);
        }
    }
}

void breadthFirstSearch(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    printf("Visited %d\n", startVertex);
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                printf("Visited %d\n", i);
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int numVertices = 6;
    Graph* graph = createGraph(numVertices);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    printf("Graph adjacency list:\n");
    printGraph(graph);
    
    printf("\nDepth First Search starting from vertex 0:\n");
    int visited[MAX_VERTICES] = {0};
    depthFirstSearch(graph, 0, visited);

    printf("\nBreadth First Search starting from vertex 0:\n");
    breadthFirstSearch(graph, 0);
    
    freeGraph(graph);
    return 0;
}