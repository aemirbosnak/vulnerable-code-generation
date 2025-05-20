//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 99999

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest, int weight);
void displayGraph(Graph* graph);
void dijkstra(Graph* graph, int startVertex);
void freeGraph(Graph* graph);

int main() {
    int vertices, edges, src, dest, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    if(vertices > MAX_VERTICES || vertices <= 0) {
        printf("Number of vertices must be between 1 and %d\n", MAX_VERTICES);
        return 1;
    }

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest weight):\n");
    for(int i = 0; i < edges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    printf("Adjacency Matrix:\n");
    displayGraph(graph);

    printf("Enter starting vertex for Dijkstra's algorithm: ");
    int startVertex;
    scanf("%d", &startVertex);

    printf("Shortest paths from vertex %d:\n", startVertex);
    dijkstra(graph, startVertex);

    freeGraph(graph);
    return 0;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            if (i == j) {
                graph->adjMatrix[i][j] = 0;
            } else {
                graph->adjMatrix[i][j] = INF;
            }
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight; // For undirected graph
}

void displayGraph(Graph* graph) {
    for(int i = 0; i < graph->numVertices; i++) {
        for(int j = 0; j < graph->numVertices; j++) {
            if(graph->adjMatrix[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", graph->adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

void dijkstra(Graph* graph, int startVertex) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for(int i = 0; i < graph->numVertices; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }
    distance[startVertex] = 0;

    for(int count = 0; count < graph->numVertices - 1; count++) {
        int minDistance = INF;
        int minIndex;

        for(int v = 0; v < graph->numVertices; v++) {
            if (visited[v] == 0 && distance[v] <= minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }
        
        visited[minIndex] = 1;

        for(int v = 0; v < graph->numVertices; v++) {
            if (!visited[v] && graph->adjMatrix[minIndex][v] != INF &&
                distance[minIndex] != INF && 
                distance[minIndex] + graph->adjMatrix[minIndex][v] < distance[v]) {
                distance[v] = distance[minIndex] + graph->adjMatrix[minIndex][v];
            }
        }
    }

    for(int i = 0; i < graph->numVertices; i++) {
        if(distance[i] == INF) {
            printf("Vertex %d is not reachable from vertex %d\n", i, startVertex);
        } else {
            printf("Distance to vertex %d: %d\n", i, distance[i]);
        }
    }
}

void freeGraph(Graph* graph) {
    free(graph);
}