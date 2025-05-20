//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9
#define M 3
#define White 0
#define Gray 1
#define Black 2
#define MAX_COLOR 7

int **graph;
int *color;
int *parent;
int time_taken;

void initialize() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 1;
        }
    }
}

void print_graph() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (graph[i][j] == 0)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}

void dfs(int v) {
    color[v] = Gray;
    time_taken++;
    int u;
    for (u = 0; u < N; u++) {
        if (graph[v][u] == 0 && color[u] == White) {
            parent[u] = v;
            dfs(u);
        }
    }
    color[v] = Black;
    time_taken++;
}

void backtrack(int u) {
    if (u!= -1) {
        color[u] = Black;
        time_taken++;
        backtrack(parent[u]);
    }
}

int main() {
    srand(time(0));
    int i, j;
    graph = (int **) malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        graph[i] = (int *) malloc(N * sizeof(int));
    }
    color = (int *) malloc(N * sizeof(int));
    parent = (int *) malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        color[i] = White;
        parent[i] = -1;
    }
    initialize();
    printf("Initial Graph:\n");
    print_graph();
    dfs(0);
    printf("\n");
    printf("Minimum Time Taken for Coloring: %d\n", time_taken);
    printf("Colored Graph:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (graph[i][j] == 0)
                printf(" ");
            else if (color[i] == 1 && color[j] == 1)
                printf("1");
            else if (color[i] == 2 && color[j] == 2)
                printf("2");
            else if (color[i] == 3 && color[j] == 3)
                printf("3");
            else if (color[i] == 4 && color[j] == 4)
                printf("4");
            else if (color[i] == 5 && color[j] == 5)
                printf("5");
            else if (color[i] == 6 && color[j] == 6)
                printf("6");
        }
        printf("\n");
    }
    return 0;
}