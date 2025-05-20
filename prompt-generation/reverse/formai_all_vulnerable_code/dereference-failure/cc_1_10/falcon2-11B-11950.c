//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));

    char* vertex_names[] = {"A", "B", "C", "D", "E"};
    int num_vertices = sizeof(vertex_names) / sizeof(char*);
    int num_edges = 4;

    struct Graph {
        int num_vertices;
        int* adjacency_list;
        char** vertex_names;
    } graph;

    graph.num_vertices = num_vertices;
    graph.adjacency_list = malloc(num_vertices * sizeof(int));
    graph.vertex_names = malloc(num_vertices * sizeof(char*));

    for (int i = 0; i < num_vertices; i++) {
        graph.adjacency_list[i] = 0;
        graph.vertex_names[i] = malloc(2 * sizeof(char));
        strcpy(graph.vertex_names[i], vertex_names[i]);
    }

    // Create edges
    int* edge_vertices[] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}
    };

    for (int i = 0; i < num_edges; i++) {
        int v1 = edge_vertices[i][0];
        int v2 = edge_vertices[i][1];

        graph.adjacency_list[v1]++;
        graph.adjacency_list[v2]++;
    }

    // Print graph
    printf("Graph: \n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%s -> %s : %d\n", graph.vertex_names[i], graph.vertex_names[i + 1], graph.adjacency_list[i]);
    }

    return 0;
}