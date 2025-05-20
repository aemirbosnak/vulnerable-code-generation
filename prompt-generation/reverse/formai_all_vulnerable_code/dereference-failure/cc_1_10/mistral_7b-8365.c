//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

void dfs(int **graph, int start, int visited[], int size);

int main() {
    int i, j, start;
    int **graph;

    graph = (int **)calloc(MAX_VERTICES, sizeof(int *));
    for (i = 0; i < MAX_VERTICES; i++) {
        graph[i] = (int *)calloc(MAX_VERTICES, sizeof(int));
    }

    // Add edges to the graph
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = i + 1; j < MAX_VERTICES; j++) {
            graph[i][j] = 1;
            graph[j][i] = 1;
            if (i == 2 && j == 3) {
                graph[i][j] = 0;
            }
        }
    }

    // Set the start vertex
    start = 0;

    int *visited = (int *)calloc(MAX_VERTICES, sizeof(int));

    dfs(graph, start, visited, MAX_VERTICES);

    for (i = 0; i < MAX_VERTICES; i++) {
        free(graph[i]);
    }
    free(graph);
    free(visited);

    return 0;
}

void dfs(int **graph, int start, int *visited, int size) {
    int i;

    visited[start] = 1;
    printf("Visited vertex %d\n", start);

    for (i = 0; i < size; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            dfs(graph, i, visited, size);
        }
    }
}