//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int** createGraph(int n)
{
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = -1;
        }
    }
    return graph;
}

void printGraph(int** graph, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

bool isValidColor(int** graph, int n, int color, int vertex)
{
    for (int i = 0; i < n; i++) {
        if (graph[i][vertex] == color) {
            return false;
        }
    }
    return true;
}

int** colorGraph(int** graph, int n, int color)
{
    int** coloredGraph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        coloredGraph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            coloredGraph[i][j] = -1;
        }
    }

    int numColors = 1;
    while (numColors < n) {
        numColors++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j]!= -1 && isValidColor(graph, n, numColors, i) && isValidColor(graph, n, numColors, j)) {
                    coloredGraph[i][j] = numColors;
                    coloredGraph[j][i] = numColors;
                }
            }
        }
    }

    return coloredGraph;
}

int main()
{
    int n = 5;
    int** graph = createGraph(n);
    printf("Original Graph:\n");
    printGraph(graph, n);

    int** coloredGraph = colorGraph(graph, n, 1);
    printf("Colored Graph:\n");
    printGraph(coloredGraph, n);

    return 0;
}