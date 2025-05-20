//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int n_vertices;
int n_colors;

bool is_valid_assignment(int vertex, int color) {
    for (int i = 0; i < n_vertices; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

void assign_color(int vertex, int color) {
    colors[vertex] = color;
    for (int i = 0; i < n_vertices; i++) {
        if (graph[vertex][i]) {
            colors[i] = -1;
        }
    }
}

void print_assignment(void) {
    for (int i = 0; i < n_vertices; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

void generate_graph(int n_vertices, int max_edges) {
    srand(time(NULL));
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

int main(void) {
    printf("Enter the number of vertices: ");
    scanf("%d", &n_vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &n_colors);
    generate_graph(n_vertices, n_vertices * 2);
    int start_vertex = rand() % n_vertices;
    int n_assigned_colors = 0;
    while (n_assigned_colors < n_colors) {
        int i = rand() % n_vertices;
        while (colors[i]!= -1) {
            i = rand() % n_vertices;
        }
        int color = rand() % n_colors;
        while (!is_valid_assignment(i, color)) {
            color = rand() % n_colors;
        }
        assign_color(i, color);
        n_assigned_colors++;
    }
    print_assignment();
    return 0;
}