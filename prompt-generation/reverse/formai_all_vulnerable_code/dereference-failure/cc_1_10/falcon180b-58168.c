//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct {
    int node;
    int color;
} Vertex;

typedef struct {
    Vertex *vertices;
    int num_vertices;
    int num_colors;
} Graph;

void init_graph(Graph *graph, int num_vertices, int num_colors) {
    graph->vertices = (Vertex *) malloc(num_vertices * sizeof(Vertex));
    graph->num_vertices = num_vertices;
    graph->num_colors = num_colors;
    for (int i = 0; i < num_vertices; i++) {
        graph->vertices[i].node = i;
        graph->vertices[i].color = -1;
    }
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d: %d\n", i, graph->vertices[i].color);
    }
}

int is_valid_color(Graph *graph, int node, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->vertices[i].node == node && graph->vertices[i].color == color) {
            return 0;
        }
    }
    return 1;
}

int color_graph(Graph *graph) {
    int num_colors_used = 0;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->vertices[i].color == -1) {
            int color = rand() % graph->num_colors;
            while (!is_valid_color(graph, i, color)) {
                color = rand() % graph->num_colors;
            }
            graph->vertices[i].color = color;
            num_colors_used++;
        }
    }
    return num_colors_used;
}

int main() {
    int num_vertices, num_colors;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    Graph graph;
    init_graph(&graph, num_vertices, num_colors);

    srand(time(NULL));
    int num_colors_used = color_graph(&graph);

    printf("Graph colored with %d colors:\n", num_colors_used);
    print_graph(&graph);

    return 0;
}