//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 6

typedef struct {
    int color;
    int size;
} Vertex;

typedef struct {
    Vertex* vertices;
    int num_vertices;
} Graph;

void create_random_graph(Graph* graph, int num_vertices, int max_degree) {
    srand(time(NULL));
    graph->num_vertices = num_vertices;
    graph->vertices = (Vertex*) malloc(sizeof(Vertex) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->vertices[i].color = rand() % MAX_COLORS;
        graph->vertices[i].size = rand() % max_degree;
    }
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: color %d, size %d\n", i, graph->vertices[i].color, graph->vertices[i].size);
    }
}

int is_valid_coloring(Graph* graph, int vertex_index, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->vertices[i].color == color && (graph->vertices[i].size > 0 && graph->vertices[i].size == graph->vertices[vertex_index].size)) {
            return 0;
        }
    }
    return 1;
}

void color_graph(Graph* graph) {
    int num_colors_used = 0;
    for (int i = 0; i < graph->num_vertices; i++) {
        int color = rand() % MAX_COLORS;
        while (!is_valid_coloring(graph, i, color)) {
            color = (color + 1) % MAX_COLORS;
        }
        graph->vertices[i].color = color;
        num_colors_used++;
    }
    printf("Graph colored with %d colors\n", num_colors_used);
}

int main() {
    Graph graph;
    int num_vertices, max_degree;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the maximum degree: ");
    scanf("%d", &max_degree);
    create_random_graph(&graph, num_vertices, max_degree);
    print_graph(&graph);
    color_graph(&graph);
    return 0;
}