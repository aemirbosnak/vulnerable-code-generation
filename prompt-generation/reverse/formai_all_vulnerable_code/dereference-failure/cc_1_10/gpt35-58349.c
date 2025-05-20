//FormAI DATASET v1.0 Category: Graph representation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

int numVertices = 0;

typedef struct edge {
    int u, v, weight;
} edge;

edge graph[MAX_VERTICES][MAX_VERTICES];

void addEdge(int u, int v, int weight) {
    graph[u][v].u = u;
    graph[u][v].v = v;
    graph[u][v].weight = weight;
}

void printGraph() {
    printf("\nGraph Representation:\n");
    for(int i=0; i<numVertices; i++) {
        for(int j=0; j<numVertices; j++) {
            if(graph[i][j].weight != 0) {
                printf("(%d, %d) : %d\t", graph[i][j].u, graph[i][j].v, graph[i][j].weight);
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int *vertices = malloc(numVertices * sizeof(int));
    for(int i=0; i<numVertices; i++) {
        vertices[i] = i;
    }

    printf("\nEnter the number of edges: ");
    int numEdges;
    scanf("%d", &numEdges);

    printf("\n");

    for(int i=0; i<numEdges; i++) {
        int u, v, weight;
        printf("Enter the details of edge %d in the format - source destination weight: ", i+1);
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(u, v, weight);
    }

    printGraph();

    free(vertices);

    return 0;
}