//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct {
    int vertex;
    int color;
} Graph;

void print_graph(Graph graph[], int num_vertices) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d has color %d\n", graph[i].vertex, graph[i].color);
    }
}

int is_valid_color(Graph graph[], int vertex, int color) {
    int i;
    for (i = 0; i < vertex; i++) {
        if (graph[i].vertex != vertex && graph[i].color == color) {
            return 0;
        }
    }
    return 1;
}

void graph_coloring_brute_force(Graph graph[], int num_vertices) {
    int i, j, color;
    for (i = 0; i < num_vertices; i++) {
        graph[i].color = MIN_COLOR;
        for (color = MIN_COLOR + 1; color <= MAX_COLOR; color++) {
            if (is_valid_color(graph, i, color)) {
                graph[i].color = color;
                break;
            }
        }
        if (graph[i].color == MIN_COLOR) {
            printf("Graph cannot be colored using %d colors.\n", MAX_COLOR + 1);
            return;
        }
    }
    print_graph(graph, num_vertices);
}

int main() {
    int num_vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (num_vertices > MAX_VERTICES || edges > num_vertices * (num_vertices - 1) / 2) {
        printf("Invalid input.\n");
        return 1;
    }

    Graph graph[num_vertices];

    for (int i = 0; i < num_vertices; i++) {
        graph[i].vertex = i;
        graph[i].color = MIN_COLOR;
    }

    int from, to;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &from, &to);
        if (graph[from].color == graph[to].color) {
            printf("Invalid edge coloring.\n");
            return 1;
        }
    }

    graph_coloring_brute_force(graph, num_vertices);

    return 0;
}