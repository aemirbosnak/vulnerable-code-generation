//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NODES 10000
#define PERCENT_OPEN 50
int main(int argc, char **argv) {
    int i, j, num_edges, num_nodes, num_open_nodes;
    int **graph, **open_graph;
    srand(time(NULL));
    num_nodes = rand() % MAX_NODES + 1;
    num_edges = rand() % (num_nodes * (num_nodes - 1)) / 2;
    graph = malloc(num_nodes * sizeof(int *));
    for (i = 0; i < num_nodes; i++) {
        graph[i] = malloc(num_nodes * sizeof(int));
    }
    open_graph = malloc(num_nodes * sizeof(int *));
    for (i = 0; i < num_nodes; i++) {
        open_graph[i] = malloc(num_nodes * sizeof(int));
    }
    for (i = 0; i < num_edges; i++) {
        int u = rand() % num_nodes, v = rand() % num_nodes;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            open_graph[i][j] = 0;
        }
    }
    for (i = 0; i < num_nodes; i++) {
        num_open_nodes = 0;
        for (j = 0; j < num_nodes; j++) {
            if (open_graph[i][j]) {
                num_open_nodes++;
            }
        }
        if (num_open_nodes > (int) (num_open_nodes * PERCENT_OPEN / 100)) {
            num_open_nodes = num_open_nodes * PERCENT_OPEN / 100;
        }
        for (j = 0; j < num_nodes; j++) {
            if (graph[i][j] && open_graph[i][j]) {
                open_graph[i][j] = 1;
            }
        }
    }
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            printf("%d ", open_graph[i][j]);
        }
        printf("\n");
    }
    free(graph);
    free(open_graph);
    return 0;
}