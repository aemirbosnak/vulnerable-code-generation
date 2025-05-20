//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void print_graph(int **graph, int vertices) {
    int i, j;
    for (i = 0; i < vertices; i++) {
        printf("Vertex %d: ", i);
        for (j = 0; j < vertices; j++) {
            printf(" %d", graph[i][j]);
        }
        printf("\n");
    }
}

void create_graph(int **graph, int vertices, int edges) {
    int i, j, k;
    for (i = 0; i < vertices; i++) {
        graph[i] = (int *)calloc(vertices, sizeof(int));
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    for (k = 0; k < edges; k++) {
        scanf("%d %d", &i, &j);
        graph[i][j] = 1;
        graph[j][i] = 1;
    }
}

int main(int argc, char **argv) {
    int vertices, edges;
    int **graph;

    if (argc != 3) {
        printf("Usage: %s <number_of_vertices> <number_of_edges>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    vertices = atoi(argv[1]);
    edges = atoi(argv[2]);

    if (vertices > MAX_VERTICES || vertices < 1 || edges < 0) {
        printf("Invalid input. Expected valid number of vertices and edges.\n");
        exit(EXIT_FAILURE);
    }

    graph = (int **)calloc(vertices, sizeof(int *));
    create_graph(graph, vertices, edges);
    print_graph(graph, vertices);

    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return EXIT_SUCCESS;
}