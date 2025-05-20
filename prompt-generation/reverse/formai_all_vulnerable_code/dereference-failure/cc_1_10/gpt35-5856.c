//FormAI DATASET v1.0 Category: Graph representation ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Graph {
    int V;
    int **adjMatrix;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));

    int i,j;
    for(i=0; i<V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
        for(j=0; j<V; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int start, int end, int weight) {
    graph->adjMatrix[start][end] = weight;
}

void printGraph(struct Graph* graph) {
    int i,j;
    for(i=0; i<graph->V; i++) {
        printf("%d -> ", i);
        for(j=0; j<graph->V; j++) {
            if(graph->adjMatrix[i][j] != 0) {
                printf("%d (weight:%d) ", j, graph->adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int V = 4;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 2, 3, 1);

    printGraph(graph);

    return 0;
}