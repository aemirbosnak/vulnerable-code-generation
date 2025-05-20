//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct Edge {
    int from;
    int to;
} Edge;

int bfs(int start, int *visited, int *parent, int num_nodes, Edge *edges, int num_edges) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    visited[start] = true;
    parent[start] = -1;
    queue[rear++] = start;

    while (front < rear) {
        int curr = queue[front++];
        for (int i = 0; i < num_edges; i++) {
            Edge *e = &edges[i];
            if (e->from == curr && !visited[e->to]) {
                visited[e->to] = true;
                parent[e->to] = curr;
                queue[rear++] = e->to;
            }
        }
    }

    return rear - num_nodes;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number_of_nodes> <number_of_edges> <edges_file>\n", argv[0]);
        return 1;
    }

    int num_nodes = atoi(argv[1]);
    int num_edges = atoi(argv[2]);

    if (num_nodes > MAX_NODES || num_edges > MAX_EDGES) {
        printf("Error: Number of nodes or edges exceeds maximum limit.\n");
        return 1;
    }

    Edge *edges = malloc(num_edges * sizeof(Edge));

    FILE *file = fopen(argv[3], "r");

    if (!file) {
        printf("Error: Unable to open file %s.\n", argv[3]);
        free(edges);
        return 1;
    }

    for (int i = 0; i < num_edges; i++) {
        fscanf(file, "%d %d", &edges[i].from, &edges[i].to);
    }

    fclose(file);

    int *visited = calloc(num_nodes, sizeof(bool));
    int *parent = calloc(num_nodes, sizeof(int));

    int num_connected_components = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            num_connected_components += bfs(i, visited, parent, num_nodes, edges, num_edges);
        }
    }

    free(visited);
    free(parent);
    free(edges);

    printf("Number of connected components: %d\n", num_connected_components);

    return 0;
}