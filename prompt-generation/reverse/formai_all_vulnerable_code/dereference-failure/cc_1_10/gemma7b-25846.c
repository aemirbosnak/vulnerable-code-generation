//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int **graph = NULL;
    int num_vertices = 0;
    char **map = NULL;

    graph = malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        graph[i] = malloc(MAX * sizeof(int));
    }

    num_vertices = 5;
    map = malloc(num_vertices * MAX);

    // Draw the map
    map[0] = 'A';
    map[1] = 'B';
    map[2] = 'C';
    map[3] = 'D';
    map[4] = 'E';

    // Connect the vertices
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;

    // Print the map
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            printf("%c ", graph[i][j] ? map[graph[i][j]] : '.');
        }
        printf("\n");
    }

    free(graph);
    free(map);

    return 0;
}