//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void create_topology(int **graph, int num_vertices)
{
    *graph = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++)
    {
        (*graph)[i] = 0;
    }
}

void add_edge(int **graph, int num_vertices, int u, int v)
{
    (*graph)[u] |= (1 << v);
}

void print_topology(int **graph, int num_vertices)
{
    for (int i = 0; i < num_vertices; i++)
    {
        int neighbors = (*graph)[i];
        printf("Vertex %d has neighbors:", i);
        for (int j = 0; neighbors & (1 << j); j++)
        {
            printf(" %d", j);
        }
        printf("\n");
    }
}

int main()
{
    int num_vertices = 5;
    int **graph;

    create_topology(&graph, num_vertices);
    add_edge(graph, num_vertices, 0, 1);
    add_edge(graph, num_vertices, 1, 2);
    add_edge(graph, num_vertices, 2, 3);
    add_edge(graph, num_vertices, 3, 4);
    add_edge(graph, num_vertices, 4, 0);

    print_topology(graph, num_vertices);

    return 0;
}