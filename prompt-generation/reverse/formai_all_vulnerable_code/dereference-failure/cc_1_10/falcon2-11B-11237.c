//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define INF INT_MAX

// Graph data structure
struct Graph {
    int numNodes;
    int **adjacencyList;
};

// Create a graph with n nodes
struct Graph *createGraph(int n) {
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numNodes = n;
    graph->adjacencyList = (int **) malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) {
        graph->adjacencyList[i] = (int *) malloc(n * sizeof(int));
    }
    
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph *graph, int from, int to, int weight) {
    graph->adjacencyList[from][to] = weight;
    graph->adjacencyList[to][from] = weight;
}

// Find the shortest path between two nodes
int findShortestPath(struct Graph *graph, int start, int end) {
    int *dist = (int *) malloc(graph->numNodes * sizeof(int));
    int *parent = (int *) malloc(graph->numNodes * sizeof(int));
    
    for (int i = 0; i < graph->numNodes; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    
    dist[start] = 0;
    for (int i = 0; i < graph->numNodes; i++) {
        for (int j = 0; j < graph->numNodes; j++) {
            if (dist[j] < INF && dist[j] + graph->adjacencyList[i][j] < dist[i]) {
                dist[i] = dist[j] + graph->adjacencyList[i][j];
                parent[i] = j;
            }
        }
    }
    
    int path[graph->numNodes];
    int current = end;
    path[0] = current;
    
    while (current!= -1) {
        path[0] = parent[current];
        current = path[0];
    }
    
    int len = 0;
    for (int i = 1; i < graph->numNodes; i++) {
        path[i] = path[i - 1] * 1000 + (int) graph->adjacencyList[path[i - 1]][path[i]];
        len += graph->adjacencyList[path[i - 1]][path[i]];
    }
    
    return len;
}

// Test the program
int main() {
    struct Graph *graph = createGraph(4);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 20);
    addEdge(graph, 1, 3, 15);
    addEdge(graph, 2, 3, 5);
    
    printf("Shortest path from node 0 to node 3 is %d\n", findShortestPath(graph, 0, 3));
    
    free(graph);
    return 0;
}