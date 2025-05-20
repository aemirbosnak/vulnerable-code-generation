//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int vertex;
    int color;
} Edge;

int numVertices;
int numColors;
int **graph;
int *colors;
int *visited;

void init(void) {
    srand(time(NULL));
    numVertices = rand() % MAX_VERTICES + 1;
    numColors = rand() % MAX_COLORS + 1;
    printf("Number of vertices: %d\n", numVertices);
    printf("Number of colors: %d\n", numColors);

    graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    colors = (int *)malloc(numColors * sizeof(int));
    for (int i = 0; i < numColors; i++) {
        colors[i] = rand() % 256;
    }

    visited = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
}

void printGraph(void) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) {
                printf("%d -- %d\n", i, j);
            }
        }
    }
}

void printColors(void) {
    for (int i = 0; i < numColors; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int dfs(int vertex, int color) {
    visited[vertex] = 1;
    colors[vertex] = color;

    int count = 0;
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 &&!visited[i]) {
            int newColor = -1;
            for (int j = 0; j < numColors; j++) {
                if (!visited[j] || (i == vertex && j == color)) {
                    newColor = j;
                    break;
                }
            }

            if (newColor == -1) {
                return 0;
            }

            count += dfs(i, newColor);
        }
    }

    return count;
}

int main(void) {
    init();
    printGraph();
    int maxCount = 0;

    for (int i = 0; i < numVertices; i++) {
        int count = dfs(i, 0);
        if (count > maxCount) {
            maxCount = count;
        }
    }

    printf("Maximum number of colors: %d\n", maxCount);
    printColors();

    return 0;
}