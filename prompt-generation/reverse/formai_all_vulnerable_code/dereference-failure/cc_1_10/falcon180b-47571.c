//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 6

int num_vertices;
int **graph;
int *color;

void init_graph() {
    srand(time(NULL));
    num_vertices = rand() % MAX_VERTICES + 1;
    graph = (int **)malloc(num_vertices * sizeof(int *));
    color = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        graph[i] = (int *)malloc(num_vertices * sizeof(int));
        color[i] = i % MAX_COLORS;
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

void print_graph() {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void print_color() {
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int check_valid_color(int v, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    for (int i = 0; i < num_vertices; i++) {
        color[i] = rand() % MAX_COLORS;
    }
    while (1) {
        int valid = 1;
        for (int i = 0; i < num_vertices; i++) {
            if (color[i] == -1) {
                int c = rand() % MAX_COLORS;
                while (!check_valid_color(i, c)) {
                    c = (c + 1) % MAX_COLORS;
                }
                color[i] = c;
            }
        }
        if (valid) {
            break;
        }
    }
}

int main() {
    init_graph();
    printf("Original Graph:\n");
    print_graph();
    printf("Colors:\n");
    print_color();
    color_graph();
    printf("Colored Graph:\n");
    print_graph();
    return 0;
}