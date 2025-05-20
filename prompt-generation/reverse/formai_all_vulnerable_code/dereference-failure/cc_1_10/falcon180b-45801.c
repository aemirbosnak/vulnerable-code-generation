//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 10000

// Graph representation using adjacency list
typedef struct {
    int vertices;
    int edges;
    int *adj_list;
} Graph;

// Function to create a new graph with given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = 0;
    graph->adj_list = (int*)malloc(vertices * sizeof(int));
    memset(graph->adj_list, -1, vertices * sizeof(int));
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v) {
    graph->adj_list[u] = v;
    graph->adj_list[v] = u;
    graph->edges++;
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adj_list[i] == j) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Function to traverse the graph using depth-first search algorithm
void dfs(Graph* graph, int start, int visited[]) {
    visited[start] = 1;
    printf("Vertex %d visited\n", start);
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj_list[start] == i &&!visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int main() {
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    Graph* graph = createGraph(vertices);

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);

    int visited[MAX_VERTICES];
    memset(visited, 0, sizeof(visited));

    dfs(graph, 0, visited);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            printf("Vertex %d not visited\n", i);
        }
    }

    return 0;
}