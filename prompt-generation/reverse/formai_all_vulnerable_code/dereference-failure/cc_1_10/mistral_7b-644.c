//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAX_VERTICES 100

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int source);
void read_graph_from_file(char *filename, int graph[MAX_VERTICES][MAX_VERTICES]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <graph_file>\n", argv[0]);
        return 1;
    }

    int graph[MAX_VERTICES][MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    read_graph_from_file(argv[1], graph);

    for (int i = 0; i < MAX_VERTICES; ++i) {
        if (!visited[i]) {
            dfs(graph, visited, i);
            printf("\nConnected Component: ");
            for (int j = 0; j < MAX_VERTICES; ++j) {
                if (visited[j]) printf(" %d", j);
            }
            printf("\n");
        }
    }

    return 0;
}

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int source) {
    visited[source] = true;

    for (int i = 0; i < MAX_VERTICES; ++i) {
        if (graph[source][i] && !visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

void read_graph_from_file(char *filename, int graph[MAX_VERTICES][MAX_VERTICES]) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    char line[100];
    int num_vertices = 0, num_edges = 0;

    fgets(line, sizeof(line), file);
    sscanf(line, "%d %d", &num_vertices, &num_edges);

    for (int i = 0; i < num_vertices; ++i) {
        for (int j = 0; j < num_vertices; ++j) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < num_edges; ++i) {
        int u, v;
        fgets(line, sizeof(line), file);
        sscanf(line, "%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    fclose(file);
}