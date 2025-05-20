//FormAI DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>

#define MAX_VERTICES 50

int graph[MAX_VERTICES][MAX_VERTICES], V;

/**
 * Adds edge between two vertices.
 */
void addEdge(int graph[][MAX_VERTICES], int u, int v)
{
    graph[u][v] = graph[v][u] = 1;
}

/**
 * Displays the graph in matrix representation.
 */
void displayGraph(int graph[][MAX_VERTICES], int n)
{
    printf("\nAdjacency Matrix of graph:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Read number of vertices input from user
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("\n");

    // Read graph input from user
    int u, v;
    while (1)
    {
        printf("Enter edge between two vertices (Enter -1 -1 to exit): ");
        scanf("%d %d", &u, &v);

        if (u == -1 && v == -1)
            break;

        if (u >= V || v >= V || u < 0 || v < 0)
        {
            printf("Invalid vertices. Try again.\n");
            continue;
        }

        addEdge(graph, u, v);
    }

    displayGraph(graph, V);

    return 0;
}