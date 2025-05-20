//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 10

typedef struct vertex {
    int id;
    int color;
} Vertex;

typedef struct graph {
    int num_vertices;
    Vertex *vertices;
} Graph;

void create_graph(Graph *graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    graph->vertices = (Vertex *)malloc(num_vertices * sizeof(Vertex));
    for (int i = 0; i < num_vertices; i++) {
        graph->vertices[i].id = i;
        graph->vertices[i].color = 0;
    }
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", graph->vertices[i].id, graph->vertices[i].color);
    }
}

bool is_valid_color(Graph *graph, int vertex_id, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (i!= vertex_id && graph->vertices[i].color == color) {
            return false;
        }
    }
    return true;
}

bool color_graph(Graph *graph) {
    int num_vertices = graph->num_vertices;
    int *colors = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = 0;
    }

    srand(time(NULL));
    for (int i = 0; i < num_vertices; i++) {
        int color = rand() % MAX_COLORS;
        while (!is_valid_color(graph, i, color)) {
            color = (color + 1) % MAX_COLORS;
        }
        colors[i] = color;
        graph->vertices[i].color = color;
    }

    free(colors);
    return true;
}

int main() {
    int num_vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    Graph graph;
    create_graph(&graph, num_vertices);

    color_graph(&graph);

    printf("Colored graph:\n");
    print_graph(&graph);

    return 0;
}