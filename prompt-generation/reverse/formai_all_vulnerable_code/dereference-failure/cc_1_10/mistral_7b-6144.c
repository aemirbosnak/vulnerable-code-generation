//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void dfs(int **adj_matrix, int start_vertex, int *visited, int num_vertices);

int main(int argc, char *argv[]) {
    int num_vertices, num_edges, i, j;
    int **adj_matrix;

    if (argc != 3) {
        printf("Usage: %s <number_of_vertices> <number_of_edges>\n", argv[0]);
        return 1;
    }

    num_vertices = atoi(argv[1]);
    num_edges = atoi(argv[2]);

    if (num_vertices <= 0 || num_vertices > MAX_VERTICES || num_edges <= 0) {
        printf("Invalid number of vertices or edges.\n");
        return 1;
    }

    adj_matrix = (int **)calloc(num_vertices, sizeof(int *));

    for (i = 0; i < num_vertices; i++) {
        adj_matrix[i] = (int *)calloc(num_vertices, sizeof(int));
    }

    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &j, &i);
        adj_matrix[i][j] = 1;
        adj_matrix[j][i] = 1;
    }

    dfs(adj_matrix, 0, (int *)calloc(num_vertices, sizeof(int)), num_vertices);

    for (i = 0; i < num_vertices; i++) {
        free(adj_matrix[i]);
    }

    free(adj_matrix);

    return 0;
}

void dfs(int **adj_matrix, int start_vertex, int *visited, int num_vertices) {
    visited[start_vertex] = 1;
    printf("Visited vertex %d\n", start_vertex);

    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[start_vertex][i] && visited[i] == 0) {
            dfs(adj_matrix, i, visited, num_vertices);
        }
    }
}