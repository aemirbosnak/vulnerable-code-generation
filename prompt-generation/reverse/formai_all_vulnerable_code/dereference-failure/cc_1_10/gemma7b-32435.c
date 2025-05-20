//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void main()
{
    int **graph = NULL;
    int i, j, k, l, num_vertices, num_edges;
    char **vertices = NULL;

    printf("Enter the number of vertices:");
    scanf("%d", &num_vertices);

    graph = (int **)malloc(num_vertices * sizeof(int *));
    vertices = (char **)malloc(num_vertices * sizeof(char *));

    for (i = 0; i < num_vertices; i++)
    {
        graph[i] = (int *)malloc(num_vertices * sizeof(int));
        vertices[i] = (char *)malloc(20 * sizeof(char));
    }

    printf("Enter the number of edges:");
    scanf("%d", &num_edges);

    for (i = 0; i < num_edges; i++)
    {
        printf("Enter the source vertex:");
        scanf("%d", &k);

        printf("Enter the destination vertex:");
        scanf("%d", &l);

        graph[k][l] = 1;
    }

    for (i = 0; i < num_vertices; i++)
    {
        for (j = 0; j < num_vertices; j++)
        {
            if (graph[i][j] == 1)
            {
                printf("%c - %c\n", vertices[i], vertices[j]);
            }
        }
    }

    free(graph);
    free(vertices);

    return;
}