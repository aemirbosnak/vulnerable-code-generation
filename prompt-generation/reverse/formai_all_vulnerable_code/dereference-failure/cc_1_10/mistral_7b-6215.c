//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int vertex;
    int color;
} Vertex;

void print_graph(Vertex **graph, int num_vertices) {
    printf("Graph Coloring Problem - Greedy Algorithm Solution\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_vertices; ++i) {
        printf("Vertex %d has color %d\n", i, graph[i]->color);
    }
}

bool is_valid_color(Vertex **graph, int num_vertices, int vertex, int color) {
    for (int i = 0; i < num_vertices; ++i) {
        if (i != vertex && graph[i]->color == color) {
            return false;
        }
    }
    return true;
}

int main() {
    int num_vertices = 6;
    Vertex *graph[num_vertices];

    for (int i = 0; i < num_vertices; ++i) {
        graph[i] = malloc(sizeof(Vertex));
        graph[i]->vertex = i;
        graph[i]->color = -1;
    }

    int edges[15][2] = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 4},
        {2, 5},
        {3, 4},
        {3, 5},
        {4, 5}
    };

    for (int i = 0; i < num_vertices; ++i) {
        printf("Assigning color to Vertex %d\n", i);
        for (int j = 0; j < 7; ++j) { // Maximum 7 colors
            int color = j + 1;
            if (is_valid_color(graph, num_vertices, i, color)) {
                graph[i]->color = color;
                break;
            }
        }
    }

    print_graph(graph, num_vertices);

    for (int i = 0; i < num_vertices; ++i) {
        free(graph[i]);
    }

    return 0;
}