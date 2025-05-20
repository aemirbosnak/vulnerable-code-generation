//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int V;
int **graph;
int *color;

void init_graph(int v);
void print_solution(int v);
int color_graph(int v, int i, int c);

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int v = rand() % 10 + 1;
    init_graph(v);
    int **solution = (int **)malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++) {
        solution[i] = (int *)malloc(v * sizeof(int));
    }
    int c = 0;
    color_graph(v, 0, c);
    print_solution(v);
    return 0;
}

void init_graph(int v) {
    graph = (int **)malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++) {
        graph[i] = (int *)malloc(v * sizeof(int));
        for (int j = 0; j < v; j++) {
            graph[i][j] = rand() % 2;
        }
    }
    color = (int *)malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) {
        color[i] = -1;
    }
}

void print_solution(int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int color_graph(int v, int i, int c) {
    if (i == v - 1) {
        return 1;
    }
    int j;
    for (j = 0; j < v; j++) {
        if (graph[i][j] == 1 && color[j] == -1 && (c & (1 << j)) == 0) {
            color[j] = c;
            if (color_graph(v, i + 1, c | (1 << j)) == 0) {
                return 0;
            }
            color[j] = -1;
        }
    }
    return 1;
}