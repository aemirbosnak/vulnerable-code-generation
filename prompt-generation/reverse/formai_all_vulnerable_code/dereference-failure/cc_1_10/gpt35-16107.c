//FormAI DATASET v1.0 Category: Graph representation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int v;
    int w;
    int weight;
} Edge;

typedef struct {
    int V;
    int E;
    int** adjMatrix;
} Graph;

Edge* createEdge(int v, int w, int weight) {
    Edge* edge = (Edge*) malloc(sizeof(Edge));
    edge->v = v;
    edge->w = w;
    edge->weight = weight;
    return edge;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = vertices;
    graph->E = 0;
    graph->adjMatrix = (int**) malloc(vertices * sizeof(int*));
    for(int i=0; i<vertices; i++) {
        graph->adjMatrix[i] = (int*) calloc(vertices, sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int v, int w, int weight) {
    graph->adjMatrix[v][w] = weight;
    // For undirected graph uncomment below line
    // graph->adjMatrix[w][v] = weight;
    graph->E++;
}

void printGraph(Graph* graph) {
    printf("Graph representation using adjacency matrix\n");
    printf("---------------------------------------------------\n");
    printf("Vertices: %d, Edges: %d\n", graph->V, graph->E);
    for (int i=0; i<graph->V; i++) {
        for (int j=0; j<graph->V; j++) {
            printf("%d\t", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("This program creates a graph using adjacency matrix representation\n");
    printf("Enter number of vertices in graph:");
    int n;
    scanf("%d", &n);
    Graph* graph = createGraph(n);
    printf("Enter number of edges:");
    int m;
    scanf("%d", &m);
    printf("Enter the edges with weight (u v weight):\n");
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }
    printGraph(graph);
    return 0;
}