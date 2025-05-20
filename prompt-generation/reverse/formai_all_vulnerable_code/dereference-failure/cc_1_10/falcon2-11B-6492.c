//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct Graph {
    int numVertices;
    int numEdges;
    int** adjacencyList;
};

int main() {
    struct Graph graph;
    graph.numVertices = 5;
    graph.numEdges = 10;
    graph.adjacencyList = malloc(graph.numVertices * sizeof(int*));

    for (int i = 0; i < graph.numVertices; i++) {
        graph.adjacencyList[i] = malloc(graph.numEdges * sizeof(int));
    }

    // Add edges to the graph

    graph.adjacencyList[0][0] = 1;
    graph.adjacencyList[0][1] = 2;
    graph.adjacencyList[0][2] = 3;
    graph.adjacencyList[0][3] = 4;

    graph.adjacencyList[1][0] = 2;
    graph.adjacencyList[1][1] = 3;
    graph.adjacencyList[1][2] = 4;

    graph.adjacencyList[2][0] = 3;
    graph.adjacencyList[2][1] = 4;

    graph.adjacencyList[3][0] = 4;

    graph.adjacencyList[4][0] = 5;

    printf("Adjacency List:\n");
    for (int i = 0; i < graph.numVertices; i++) {
        for (int j = 0; j < graph.numEdges; j++) {
            printf("%d ", graph.adjacencyList[i][j]);
        }
        printf("\n");
    }

    return 0;
}