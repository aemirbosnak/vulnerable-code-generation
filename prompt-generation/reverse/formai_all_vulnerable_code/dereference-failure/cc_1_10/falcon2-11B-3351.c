//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int vertex;
    int weight;
} edge_t;

typedef struct {
    int num_vertices;
    int num_edges;
    int **adj_list;
} graph_t;

int main() {
    graph_t graph;
    int i, j, num_vertices, num_edges, v, w;
    edge_t *edge;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    graph.num_vertices = num_vertices;
    graph.num_edges = num_edges;
    graph.adj_list = (int **) malloc(num_vertices * sizeof(int *));

    for (i = 0; i < num_vertices; i++) {
        graph.adj_list[i] = (int *) malloc(num_vertices * sizeof(int));
    }

    printf("Enter the edges (vertex 1, vertex 2, weight):\n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &v, &w, &edge[i].weight);
        graph.adj_list[v][v] = 1; // add self-loop
        graph.adj_list[w][v] = 1; // add edge from vertex v to vertex w
        graph.adj_list[v][w] = 1; // add edge from vertex w to vertex v
    }

    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d:\n", i);
        for (j = 0; j < num_vertices; j++) {
            if (graph.adj_list[i][j] == 1) {
                printf(" - Edge to vertex %d with weight %d\n", j, edge[j].weight);
            }
        }
    }

    free(graph.adj_list);
    free(edge);

    return 0;
}