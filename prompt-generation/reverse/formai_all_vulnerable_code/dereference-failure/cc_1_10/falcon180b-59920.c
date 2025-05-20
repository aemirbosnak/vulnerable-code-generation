//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLOR_NUM 100

int V;
int E;
int **graph;
int **color;
int **parent;

void init() {
    srand(time(NULL));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph[i] = (int *)malloc(sizeof(int) * MAX_VERTICES);
        color[i] = rand() % MAX_COLOR_NUM;
    }
}

void createGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (v1 v2): ");
    for (int i = 0; i < E; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
}

int isColorValid(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void colorGraph() {
    for (int v = 0; v < V; v++) {
        int c = rand() % MAX_COLOR_NUM;
        while (!isColorValid(v, c)) {
            c = rand() % MAX_COLOR_NUM;
        }
        color[v] = c;
    }
}

void printGraph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                printf("%d-%d ", i, j);
            }
        }
    }
}

int main() {
    init();
    createGraph();
    colorGraph();
    printGraph();

    return 0;
}