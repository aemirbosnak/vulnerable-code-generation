//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int vertex;
    int color;
} Node;

int get_random_color(int num_colors) {
    return rand() % num_colors;
}

void print_graph(Node graph[], int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        printf("%d: %d\n", i, graph[i].color);
    }
}

int is_valid_coloring(Node graph[], int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (graph[i].color == graph[j].color && i!= j) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int num_vertices, num_colors;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    Node graph[num_vertices];

    for (int i = 0; i < num_vertices; i++) {
        graph[i].vertex = i;
        graph[i].color = get_random_color(num_colors);
    }

    int num_iterations = 0;
    while (!is_valid_coloring(graph, num_vertices)) {
        for (int i = 0; i < num_vertices; i++) {
            int target_color = get_random_color(num_colors);
            while (graph[i].color == target_color) {
                target_color = get_random_color(num_colors);
            }
            graph[i].color = target_color;
        }
        num_iterations++;
    }

    printf("The graph has been colored with %d colors:\n", num_colors);
    print_graph(graph, num_vertices);

    return 0;
}