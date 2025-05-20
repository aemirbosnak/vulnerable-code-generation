//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 6

typedef struct {
    int id;
    int color;
    bool visited;
} Vertex;

Vertex graph[MAX_VERTICES];
int numVertices;
int numColors;
int **adjMatrix;

void createGraph(int numVertices) {
    printf("Enter the number of vertices:\n");
    scanf("%d", &numVertices);

    printf("Enter the number of colors:\n");
    scanf("%d", &numColors);

    for (int i = 0; i < numVertices; i++) {
        graph[i].id = i;
        graph[i].color = -1;
        graph[i].visited = false;
    }

    adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

bool isSafe(int v, int c, int *color) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[i].color == c && adjMatrix[v][i] == 1) {
            return false;
        }
    }
    return true;
}

void colorGraph(int startVertex) {
    int *color = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        color[i] = -1;
    }

    int c = 0;
    color[startVertex] = c;
    for (int i = 0; i < numVertices; i++) {
        if (graph[i].color == -1) {
            if (isSafe(i, c, color)) {
                graph[i].color = c;
            } else {
                c++;
                while (!isSafe(i, c, color)) {
                    c++;
                }
                graph[i].color = c;
            }
        }
    }

    printf("The coloring of the graph is:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", graph[i].color);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int numVertices;
    printf("Enter the number of vertices:\n");
    scanf("%d", &numVertices);

    createGraph(numVertices);

    int startVertex;
    printf("Enter the starting vertex:\n");
    scanf("%d", &startVertex);

    colorGraph(startVertex);

    return 0;
}