//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UNCOLORED -1

typedef struct {
    int *colors;
    int n;
} Graph;

Graph *create_graph(int n) {
    Graph *graph = malloc(sizeof(Graph));
    graph->n = n;
    graph->colors = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        graph->colors[i] = UNCOLORED;
    }
    return graph;
}

void destroy_graph(Graph *graph) {
    free(graph->colors);
    free(graph);
}

int is_safe(Graph *graph, int v, int color) {
    for (int i = 0; i < graph->n; i++) {
        if (graph->colors[i] == color && (i == v || graph->colors[i] == UNCOLORED)) {
            return 0;
        }
    }
    return 1;
}

int graph_color(Graph *graph, int v) {
    if (v == graph->n) {
        return 1;
    }
    for (int color = 0; color < graph->n; color++) {
        if (is_safe(graph, v, color)) {
            graph->colors[v] = color;
            if (graph_color(graph, v + 1)) {
                return 1;
            }
            graph->colors[v] = UNCOLORED;
        }
    }
    return 0;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->n; i++) {
        printf("%d ", graph->colors[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph *graph = create_graph(n);
    if (graph_color(graph, 0)) {
        printf("Graph colored successfully.\n");
        print_graph(graph);
    } else {
        printf("Graph could not be colored.\n");
    }
    destroy_graph(graph);
    return 0;
}