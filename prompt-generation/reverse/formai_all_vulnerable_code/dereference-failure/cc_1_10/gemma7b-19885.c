//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void findMinDistance(int **graph, int n, int m)
{
    int i, j, k, minDistance = MAX, currentDistance;

    // Create a distance matrix
    int **distance = (int *)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        distance[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++)
        {
            distance[i][j] = MAX;
        }
    }

    // Initialize the distance of the source vertex to 0
    distance[0][0] = 0;

    // Iterate over the number of iterations
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (distance[i][j] == MAX)
                {
                    continue;
                }
                currentDistance = distance[i][j] + graph[i][j];
                if (currentDistance < minDistance)
                {
                    minDistance = currentDistance;
                }
            }
        }
    }

    // Print the minimum distance
    printf("The minimum distance is: %d\n", minDistance);

    // Free the memory allocated for the distance matrix
    for (i = 0; i < n; i++)
    {
        free(distance[i]);
    }
    free(distance);
}

int main()
{
    int n, m, i, j;
    int **graph;

    // Get the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    // Create the adjacency matrix
    graph = (int *)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Get the edges of the graph
    printf("Enter the edges of the graph (source vertex, destination vertex, weight):\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &graph[0][i], &graph[1][i], &graph[2][i]);
    }

    // Find the minimum distance
    findMinDistance(graph, n, m);

    // Free the memory allocated for the adjacency matrix
    for (i = 0; i < n; i++)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}