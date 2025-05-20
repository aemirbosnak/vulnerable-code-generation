//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VERTEX_COUNT 1000
#define MAX_EDGE_COUNT 2000
#define MAX_CHAR_COUNT 100

typedef struct {
    int vertex_count;
    int edge_count;
    char **vertices;
    int *edges;
} Graph;

Graph *graph_create() {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->vertex_count = 0;
    graph->edge_count = 0;
    graph->vertices = (char **) malloc(MAX_VERTEX_COUNT * sizeof(char *));
    graph->edges = (int *) malloc(MAX_EDGE_COUNT * sizeof(int));
    return graph;
}

void graph_destroy(Graph *graph) {
    for (int i = 0; i < graph->vertex_count; i++) {
        free(graph->vertices[i]);
    }
    free(graph->vertices);
    free(graph->edges);
    free(graph);
}

void graph_add_edge(Graph *graph, char *v1, char *v2) {
    int edge_index = graph->edge_count++;
    graph->edges[edge_index] = 0;
    graph->vertices[graph->vertex_count++] = v1;
    graph->vertices[graph->vertex_count++] = v2;
}

void graph_print(Graph *graph) {
    for (int i = 0; i < graph->vertex_count; i++) {
        printf("%s ", graph->vertices[i]);
    }
    printf("\n");
    for (int i = 0; i < graph->edge_count; i++) {
        printf("(%s, %s) ", graph->vertices[graph->edges[i] * 2],
               graph->vertices[graph->edges[i] * 2 + 1]);
    }
    printf("\n");
}

int main() {
    Graph *graph = graph_create();
    graph_add_edge(graph, "A", "B");
    graph_add_edge(graph, "B", "C");
    graph_add_edge(graph, "C", "D");
    graph_add_edge(graph, "D", "E");
    graph_add_edge(graph, "E", "F");
    graph_add_edge(graph, "F", "A");
    graph_print(graph);
    graph_destroy(graph);
    return 0;
}