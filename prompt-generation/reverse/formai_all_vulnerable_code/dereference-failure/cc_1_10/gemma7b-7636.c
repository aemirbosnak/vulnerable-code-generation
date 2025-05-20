//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm(int **graph, int n, int m)
{
    int i, j, k, min_distance = MAX, current_distance = MAX, total_distance = 0;
    int visited = 0, current_vertex = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (graph[i][j] != 0)
            {
                current_distance = graph[i][j];
                if (current_distance < min_distance)
                {
                    min_distance = current_distance;
                    current_vertex = i;
                }
            }
        }
    }

    visited = 1;
    current_distance = min_distance;
    total_distance += current_distance;

    for (k = 0; k < n; k++)
    {
        if (visited == 0)
        {
            current_distance = min_distance;
            if (current_distance < min_distance)
            {
                min_distance = current_distance;
                current_vertex = k;
            }
            visited = 1;
        }
    }

    total_distance += min_distance;

    printf("Total Distance: %d", total_distance);
}

int main()
{
    int n, m;
    int **graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    greedy_algorithm(graph, n, m);

    return 0;
}