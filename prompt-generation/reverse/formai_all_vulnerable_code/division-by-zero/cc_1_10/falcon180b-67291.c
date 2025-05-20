//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX 100
#define MAX_COLOR 100

int graph[MAX_VERTEX][MAX_VERTEX];
int vertex_num, edge_num;
int color_num;
int color[MAX_VERTEX];

void init() {
    srand(time(NULL));
    vertex_num = rand() % MAX_VERTEX + 1;
    edge_num = rand() % (vertex_num * (vertex_num - 1) / 2) + 1;
    color_num = rand() % MAX_COLOR + 1;
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            graph[i][j] = rand() % 2;
        }
        color[i] = rand() % color_num;
    }
}

void print_graph() {
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            printf("%d", graph[i][j]);
        }
        printf("\n");
    }
}

void print_color() {
    for (int i = 0; i < vertex_num; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int check_color(int v, int c) {
    for (int i = 0; i < vertex_num; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int v, int c) {
    if (v == vertex_num) {
        return;
    }
    color[v] = c;
    for (int i = 0; i < vertex_num; i++) {
        if (graph[v][i] && check_color(i, c)) {
            color[i] = c;
            backtrack(v + 1, c);
        }
    }
}

int main() {
    init();
    printf("Graph:\n");
    print_graph();
    printf("Color:\n");
    print_color();
    backtrack(0, 1);
    printf("Coloring:\n");
    for (int i = 0; i < vertex_num; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
    return 0;
}