//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10
#define MAX_ITERATIONS 1000

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_colors;
int num_vertices;

void init_graph(int n) {
    num_vertices = n;
    num_colors = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % (n-1) + 1;
        }
    }
}

int is_valid_color(int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (colors[i] == color) {
            return 0;
        }
        for (int j = 0; j < num_vertices; j++) {
            if (graph[i][j] == color) {
                return 0;
            }
        }
    }
    return 1;
}

int find_min_color() {
    int min_color = MAX_COLORS;
    for (int i = 1; i <= MAX_COLORS; i++) {
        if (is_valid_color(i)) {
            min_color = i;
            break;
        }
    }
    return min_color;
}

int color_graph() {
    int iterations = 0;
    while (iterations < MAX_ITERATIONS) {
        int min_color = find_min_color();
        if (min_color == MAX_COLORS) {
            return 0;
        }
        for (int i = 0; i < num_vertices; i++) {
            if (colors[i] == 0) {
                colors[i] = min_color;
                for (int j = 0; j < num_vertices; j++) {
                    if (graph[i][j] == min_color) {
                        return 0;
                    }
                }
            }
        }
        iterations++;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph(n);
    printf("Initial Graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    int result = color_graph();
    if (result) {
        printf("Colored Graph:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d is colored %d\n", i, colors[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", MAX_COLORS);
    }
    return 0;
}